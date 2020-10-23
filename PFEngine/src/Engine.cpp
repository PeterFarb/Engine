
#include <iostream>
#include <PFEngine/Engine.h>

void framebuffer_size_callback(GLFWwindow *window, int width, int height);

bool Engine::Initialize(int screen_width, int screen_height, const char *screen_title)
{

    this->screen_width_ = screen_width;
    this->screen_height_ = screen_height;
    this->screen_title_ = screen_title;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // glfw window creation
    // --------------------
    this->window_ = glfwCreateWindow(this->screen_width_, this->screen_height_, this->screen_title_, NULL, NULL);
    if (window_ == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window_);
    glfwSetFramebufferSizeCallback(window_, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    std::cout << glGetString(GL_VENDOR) << std::endl; 
    std::cout << glGetString(GL_RENDERER) << std::endl; 
    std::cout << glGetString(GL_VERSION) << std::endl; 
    std::cout << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl; 

    return 0;
}

void Engine::Update()
{
    glfwPollEvents();
}

void Engine::Render()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glfwSwapBuffers(window_);
}

Engine::Engine()
{
}

Engine::~Engine()
{
    glfwTerminate();
}


// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}