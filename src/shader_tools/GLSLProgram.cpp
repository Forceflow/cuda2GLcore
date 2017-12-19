#include "GLSLProgram.h"

GLSLProgram::GLSLProgram() : program(0), vertex_shader(NULL), fragment_shader(NULL), linked(false) {}

GLSLProgram::GLSLProgram(GLSLShader* vertex, GLSLShader* fragment) : program(0), vertex_shader(vertex), fragment_shader(fragment), linked(false) {}

void GLSLProgram::compile() {
	// create empty program
	program = glCreateProgram();
	// try to attach all shaders
	GLSLShader* shaders[2] = { vertex_shader, fragment_shader };
	for (unsigned int i = 0; i < 2; i++) {
		if (shaders[i] != NULL) {
			if (!shaders[i]->compiled) { shaders[i]->compile(); } // try to compile shader if not yet compiled
			if (shaders[i]->compiled) {
				glAttachShader(program, shaders[i]->shader);
				printf("(P) Attached shader \"%s\"(%i) to program (%i)\n", shaders[i]->shader_name.c_str(), shaders[i]->shader, program);
			}
			else {
				printf("(P) Failed to attach shader \"%s\"(%i) to program (%i)\n", shaders[i]->shader_name.c_str(), shaders[i]->shader, program);
				glDeleteProgram(program);
				return;
			}
		}
	}
	// try to link program
	glLinkProgram(program);
	GLint isLinked = 0;
	glGetProgramiv(program, GL_LINK_STATUS, &isLinked); // check if program linked
	if (isLinked == GL_FALSE) {
		printLinkError(program);
		glDeleteProgram(program);
		linked = false;
	}
	else {
		linked = true;
		printf("(P) Linked program %i \n", program);
	}
}

void GLSLProgram::use() {
	glUseProgram(this->program);
}

void GLSLProgram::printLinkError(GLuint program) {
	GLint infologLength = 0;
	glGetProgramiv(program, GL_INFO_LOG_LENGTH, (GLint *)&infologLength);
	char* infoLog = (char *)malloc(infologLength);
	glGetProgramInfoLog(program, infologLength, NULL, infoLog); // will include terminate char
	printf("(P) Program compilation error: %s\n", infoLog);
	free(infoLog);
}