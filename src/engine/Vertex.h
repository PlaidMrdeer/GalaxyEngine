class Vertex
{
public:
    explicit Vertex(float *vertices);

    void handleVertex();

    unsigned int *getVBO();
    unsigned int *getVAO();
private:
    float *vertices;
    unsigned int VBO{}, VAO{};
};
