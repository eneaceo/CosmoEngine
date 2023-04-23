#pragma once
#include "layer.h"
#include "../batchrenderer2D.h"

namespace cosmo { namespace graphics {
	
	
	class TileLayer : public Layer
	{
	public:
		TileLayer(Shader* shader);
		~TileLayer();
	};


} }