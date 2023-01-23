#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include"imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "DebugCommands.h"
#include "DebugFile.h"

using namespace std;

void Tooltips_Debug()
{
	if (ShowToolTips == false)
	{
		//string Log = "DEBUG_VARIABLE (ShowToolTips) has a state of ", ShowToolTips, endl;
		WriteToFile("DebugFile.DAT", "C:/Users/sheha/source/C++/SDL/GameEngine-Project/Project1/Project1/", "hi");
	}
	else
	{
		cout << "True";
	}
}

