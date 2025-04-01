#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <map>
using namespace std;
//这个程序需要实现：输入来自button的金额来源和金额数量，将其存储到文件里面,展示文件中的内容
//思路规划：用2个string记录金额来源和数量，存储到文件里面，用vector<string>提取并且做计算和展示
//所以程序应当拥有：存储函数，提取函数，计算函数，展示函数
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

//账号： UIDA51562
//密码： 899325285
//网址： debug996.com