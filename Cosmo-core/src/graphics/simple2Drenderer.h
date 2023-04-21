#pragma once

#include "renderer2D.h"
#include <deque>

namespace cosmo { namespace graphics {


	class Simple2DRenderer : public Rendered2D
	{

	private:
		std::deque<const Renderable2D*> m_render_queue;

	public:

		virtual void submit(const Renderable2D* renderable) override;
		virtual void flush() override;
	};


} }