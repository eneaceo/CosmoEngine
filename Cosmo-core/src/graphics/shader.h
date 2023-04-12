#pragma once

#include <vector>
#include <iostream>
#include "../utils/file_utils.h"
#include "GL/glew.h"

namespace cosmo { namespace graphics {

	class Shader
	{

	public:
		
		GLuint m_shader_id;
		
		const char *m_vertpath, *m_fragpath;
	
	public:

		Shader(const char* vertpath, const char* fragpath);
		~Shader();

		void enabled() const;
		void disabled() const;

	private:

		GLuint load();
	
	};


} }