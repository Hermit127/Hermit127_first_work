#pragma once
#include "money.h"
#include <Windows.h>
void Money::cutString(string h)
{
	size_t pos = h.find(' ');
	size_t rpos = h.rfind(' ');
	if (pos != string::npos)
	{
		zamount = h.substr(0, pos);
		zsource = h.substr(rpos + 1);
	}
	else
	{
		cerr << "没有找到空格" << endl;
	}
}
Money::Money(){};

void Money::recordMoney(string amo, string sou)
{
	int templength = amo.length();
	for (int i = 0; i <10-templength; i++)
	{
		amo+= "  ";
	}
	amount = amo;
	source = sou;
//	allmoney.push_back(amount);
//	allsource.push_back(source);
}

void Money::fileMoney() 
{
	ofstream outfile("money.txt",ios::app);
	if (outfile.is_open()&&amount!=""&&source!="")
	{
		outfile << amount << " " << source << endl;
		outfile.close();
	}
	else
	{
		cerr << "文件输入错误" << endl;
	}
}
void Money::getMoney()
{
	allmoney.clear();
	MoneyMap.clear();
	ifstream infile("money.txt");
		if (infile.is_open())
		{
			string line;
			while (getline(infile, line))
			{
				cutString(line);
				cout << zamount << "-" << zsource << endl;
				int zzamount = stoi(zamount);
				auto it = MoneyMap.find(zsource);
				if (it != MoneyMap.end())
				{
					MoneyMap[zsource]+= zzamount;
				}
				else
				{
					MoneyMap[zsource] = zzamount;
				}
				allmoney.push_back(line);
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
			cerr << "启动错误" << endl;
		}
		return ;
}
//拓展部分，对一周的花费进行各种计算，目前还没有做
void Money::calculateMoney()
{

}
void Money::displayMoney()
{
	//用消息框的方式进行展示
	for (auto& element : MoneyMap)
	{
		cout << element.first << " " << element.second << endl;
	}
	string temp = "消费金额     消费原因\n";
	for (auto& str : allmoney)
	{
		temp = temp + str + "\n";
	}
	string alltemp = "总消费\n";
	temp += alltemp;
	int moneya = 0;
	for (auto& element :MoneyMap)
	{
		temp = temp + element.first + "      " + to_string(element.second)+"\n";
		moneya += element.second;
	}
	temp += "您近期的总消费为"+to_string(moneya);
	LPCSTR lpStr = temp.data();
	LPCSTR title = "您的消费";
	// 弹出消息框
	int result = MessageBox(NULL, lpStr, title, MB_OK);
}
