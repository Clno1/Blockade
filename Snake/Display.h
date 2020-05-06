#pragma once
#include<iostream>
#include<vector>
#include"Snake.h"

using namespace std;

class Display {
public:
	void printBorder();
	void printSnake(const list<point> &body);
	void destroySnake(const list<point> &body);
	void gotoxy(int x, int y);
	void printFood(int x, int y);
	void destroyFood(int x, int y);
	void clean();   //清理按任意键继续字样
	void gameover();
};