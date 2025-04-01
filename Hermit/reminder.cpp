#pragma once
#include "reminder.h"
using namespace std;
Reminder::Reminder()
{
	allAlarm.clear();
	ifstream infile("reminder.txt");
	ofstream tempFile("temp.txt");
	if (infile.is_open())
	{
		string line;
		while (getline(infile, line))
		{
			cout << line << endl;
			transform(line);
			GetLocalTime(&st);
			if ((st.wMonth < alarmt.amonth)||(st.wMonth==alarmt.amonth&&st.wDay<=alarmt.aday))
			{
				tempFile << line << endl;
			}
			recorder.push_back(line);
			allAlarm.push_back(alarmt);
			if (line.empty())
			{
				continue;
			}

			//	cout << line << endl;
		}
		infile.close();
		tempFile.close();
		remove("reminder.txt");
		cout<<rename("temp.txt", "reminder.txt")<<endl;
	}
	else
	{
		cerr << "��������" << endl;
	}
	return;
}
void Reminder::getTime()
{
	GetLocalTime(&st);
	return;
}
void Reminder::transform(string strm1)
{
	string strm;
	string reason;
	if (strm1.length() == 14)
	{
		 strm = strm1;
	}
	else if(strm1.length()>14)
	{
		 strm = strm1.substr(0, 14);
		 reason = strm1.substr(14);
	}
	//cout << reason << endl;
	if (strm.empty())
	{
		return;
	}
	if (strm.length() != 14)
	{
		MessageBox(NULL, "��������ȷ��������,�����ʽ�д�Ŷ", "����С�Ƶ�����", NULL);
		return;
	}
	const vector<int> p = { 0,1,3,4,6,7,9,10,12,13 };
	const vector<int> q = { 2,5,8,11 };
	for (int i = 0; i < p.size(); i++)
	{
		if (strm[p[i]] > '9' || strm[p[i]] < '0')
		{
			MessageBox(NULL, "��������ȷ��������,�����ʽ�д�Ŷ", "����С�Ƶ�����", NULL);
			return;
		}
	}
	for (int i = 0; i < q.size(); i++)
	{
		if (strm[q[i]] != '-')
		{
			MessageBox(NULL, "��������ȷ��������,�����ʽ�д�Ŷ", "����С�Ƶ�����", NULL);
			return;
		}
	}
	stringstream ssa(strm);
	char delimiter;
	ssa >> alarmt.amonth >> delimiter >> alarmt.aday >> delimiter >> alarmt.ahour >> delimiter >> alarmt.aminute >> delimiter >> alarmt.asecond;
	alarmt.reason1 = reason;
	allAlarm.push_back(alarmt);
	return;
}
void Reminder::setTime()
{
	char m[100];
	char m2[100];
	InputBox(m, 100, "�����������趨��ʱ����\n�������ʽ:xx���£�-xx����)-xx(ʱ)-xx(��)-xx(��)\n��ʽ����Ļ��һ�ʶ����Ŷ");
	InputBox(m2, 100, "�����������ʲô����������");
	string strm1(m);
	string strm2(m2);
	string strm = strm1 + strm2;
	transform(strm);
	ofstream outfile("reminder.txt", ios::app);
	if (outfile.is_open())
	{
		outfile <<strm<< endl;
		outfile.close();
	}
}
void Reminder::compareAlarm(SYSTEMTIME st, Alarmtime alarmt)
{
//	cout << alarmt.amonth << "-" << st.wMonth << " " << alarmt.aday << "-" << st.wDay << " " << alarmt.ahour
//		<< "-" << st.wHour << " " << alarmt.aminute << "-" << st.wMinute << " " << alarmt.asecond << "-" << st.wSecond << "--"<<alarmt.reason1<< endl;
	if (alarmt.amonth == st.wMonth && alarmt.aday == st.wDay && alarmt.ahour == st.wHour && alarmt.aminute == st.wMinute && alarmt.asecond == st.wSecond && alarmt.amonth != 0)
	{
		playMusic();
	}
}
void Reminder::playMusic()
{
	cout << mciSendString("open resource/1.MP3 type mpegvideo alias myMusic", NULL, 0, NULL);
	cout << mciSendString("play resource/1.MP3", NULL, 0, NULL);
	int volume = 200; // 50%��������Χ��0 - 1000
	std::string setVolumeCommand = "setaudio myMusic volume to " + std::to_string(volume);
	mciSendString(setVolumeCommand.c_str(), NULL, 0, NULL);
	string temp1 = "���趨��ʱ�䵽��\nԭ�� " + alarmt.reason1;
	MessageBox(NULL, temp1.c_str(), " ", NULL);
	cout << "66666666" << endl;
	return;
}
void Reminder::Alarmtrigger()
{
	for (auto &ala : allAlarm)
	{
		compareAlarm(st, ala);
	}
}
void Reminder::stopAlarm()
{
	mciSendString("stop resource/1.MP3", NULL, 0, NULL);
}
string Reminder::stringAlarm(Alarmtime alarmt)
{
	string alarmstring;
	alarmstring =  to_string(alarmt.amonth) + "�� " +  to_string(alarmt.aday) +"�� "  + to_string(alarmt.ahour) +"ʱ "  + to_string(alarmt.aminute) + "�� " + to_string(alarmt.asecond)+"��"
		+ " ԭ��:" + alarmt.reason1 + "\n";
	return alarmstring;
}
void Reminder::showAlarm()
{
	string sumalarm = "Ҫɾ���ĸ�����������~\n";
	int temp = 1;
	for (auto& ala : allAlarm)
	{
		sumalarm = sumalarm+to_string(temp)+":" + stringAlarm(ala);
		temp++;
	}
	char m1[100];
	//		char r1[100];
	InputBox(m1, 100, sumalarm.c_str());
	string strm(m1);
	if (strm == "")
	{
		return;
	}
	int sizea = recorder.size();
	if (strm[0]<='9'&&strm[0]>'0'&&stoi(strm)<=recorder.size())
	{
		cout << stoi(strm) << endl;
	}
	else
	{
		MessageBox(NULL, "���������", "�����ʽ����", NULL);
		return;
	}
	deletenum = stoi(strm) - 1;
	deleteAlarm(deletenum);
}
void Reminder::deleteAlarm(int num)
{
	ofstream tempFile("temp.txt");
	recorder.erase(recorder.begin() + num);
	allAlarm.erase(allAlarm.begin() + num);
	for (auto& p : recorder)
	{
		tempFile <<p << endl;
	}
	tempFile.close();
	remove("reminder.txt");
	cout << rename("temp.txt", "reminder.txt") << endl;
	return;
}

