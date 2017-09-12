#pragma once

#include <GLFW/glfw3.h>
#include <cstdio>
#include <string>

using namespace std;

void printGLFWInfo(GLFWwindow* w){
	int p = glfwGetWindowAttrib(w, GLFW_OPENGL_PROFILE);
	string version = glfwGetVersionString();
	string opengl_profile = "";
	if(p == GLFW_OPENGL_COMPAT_PROFILE){
		opengl_profile = "OpenGL Compatibility Profile";
	}
	else if (p == GLFW_OPENGL_CORE_PROFILE){
		opengl_profile = "OpenGL Core Profile";
	}
	printf("GLFW: %s \n", version.c_str());
	printf("GLFW: %s %i \n", opengl_profile.c_str(), p);
}
