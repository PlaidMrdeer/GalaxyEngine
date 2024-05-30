#ifndef GALAXYENGINE_VERTEX_H
#define GALAXYENGINE_VERTEX_H

#include <iostream>

class Vertex
{
public:
    Vertex(float *vertices);

    void handleVertex();

    unsigned int getVAO();
    unsigned int getVBO();
private:
    float *vertices;
    unsigned int VBO, VAO;
};


#endif
