#pragma once

#include <vector>
#include <GL/glew.h>
#include "buffer.h"

namespace cosmo { namespace graphics {

	class VertexArray
	{

	private:
		
		GLuint m_array_id;
		std::vector<Buffer*> m_buffers;

	public:

		VertexArray();
		~VertexArray();

		void add_buffer(Buffer* buffer, GLuint index);
		void bind() const;
		void unbind() const;

	};
	
} }
