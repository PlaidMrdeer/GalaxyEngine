#include <string>

class Shader
{
public:
    Shader(const std::string& vertexShaderSource, const std::string& fragmentShaderSource);

    void compileVertexShader();
    void compileFragmentShader();
    unsigned int linkShader();
private:
    unsigned int vertexShader{};
    unsigned int fragmentShader{};
    unsigned int shaderProgram{};

    const char *vertexCode{};
    const char *fragmentCode{};
};