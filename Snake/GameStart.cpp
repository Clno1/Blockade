#include "pch.h"
#include<iostream>
#include<Windows.h>
#include"GmaeInit.h"
#include"Display.h"
#include"Food.h"
#include"Snake.h"

using namespace std;

int main()
{
	GameInit gameinit(1);
	Display display;
	Snake snake;
	Food food;
	display.printBorder();
	display.printSnake(snake.body);
	bool hasFood = 0;

	display.gotoxy(32,16 );
	system("pause");
	display.clean();

	int tim = 0;
	while (1) {
		tim++;
		if (tim < 80000000) continue;	//在这里可以调节Snake的速度

		display.destroySnake(snake.body);
		if (hasFood == 0) {
			food.CreateFood(snake.body);
			display.printFood(food.getx(),food.gety());
			hasFood = 1;
		}
		snake.listen_key_borad();
		if (food.EatFood(snake.body)) {
			if (snake.moveHead() == false) break;
			display.destroyFood(food.getx(), food.gety());
			hasFood = 0;
		}
		else {
			if (snake.moveHeadAndTail() == false) break;
		}
		
		display.printSnake(snake.body);
		tim = 0;
	}

	display.destroyFood(food.getx(), food.gety());
	display.destroySnake(snake.body);
	display.gameover();
	
	cin.get();
	return 0;
}