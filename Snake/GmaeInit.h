#pragma once

#include<iostream>
using namespace std;

class GameInit {
private:
	int speed;


public:
	static const int windowHeight = 35;
	static const int windowWidth = 80;
	GameInit(int s);
};