#include "window.h"
#pragma comment(lib,"winmm.lib")
using namespace std;
int main()
{
	//下面是程序介绍，感兴趣的可以暂停自己看，我就直接展示了 
	//战歌，起！
	//演示闹钟我就把音乐先关一下了
	// 谢谢收看
	//本程序是武汉大学计院某学生所编写的大一上c++大作业，共用时2周代码带注释1600行
	//程序主要用于实现一个桌面助手（作为一个刚看完mygo的炉批，虽然想做一个mygo桌宠但是做出来一点没有宠物的样子，或者说简直是唐完了，所以还是叫桌面助手好了）
	//程序主要有以下功能 
	//1、记账，通过输入账单的金额和消费的原因来记录账单，可以显示账单，程序会计算不同消费原因的消费总和和总消费
	//2、设定提醒，你可以手动设定闹钟提醒，也可以通过导入course.txt文件自动设置闹钟提醒，提醒在到时间后响起闹钟，你可以将课表导入从而做到在上课前提醒以免错过课程
	//（事实上会响起春日影，这样春日影响起就会有人跑了，符合原著）
	//3、记录密码，你可以将某个网站的密码记录入程序，程序记录的密码是通过某种方式加密的，所以你不能直接从txt查看,也不能直接查看，要输入密码之后才能查看
	//4、移动程序，我本来是自己写了一个拖动能让程序进行拖动的，但是拖动过于卡顿我干脆删了，你可以设置程序的坐标来改变程序的位置
	//5、快捷键，你可以通过一个按钮设置快捷键从而直接打开网页，程序，也可以让程序模拟快捷键实现切歌等功能
	//6、退出程序，没什么好多说的
	// 
	//作者写程序的时候还没有学数据结构和算法等，所以只会一些基础的语法和知识，程序的效率可能相对不高，希望能够包容
	//用的是c++，easyx库和window api，由于本人水平浅薄并且美术功底依托，所以做出的gui界面比较简陋
	//主要还是功能的实现，我希望能做一些真正实用的功能，自己写的东西能用上还是很有成就感的
	//程序的实现还是挺简单的，如果希望的话我也可以做一个视频讲解这个程序的制作流程
	//发这个视频不求数据，只是给我自己第一个项目做留档纪念
	//下面给大家运行一下程序看看程序的效果
	Window win;
	win.createWindow();
	thread Thread([&]() {
		while (true)
		{
			win.setWindowTop();
			Sleep(1000);
	//		cout << 1;
		}
	});
	win.putButton();
	win.createImage();	
	win.threadrun();
	//Thread.detach();
	getchar();
	//cout << 1 << endl;
	return 0;
}