
#ifndef GALAXYENGINE_ENGINE_H
#define GALAXYENGINE_ENGINE_H

class Engine
{
public:
    void run();
private:
    static void initGLFW();
    static void createWindow();
    static void mainLoop();
    static void cleanup();
};

#endif