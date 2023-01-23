#include"imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"


#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <fstream>
#include "DebugFile.h"
#include "DebugWindows.h"
#include "DebugCommands.h"





const char* fragmentShaderSource = "#version 420 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0"
;

const char* vertexShaderSource = "#version 420 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0"
;

int Rendering()
{
    //Vertices
    //=====================================
    float vertices[] =
    {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f, 0.5f, 0.0f
    };

    //Creating a VBO
    //=======================================
    unsigned int VBO;
    glGenBuffers(1, &VBO);

    //Binding Buffer to the VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //Creating a Vertex Shader (First Step)
    //=======================================
    unsigned int VertexShader;
    VertexShader = glCreateShader(GL_VERTEX_SHADER);

    //Binding the Vertex shader source to the newly created vertex shader object
    //================================================================================================
    glShaderSource(VertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(VertexShader);

    //Creating a Fragment Shader (Second Step)
    //====================================================================
    unsigned int FragmentShader;
    FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    //Binding the Fragment Shader source to the newly created Fragment Shader object
    //================================================================================================
    glShaderSource(FragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(FragmentShader);


    //Creating a Shader Program to take in both shader objects created beforehand
    //===================================================================================================
    unsigned int ShaderProgram;
    ShaderProgram = glCreateProgram();

    glAttachShader(ShaderProgram, VertexShader);
    glAttachShader(ShaderProgram, FragmentShader);
    
    glLinkProgram(ShaderProgram);

    //Next, we interpret the Vertex Data
    //================================================================================
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);


    //Create a VAO Object
    //==========================================================
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);
    
    return 0;

}