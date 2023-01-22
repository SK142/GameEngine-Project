#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include"imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "GUI.h"

using namespace std;


int XValue = 10;
int YValue = 5;
int ZValue = 2;
bool Selected = false;
bool enabled = true;
int Size = 10;
string LineOfText = "";
string Lines[10];


/*void File()
{
	ifstream file;
	file.open("ToolTips.DLL");
	while (!EOF, file)
	{
		for (int x = 0; x < 10; x++)
		{
		     getline(file, LineOfText);
			 Lines[x] = LineOfText;
			 cout << Lines[x];
		}
	}
} */
int CreateComponentWindow(bool ToolTips)
{

	ImGui::Begin("Component Window");
	if (ToolTips && ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
	{
		ImGui::BeginTooltip();
		ImGui::Text("Component Window");
		ImGui::EndTooltip();
	}


	ImGui::Text("Transform");
	ImGui::Separator();
	ImGui::SliderInt("X Axis", &XValue, 1, 100);
	if (ToolTips && ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
	{
		ImGui::BeginTooltip();
		ImGui::Text("X Axis values for GameObjects");
		ImGui::EndTooltip();
	}

	GUISliderInt(" NEW TEST", ZValue, 1, 100, ToolTips, "it works");
	GUISliderFloat("another test", ZValue, 1.0f, 100.0f, ToolTips, "ot workfg");


	ImGui::SliderInt("Y Axis", &YValue, 1, 100);
	if (ToolTips && ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
	{
		ImGui::BeginTooltip();
		ImGui::Text("Y Axis values for GameObjects");
		ImGui::EndTooltip();
	}

	ImGui::SliderInt("Z Axis", &ZValue, 1, 100);
	if (ToolTips && ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
	{
		ImGui::BeginTooltip();
		ImGui::Text("Z Axis values for GameObjects");
		ImGui::EndTooltip();
	}
	ImGui::Separator();



	ImGui::BeginMenuBar();
	ImGui::MenuItem("GameObject", "1", Selected, enabled);
	//ImGui::EndMenuBar();


	ImGui::End();
	return 0;
}

