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
//这个程序首先实现一个闹钟功能，时间到了自动播放音乐（春日影bushi）
//能够设定闹钟时间，添加闹钟，删除闹钟，显示闹钟，关闭闹钟，并且以文件形式永久保存
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