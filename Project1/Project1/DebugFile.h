#pragma once
#include <string>
using namespace std;
int OpenGL_Compilation_DebugError(string InfoLog);
int OpenGL_Linking_DebugError(string InfoLog);
void WriteToFile(string FileName, string path, string Log);