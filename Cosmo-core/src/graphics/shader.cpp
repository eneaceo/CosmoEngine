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

		std::string vertsource_string = FileUtils::read_file(m_vertpath);
		std::string fragsource_string = FileUtils::read_file(m_fragpath);
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


	void Shader::set_uniform_1f(const GLchar* name, float value)
	{
		glUniform1f(get_uniform_location(name), value);
	}

	void Shader::set_uniform_1i(const GLchar* name, int value)
	{
		glUniform1f(get_uniform_location(name), value);
	}

	void Shader::set_uniform_2f(const GLchar* name, const maths::vec2& vector)
	{
		glUniform2f(get_uniform_location(name), vector.x, vector.y);
	}

	void Shader::set_uniform_3f(const GLchar* name, const maths::vec3& vector)
	{
		glUniform3f(get_uniform_location(name), vector.x, vector.y, vector.z);
	}

	void Shader::set_uniform_4f(const GLchar* name, const maths::vec4& vector)
	{
		glUniform4f(get_uniform_location(name), vector.x, vector.y, vector.z, vector.w);
	}

	void Shader::set_uniform_mat4(const GLchar* name, const maths::mat4& matrix)
	{
		glUniformMatrix4fv(get_uniform_location(name), 1, GL_FALSE, matrix.elements);
	}

	GLuint Shader::get_uniform_location(const GLchar* name)
	{
		return glGetUniformLocation(m_shader_id, name);
	}

} }