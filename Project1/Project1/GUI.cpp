#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include"imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

using namespace std;

void GUISliderInt(string Name, int Value, int min, int max, bool ToolTips, string ToolText) // Makes a gui slider (int) including the check for tooltips.
{
	ImGui::SliderInt(Name.c_str(), &Value, min, max);
	if (ToolTips && ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
	{
		ImGui::BeginTooltip();
		ImGui::Text(ToolText.c_str());
		ImGui::EndTooltip();
	}
}
void GUISliderFloat(string Name, float Value, float min, float max, bool ToolTips, string ToolText)
{
	ImGui::SliderFloat(Name.c_str(), &Value, min, max);
	if (ToolTips && ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
	{
		ImGui::BeginTooltip();
		ImGui::Text(ToolText.c_str());
		ImGui::EndTooltip();
	}
}
void GUISliderInt(string Name, int Value, int min, int max) // Makes a gui slider (int) NOT including the check for tooltips.
{
	ImGui::SliderInt(Name.c_str(), &Value, min, max);
}
void GUISliderFloat(string Name, float Value, float min, float max) // Makes a gui slider (flaot) NOT including the check for tooltips.
{
	ImGui::SliderFloat(Name.c_str(), &Value, min, max);
}