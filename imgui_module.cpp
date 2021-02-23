#include <iostream>
#define WINDOW_IMPLEMENTATION
#include "window.hxx"
#include "spdlog/spdlog.h"
bool rs232_imgui_interface(ui::window_t*)
{
	static int receive_flag;
	ImGui::Begin("RS-232 Communication");
	ImGui::Text("Please input Port");
	//ImGui::InputText("Port", port_buff, IM_ARRAYSIZE(port_buff));
	ImGui::Text("Please input Bdrate");
	//ImGui::InputText("Bdrate", bdrate_buff, IM_ARRAYSIZE(bdrate_buff));
	ImGui::Text("Please input command");
	//ImGui::InputText("Command", command_buff, IM_ARRAYSIZE(command_buff));
	if (ImGui::Button("Open Port")) {

	}
	ImGui::SameLine();
	if (ImGui::Button("Close Port")) {

	}
	ImGui::SameLine();
	if (ImGui::Button("Send Command")) {

	}
	if (ImGui::Button("Receive Command")) {
		receive_flag = 1;
	}
	ImGui::SameLine();
	if (receive_flag == 1) {
		ImGui::Text("Receive status is Yes");
	}
	else {
		ImGui::Text("Receive status is No");
	}
	ImGui::End();
	return true;
}
int main()
{
	//ui::window_t* p = (ui::window_t*)malloc(sizeof(ui::window_t));
	ui::window_t* p = new ui::window_t;
	std::array<float, 4> background_color = { 0.45f, 0.55f, 0.60f, 0.95f };
	int x = 0;
	int y = 0;
	int w = 1280;
	int h = 720;
	char title[50] = "Port Communication";
	bool ret = ui::init(p, x, y, w, h, background_color, title, rs232_imgui_interface);
	if (ret == false) {
		spdlog::error("init failed");
		return -1;
	}
	spdlog::debug("init successfully");
	//bool show_demo_window = true;
	//Main loop
	while (!is_close(p)) {
		new_frame(p);
		/*	if (show_demo_window) {
				ImGui::ShowDemoWindow(&show_demo_window);
			}*/
			//draw(p);
		render(p);
	}
	clean_up(p);
	delete(p);
	return 0;
}
