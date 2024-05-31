class Vertex
{
public:
    explicit Vertex(float *vertices);

    float *getVertex();
private:
    float *vertices;
};
