#include "batchrenderer2D.h"


namespace cosmo { namespace graphics {

	BatchRenderer2D::BatchRenderer2D()
	{
		init();
	}

	BatchRenderer2D::~BatchRenderer2D()
	{
		delete m_ibo;
		glDeleteBuffers(1, &m_vbo);

	}

	void BatchRenderer2D::init()
	{
		glGenVertexArrays(1, &m_vao);
		glGenBuffers(1, &m_vbo);

		glBindVertexArray(m_vao);
		glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
		glBufferData(GL_ARRAY_BUFFER, RENDERER_BUFFER_SIZE, NULL, GL_DYNAMIC_DRAW);
		glEnableVertexAttribArray(SHADER_VERTEX_INDEX);
		glEnableVertexAttribArray(SHADER_COLOR_INDEX);
		glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const GLvoid*)0);
		glVertexAttribPointer(SHADER_COLOR_INDEX, 4, GL_UNSIGNED_BYTE, GL_TRUE, RENDERER_VERTEX_SIZE, (const GLvoid*)(offsetof(VertexData, VertexData::color)));
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		GLuint* indices = new GLuint[RENDERER_INDICES_SIZE];

		int offset = 0;
		for (int i = 0; i < RENDERER_INDICES_SIZE; i += 6)
		{
			indices[i] = offset + 0;
			indices[i + 1] = offset + 1;
			indices[i + 2] = offset + 2;

			indices[i + 3] = offset + 2;
			indices[i + 4] = offset + 3;
			indices[i + 5] = offset + 0;

			offset += 4;
		}

		m_ibo = new IndexBuffer(indices, RENDERER_INDICES_SIZE);

		glBindVertexArray(0);
	}

	void BatchRenderer2D::begin()
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
		m_buffer = (VertexData*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
	}

	void BatchRenderer2D::end()
	{
		glUnmapBuffer(GL_ARRAY_BUFFER);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void BatchRenderer2D::submit(const Renderable2D* renderable)
	{

		const maths::vec3& position = renderable->get_position();
		const maths::vec2& size = renderable->get_size();
		const maths::vec4& color = renderable->get_color();

		int r = color.x * 255.0f;
		int g = color.y * 255.0f;
		int b = color.z * 255.0f;
		int a = color.w * 255.0f;

		unsigned int c = a << 24 | b << 16 | g << 8 | r;

		m_buffer->vertex = *m_transformation_back * position;
		m_buffer->color = c;
		m_buffer++;

		m_buffer->vertex = *m_transformation_back * maths::vec3(position.x, position.y + size.y, position.z);
		m_buffer->color = c;
		m_buffer++;

		m_buffer->vertex = *m_transformation_back * maths::vec3(position.x + size.x, position.y + size.y, position.z);
		m_buffer->color = c;
		m_buffer++;

		m_buffer->vertex = *m_transformation_back * maths::vec3(position.x + size.x, position.y, position.z);
		m_buffer->color = c;
		m_buffer++;

		m_index_count += 6;
	}

	void BatchRenderer2D::flush()
	{
		glBindVertexArray(m_vao);
		m_ibo->bind();

		glDrawElements(GL_TRIANGLES, m_index_count, GL_UNSIGNED_INT, NULL);

		m_ibo->unbind();
		glBindVertexArray(0);

		m_index_count = 0;
	}

} }