#include "src/graphics/window.h"

int main()
{

	using namespace cosmo;
	using namespace graphics;

	Window window("Cosmo", 960, 580);

	glClearColor(0.2f, 0.3f, 0.7f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	while (!window.closed())
	{

		window.clear();

		double x, y;
		window.get_mouse_position(x, y);
		if (window.is_mouse_button_pressed(GLFW_MOUSE_BUTTON_LEFT))
		{
			std::cout << x << ", " << y << std::endl;
		}

# if 1
		glBegin(GL_QUADS);
		glVertex2f( -0.5f, -0.5f);
		glVertex2f( -0.5f,  0.5f);
		glVertex2f(  0.5f,  0.5f);
		glVertex2f(  0.5f, -0.5f);
		glEnd();
# else
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
# endif 
		
		window.update();
	}

	return 0;
}