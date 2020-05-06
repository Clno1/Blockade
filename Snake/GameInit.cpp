#include"pch.h"
#include "GmaeInit.h"
#include<Windows.h>
#include<random>
#include<ctime>
#include <conio.h>

using namespace std;

GameInit::GameInit(int s) : speed(s) {
	//设置游戏窗口大小
	char buffer[32];
	sprintf_s(buffer, "mode con cols=%d lines=%d", windowWidth, windowHeight);
	system(buffer);

	//隐藏光标
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息
	CursorInfo.bVisible = false; //隐藏控制台光标
	SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态
	//初始化随机数种子
	srand((unsigned int)time(0));
}