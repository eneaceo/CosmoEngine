#include "window.h"

namespace cosmo { namespace graphics {

	// Window resize callback declaration
	void window_resize_callback(GLFWwindow* window, int width, int height);
	// Key press callback
	void key_press_callback(GLFWwindow* _window, int key, int scancode, int action, int mods);
	// Key press callback
	void mouse_button_callback(GLFWwindow* _window, int button, int action, int mods);
	// Cursos position callback
	void cursor_position_callback(GLFWwindow* _window, double xpos, double ypos);


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

		for (int i = 0; i < MAX_KEYS; i++)
		{
			m_keys[i] = false;
		}

		for (int i = 0; i < MAX_MOUSE_BUTTONS; i++)
		{
			m_mouse_buttons[i] = false;
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
			glfwSetWindowUserPointer(m_window, this);
			glfwSetWindowSizeCallback(m_window, window_resize_callback);
			glfwSetKeyCallback(m_window, key_press_callback);
			glfwSetMouseButtonCallback(m_window, mouse_button_callback);
			glfwSetCursorPosCallback(m_window, cursor_position_callback);

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

	
	//
	bool Window::is_key_pressed(unsigned int keycode) const
	{
		if (keycode >= MAX_KEYS)
		{
			std::cout << "ERROR: Keycode out of range" << std::endl;
			return false;
		}
			return m_keys[keycode];
	}


	//
	bool Window::is_mouse_button_pressed(unsigned int button) const
	{
		if (button >= MAX_MOUSE_BUTTONS)
		{
			std::cout << "ERROR: Keycode out of range" << std::endl;
			return false;
		}
		return m_mouse_buttons[button];
	}


	//
	void Window::get_mouse_position(double& x, double& y) const
	{
		x = m_mouse_x_position;
		y = m_mouse_y_position;
	}


	// Window resize callback
	void window_resize_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}


	// Key press callback
	void key_press_callback(GLFWwindow* _window, int key, int scancode, int action, int mods)
	{
		Window* window = (Window*) glfwGetWindowUserPointer(_window);
		window->m_keys[key] = action != GLFW_RELEASE;
	}


	// Mouse button press callback
	void mouse_button_callback(GLFWwindow* _window, int button, int action, int mods)
	{
		Window* window = (Window*)glfwGetWindowUserPointer(_window);
		window->m_mouse_buttons[button] = action != GLFW_RELEASE;
	}


	// Cursor position callback
	void cursor_position_callback(GLFWwindow* _window, double xpos, double ypos)
	{
		Window* window = (Window*)glfwGetWindowUserPointer(_window);
		window->m_mouse_x_position = xpos;
		window->m_mouse_y_position = ypos;
	}

} }
