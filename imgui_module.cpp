#include <iostream>
#define WINDOW_IMPLEMENTATION
#include "window.hxx"
#include "spdlog/spdlog.h"
bool rs232_imgui_interface(ui::window_t*)
{
	static int open_flag;
	static int close_flag;
	static int receive_flag;
	ImGui::Begin("RS-232 Communication");
	ImGui::Text("Please input Port");
	//ImGui::InputText("Port", port_buff, IM_ARRAYSIZE(port_buff));
	ImGui::Text("Please input Bdrate");
	//ImGui::InputText("Bdrate", bdrate_buff, IM_ARRAYSIZE(bdrate_buff));
	if (ImGui::Button("Open Port")) {
		open_flag = 1;
	}
	ImGui::SameLine();
	if (open_flag == 1) {
		ImGui::Text("Open status is Yes");
	}
	else if (open_flag == 0) {
		ImGui::Text("Open status is No");
	}
	if (ImGui::Button("Close Port")) {
		close_flag = 1;
	}
	ImGui::SameLine();
	if (close_flag == 1) {
		ImGui::Text("Close status is Yes");
	}
	else if (close_flag == 0) {
		ImGui::Text("Close status is No");
	}
	if (ImGui::Button("Receive Command")) {
		receive_flag = 1;
	}
	ImGui::SameLine();
	if (receive_flag == 1) {
		ImGui::Text("Receive status is Yes");
	}
	else if (receive_flag == 0) {
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
		draw(p);
		render(p);
	}
	clean_up(p);
	delete(p);
	return 0;
}
