#pragma once

#include "../renderer2D.h"

namespace cosmo { namespace graphics {

	class Layer
	{

	protected:
		Renderer2D* m_renderer;
		std::vector<Renderable2D*> m_renderables;
		Shader* m_shader;
		maths::mat4 m_projection_matrix;
	protected:
		Layer(Renderer2D* renderer, Shader* shader, maths::mat4 projection_matrix);
	public:
		virtual ~Layer();
		virtual void add(Renderable2D* renderable);
		virtual void render();

	};


} }