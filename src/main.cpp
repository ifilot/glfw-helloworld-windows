#include <windows.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

/*
 * execute this function is an error is encountered
 */
static void error_callback(int error, const char* description) {
    std::cerr << "Error: "<< description << std::endl;
}

/*
 * execute this function every time a key is pressed
 */
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

/*
 * WinMain enables us to launch a Windows application that immediately returns to the prompt
 */
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
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // white background
        glClear(GL_COLOR_BUFFER_BIT);

        // add draw calls

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