void Reminder::getCourses()//��course.txt�ļ��ж�ȡ�γ�
{
	courseAlarm.clear();
	ifstream infile("course.txt");
	if (infile.is_open())
	{
		string line;
		while (getline(infile,line))
		{
			cout << line << endl;
		//	cout << 1 << endl;
			transform(line);
			courseAlarm.push_back(alarmt);
			if (line.empty())
			{
				continue;
			}
		}
		infile.close();
	}
	else
	{
		cerr << "��������" << endl;
	}
	cout << 12947384361 << endl;
	return;
}
void Reminder::courseCompare(SYSTEMTIME st, Alarmtime alarmt)
{
	if (alarmt.aday==st.wDayOfWeek&&alarmt.ahour == st.wHour && alarmt.aminute == st.wMinute && alarmt.asecond == st.wSecond)
	{
	//		cout  << alarmt.aday << "-" << st.wDayOfWeek << " " << alarmt.ahour
	//	<< "-" << st.wHour << " " << alarmt.aminute << "-" << st.wMinute << " " << alarmt.asecond << "-" << st.wSecond << "--"<<alarmt.reason1<< endl;
		playMusic();
	}
	return;
}
void Reminder::coursetrigger()
{
	for (auto& alarmt : courseAlarm)
	{
	//			cout  << alarmt.aday << "-" << st.wDayOfWeek << " " << alarmt.ahour
	//<< "-" << st.wHour << " " << alarmt.aminute << "-" << st.wMinute << " " << alarmt.asecond << "-" << st.wSecond << "--"<<alarmt.reason1<< endl;
		courseCompare(st, alarmt);
	}
	return;
}