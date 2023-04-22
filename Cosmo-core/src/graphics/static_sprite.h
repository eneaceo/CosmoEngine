#pragma once

#include "renderable2D.h"

namespace cosmo { namespace graphics {



	class StaticSprite : public Renderable2D
	{
	private:

		VertexArray* m_vertex_array;
		IndexBuffer* m_index_buffer;

		Shader& m_shader;

	public:

		StaticSprite(float x, float y, float width, float height, const maths::vec4& color, Shader& shader);
		~StaticSprite();

		inline const VertexArray* get_vao() const { return m_vertex_array; }
		inline const IndexBuffer* get_ibo() const { return m_index_buffer; }
		inline Shader& get_shader() const { return m_shader; }

	};



} }
