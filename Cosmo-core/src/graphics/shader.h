#pragma once

#include <vector>
#include <iostream>

#include "GL/glew.h"

#include "../maths/maths.h"
#include "../utils/file_utils.h"

namespace cosmo { namespace graphics {

	class Shader
	{

	private:
		
		GLuint m_shader_id;
		
		const char *m_vertpath, *m_fragpath;
	
	public:

		Shader(const char* vertpath, const char* fragpath);
		~Shader();

		void set_uniform_1f(const GLchar* name, float value);
		void set_uniform_1i(const GLchar* name, int value);	
		void set_uniform_2f(const GLchar* name, const maths::vec2& vector);
		void set_uniform_3f(const GLchar* name, const maths::vec3& vector);
		void set_uniform_4f(const GLchar* name, const maths::vec4& vector);

		void set_uniform_mat4(const GLchar* name, const maths::mat4& matrix);

		void enabled() const;
		void disabled() const;

	private:

		GLuint get_uniform_location(const GLchar* name);
	
		GLuint load();
	};


} }