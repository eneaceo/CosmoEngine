#include "window.h"

namespace cosmo { namespace graphics {
	
	//Window resize callback declaration
	void window_resize(GLFWwindow* window, int width, int height);


	// Window constructor
	Window::Window(const char* title, int width, int height)
	{
		m_title = title;
		m_width = width;
		m_height = height;

		if (!init())
		{
			glfwTerminate();
		}
	
	}


	// Window destructor
	Window::~Window()
	{
		glfwTerminate();
	}


	// Window initialization
	bool Window::init()
	{
		if (glfwInit())
		{
			m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);

			if (m_window == NULL)
			{
				glfwTerminate();
				std::cout << "ERROR: Failed GLFW window creation" << std::endl;
				return false;
			}

			glfwMakeContextCurrent(m_window);
			glfwSetWindowSizeCallback(m_window, window_resize);

			if (glewInit() != GLEW_OK)
			{
				std::cout << "ERROR: Failed GLEW initialization" << std::endl;
			}

		}
		else
		{
			std::cout << "ERROR: Failed GLFW Initialization" << std::endl;
			return false;
		}

		return true;
	}


	// Clear window
	void Window::clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}


	// Update window, called every frame
	void Window::update()
	{
		glfwPollEvents();
		glfwGetFramebufferSize(m_window, &m_width, &m_height);
		glfwSwapBuffers(m_window);
	}


	// Is window closed
	bool Window::closed() const
	{
		return glfwWindowShouldClose(m_window);
	}


	// Window resize callback
	void window_resize(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}


} }
