#include "index_buffer.h"



namespace cosmo { namespace graphics {


		IndexBuffer::IndexBuffer(GLushort* data, GLsizei count)
			: m_count(count)
		{

			glGenBuffers(1, &m_buffer_id);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_buffer_id);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLushort), data, GL_STATIC_DRAW);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		}


		IndexBuffer::IndexBuffer(GLuint* data, GLsizei count)
			: m_count(count)
		{

			glGenBuffers(1, &m_buffer_id);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_buffer_id);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), data, GL_STATIC_DRAW);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		}

		IndexBuffer::~IndexBuffer()
		{
			glDeleteBuffers(1, &m_buffer_id);
		}

		void IndexBuffer::bind() const
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_buffer_id);
		}


		void IndexBuffer::unbind() const
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}


} }