#pragma once
#include "button.h"
static bool judgenumber(string str)
{
	for (char c : str)
	{
		if (c < '0' || c > '9') return false;
	}
	return true;
}

Button::Button(int x, int y, string le)
{
	bx = x;
	by = y;
	letter = le;
}

void Button::createButton(int x1,int y1,int x2,int y2)//创建按钮
{
	bx1 = x1;
	bx2 = x2;
	by1 = y1;
	by2 = y2;
	//loadimage(&buttonimage, "resource/button1.png", bx, by);
	setfillcolor(RGB(255,255,153));
	solidrectangle(x1,y1,x2,y2);
	setbkcolor(RGB(255, 255, 153));
}
	
bool Button::pushButton(int mx,int my,bool t)//检测是否被按下
{
//	ExMessage Mouse;
//	Mouse = getmessage(EX_MOUSE);
//	int mx = Mouse.x;
//	int my = Mouse.y;
	if (mx <= bx2 && mx >= bx1 && my <= by2 && my >= by1&&t==1)
	{
		//cout << 1 << endl;
		Sleep(300);
		return 1;
	}
	return 0;
}

void Button1::Buttonpushed(int mx, int my, bool t)//按下之后
{
	if (pushButton(mx, my, t) == 1)
	{
	//Sleep(100);
		char m[100];
//		char r1[100];
		InputBox(m, 100, "请选择模式：\n1、记录账单\n2、显示账单");
		string strm(m);
		if (strm == "1")
		{
			char m1[100];
			char r1[100];
			InputBox(m1, 100, "花了多少钱呢~");
			string strm1(m1);
			if (judgenumber(m1) == false)
			{
				MessageBox(NULL, "输入一个数字,好么", "来自小灯的提醒", NULL);
				return;
			}
			InputBox(r1, 100, "怎么花这么多钱的啊");
			//	cout << s;

			string strr1(r1);
			money1.recordMoney(m1, r1);
			money1.fileMoney();
		}
		else if (strm == "2")
		{
			money1.getMoney();
			money1.displayMoney();
		}
		else
		{
			MessageBox(NULL, "请输入1,2,3,4,5中的一个，不对的话我识别不了哦", "来自小灯的提醒", NULL);
			return;
		}
		return;
	//	cout << sizeof(str);
	}
}

void Button2::Buttonpushed(int mx, int my, bool t)
{
	if (pushButton(mx, my, t) == 1)
	{
		char m1[100];
		InputBox(m1, 100, "输入的密码会被加密喵~\n请选择模式：\n1、输入密码 \n2、查看密码\n3、删除密码");
		string strm(m1);
		if (strm == "1")
		{
			password.recordPassword();
			//cout << "1" << endl;
		}
		else if (strm == "2")
		{
			password.filePassword();
			password.showPassword();
			//cout << 2 << endl;
		}
		else if (strm == "3")
		{
			password.showDelete();
			//cout << 3 << endl;
		}
		else
		{
			MessageBox(NULL, "请输入1,2,3中的一个，不对的话我识别不了哦", "来自小灯的提醒", NULL);
			return;
		}
		return;
	}
}

void Button3::Buttonpushed(int mx, int my, bool t)//按下之后
{
	if (pushButton(mx, my, t) == 1)
	{
		char m1[100];
//		char r1[100];
		InputBox(m1, 100, "请选择模式：\n1、设定闹钟 \n2、关闭闹钟 \n3、删除闹钟\n4、启动课表提醒\n5、关闭课表提醒");
		string strm(m1);
		if (strm == "1")
		{
			reminder.setTime();
//			cout << "setalarm" << endl;
		}
		else if (strm == "2")
		{
			reminder.stopAlarm();
			//cout << "stopalarm" << endl;
		}
		else if (strm == "3")
		{
			reminder.showAlarm();
			//cout << "deletealarm" << endl;
		}
		else if (strm == "4")
		{
			reminder.getCourses();
			//cout << "getCourses" << endl;
		}
		else if (strm == "5")
		{
			//cout<< "closereminder";
		}
		else
		{
			MessageBox(NULL, "你选的模式好像不在范围里呢", "来自小灯的提醒", NULL);
			return;
		}
		return;
	}
}

void Button4::setCoord()
{
	char m[100];
	char m2[100];
	InputBox(m, 100, "请输入横坐标");
	InputBox(m2, 100, "请输入纵坐标");
	string X(m);
	string Y(m2);
	if (X.empty() || Y.empty())
	{
		return;
	}
	x = stoi(X);
	y = stoi(Y);
	HWND hwnd=GetHWnd();
	SetWindowPos(hwnd, HWND_TOPMOST, x,y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	return;
}
void Button4::Buttonpushed(int mx, int my, bool t)
{
	if (pushButton(mx, my, t) == 1)
	{
		setCoord();
	}
	return;
}
void Button5::Buttonpushed(int mx, int my, bool t)
{
	if (pushButton(mx, my, t) == 1)
	{
		otm.getinformation();
	}
	return;
}

void Button6::Buttonpushed(int mx, int my, bool t)
{
	if (pushButton(mx, my, t) == 1)
	{
		//cout << 1 << endl;
		application.startapplication();
	}
	return;
}

void Button7::Buttonpushed(int mx, int my, bool t)
{
	if (pushButton(mx, my, t) == 1)
	{
		website.startwebsite();
	}
	return;
}


void Button8::Buttonpushed(int mx, int my, bool t)
{
	if (pushButton(mx, my, t) == 1)
	{
		qkb.startkeyboard();
	}
	return;
}

void Button9::Buttonpushed(int mx, int my, bool t)
{
	if (pushButton(mx, my, t) == 1)
	{
		MessageBox(NULL, "再见啦，要一辈子陪我哦~","来自小灯的告别",NULL);
		exit(0);
	}
	return;
}