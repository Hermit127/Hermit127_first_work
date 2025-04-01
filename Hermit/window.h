#pragma once
#include <Windows.h>
#include <graphics.h>
#include <iostream>
#include "button.h"
class Window
{
private:
	IMAGE image;
	IMAGE imagedrag;
	const double tomo = 943.0 / 348.0;
	Button1 button1;//记录账本
	Button2 button2;//显示钱
	Button3 button3;//提醒
	Button4 button4;//设置坐标
	Button5 button5;
	Button6 button6;
	Button6 button62;
	Button7 button7;
	Button7	button72;
	Button8 button8;
	Button8 button82;
	Button9 button9;
	int dx=0;
	int dy=0;
public:
	Window() :button1(30, 30, "s"), button2(30, 30, "s"), button3(30, 30, "s"), button4(30, 30, "s") ,button5(30,30,"s"),button6(30, 30, "s"), button62(30, 30, "s"), button7(30, 30, "s"), button72(30, 30, "s")
		,button8(30, 30, "s"), button82(30, 30, "s"), button9(30, 30, "s") {};
	void createWindow();
	void setTransparentBackground(HWND hwnd, COLORREF transparentColor);
	void removeBorder(HWND hwnd);
	void threadrun();
	void createImage();
	void putButton();
	bool setWindowTop();
	//id hideButton();
	//bool OnForceShow(HWND hWnd);
};