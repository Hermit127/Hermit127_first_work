#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <Windows.h>
#include <vector>
#include <easyx.h>
#include <locale>
#include <codecvt>
//��¼����
//���˼·��money��࣬�������˼��ܰ��,����ͨ�����ļ��Ľ��ܷ��ʲ��ܵõ����
using namespace std;
class Password
{
private:
	struct password
	{
		string apassword;
		string place;
		string account;
	};
	string openp;
	bool judge = true;
	vector<password>allpassword;
	password temp;
public:
	void recordPassword();
	void showPassword();
	void encrypt(password& p);
	void decrypt(string &p);
	void filePassword();
	void deletePassword(int num);
	void showDelete();
	void encryptString(string& p);
}; 