#pragma once

#include <GL/glew.h>

namespace cosmo { namespace graphics {


	class Buffer
	{
	
	private :
	
		GLuint m_buffer_id;
		GLuint m_component_count;
	
	public:

		Buffer(GLfloat* data, GLsizei count, GLuint component_count);

		void bind() const;
		void unbind() const;

		inline GLuint get_component_count() const { return m_component_count;}

	};

} }

