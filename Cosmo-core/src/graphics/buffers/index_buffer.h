#pragma once

#include <GL/glew.h>

namespace cosmo { namespace graphics {


		class IndexBuffer
		{

		private:

			GLuint m_buffer_id;
			GLuint m_count;

		public:

			IndexBuffer(GLushort* data, GLsizei count);

			void bind() const;
			void unbind() const;

			inline GLuint get_count() const { return m_count; }

		};

} }

