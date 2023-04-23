#pragma once

#include "renderable2D.h"
#include <GL/glew.h>

namespace cosmo { namespace graphics {

	class Renderer2D
	{

	protected:

		std::vector<maths::mat4> m_transformation_stack;
		const maths::mat4* m_transformation_back;

	protected:

		Renderer2D()
		{
			m_transformation_stack.push_back(maths::mat4::identity());
			m_transformation_back = &m_transformation_stack.back();
		}

	public:

		void push(const maths::mat4& matrix, bool override = false)
		{
			if (override)
				m_transformation_stack.push_back(matrix);
			else
				m_transformation_stack.push_back(m_transformation_stack.back() * matrix);

			m_transformation_back = &m_transformation_stack.back();
		}

		void pop()
		{
			if (m_transformation_stack.size() > 1)
				m_transformation_stack.pop_back();

			m_transformation_back = &m_transformation_stack.back();
		}
		


		virtual void submit(const Renderable2D* renderable) = 0;
		virtual void flush() = 0;
		virtual void begin() {}
		virtual void end() {}
	};


} }