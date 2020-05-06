#pragma once
#include<iostream>
#include<random>
#include"Snake.h"
using namespace std;

class Food {
private:
	int x, y;
public:
	int getx() { return x; }
	int gety() { return y; }
	bool FoodOnBody(int tmpx,int tmpy,const list<point>& body);
	bool EatFood(const list<point>& body);
	void CreateFood(const list<point>& body);
};