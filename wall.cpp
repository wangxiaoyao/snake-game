//
//  wall.cpp
//  snake-game
//
//  Created by 王逍遥 on 2020/3/12.
//  Copyright © 2020 王逍遥. All rights reserved.
//
#include "wall.h"

void Wall::initWall() {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (i == 0 || j == 0 || i == ROW - 1 || j == COL - 1) {
				gameArray[i][j] = '*';
			}
			else {
				gameArray[i][j] = ' ';
			}
		}
	}
}

void Wall::draw() {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			std::cout << gameArray[i][j] << ' ';
		}
		if (i == 5) {
			std::cout << "create by xiaoyao";
		}
		if (i == 6) {
			std::cout << "w 按键向上";
		}
		if (i == 7) {
			std::cout << "s 按键向下";
		}
		if (i == 8) {
			std::cout << "a 按键向左";
		}
		if (i == 9) {
			std::cout << "d 按键向右";
		}
		std::cout << std::endl;
	}
}
void Wall::setWall(int x, int y, char c) {
	gameArray[x][y] = c;
};

char Wall::getWall(int x, int y) {
	return gameArray[x][y];
};
