#include "src/graphics/window.h"
#include "src/maths/maths.h"
#include "src/graphics/shader.h"
#include "src/graphics/buffers/buffer.h"
#include "src/graphics/buffers/index_buffer.h"
#include "src/graphics/buffers/vertex_array.h"


int main()
{

	using namespace cosmo;
	using namespace graphics;
	using namespace maths;

	Window window("Cosmo", 960, 580);

	//glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

#if 0

	GLfloat vertices[] =
	{
		0,0,0,
		8,0,0,
		0,3,0,
		0,3,0,
		8,3,0,
		8,0,0
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

#else

	GLfloat vertices[] =
	{
		0,0,0,
		0,3,0,
		8,3,0,
		8,0,0
	};

	GLushort indices[] =
	{
		0,1,2,
		2,3,0
	};

	GLfloat colors_a[] =
	{
		1,0,1,1,
		1,0,1,1,
		1,0,1,1,
		1,0,1,1
	};

	GLfloat colors_b[] =
	{
		0.2f,0.3f,0.8f,1,
		0.2f,0.3f,0.8f,1,
		0.2f,0.3f,0.8f,1,
		0.2f,0.3f,0.8f,1
	};

	VertexArray sprite1, sprite2;
	IndexBuffer ibo(indices, 6);

	sprite1.add_buffer(new Buffer(vertices, 4 * 3, 3), 0);
	sprite1.add_buffer(new Buffer(colors_a, 4 * 4, 4), 1);
	sprite2.add_buffer(new Buffer(vertices, 4 * 3, 3), 0);
	sprite2.add_buffer(new Buffer(colors_b, 4 * 4, 4), 1);

#endif

	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader shader("Cosmo-core/src/shaders/basic.vert", "Cosmo-core/src/shaders/basic.frag");
	shader.enabled();
	shader.set_uniform_mat4("pr_matrix", ortho);
//	shader.set_uniform_mat4("ml_matrix", mat4::translation(vec3(4, 3, 0)));

//	shader.set_uniform_2f("light_pos", vec2(4.0f, 1.5f));
	shader.set_uniform_4f("colour", vec4(0.2f, 0.3f, 0.8f, 1.0f));

	float count = 0.0f;
	bool dir = true;

	while (!window.closed())
	{
		window.clear();

		double x, y;
		window.get_mouse_position(x, y);

		shader.set_uniform_2f("light_pos", vec2(float(x * 16.0f / 960.0f), float(9.0f - y * 9.0f / 540.0f)));

#if 0
		glDrawArrays(GL_TRIANGLES, 0, 6);	
#else
		sprite1.bind();
		ibo.bind();
		shader.set_uniform_mat4("ml_matrix", mat4::translation(vec3(4, 3, 0)));
		glDrawElements(GL_TRIANGLES, ibo.get_count(), GL_UNSIGNED_SHORT, 0);
		ibo.unbind();
		sprite1.unbind();

		sprite2.bind();
		ibo.bind();
		shader.set_uniform_mat4("ml_matrix", mat4::translation(vec3(0, 0, 0)));
		glDrawElements(GL_TRIANGLES, ibo.get_count(), GL_UNSIGNED_SHORT, 0);
		ibo.unbind();
		sprite2.unbind();


#endif

		window.update();

	}

	return 0;
}