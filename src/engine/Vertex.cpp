#include "Vertex.h"

Vertex::Vertex(float *vertices)
{
    this->vertices = vertices;
}

float *Vertex::getVertex() {
    return vertices;
}