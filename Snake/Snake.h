#pragma once
#include<iostream>
#include<vector>
#include<list>

using namespace std;

struct point
{
	int x, y;
};

class Snake {
	friend class Display;
	friend class Food;
	friend int main();
private:
	list<point> body;
	int oldDirection;
	int newDirection;

public:
	const int dy[4] = { -1,0,1,0 };
	const int dx[4] = { 0,1,0,-1 };
	Snake();
	void listen_key_borad();
	bool movePoint(point &pt,int dir);
	bool moveHead();
	bool moveHeadAndTail();
};