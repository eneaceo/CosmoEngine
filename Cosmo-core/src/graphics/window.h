#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace cosmo { namespace graphics
{

		class Window
		{
		private:

			GLFWwindow* m_window;
			
			const char *m_title;
			int m_width, m_height;

		public:

			// Constrcutor and destructor
			Window(const char* title, int width, int height);
			~Window();

			// Window functions
			void clear() const;
			void update();

			bool closed() const;

			//Getters and Setters
			inline int get_width() const { return m_width; };
			inline int get_height() const { return m_height; };

		private:
			
			// Window initialization
			bool init();

		};

} }