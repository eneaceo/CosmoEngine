#pragma once

#include "renderer2D.h"
#include "static_sprite.h"
#include <deque>

namespace cosmo { namespace graphics {


	class Simple2DRenderer : public Renderer2D
	{

	private:
		std::deque<const StaticSprite*> m_render_queue;

	public:

		virtual void submit(const Renderable2D* renderable) override;
		virtual void flush() override;
	};


} }