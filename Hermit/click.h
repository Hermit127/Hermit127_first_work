#pragma once
#include <graphics.h>
#include <windows.h>
#include <iostream>
#include <ctime>
using namespace std;
// ���峤����ʱ����ֵ����λΪ���룬��������Ϊ500���룬���Ը���ʵ���������
const int LONG_PRESS_TIME_THRESHOLD = 50;

bool judge_click()
{
    ExMessage firstMsg;
    // ��ȡ��һ�������Ϣ
    if (peekmessage(&firstMsg, EX_MOUSE, true) == 1)
    {
        cout << firstMsg.x;
        // �жϵ�һ�λ�ȡ����Ϣ�Ƿ�Ϊ����������
        if (firstMsg.message == WM_LBUTTONDOWN)
        {
            clock_t startTime = clock();
            while (true)
            {
                ExMessage currentMsg;
                // �����鿴��Ϣ�������Ƿ����µ������Ϣ
                if (peekmessage(&currentMsg, EX_MOUSE, true) == 1)
                {
                    // �����������̧����Ϣ��˵�����ǳ�����ֱ�ӷ��� false
                    if (currentMsg.message == WM_LBUTTONUP)
                    {
                        return false;
                    }
                }
                // ��������������¿�ʼ�����ھ�����ʱ��
                clock_t elapsedTime = clock() - startTime;
                // ��ʱ��ת��Ϊ����
                int elapsedTimeMs = elapsedTime * 1000 / CLOCKS_PER_SEC;
                // ���������ʱ�䳬���˳���ʱ����ֵ������Ϊ�ǳ��������� true
                if (elapsedTimeMs > LONG_PRESS_TIME_THRESHOLD)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
