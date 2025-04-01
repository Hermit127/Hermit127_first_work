#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <Windows.h>
#include <easyx.h>
#include <vector>
#include <map>
using namespace std;
class OtherManager
{
private:
	string message;
	int number;
	vector<string>information;
public:
	OtherManager();
	void getinformation();
};

class Application
{
private:
public:
	Application() {};
	int i=1;
	void startapplication();
};

class Website
{
public:
	int i = 1;
	void startwebsite();
};

class Quickkeyboard
{
private:
	map<string, WORD>keyMap;
public:
	vector<string>hermit;
	int i=2;
	void startkeyboard();
	void initkeymap();
	void imitatekey();
	void getkey(string key);
};

