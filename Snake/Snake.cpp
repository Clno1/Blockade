#include"pch.h"
#include"Snake.h"
#include"GmaeInit.h"
#include<iostream>
#include<unordered_set>
#include<Windows.h>
#include <conio.h>

using namespace std;

Snake::Snake() {
	oldDirection = 1;
	newDirection = -1;
	body.push_back(point{ 40, 15 });
	body.push_back(point{ 39,15 });
	body.push_back(point{ 38,15 });
	body.push_back(point{ 37, 15 });
	body.push_back(point{ 36, 15 });
}

//监听键盘
void Snake::listen_key_borad() {
	char ch;
	if (_kbhit())					//kbhit 非阻塞函数 
	{
		ch = _getch();	//使用 getch 函数获取键盘输入 
		switch (ch)
		{
		case 'w':
		case 'W':
			if (oldDirection == 2) break;
			newDirection = 0;
			break;
		case 's':
		case 'S':
			if (oldDirection == 0) break;
			newDirection = 2;
			break;
		case 'a':
		case 'A':
			if (oldDirection == 1) break;
			newDirection = 3;
			break;
		case 'd':
		case 'D':
			if (oldDirection == 3) break;
			newDirection = 1;
			break;
		}
	}
}

bool Snake::movePoint(point& pt,int dir) {
	point newpt = pt;
	newpt.x += dx[dir];
	newpt.y += dy[dir];
	if (newpt.x<=1 || newpt.x>=GameInit::windowWidth || newpt.y<=1 || newpt.y>=GameInit::windowHeight) return 0;
	unordered_set<int> snakebody;
	for (auto pt : body)  snakebody.insert(pt.x*1000+pt.y);
	if (snakebody.count(newpt.x*1000+newpt.y)) return 0;
	pt = newpt;
	return 1;
}

bool Snake::moveHead() {
	if (newDirection == -1) newDirection = oldDirection;

	point newpt = body.front();
	if (movePoint(newpt,newDirection) == 0) return 0;
	body.push_front(newpt);

	oldDirection = newDirection; newDirection = -1;
	return 1;
}

bool Snake::moveHeadAndTail() {
	if (newDirection == -1) newDirection = oldDirection;

	body.pop_back();
	point newpt = body.front();
	if (movePoint(newpt,newDirection) == 0) return 0;
	body.push_front(newpt);
	
	oldDirection = newDirection; newDirection = -1;
	return 1;
}