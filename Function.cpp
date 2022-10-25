#include"RefreshRate.h"

App::App() {
	glfwInitHint(GLFW_VERSION_MAJOR, 4);
	glfwInitHint(GLFW_VERSION_MINOR, 3);

	if (glfwInit() == GLFW_FALSE) {
		std::cout << "Impossibile inizializzare opengl" << std::endl;
		exit(EXIT_FAILURE);
	}

	this->running = true;

	this->nid = {};

	HWND h = GetConsoleWindow();
	ShowWindow(h, SW_HIDE);

	nid.cbSize = sizeof(nid);
	nid.hWnd = h;
	nid.uFlags = NIF_ICON | NIF_TIP;
	nid.hIcon = (HICON)LoadImage(NULL, L"icon.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_SHARED);

	int val = this->getRefreshRate();

	std::wstring V = std::to_wstring(val);

	memcpy(this->nid.szTip, V.c_str(), 128);

	Shell_NotifyIcon(NIM_ADD, &nid);
	
}

App::~App() {
	Shell_NotifyIcon(NIM_DELETE, &this->nid);
	glfwTerminate();
}

void App::mainLoop() {

	int val = 0;
	std::wstring V = L"";

	while (this->running) {
		Sleep(5000);
		val = this->getRefreshRate();
		V = std::to_wstring(val);
		memcpy(this->nid.szTip, V.c_str(), 128);
		Shell_NotifyIcon(NIM_MODIFY, &this->nid);
	}

}

int App::getRefreshRate() {
	int count = 0;
	GLFWmonitor** monitor = glfwGetMonitors(&count);
	GLFWvidmode *videomode = const_cast<GLFWvidmode*>(glfwGetVideoMode(monitor[0]));
	return videomode->refreshRate;
}