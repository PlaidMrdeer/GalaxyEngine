
class Shader
{
public:
    Shader(const char *vertexShaderSource, const char *fragmentShaderSource);

    void compileVertexShader();
    void compileFragmentShader();
    unsigned int linkShader();
private:
    unsigned int vertexShader{};
    unsigned int fragmentShader{};
    unsigned int shaderProgram{};

    const char *vertexShaderSource{};
    const char *fragmentShaderSource{};
};