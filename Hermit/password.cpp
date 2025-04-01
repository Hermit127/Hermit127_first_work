#pragma once
#include "password.h"
void Password::recordPassword()
{
	char m1[100];
	char r1[100];
	char q1[100];
	InputBox(m1, 100, "��������������ö���");
	temp.place=string(m1);
	InputBox(r1, 100, "�������˺�");
	temp.account=string(r1);
	InputBox(q1, 100, "����������");
	temp.apassword = string(q1);
	ofstream outfile("password.txt",ios::app);
//	locale utf8_locale = locale(locale(), new codecvt_utf8<wchar_t>);
//	outfile.imbue(utf8_locale);
	if (outfile.is_open() && !temp.place.empty() && !temp.account.empty() && !temp.apassword.empty())
	{
		encrypt(temp);
		string temppassword = temp.place +" " + temp.account+" " + temp.apassword;
		outfile << temppassword << endl;
//		cout << temppassword << endl;
//	decrypt(temppassword);
//		cout << temppassword << endl;
		outfile.close();
	}
	else
	{
		cerr << "�ļ��������" << endl;
	}
}
void Password::showPassword()
{
	if (judge == true)
	{
		char q1[100];
		InputBox(q1, 100, "�������һ�δ򿪣������ò鿴����");
		openp = string(q1);
		judge = false;
	}
	else if (judge == false)
	{
		char q1[100];
		InputBox(q1, 100, "����������");
		if (string(q1) == openp)
		{
			goto H;
		}
		else
		{
			return;
		}
	}
	H:
	string sumpassword = "��������������,�벻Ҫ�����˿���~\n";
	int temp = 1;
	for (auto&allpa:allpassword)
	{
		sumpassword = sumpassword + to_string(temp) + "��"+ allpa.place + "���˺ţ�" + allpa.account + " ���룺" + allpa.apassword + "\n";
		temp++;
	}
	MessageBox(NULL, sumpassword.c_str(), "����", NULL);
}
void Password::encrypt(password &p)
{
	encryptString(p.place);
	encryptString(p.account);
	encryptString(p.apassword);
}
void Password::encryptString(string& p)
{
	for (char& c : p)
	{
		c=c+30;
	}
}
void Password::decrypt(string& p)
{
	for (char& c : p)
	{
		if (c != ' ')
		{
			c = c - 30;
		}
	}
}
void Password::filePassword()
{
	allpassword.clear();
	ifstream infile("password.txt");
	locale utf8_locale = locale(locale(), new codecvt_utf8<wchar_t>);
	infile.imbue(utf8_locale);
	if (infile.is_open())
	{
		string line;
		while (getline(infile, line))
		{
			decrypt(line);
			stringstream ss(line);
			ss >> temp.place >> temp.account >> temp.apassword;
			allpassword.push_back(temp);
			if (line.empty())
			{
				continue;
			}
			//	cout << line << endl;
		}
		infile.close();
	}
	else
	{
		cerr << "��������" << endl;
	}
}
void Password::showDelete()
{
	string sumpassword = "����Ҫɾ���ĸ���~\n";
	int temp = 1;
	for (auto& allpa : allpassword)
	{
		sumpassword =   sumpassword + to_string(temp) + "��" + allpa.place + "���˺ţ�" + allpa.account + " ���룺" + allpa.apassword + "\n";
		temp++;
	}
	char m1[100];
	//		char r1[100];
	InputBox(m1, 100, sumpassword.c_str());
	string strm(m1);
	if (strm.empty())
	{
		return;
	}
	int sizea = allpassword.size();
	if (strm[0] <= '9' && strm[0] > '0' && stoi(strm) <= allpassword.size())
	{
		cout << stoi(strm) << endl;
	}
	else
	{
		MessageBox(NULL, "���������", "�����ʽ����", NULL);
		return;
	}
	int deletenum = stoi(strm) - 1;
	deletePassword(deletenum);
}
void Password::deletePassword(int num)
{
		ofstream tempFile("temp.txt");
		allpassword.erase(allpassword.begin() + num);
		for (auto& temp1 : allpassword)
		{
			encrypt(temp1);
			string temppassword = temp1.place + " " + temp1.account + " " + temp1.apassword;
			tempFile<< temppassword << endl;
		}
		tempFile.close();
		remove("password.txt");
		cout << rename("temp.txt", "password.txt") << endl;
		return;
}