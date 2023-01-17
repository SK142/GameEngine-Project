#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <string>
#include "DebugFile.h"

using namespace std;

int counter = 0;

int OpenGL_Compilation_DebugError(string InfoLog)
{
	string FileName_Compilation = "OPENGL_SHADER_COMPILATION_ERROR.DAT";
	fstream ErrorFile(FileName_Compilation);
	ErrorFile.open(FileName_Compilation, ios::out);
	ErrorFile << InfoLog;

	std::cout << "A file containing the error had been created in the project directory, File Name: " << FileName_Compilation;
	ErrorFile.close();
	return 0;
}
int OpenGL_Linking_DebugError(string InfoLog)
{
	string FileName_Linking = "OPENGL_SHADER_LINKING_ERROR";
	fstream ErrorFile_LINKING(FileName_Linking);
	ErrorFile_LINKING.open(FileName_Linking, ios::out);
	ErrorFile_LINKING << InfoLog;
	std::cout << "A file containing the error had been created in the project directory, File Name: " << FileName_Linking;
	ErrorFile_LINKING.close();
	return 0;
}