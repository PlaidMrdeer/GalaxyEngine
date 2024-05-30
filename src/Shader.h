#ifndef GALAXYENGINE_SHADER_H
#define GALAXYENGINE_SHADER_H


class Shader
{
public:
    Shader(const char *vertexShaderSource, const char *fragmentShaderSource);

    void handleShader();

    unsigned int getShader();
private:
    const char *vertexShaderSource;
    const char *fragmentShaderSource;

    void compileVertexShader();
    void compileFragmentShader();
    void linkShader();
};


#endif
