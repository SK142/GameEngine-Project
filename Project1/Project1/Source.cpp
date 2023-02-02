#include"imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <irrKlang.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <fstream>
#include "DebugFile.h"
#include "DebugWindows.h"
#include "DebugCommands.h"
#include "Rendering.h"

using namespace std;
using namespace irrklang;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
bool NewWindow = false;
float FontSize = 13.5;
bool ShowToolTips = false;
bool DebugCommands = false;



const char* vertexShaderSource = "#version 420 core\n"
"layout (location = 0) in vec3 aPos;\n"
"out vec4 vertexColor;\n"
"void main()\n"
"{\n"
    "gl_Position = vec4(aPos, 1.0);\n"
    "vertexColor = vec4(0.5, 0.0, 0.0, 1.0);\n"
//"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0"
;



const char* fragmentShaderSource = "#version 420 core\n"
"out vec4 FragColor;\n"
"uniform vec4 ourColor;\n"
"void main()\n"
"{\n"
"FragColor = ourColor;\n"
//"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0"
;


/*
 const char* fragmentShaderSource = "#version 420 core\n"
"out vec4 FragColor;\n"
"uniform vec4 vertexColor;\n"
"void main()\n"
"{\n"
"FragColor = vertexColor;\n"
//"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0"
;*/
 



ISoundEngine* SoundEngine = createIrrKlangDevice();


int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    bool DrawTriangle = true;
    bool WireFrame = false;

    

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 420");
 // ImGui Custom Font
    //========================================================
    io.Fonts->AddFontDefault();
    ImFont* mainFont = io.Fonts->AddFontFromFileTTF("C:/Users/sheha/Downloads/OpenGL Libraries/Font/Gepestev-nRJgO.ttf", FontSize);
    IM_ASSERT(mainFont != NULL);


    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }



    /*float vertices[] = {
    
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
    };

    unsigned int VBO;
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); 

    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader); 

    //Checking for any errors in Vertex Shader Compilation
    //=============================================================

    int success;
    char InfoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, InfoLog);
        std::cout << "Error While compiling shader, OPENLGL_ERROR: \n" << InfoLog;
       
        string Log(InfoLog);
        OpenGL_Compilation_DebugError(Log);
    } */


    //Fragment Shader
    //==================================================================
  /*  unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);


    //Checking for any errors in Fragment Shader Compilation
    //=============================================================
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, InfoLog);
        std::cout << "Failed to compile Fragment Shader, OPENGL_ERROR: \n" << InfoLog;
    } */


    // Shader Program
    //=============================================================

 /*  unsigned int shaderProgram;
    shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLgiog(shaderProgram, 512, NULL, InfoLog);
        std::cout << "Failed to link Both shaders with the shader program, LINKING_ERROR: \n" << InfoLog;
    }
    else
    {
        glUseProgram(shaderProgram);
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }

    //Interpreting Vertex Data
    //=============================================================================
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // 0. copy our vertices array in a buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    // 1. then set the vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // 2. use our shader program when we want to render an object
    glUseProgram(shaderProgram);
    // 3. now draw the object 
    glDrawArrays(GL_TRIANGLES, 0, 3); */


    //VAO
    //=======================
  /*  unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0); */


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
int success;
char InfoLog[512];
glGetShaderiv(VertexShader, GL_COMPILE_STATUS, &success);
if (!success)
{
    glGetShaderInfoLog(VertexShader, 512, NULL, InfoLog);
    std::cout << "Error While compiling shader, OPENLGL_ERROR: \n" << InfoLog;

    string Log(InfoLog);
    OpenGL_Compilation_DebugError(Log);
}

//Creating a Fragment Shader (Second Step)
//====================================================================
unsigned int FragmentShader;
FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

//Binding the Fragment Shader source to the newly created Fragment Shader object
//================================================================================================
glShaderSource(FragmentShader, 1, &fragmentShaderSource, NULL);
glCompileShader(FragmentShader);
glGetShaderiv(FragmentShader, GL_COMPILE_STATUS, &success);
if (!success)
{
    glGetShaderInfoLog(FragmentShader, 512, NULL, InfoLog);
    std::cout << "Failed to compile Fragment Shader, OPENGL_ERROR: \n" << InfoLog;
}

//Creating a Shader Program to take in both shader objects created beforehand

//===================================================================================================
unsigned int ShaderProgram;
ShaderProgram = glCreateProgram();

glAttachShader(ShaderProgram, VertexShader);
glAttachShader(ShaderProgram, FragmentShader);

glLinkProgram(ShaderProgram);
glGetProgramiv(ShaderProgram, GL_LINK_STATUS, &success);
if (!success)
{
    glGetProgramInfoLog(ShaderProgram, 512, NULL, InfoLog);
    std::cout << "Failed to link Both shaders with the shader program, LINKING_ERROR: \n" << InfoLog;
}
else
{
    glUseProgram(ShaderProgram);
    glDeleteShader(VertexShader);
    glDeleteShader(FragmentShader);
}

//Next, we interpret the Vertex Data
//================================================================================
glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
glEnableVertexAttribArray(0);


//Create a VAO Object
//==========================================================
unsigned int VAO;
glGenVertexArrays(1, &VAO);
glBindVertexArray(VAO);
glBindBuffer(GL_ARRAY_BUFFER, VBO);
glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
glEnableVertexAttribArray(0);






    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(ShaderProgram);

        // update the uniform color
        float timeValue = glfwGetTime();
        float greenValue = sin(timeValue) / 2.0f + 0.5f;
        int vertexColorLocation = glGetUniformLocation(ShaderProgram, "ourColor");
        glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);




        glBindVertexArray(VAO);
        if (DrawTriangle)
        {
            glDrawArrays(GL_TRIANGLES, 0, 3);
        } 

        // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        ImGui::PushFont(mainFont);
        ImGui::Begin("hi");
        ImGui::Text("hello there");
        ImGui::Checkbox("Draw Triangle", &DrawTriangle);
        ImGui::Checkbox("Wireframe Mode", &WireFrame);
        ImGui::Checkbox("Make Window", &NewWindow);
        ImGui::Checkbox("Tooltips", &ShowToolTips);
        ImGui::Checkbox("Debug Commands", &DebugCommands);
        ImGui::SliderFloat("Font Size", &FontSize ,1, 100);
        if (ImGui::Button("Play"))
        {
            SoundEngine->play2D("audio/OST.mp3", true);
        }
        if (ImGui::Button("Click Me"))
        {
            NewWindow = true;
        }
        ImGui::End();
        if (NewWindow)
        {
            CreateComponentWindow(ShowToolTips);
        }ImGui::PopFont();

        bool Show = true;
        ImGui::ShowDemoWindow(&Show);
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();

    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();


    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}