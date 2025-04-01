#pragma once
#include "window.h"
//#include "transparent.h"
#include <iostream>
#include "click.h"
#pragma comment(lib, "Msimg32.lib")
using namespace std;
//��cpp�ǳ���ĺ��Ĵ�����
void Window::setTransparentBackground(HWND hwnd, COLORREF transparentColor) //����͸��
{
	LONG style = GetWindowLong(hwnd, GWL_EXSTYLE);
	style &= WS_EX_TOPMOST;
	SetWindowLong(hwnd, GWL_EXSTYLE, style | WS_EX_LAYERED);
	SetLayeredWindowAttributes(hwnd, transparentColor, 0, LWA_COLORKEY);
}
void Window::removeBorder(HWND hwnd)//�ޱ߿�
{
	LONG style = GetWindowLong(hwnd, GWL_STYLE);
	style &= ~WS_CAPTION; 
	style &= ~WS_THICKFRAME;
	style &= ~WS_BORDER;
	SetWindowLong(hwnd, GWL_STYLE, style);
	HDC screenDC = GetDC(NULL);
	int screenWidth = GetDeviceCaps(screenDC, HORZRES);
	int screenHeight = GetDeviceCaps(screenDC, VERTRES);
	ReleaseDC(NULL, screenDC);

//	std::cout << "��Ļ���: " << screenWidth << " ����" << std::endl;
//	std::cout << "��Ļ�߶�: " << screenHeight << " ����" << std::endl;

	SetWindowPos(hwnd,HWND_TOPMOST,screenWidth-600,screenHeight-600,600,600, SWP_NOZORDER | SWP_FRAMECHANGED);
}
//
void Window::createWindow()//��������
{
//	int Systemw = GetSystemMetrics(SM_CXSCREEN);
//	int Systemh = GetSystemMetrics(SM_CYSCREEN);
//	cout << Systemw << " " << Systemh << endl;
	initgraph(1500, 1500);   
	HWND hwnd = GetHWnd();
	setTransparentBackground(hwnd, RGB(255, 255, 255));
	removeBorder(hwnd);
	setbkcolor(WHITE);
	cleardevice();
	loadimage(&image, "resource/tomorin.png", 130, int(130 * tomo));
	loadimage(&imagedrag, "resource/drag.jpg", 30, 30);
}
void Window::createImage()//��������
{
//	setlinecolor(RED);
//	rectangle(100, 100, 300, 300);
//	std::cout << tomo << std::endl;
//	putimage(0, 0, &image);
//	setbkmode(TRANSPARENT);
//	putimage(0, 0, &imagedrag);
//	button1.createButton();
	COLORREF transparentColor = RGB(0, 0, 0);
	TransparentImage(NULL, 0, 0, &image, transparentColor);
//	COLORREF transparentColor = RGB(0, 10,10);
}
//���������������϶�����
//����϶��кܴ����⣬Ŀǰ���������ǵ�һ�¾ͻ�˲��
//Ŀ���ܹ��ж��ǵ�һ�»����϶����ܽ��
//ʵ��û�н������Ȼ��֪����������
/*
bool judge_click()
{
	ExMessage t1,t2;
	if (peekmessage(&t1, EX_MOUSE, true) == 1)
	{
		Sleep(5);
		cout << t1.x << endl;
		if (peekmessage(&t2, EX_MOUSE, true) == 1)
		{
			return 1;
		}
	}
	return 0;
}
*/
void Window::threadrun()
{
	//COLORREF transparentColor = RGB(0, 0, 0);
	ExMessage Mouse;
	POINT windowStartPos = { 0, 0 };
	HWND hwnd = GetHWnd();
	struct coord { int x = 0; int y = 0; };
	POINT cursorPos = { 0,0 };
	POINT cursorPos2 = { 0,0 };
    //solidrectangle(0, 0, 10, 10);
	thread Thread1([&]() {
		while (true) 
		{
			button1.Buttonpushed(Mouse.x, Mouse.y, Mouse.message == WM_LBUTTONDOWN);
			button2.Buttonpushed(Mouse.x, Mouse.y, Mouse.message == WM_LBUTTONDOWN);
			button3.Buttonpushed(Mouse.x, Mouse.y, Mouse.message == WM_LBUTTONDOWN);
			button4.Buttonpushed(Mouse.x, Mouse.y, Mouse.message == WM_LBUTTONDOWN);
			button5.Buttonpushed(Mouse.x, Mouse.y, Mouse.message == WM_LBUTTONDOWN);
			button6.Buttonpushed(Mouse.x, Mouse.y, Mouse.message == WM_LBUTTONDOWN);
			button62.Buttonpushed(Mouse.x, Mouse.y, Mouse.message == WM_LBUTTONDOWN);
			button7.Buttonpushed(Mouse.x, Mouse.y, Mouse.message == WM_LBUTTONDOWN);
			button72.Buttonpushed(Mouse.x, Mouse.y, Mouse.message == WM_LBUTTONDOWN);
			button8.Buttonpushed(Mouse.x, Mouse.y, Mouse.message == WM_LBUTTONDOWN);
			button82.Buttonpushed(Mouse.x, Mouse.y, Mouse.message == WM_LBUTTONDOWN);
			button9.Buttonpushed(Mouse.x, Mouse.y, Mouse.message == WM_LBUTTONDOWN);
			Sleep(10);
		}
		});
	Thread1.detach();
	thread Thread2([&]() {
		while (true)
		{
			button3.triggeralarm();
			Sleep(300);
		}
		});
	Thread2.detach();
/*	thread Thread3([&]() {//�����һЩ�Ի�,���ﻹ�ڹ�˼��ôд�ĸ���ʵ���Ҳ�Ӱ����������
		while (true)
		{
			Sleep(20000);
			MessageBox(NULL, "�ܺ�����һ�����ֶ���", "", NULL);
			Sleep(10000);
		}
		});
	Thread3.detach();*/
	while (1)
	{
		//cout << Mouse.x << endl;
		if (peekmessage(&Mouse, EX_MOUSE) == true)
		{
		////	Mouse = getmessage(EX_MOUSE);
		//	if (Mouse.x > 30 && Mouse.x < 140&&Mouse.y>0&&Mouse.y<200 && Mouse.message == WM_LBUTTONDOWN);
		//	{
		//		MessageBox(NULL, "�ܺ�����һ�����ֶ���", "", NULL);
		//	}
			/*		//		cout << Mouse.x << " " << Mouse.y << endl;
					//Sleep(1000);
					//	cleardevice();
					//	TransparentImage(NULL, x1, y1, &image, transparentColor);
				//	cout << Mouse.x << " " << endl;
					dx = 0; dy = 0;
					if (Mouse.x < 30 && Mouse.lbutton == 1)
					{
						//	cursorPos2 = cursorPos;
						GetCursorPos(&cursorPos);
						dx = cursorPos.x - cursorPos2.x;
						dy = cursorPos.y - cursorPos2.y;
						//	dx=Mouse.x-
						cursorPos2 = cursorPos;
						RECT rect;
						GetWindowRect(hwnd, &rect);
						windowStartPos.x = rect.left;
						windowStartPos.y = rect.top;
						//	cout << cursorPos.x << " " <<cursorPos2.x << endl;
							//		cout << x1 << endl;
						//	if (dx > 30)dx = 0;
						//	if (dy > 30)dy = 0;
						SetWindowPos(hwnd, HWND_TOPMOST, windowStartPos.x + dx, windowStartPos.y + dy, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
						//Sleep(100);
					}
					//	cout << Mouse.x << Mouse.y << endl;
				}*/
		}
		Sleep(5);
	}
}

