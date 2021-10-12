#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <ecs/ecsWorld.h>

#include <tqnode/node.h>

#include <util/generationalArray.h>

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

    GenerationalArray<int> arr;
    GenerationalIndex i = arr.push(2);

    std::cout << arr[i] << std::endl;

    while(!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.1, 0.1, 0.15, 1.0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}