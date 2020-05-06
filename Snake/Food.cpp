#include"pch.h"
#include<iostream>
#include<random>
#include<cstdlib>
#include"Food.h"
#include"GmaeInit.h"
#include"Snake.h"

using namespace std;

bool Food::EatFood(const list<point>& body) {
	if (x == body.front().x && y == body.front().y) return 1;
	else return 0;
}

bool Food::FoodOnBody(int tmpx,int tmpy,const list<point>& body) {
	for (auto pt : body)
		if (pt.x == tmpx && pt.y == tmpy) return 1;
	return 0;
}

void Food::CreateFood(const list<point>& body) {
	int tmpx,tmpy;
	do {
		tmpx = rand() % GameInit::windowWidth + 1;
		tmpy = rand() % GameInit::windowHeight + 1;
	} while (FoodOnBody(tmpx, tmpy, body));
	this->x = tmpx;
	this->y = tmpy;
}