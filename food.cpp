//
//  food.cpp
//  snake-game
//
//  Created by 王逍遥 on 2020/3/12.
//  Copyright © 2020 王逍遥. All rights reserved.
//

#include "food.h"
#include "windows.h"
	//不需要刷新；光标定位
void gotoxy2(HANDLE hOut2, int x, int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOut2, pos);
}
HANDLE hOut2 = GetStdHandle(STD_OUTPUT_HANDLE);

Food::Food(Wall &tempWall):wall(tempWall){
    srand((unsigned int)time(NULL));
}

void Food::setFood(){
    
    while (true) {
        foodX = rand()%(Wall::ROW-2)+1;
        foodY = rand()%(Wall::COL-2)+1;
        if (wall.getWall(foodX, foodY) == ' ') {
			wall.setWall(foodX, foodY, '#');
			gotoxy2(hOut2, foodY * 2, foodX);
			std::cout << '#';
            break;
        }
    }
}
