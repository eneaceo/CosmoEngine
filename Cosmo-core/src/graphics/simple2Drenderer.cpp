#include "simple2Drenderer.h"

namespace cosmo { namespace graphics {



	void Simple2DRenderer::submit(const Renderable2D* renderable)
	{
		m_render_queue.push_back((StaticSprite*)renderable);
	}

	void Simple2DRenderer::flush()
	{
		while (!m_render_queue.empty())
		{
			const StaticSprite* sprite = m_render_queue.front();

			sprite->get_vao()->bind();
			sprite->get_ibo()->bind();

			sprite->get_shader().set_uniform_mat4("ml_matrix", maths::mat4::translation(sprite->get_position()));
			glDrawElements(GL_TRIANGLES, sprite->get_ibo()->get_count(), GL_UNSIGNED_SHORT, nullptr);

			sprite->get_ibo()->unbind();
			sprite->get_vao()->unbind();

			m_render_queue.pop_front();
		}
	}



} }