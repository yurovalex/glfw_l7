cmake_minimum_required(VERSION 3.1)

project(GLFW_3D_Geometry LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OpenGL_GL_PREFERENCE LEGACY)
find_package(OpenGL REQUIRED)

add_subdirectory(external)

add_executable(GLFW_3D_Geometry main.cpp)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        external
        ${OPENGL_INCLUDE_DIR}
)

target_link_libraries(GLFW_3D_Geometry
    ${OPENGL_LIBRARIES}
    glfw
    glad
)


