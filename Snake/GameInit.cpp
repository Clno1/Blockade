#include"pch.h"
#include "GmaeInit.h"
#include<Windows.h>
#include<random>
#include<ctime>
#include <conio.h>

using namespace std;

GameInit::GameInit(int s) : speed(s) {
	//������Ϸ���ڴ�С
	char buffer[32];
	sprintf_s(buffer, "mode con cols=%d lines=%d", windowWidth, windowHeight);
	system(buffer);

	//���ع��
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);//��ȡ����̨�����Ϣ
	CursorInfo.bVisible = false; //���ؿ���̨���
	SetConsoleCursorInfo(handle, &CursorInfo);//���ÿ���̨���״̬
	//��ʼ�����������
	srand((unsigned int)time(0));
}