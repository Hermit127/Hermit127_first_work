#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <map>
using namespace std;
//���������Ҫʵ�֣���������button�Ľ����Դ�ͽ������������洢���ļ�����,չʾ�ļ��е�����
//˼·�滮����2��string��¼�����Դ���������洢���ļ����棬��vector<string>��ȡ�����������չʾ
//���Գ���Ӧ��ӵ�У��洢��������ȡ���������㺯����չʾ����
class Money
{
private:
	string amount;
	string source;
	string zamount;
	string zsource;
	vector<string>allmoney;
	vector<string>allsource;
	map<string, int>MoneyMap;
	string s;
public:
	Money();
	void recordMoney(string amo, string sou);
	void fileMoney();
	void getMoney();
	void calculateMoney();
	void displayMoney();
	void cutString(string h);
	//void clearMoney();
};

//�˺ţ� UIDA51562
//���룺 899325285
//��ַ�� debug996.com