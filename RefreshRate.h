#pragma once

#include<Windows.h>
#include<conio.h>
#include<iostream>
#include<string>

#include"GL/gl.h"
#include"GLFW/glfw3.h"



#pragma comment(lib,"opengl32")
#pragma comment(lib,"glfw3")

class App {
public:
	App();
	~App();
	void mainLoop();
	int getRefreshRate();
private:
	NOTIFYICONDATA nid;
	bool running;
};
