class Engine
{
public:
    static void run();
private:
    static void initGLFW();
    static void createWindow();
    static void handleShader();
    static void handleVertex();
    static void mainLoop();
    static void cleanup();
};