void Window::putButton()
{
//	cout << 1 << endl;
	button1.createButton(150,150 - 50,200,200 - 50);
	settextcolor(RED);
	settextstyle(15, 0, "����");
	outtextxy(160 , 160 - 50, "����");
	outtextxy(160, 180 - 50, "�˵�");
	button2.createButton(150,230 - 50,200,280 - 50);
	outtextxy(160, 240 - 50, "����");
	outtextxy(160, 260 - 50, "����");
	button3.createButton(150, 70 - 50,200,120 - 50);
	outtextxy(160, 80 - 50, "����");
	outtextxy(160, 100 - 50, "����");
	button4.createButton(150, 310 - 50, 200, 360 -50);
	outtextxy(160, 320 - 50, "����");
	outtextxy(160, 340 - 50, "����");
	button5.createButton(230, 20, 280, 70);
	outtextxy(240, 30, "���");
	outtextxy(240, 50, "����");
	button6.createButton(230, 100, 280, 150);
	button6.application.i = 1;
	outtextxy(240, 110, "��");
	outtextxy(237, 130, "���1");
	button62.createButton(230, 180, 280, 230);
	button62.application.i = 2;
	outtextxy(240, 190, "��");
	outtextxy(237, 210, "���2");
	button7.createButton(230, 260, 280, 310);
	button7.website.i = 3;
	outtextxy(240, 270, "��");
	outtextxy(237, 290, "��ҳ1");
	button72.createButton(310, 20, 360, 70);
	button72.website.i = 4;
	outtextxy(320, 30, "��");
	outtextxy(317, 50, "��ҳ2");
	button8.createButton(310, 100, 360, 150);
	button8.qkb.i = 5;
	outtextxy(320, 110, "���");
	outtextxy(317, 130, "��λ1");
	button82.createButton(310, 180, 360, 230);
	button82.qkb.i = 6;
	outtextxy(320, 190, "���");
	outtextxy(317, 210, "��λ2");
	button9.createButton(310, 260, 360, 310);
	outtextxy(320, 270, "�˳�");
	outtextxy(320, 290, "����");
}

bool Window::setWindowTop()
{
	HWND hWnd = GetHWnd();
	SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 100, 100, SWP_NOMOVE | SWP_NOSIZE);
	return true;
}
