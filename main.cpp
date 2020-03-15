// snake.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "wall.h"
#include "food.h"
#include "snake.h"
#include "conio.h"
#include "windows.h"
	//不需要刷新；光标定位
void gotoxy(HANDLE hOut, int x, int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOut, pos);
}
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
int main()
{
	bool isDead = false;
	char preKey = '\0';
	Wall wall;
	wall.initWall();
	wall.draw();

	Food food(wall);
	food.setFood();
	
	Snake snake(wall, food);
	snake.initSnake();
	
	//wall.draw();
	gotoxy(hOut, 0, Wall::ROW);
	std::cout << "分数为：" << snake.getScore() << std::endl;
	// 由于y多加了空格 所以x乘以2；
	gotoxy(hOut,10,5);
	while (!isDead) {
		char key = _getch();
		if (preKey == '\0' && key == snake.LEFT) {
			continue;
		}
		do {
			if (key == snake.UP || key == snake.DOWN || key == snake.LEFT || key == snake.RIGHT) {
				if ((key == snake.LEFT && preKey == snake.RIGHT) ||
					(key == snake.RIGHT && preKey == snake.LEFT) ||
					(key == snake.UP && preKey == snake.DOWN) ||
					(key == snake.DOWN && preKey == snake.UP)
					)
				{
					key = preKey;
				}
				else {
					preKey = key;
				}
				if (snake.move(key) == true) {
					//system("cls");
					//wall.draw();
					gotoxy(hOut, 0, Wall::ROW);
					std::cout<< "分数为："<< snake.getScore() <<std::endl;
					Sleep(snake.getSleepTime());
				}
				else {
					isDead = true;
					std::cout << "分数为：" << snake.getScore() << std::endl;
					break;
				}
			}
			else {
				key = preKey;
			}
		} while (!_kbhit());
	}
	return 0;
}