#pragma once
#include <graphics.h>
#include <iostream>
#include <string>
#include <tchar.h>
#include "transparent.h"
#include "other.h"
#include "money.h"
#include "reminder.h"
#include "password.h"
using namespace std;
//��һ��˼·
//�����Ҫ5-6����ť
//ÿ����ť�ֱ�������¼����ʾ����¼һ����ť��ʾһ����ť
//����Ŀǰ��д��Ӧ���Ƕ�buttonpushed�ĺ���дλ���ж�����ifд��ͬλ���µĲ�ͬʵ��
class Button
{
private:
	string letter;
	IMAGE buttonimage;
	int bx,by;
	int bx1=0, bx2=0, by1=0, by2=0;
public:
	Button(int x, int y, string le);
	void createButton(int x1, int y1, int x2, int y2);
	bool pushButton(int mx,int my,bool t);
	//void deleteButton();
	virtual void Buttonpushed() {};
};

class Button1 :public Button
{
private:
	Money money1;
public:
	using Button::Button;
	void Buttonpushed(int mx, int my, bool t);
};

class Button2 : public Button
{
private:
	Password password;
public:
	using Button::Button;
	void Buttonpushed(int mx, int my, bool t);
};

class Button3 : public Button
{
private:
	Reminder reminder;
public:
	using Button::Button;
	void Buttonpushed(int mx, int my, bool t);
	void triggeralarm()
	{
		reminder.Alarmtrigger();
		reminder.getTime();
		reminder.coursetrigger();
	}
};

class Button4 : public Button
{
private:
	int x = 0;
	int y = 0;
public:
	using Button::Button;
	void setCoord();
	void Buttonpushed(int mx, int my, bool t);
};

class Button5 :public Button
{
private:
	OtherManager otm;
public:
	using Button::Button;
	void Buttonpushed(int mx, int my, bool t);
};

class Button6 :public Button
{
public:
	int p;
	Application application;
	using Button::Button;
	void Buttonpushed(int mx, int my, bool t);
};
class Button7 :public Button
{
private:
	int p;
public:
	Website website;
	using Button::Button;
	void Buttonpushed(int mx, int my, bool t);
};
class Button8 :public Button
{
public:
	int p;
public:
	Quickkeyboard qkb;
	using Button::Button;
	void Buttonpushed(int mx, int my, bool t);
};
class Button9 :public Button
{
public:
	using Button::Button;
	void Buttonpushed(int mx, int my, bool t);
};