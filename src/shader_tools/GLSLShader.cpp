#include "GLSLShader.h"

GLSLShader::GLSLShader() :
	shader(0), compiled(false), shadertype(0), shader_name(""), shader_src("") {
}

GLSLShader::GLSLShader(const std::string &shader_name, const char *shader_text, GLenum shadertype) :
	shader(0), compiled(false), shadertype(shadertype), shader_name(shader_name), shader_src(std::string(shader_text)) {
}

GLSLShader::GLSLShader(const std::string &shader_name, const std::string &shader_text, GLenum shadertype) :
	shader(0), compiled(false), shadertype(shadertype), shader_name(shader_name), shader_src(shader_text) {
}

std::string GLSLShader::getSrc() const {
	return shader_src;
}

void GLSLShader::setSrc(const std::string &new_source) {
	shader_src = new_source;
	compiled = false; // setting new source forces recompile
}

void GLSLShader::setSrc(const char* new_source) {
	shader_src = std::string(new_source);
	compiled = false; // setting new source forces recompile
}

void GLSLShader::compile() {
	printf("(S) Compiling shader \"%s\" ... ", this->shader_name.c_str());
	shader = glCreateShader(shadertype);
	glShaderSource(shader, 1, ShaderStringHelper(shader_src), NULL);
	glCompileShader(shader);
	// check if shader compiled
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
	if (!compiled) {
		getCompilationError(shader);
		glDeleteShader(shader);
		compiled = false;
	}
	else {
		printf("OK - Shader ID: (%i) \n", shader);
	}
}

void GLSLShader::getCompilationError(GLuint shader) {
	int infologLength = 0;
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, (GLint *)&infologLength);
	char* infoLog = (char *)malloc(infologLength);
	glGetShaderInfoLog(shader, infologLength, NULL, infoLog); // will include terminate char
	printf("(S) Shader compilation error:\n%s\n", infoLog);
	free(infoLog);
}