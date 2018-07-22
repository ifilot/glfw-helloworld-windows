#include <windows.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

static void error_callback(int error, const char* description) {
    fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

INT WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow) {

	// create pointer to new window
    GLFWwindow* window;

    // set error callback function
    glfwSetErrorCallback(error_callback);

    // try to initialize glfw
    if (!glfwInit())
        exit(EXIT_FAILURE);
	    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    
    // create a new window
    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    
    // check if the window was succesfully created
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // set a key callback function
    glfwSetKeyCallback(window, key_callback);

    // make the created windows the active context
    glfwMakeContextCurrent(window);

    // set swap interval
    glfwSwapInterval(1);

    // start loop
    while (!glfwWindowShouldClose(window)) {
    	// get width window width and height
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);

        // set the viewport to match width and height
        glViewport(0, 0, width, height);

        // clear the buffer
        glClear(GL_COLOR_BUFFER_BIT);

        // swap buffers
        glfwSwapBuffers(window);

        // poll for any events
        glfwPollEvents();
    }

    // destroy the window and clean up
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}