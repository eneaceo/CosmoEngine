#include "layer.h"


namespace cosmo { namespace graphics {

	Layer::Layer(Renderer2D* renderer, Shader* shader, maths::mat4 projectionMatrix)
		: m_renderer(renderer), m_shader(shader), m_projection_matrix(projectionMatrix)
	{
		m_shader->enabled();
		m_shader->set_uniform_mat4("pr_matrix", m_projection_matrix);
		m_shader->disabled();
	}

	Layer::~Layer()
	{
		delete m_shader;
		delete m_renderer;

		for (int i = 0; i < m_renderables.size(); i++)
			delete m_renderables[i];
	}

	void Layer::add(Renderable2D* renderable)
	{
		m_renderables.push_back(renderable);
	}

	void Layer::render()
	{
		m_shader->enabled();
		m_renderer->begin();

		for (const Renderable2D* renderable : m_renderables)
		{
			m_renderer->submit(renderable);
		}

		m_renderer->end();
		m_renderer->flush();
	}


} }