#include "Vertex.h"

#include <glad/glad.h>

Vertex::Vertex(float *vertices)
{
    this->vertices = vertices;
}

void Vertex::handleVertex()
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)nullptr);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
}

unsigned int *Vertex::getVBO()
{
    return &VBO;
}

unsigned int *Vertex::getVAO()
{
    return &VAO;
}
