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

void Button::createButton(int x1,int y1,int x2,int y2)//������ť
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
	
bool Button::pushButton(int mx,int my,bool t)//����Ƿ񱻰���
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

void Button1::Buttonpushed(int mx, int my, bool t)//����֮��
{
	if (pushButton(mx, my, t) == 1)
	{
	//Sleep(100);
		char m[100];
//		char r1[100];
		InputBox(m, 100, "��ѡ��ģʽ��\n1����¼�˵�\n2����ʾ�˵�");
		string strm(m);
		if (strm == "1")
		{
			char m1[100];
			char r1[100];
			InputBox(m1, 100, "���˶���Ǯ��~");
			string strm1(m1);
			if (judgenumber(m1) == false)
			{
				MessageBox(NULL, "����һ������,��ô", "����С�Ƶ�����", NULL);
				return;
			}
			InputBox(r1, 100, "��ô����ô��Ǯ�İ�");
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
			MessageBox(NULL, "������1,2,3,4,5�е�һ�������ԵĻ���ʶ����Ŷ", "����С�Ƶ�����", NULL);
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
		InputBox(m1, 100, "���������ᱻ������~\n��ѡ��ģʽ��\n1���������� \n2���鿴����\n3��ɾ������");
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
			MessageBox(NULL, "������1,2,3�е�һ�������ԵĻ���ʶ����Ŷ", "����С�Ƶ�����", NULL);
			return;
		}
		return;
	}
}

void Button3::Buttonpushed(int mx, int my, bool t)//����֮��
{
	if (pushButton(mx, my, t) == 1)
	{
		char m1[100];
//		char r1[100];
		InputBox(m1, 100, "��ѡ��ģʽ��\n1���趨���� \n2���ر����� \n3��ɾ������\n4�������α�����\n5���رտα�����");
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
			MessageBox(NULL, "��ѡ��ģʽ�����ڷ�Χ����", "����С�Ƶ�����", NULL);
			return;
		}
		return;
	}
}

void Button4::setCoord()
{
	char m[100];
	char m2[100];
	InputBox(m, 100, "�����������");
	InputBox(m2, 100, "������������");
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
		MessageBox(NULL, "�ټ�����Ҫһ��������Ŷ~","����С�Ƶĸ��",NULL);
		exit(0);
	}
	return;
}