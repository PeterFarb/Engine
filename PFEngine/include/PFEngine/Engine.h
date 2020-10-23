#ifndef ENGINE_H
#define ENGINE_H

    #include <glad/glad.h>
    #include <GLFW/glfw3.h>

    class Engine
    {
    private:

        GLFWwindow* window_;
        const char* screen_title_;
        int screen_width_;
        int screen_height_;
        
    public:

        bool Initialize(int screenWidth, int screenHeight, const char* screenTitle);
        void Update();
        void Render();

        Engine();
        ~Engine();
    };
    



#endif