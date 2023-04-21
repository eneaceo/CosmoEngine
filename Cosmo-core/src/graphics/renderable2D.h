#pragma once

#include "../maths/maths.h"
#include "buffers/buffer.h"
#include "buffers/index_buffer.h"
#include "buffers/vertex_array.h"
#include "shader.h"

namespace cosmo { namespace graphics {


	class Renderable2D
	{

	protected:

		maths::vec3 m_position;
		maths::vec2 m_size;
		maths::vec4 m_color;

		VertexArray* m_vertex_array;
		IndexBuffer* m_index_buffer;

		Shader& m_shader;

	public:

		Renderable2D(maths::vec3 position, maths::vec2 size, maths::vec4 color, Shader& shader)
			: m_position(position), m_size(size), m_color(color), m_shader(shader)
		{
			m_vertex_array = new VertexArray();

			GLfloat vertices[] =
			{
				0, 0, 0,
				0, size.y, 0,
				size.x, size.y, 0,
				size.x, 0, 0
			};

			GLfloat colors[] =
			{
				color.x, color.y, color.z, color.w,
				color.x, color.y, color.z, color.w,
				color.x, color.y, color.z, color.w,
				color.x, color.y, color.z, color.w
			};

			m_vertex_array->add_buffer(new Buffer(vertices, 4 * 3, 3), 0);
			m_vertex_array->add_buffer(new Buffer(colors, 4 * 4, 4), 1);

			GLushort indices[] = { 0, 1, 2, 2, 3, 0 };
			m_index_buffer = new IndexBuffer(indices, 6);
		}

		~Renderable2D()
		{
			delete m_vertex_array;
			delete m_index_buffer;
		}


		inline const VertexArray* get_vao() const { return m_vertex_array; }
		inline const IndexBuffer* get_ibo() const { return m_index_buffer; }
		inline Shader& get_shader() const { return m_shader; }

		inline const maths::vec3& get_position() const { return m_position; }
		inline const maths::vec2& get_size() const { return m_size; }
		inline const maths::vec4& get_color() const { return m_color; }

	};


} }