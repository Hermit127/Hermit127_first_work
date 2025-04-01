#pragma once
#include "other.h"
using namespace std;
OtherManager::OtherManager()
{ 
	message = "1";
	number = 1;
	ifstream infile("information.txt");
	
	if (infile.is_open())
	{
		string line;
		while (getline(infile, line))
		{
			information.push_back(line);
		}
		if (line.empty())
		{
			return;
		}
		infile.close();
	}
	else
	{
		cerr << "����" << endl;
	}
}

void OtherManager::getinformation()
{
		char m1[100];
		char r1[100];
		string getinf="";
		for (auto& str : information)
		{
			getinf = getinf + str + "\n";
		}
		string inf = "��ѡ����Ҫ�޸ĵ����\n������ϵͳ��\n1��2ΪӦ�ó���\n3��4Ϊ��ҳ\n5��6Ϊ��ݼ�\n����Ӧ�ó�����д·������ҳ��д��ַ����\n��ݼ����ڰ����֣���Ϸ�������ʵ��һ���и�ȹ���\n��������Ŀǰ����Ŀ�ݷ�ʽ:\n";
		getinf = inf + getinf;
		InputBox(m1, 5, getinf.c_str());
		string s(m1);
		if (s[0] > '0' && s[0] <= '6' && s.length() == 1 && !s.empty())
		{
			number = stoi(s);
			InputBox(r1, 100, "��������Ҫ�޸ĵ�����,���ݲ���Ϊ��");
			message = string(r1);
			if (!message.empty())
			{
				information[number - 1] = to_string(number) + "." + message;
			}
			for (auto& mes : information)
			{
				cout << mes << endl;
			}
		}
		else
		{
			MessageBox(NULL, "��������ȷ����ţ������ʽ�д�Ŷ","����С�Ƶ�����",NULL);
		}
		ofstream tempFile("temp1.txt");
		for (auto& p : information)
		{
			tempFile << p << endl;
		}
		tempFile.close();
		remove("information.txt");
		int x=rename("temp1.txt", "information.txt") ;
		return;
}
void Application::startapplication()
{
	ifstream infile("information.txt");
	if (infile.is_open())
	{
        string line;
		while (getline(infile, line))
		{
			string h = line.substr(0, 1);
			int q = stoi(h);
			string app = line.substr(2);
			if (q == i)
			{
				string h = "start " + app;
				cout << app << endl;
				system(h.c_str());
			}

		}
		if (line.empty())
		{
			return;
		}
		infile.close();
	}
	else
	{
		cerr << "����" << endl;
	}
}
void Website::startwebsite()
{
	ifstream infile("information.txt");
	if (infile.is_open())
	{
		string line;
		while (getline(infile, line))
		{
			string h = line.substr(0, 1);
			int q = stoi(h);
			string app = line.substr(2);
			if (q == i)
			{
				string h = "start " + app;
				cout << app << endl;
				system(h.c_str());
			}

		}
		if (line.empty())
		{
			return;
		}
		infile.close();
	}
	else
	{
		cerr << "����" << endl;
	}
}

void Quickkeyboard::startkeyboard()
{
	ifstream infile("information.txt");
	if (infile.is_open())
	{
		string line;
		while (getline(infile, line))
		{
			string h = line.substr(0, 1);
			int q = stoi(h);
			string app = line.substr(2);
			if (q == i)
			{
			//	infile.close();
				initkeymap();
				getkey(app);
				imitatekey();
			}
		}
		if (line.empty())
		{
			return;
		}
		infile.close();
	}
	else
	{
		cerr << "����" << endl;
	}
}

void Quickkeyboard::initkeymap()
{
	keyMap["ctrl"] = VK_CONTROL;
	keyMap["alt"] = VK_MENU;
	keyMap["shift"] = VK_LSHIFT;
	keyMap["capslock"] = VK_CAPITAL;
	keyMap["tab"] = VK_TAB;
	keyMap["enter"] = VK_RETURN;
	keyMap["space"] = VK_SPACE;
	for (int i = 'A'; i <= 'Z'; i++)
	{
		string keyName(1, (char)i);
		keyMap[keyName] = i;
	}
	for (int i = '0'; i <= '9'; i++)
	{
		string keyName(1, (char)i);
		keyMap[keyName] = i;
	}
	for (int i = 'a'; i <= 'z'; i++) 
	{
		string keyName(1, (char)i);
		keyMap[keyName] = i;
	}
	for (int i = 1; i <= 11; i++)
	{
		string keyName = "F" + to_string(i);
		string keyName2 = "F" + to_string(i);
		keyMap[keyName] = VK_F1 + (i - 1);
		keyMap[keyName2] = VK_F1 + (i - 1);
	}
}

void Quickkeyboard::imitatekey()
{
	if (hermit.size() == 1)
	{
		INPUT input[2];
		input[0].type = INPUT_KEYBOARD;
		input[0].ki.wVk = keyMap[hermit[0]];
		input[0].ki.dwFlags = 0;
		input[1].type = INPUT_KEYBOARD;
		input[1].ki.wVk = keyMap[hermit[0]];
		input[1].ki.dwFlags = KEYEVENTF_KEYUP;
		UINT result = SendInput(2, input, sizeof(INPUT));
		cout << hermit[0] << endl;
		if (result == 0) 
		{
			cerr << "SendInput failed." << endl;
		}
	}
	if (hermit.size() >= 2)
	{
		INPUT input[400];
		int cnt = 0;
		for (auto& s : hermit)
		{
			input[cnt].type = INPUT_KEYBOARD;
			input[cnt].ki.wVk = keyMap[s];
			input[cnt].ki.dwFlags = 0;
			cnt += 1;
		}
		UINT result = SendInput(cnt, input, sizeof(INPUT));
		Sleep(30);
		for (auto& s : hermit)
		{
			input[cnt].type = INPUT_KEYBOARD;
			input[cnt].ki.wVk = keyMap[s];
			input[cnt].ki.dwFlags = KEYEVENTF_KEYUP;
			cnt += 1;
		}
		result = SendInput(cnt, input, sizeof(INPUT));
		if (result == 0)
		{
			cerr << "SendInput failed." << endl;
		}
	}
	else
	{
		cerr << "����" << endl;
	}
	return;
}

void Quickkeyboard::getkey(string key)
{
	stringstream ss(key);
	string token="";
	int count = 0;
	int maxCount = 1000; // �������ѭ������Ϊ1000
	while (getline(ss, token, '+'))
	{
		cout << token << endl;
		hermit.push_back(token);
		count++;
	}
	return;
}