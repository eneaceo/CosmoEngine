#pragma once

#include "../maths/maths.h"
#include "buffers/buffer.h"
#include "buffers/index_buffer.h"
#include "buffers/vertex_array.h"
#include "shader.h"

namespace cosmo { namespace graphics {

	struct VertexData
	{
		maths::vec3 vertex;
		//maths::vec4 color;
		unsigned int color;
	};

	class Renderable2D
	{

	protected:

		maths::vec3 m_position;
		maths::vec2 m_size;
		maths::vec4 m_color;

	public:

		Renderable2D(maths::vec3 position, maths::vec2 size, maths::vec4 color)
			: m_position(position), m_size(size), m_color(color)
		{ }

		~Renderable2D(){ }

		inline const maths::vec3& get_position() const { return m_position; }
		inline const maths::vec2& get_size() const { return m_size; }
		inline const maths::vec4& get_color() const { return m_color; }

	};


} }