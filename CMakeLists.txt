cmake_minimum_required(VERSION 3.1)
project(TenQuartersEngine)

add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)

add_subdirectory(lib/glfw)
target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC glfw)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC src/modules)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC lib/stb)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC lib/glew/include)
# target_link_directories(${CMAKE_PROJECT_NAME} PUBLIC lib/glew/lib)
add_subdirectory(lib/glew/build/cmake)
target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC glew)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC lib/glm/glm)
add_subdirectory(lib/glm)
target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC glm)
