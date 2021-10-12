cmake_minimum_required(VERSION 3.1)
project(TenQuartersEngine)

file(GLOB_RECURSE SRC
     "src/modules/*.cpp"
     "src/modules/*.h"
)

add_executable(${CMAKE_PROJECT_NAME} src/main.cpp ${SRC})



add_subdirectory(lib/glfw)
# target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC glfw)

add_subdirectory(lib/glew/build/cmake)
# target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC glew_s)

add_subdirectory(lib/glm)
# target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC glm)

add_library(StbImage "lib/stb/include/stb_image.cpp")
set_target_properties(StbImage PROPERTIES LINKER_LANGUAGE CXX)

set(LIBS StbImage glm glew_s glfw)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC lib/stb/include)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC lib/glew/include)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC lib/glfw/include)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC lib/glm/glm)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC src/modules)

target_link_libraries(${CMAKE_PROJECT_NAME} ${LIBS})