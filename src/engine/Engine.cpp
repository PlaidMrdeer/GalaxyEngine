#include "Engine.h"
#include "Shader.h"
#include "Vertex.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

GLFWwindow* window;
unsigned int shaderProgram;
unsigned int *VBO, *VAO;

void Engine::run()
{
    initGLFW();
    createWindow();
    handleShader();
    handleVertex();
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
    window = glfwCreateWindow(1000, 1000, "GalaxyEngine", nullptr, nullptr);
    if (window == nullptr)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        cleanup();
        return;
    }
    glfwMakeContextCurrent(window);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        cleanup();
        return;
    }
}

void Engine::handleShader()
{
    Shader shader{"/home/plaidmrdeer/dev/GalaxyEngine/shader/v.glsl", "/home/plaidmrdeer/dev/GalaxyEngine/shader/f.glsl"};
    shader.compileVertexShader();
    shader.compileFragmentShader();
    shaderProgram = shader.linkShader();
}

void Engine::handleVertex()
{
    float vertices[] = {
            0.5f,  0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f,
            -0.5f,  0.5f, 0.0f
    };
    Vertex vertex{vertices};
    vertex.handleVertex();

    VBO = vertex.getVBO();
    VAO = vertex.getVAO();

}

void Engine::mainLoop()
{
//    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    while (!glfwWindowShouldClose(window))
    {
        glUseProgram(shaderProgram);
        glBindVertexArray(*VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void Engine::cleanup()
{
    glDeleteVertexArrays(1, VAO);
    glDeleteBuffers(1, VBO);
    glDeleteProgram(shaderProgram);

    glfwTerminate();
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}