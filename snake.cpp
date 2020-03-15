//
//  snake.cpp
//  snake-game
//
//  Created by 王逍遥 on 2020/3/12.
//  Copyright © 2020 王逍遥. All rights reserved.
//

#include "snake.h"
#include "windows.h"
	//不需要刷新；光标定位
void gotoxy1(HANDLE hOut1, int x, int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOut1, pos);
}
HANDLE hOut1 = GetStdHandle(STD_OUTPUT_HANDLE);


// 传递wall!
Snake::Snake(Wall& tempWall, Food& tempFood) :wall(tempWall), food(tempFood) {
	//  wall= tempWall;
	pHead = NULL;
	isRool = false;
}

void Snake::destroyPoint() {
	Point* pCur = pHead;
	while (pCur != NULL) {  
		pCur = pHead->next;
		delete pHead;
		pHead = pCur;
	}
}

void Snake::addPoint(int x, int y) {
	Point* newPoint = new Point;
	newPoint->x = x;
	newPoint->y = y;

	if (pHead != NULL) {
		wall.setWall(pHead->x, pHead->y, '=');
		gotoxy1(hOut1, pHead->y * 2, pHead->x);
		std::cout << '=';
	};
	newPoint->next = pHead;
	pHead = newPoint;
	wall.setWall(newPoint->x, newPoint->y, '@');
	gotoxy1(hOut1, 2*pHead->y, pHead->x);
	std::cout << '@';

}
void Snake::initSnake() {
	destroyPoint();
	addPoint(5, 3);
	addPoint(5, 4);
	addPoint(5, 5);
}

void Snake::delPoint() {
	if (NULL == pHead || NULL == pHead->next) {
		return;
	}
	Point* pPre = pHead;
	Point* pCur = pPre->next;

	while (NULL != pCur->next) {
		pPre = pPre->next;
		pCur = pCur->next;
	};
	wall.setWall(pCur->x, pCur->y, ' ');
	gotoxy1(hOut1, 2*pCur->y, pCur->x);
	std::cout << ' ';
	delete pCur;
	pCur = NULL;
	pPre->next = NULL;
}

bool Snake::move(char key) {
	int posX = pHead->x;
	int posY = pHead->y;
	switch (key) {
	case UP:
		posX--;
		break;
	case DOWN:
		posX++;
		break;
	case LEFT:
		posY--;
		break;
	case RIGHT:
		posY++;
		break;
	default:
		break;
	}

	// 判断是否为尾巴若是则不会死亡
	Point* pPre = pHead;
	Point* pCur = pPre->next;

	while (NULL != pCur->next) {
		pPre = pPre->next;
		pCur = pCur->next;
	};
	// 尾巴等于头部
	if (pCur->x == posX && pCur->y == posY) {
		isRool = true;
	}
	else {
		//失败情况
		if (wall.getWall(posX, posY) == '*' || wall.getWall(posX, posY) == '=') {
			addPoint(posX, posY);
			delPoint();
			system("cls");
			wall.draw();
			std::cout << "gameover" << std::endl;
			return false;
		}
	}

	// 吃食物
	if (wall.getWall(posX, posY) == '#') {
		addPoint(posX, posY);
		food.setFood();
	}
	else {
		addPoint(posX, posY);
		delPoint();
		if (isRool) {
			wall.setWall(posX, posY, '@');
			gotoxy1(hOut1, posY * 2, posX);
			std::cout << '@';

		}
	}
	return true;
}

int Snake::getSleepTime()
{	
	int sleepTime = 0;
	int size = countList();
	if (size<4) {
		sleepTime = 500;
	}
	else if (size>=4 && size<=5) {
		sleepTime = 200;
	}
	else {
		sleepTime = 100;
	}
	return sleepTime;

}

int Snake::countList()
{	
	int size = 0;
	Point* pCur = pHead;
	while (pCur != '\0') {
		size++;
		pCur = pCur->next;
	}
	return size;
}

int Snake::getScore()
{
	int size = countList();
	int score = (size - 3) * 10;
	return score;
}
