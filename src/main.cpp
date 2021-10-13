#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <ecs/ecsWorld.h>
#include <ecs/entity.h>
#include <util/generationalArray.h>

class Health : public Component
{
    public:
        int health;
};

int main()
{
    
    std::cout << "Hello World!" << std::endl;
    if(glfwInit() != GLFW_TRUE)
    {
        std::cout << "Glfw shat itself" << std::endl;
    }
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    GLFWwindow* window = glfwCreateWindow(800, 800, "Hello World!", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    if(glewInit() != GLEW_OK)
    {
        std::cout << "Glew pissed the bed" << std::endl;
    }

    FUCK ECS, JUST RIP OFF UNITY'S SYSTEM INSTEAD LOL

    World world;
    Entity player = world.entity();

    world.addComponent<Health>(&player);
    world.getComponent<Health>(player).health = 1;

    while(!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.1, 0.1, 0.15, 1.0);

        world.getComponent<Health>(player).health -= 1;
        // std::cout << world.getComponent<Health>(player).health << std::endl;


        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}