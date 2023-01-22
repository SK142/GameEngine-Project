#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include"imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

using namespace std;

void GUISliderInt(string Name, int Value, int min, int max, bool ToolTips, string ToolText); // Makes a gui slider (int) including the check for tooltips.
void GUISliderFloat(string Name, float Value, float min, float max, bool ToolTips, string ToolText);// Makes a gui slider (float) including the check for tooltips.

void GUISliderInt(string Name, int Value, int min, int max); // Makes a gui slider (int) NOT including the check for tooltips.
void GUISliderFloat(string Name, float Value, float min, float max); // Makes a gui slider (flaot) NOT including the check for tooltips.