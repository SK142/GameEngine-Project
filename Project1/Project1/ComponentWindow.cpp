#include <iostream>
#include <string>
#include"imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

using namespace std;


int XValue = 10;
int YValue = 5;
int ZValue = 2;
bool Selected = false;
bool enabled = true;





int CreateComponentWindow()
{
	


	ImGui::Begin("Component Window");
	ImGui::Text("Transform");
	ImGui::Separator();
	ImGui::SliderInt("X Axis", &XValue, 1, 100);
	ImGui::SliderInt("Y Axis", &YValue, 1, 100);
	ImGui::SliderInt("Z Axis", &ZValue, 1, 100);
	ImGui::Separator();



	ImGui::BeginMenuBar();
	ImGui::MenuItem("GameObject", "1", Selected, enabled);
	//ImGui::EndMenuBar();


	ImGui::End();
	return 0;
}