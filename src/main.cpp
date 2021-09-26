#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>


#include <tqnode/node.h>


class Health : public NodeBehaviour
{
    public:
        float health;
        void start()
        {
            std::cout << "I started lol" << std::endl;
        }
        void update(float delta)
        {
            std::cout << "I am updateing lmaoo" << std::endl;
        }
};

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
    GLFWwindow* window = glfwCreateWindow(800, 700, "Sbura", nullptr, nullptr);


    glfwMakeContextCurrent(window);
    glewInit();


    Node player;

    while(!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.1, 0.1, 0.3, 1.0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}