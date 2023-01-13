#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include"RefreshRate.h"

int main(){//WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	App app;
	app.mainLoop();
	return 0;
}