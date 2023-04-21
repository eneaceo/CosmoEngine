#pragma once

#include "renderable2D.h"
#include "../maths/maths.h"
#include <GL/glew.h>

namespace cosmo { namespace graphics {

	class Rendered2D
	{

	public:
		
		virtual void submit(const Renderable2D& renderable) = 0;
		virtual void flush() = 0;

	};


} }