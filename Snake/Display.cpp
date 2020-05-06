#include"pch.h"
#include"Display.h"
#include"GmaeInit.h"
#include"Snake.h"
#include<iostream>
#include<Windows.h>
#include <conio.h>

using namespace std;

void Display::printBorder() {
	system("cls");
	int n = GameInit::windowHeight;
	int m = GameInit::windowWidth;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1 || i==n  || j == 1 || j == m) cout << "#"; else cout << " ";
		}
		cout << endl;
	}
}

//将光标移动到x,y位置
void Display::gotoxy(int x, int y) {
	COORD c;
	c.X = x; c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void Display::printSnake(const list<point> &body) {
	for (auto pt : body) {
		gotoxy(pt.x, pt.y);
		cout << "*";
	}
}

void Display::destroySnake(const list<point> &body) {
	for (auto pt : body) {
		gotoxy(pt.x, pt.y);
		cout << " ";
	}
}

void Display::printFood(int x, int y) {
	gotoxy(x, y);
	cout << "@";
}

void Display::destroyFood(int x, int y) {
	gotoxy(x, y);
	cout << " ";
}

void Display::clean() {
	for (int i = 32; i <= 50; i++) {
		gotoxy(i, 16);
		cout << " ";
	}
}

void Display::gameover() {
	string over = "游戏结束";
	for (int i = 32; i <= 40; i++) {
		gotoxy(i, 16);
		cout << over[i-32];
	}
}