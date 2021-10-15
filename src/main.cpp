#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <util/generationalArray.h>
#include <gameObject/gameObject.h>
#include <gameObject/components/core/transform.h>

class Health : public Component
{
    public:
        float health;

        void start()
        {
            health = 100;
        }

        void update(float delta)
        {
            health -= 0.1f;
            std::cout << "Health: " << health << std::endl;
        }
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

    // FUCK ECS, JUST RIP OFF UNITY'S SYSTEM INSTEAD LOL
    GameObject player;
    player.addComponent<Transform>();
    player.addComponent<Health>();
    

    player.start();

    while(!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.1f, 0.1f, 0.15f, 1.0f);

        player.update(0.1f);


        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}