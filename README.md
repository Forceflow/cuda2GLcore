# cuda2GLcore
This is an implementation of the *SimpleCuda2GL* sample provided in the [CUDA Samples by Nvidia](http://docs.nvidia.com/cuda/cuda-samples/index.html). The project shows how to generate a texture in CUDA and use it in an [OpenGL](https://www.opengl.org/) context without copying it to main memory. The original implementation uses [Glut](https://www.opengl.org/resources/libraries/glut/) and OpenGL immediate mode to draw the resulting texture. 

This implementation improves on the original example by using [GLEW](http://glew.sourceforge.net/), [GLFW](http://www.glfw.org/) and OpenGL 4.5 core, using buffer objects, allowing your applications to be analyzed by excellent tools such as Renderdoc, which only support core OpenGL Profiles.

**Note:** This example was based on the CUDA 8.0 samples and has been updated to work with newer CUDA versions. Since CUDA 11.0, the official NVIDIA sample has been problematic for me to run ([issue here](https://github.com/NVIDIA/cuda-samples/issues/61)). I'm working on pulling this example in line with the official samples. For now, this still seems like a good starting point, unless you're on OSX.

# Usage
In the `msvc` folder, there is a VS2017 and a VS2019 project (both have been tested using the VS Community Edition). Use the`custom_includes.props` file to define the locations of your GLEW and GLFW installations, then run the project.

![Cuda2GLCore example](https://raw.githubusercontent.com/Forceflow/cuda2GLcore/main/html/cuda2glcore.JPG)

# Notes
 * This code contains helper libraries by [Nvidia](http://docs.nvidia.com/cuda/cuda-samples/index.html). All of the code samples are available under a permissive license that allows you to freely incorporate them into your applications and create derivative works for commercial, academic, or personal use.
