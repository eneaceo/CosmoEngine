#include "buffer.h"



namespace cosmo { namespace graphics {


	Buffer::Buffer(GLfloat* data, GLsizei count, GLuint component_count)
		: m_component_count(component_count)
	{

		glGenBuffers(1, &m_buffer_id);
		glBindBuffer(GL_ARRAY_BUFFER, m_buffer_id);
		glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

	}

	Buffer::~Buffer()
	{
		glDeleteBuffers(1, &m_buffer_id);
	}

	void Buffer::bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_buffer_id);
	}


	void Buffer::unbind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}


} }
