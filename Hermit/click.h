#pragma once
#include <graphics.h>
#include <windows.h>
#include <iostream>
#include <ctime>
using namespace std;
// 定义长按的时间阈值，单位为毫秒，这里设置为500毫秒，可以根据实际需求调整
const int LONG_PRESS_TIME_THRESHOLD = 50;

bool judge_click()
{
    ExMessage firstMsg;
    // 获取第一次鼠标消息
    if (peekmessage(&firstMsg, EX_MOUSE, true) == 1)
    {
        cout << firstMsg.x;
        // 判断第一次获取的消息是否为鼠标左键按下
        if (firstMsg.message == WM_LBUTTONDOWN)
        {
            clock_t startTime = clock();
            while (true)
            {
                ExMessage currentMsg;
                // 持续查看消息队列中是否有新的鼠标消息
                if (peekmessage(&currentMsg, EX_MOUSE, true) == 1)
                {
                    // 如果是鼠标左键抬起消息，说明不是长按，直接返回 false
                    if (currentMsg.message == WM_LBUTTONUP)
                    {
                        return false;
                    }
                }
                // 计算从鼠标左键按下开始到现在经过的时间
                clock_t elapsedTime = clock() - startTime;
                // 将时间转换为毫秒
                int elapsedTimeMs = elapsedTime * 1000 / CLOCKS_PER_SEC;
                // 如果经过的时间超过了长按时间阈值，就认为是长按，返回 true
                if (elapsedTimeMs > LONG_PRESS_TIME_THRESHOLD)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
