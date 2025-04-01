#pragma once
#include <vector>
#include <easyx.h>
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <mmsystem.h>
#include <vector>
#include <iomanip>
#include <thread>
#include <chrono>
using namespace std;
#pragma comment(lib,"winmm.lib")
//�����������ʵ��һ�����ӹ��ܣ�ʱ�䵽���Զ��������֣�����Ӱbushi��
//�ܹ��趨����ʱ�䣬������ӣ�ɾ�����ӣ���ʾ���ӣ��ر����ӣ��������ļ���ʽ���ñ���
class Reminder
{
private:
	SYSTEMTIME st;
	struct Alarmtime
	{
		int amonth=1;
		int aday=1;
		int ahour=1;
		int aminute=1;
		int asecond=1;
		string reason1="";
	};
	string reason;
	vector<Alarmtime>allAlarm;
	vector<Alarmtime>courseAlarm;
	vector<string>recorder;
	Alarmtime alarmt;
	int deletenum;
public:
	Reminder();
	void getTime();
	void setTime();
	void getCourses();
	void showAlarm();
	void Alarmtrigger();
	void transform(string strm);
	void stopAlarm();
	void compareAlarm(SYSTEMTIME st, Alarmtime alarmt);
	void deleteAlarm(int num);
	void courseCompare(SYSTEMTIME st, Alarmtime alarmt);
	void playMusic();
	void coursetrigger();
	string stringAlarm(Alarmtime alarmt);

};