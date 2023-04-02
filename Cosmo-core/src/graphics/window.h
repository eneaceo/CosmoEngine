#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace cosmo { namespace graphics
{

#define MAX_KEYS			1024
#define MAX_MOUSE_BUTTONS	32

		class Window
		{

		private:

			friend struct GLFWwindow;

			GLFWwindow* m_window;
			
			const char *m_title;
			int m_width, m_height;

			bool m_keys[MAX_KEYS];
			bool m_mouse_buttons[MAX_MOUSE_BUTTONS];
			double m_mouse_x_position, m_mouse_y_position;

		public:

			// Constrcutor and destructor
			Window(const char* title, int width, int height);
			~Window();

			// Window functions
			void clear() const;
			void update();

			bool closed() const;

			bool is_key_pressed(unsigned int keycode) const;
			bool is_mouse_button_pressed(unsigned int button) const;
			void get_mouse_position(double& x, double& y) const;

			//Getters and Setters
			inline int get_width() const { return m_width; };
			inline int get_height() const { return m_height; };

		private:
			
			// Window initialization
			bool init();

			friend static void key_press_callback(GLFWwindow* _window, int key, int scancode, int action, int mods);
			friend static void mouse_button_callback(GLFWwindow* _window, int button, int action, int mods);
			friend static void cursor_position_callback(GLFWwindow* _window, double xpos, double ypos);

		};

} }