#include "src/graphics/window.h"
#include "src/maths/maths.h"
#include "src/graphics/shader.h"


int main()
{

	using namespace cosmo;
	using namespace graphics;
	using namespace maths;

	Window window("Cosmo", 960, 580);

	glClearColor(0.2f, 0.3f, 0.7f, 1.0f);


	GLfloat vertices[] =
	{
		4,3,0,
		12,3,0,
		4,6,0,
		4,6,0,
		12,6,0,
		12,3,0
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader shader("Cosmo-core/src/shaders/basic.vert", "Cosmo-core/src/shaders/basic.frag");
	shader.enabled();

	glUniformMatrix4fv(glGetUniformLocation(shader.m_shader_id, "pr_matrix"), 1, GL_FALSE, ortho.elements);

	while (!window.closed())
	{
		window.clear();

		glDrawArrays(GL_TRIANGLES, 0, 6);	

		window.update();

	}

	return 0;
}