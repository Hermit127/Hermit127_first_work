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
		cerr << "û���ҵ��ո�" << endl;
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
		cerr << "�ļ��������" << endl;
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
			cerr << "��������" << endl;
		}
		return ;
}
//��չ���֣���һ�ܵĻ��ѽ��и��ּ��㣬Ŀǰ��û����
void Money::calculateMoney()
{

}
void Money::displayMoney()
{
	//����Ϣ��ķ�ʽ����չʾ
	for (auto& element : MoneyMap)
	{
		cout << element.first << " " << element.second << endl;
	}
	string temp = "���ѽ��     ����ԭ��\n";
	for (auto& str : allmoney)
	{
		temp = temp + str + "\n";
	}
	string alltemp = "������\n";
	temp += alltemp;
	int moneya = 0;
	for (auto& element :MoneyMap)
	{
		temp = temp + element.first + "      " + to_string(element.second)+"\n";
		moneya += element.second;
	}
	temp += "�����ڵ�������Ϊ"+to_string(moneya);
	LPCSTR lpStr = temp.data();
	LPCSTR title = "��������";
	// ������Ϣ��
	int result = MessageBox(NULL, lpStr, title, MB_OK);
}
