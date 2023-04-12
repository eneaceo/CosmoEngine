#include "shader.h"

namespace cosmo { namespace graphics {

	Shader::Shader(const char* vertpath, const char* fragpath)
		: m_vertpath(vertpath), m_fragpath(fragpath)
	{
		m_shader_id = load();
	}

	Shader::~Shader()
	{
		glDeleteProgram(m_shader_id);
	}

	GLuint Shader::load()
	{
		GLuint program = glCreateProgram();
		GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
		GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

		std::string vertsource_string = file_utils::read_file(m_vertpath);
		std::string fragsource_string = file_utils::read_file(m_fragpath);
		const char* vertsource = vertsource_string.c_str();
		const char* fragsource = fragsource_string.c_str();

		glShaderSource(vertex, 1, &vertsource, NULL);
		glCompileShader(vertex);
		
		GLint result;
		glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE)
		{
			int length;
			glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> error(length);
			glGetShaderInfoLog(vertex, length, &length, &error[0]);
			std::cout << "FAILED TO COMPILE VERTEX SHADER:\n"  << &error[0] << std::endl;
			glDeleteShader(vertex);
			return 0;
		}

		glShaderSource(fragment, 1, &fragsource, NULL);
		glCompileShader(fragment);
	

		glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE)
		{
			int length;
			glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> error(length);
			glGetShaderInfoLog(fragment, length, &length, &error[0]);
			std::cout << "FAILED TO COMPILE FRAGMENT SHADER:\n" << & error[0] << std::endl;
			glDeleteShader(fragment);
			return 0;
		}

		glAttachShader(program, vertex);
		glAttachShader(program, fragment);

		glLinkProgram(program);
		glValidateProgram(program);

		glDeleteShader(vertex);
		glDeleteShader(fragment);

		return result;
	}


	void Shader::enabled() const
	{
		glUseProgram(m_shader_id);
	}

	void Shader::disabled() const
	{
		glUseProgram(0);
	}


} }