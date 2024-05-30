#include "Engine.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

GLFWwindow* window;

void Engine::run()
{
    initGLFW();
    createWindow();
    mainLoop();
    cleanup();
}

void Engine::initGLFW()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CENTER_CURSOR, GLFW_TRUE);
}

void Engine::createWindow()
{
    window = glfwCreateWindow(800, 600, "GalaxyEngine", nullptr, nullptr);
    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return;
    }
}

void Engine::mainLoop()
{
    while (!glfwWindowShouldClose(window))
    {
        glViewport(0, 0, 800, 600);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void Engine::cleanup()
{
    glfwTerminate();
}
