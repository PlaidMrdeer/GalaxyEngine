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

    std::string s_vertexCode{};
    std::string s_fragmentCode{};
};