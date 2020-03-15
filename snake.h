//
//  snake.hpp
//  snake-game
//
//  Created by 王逍遥 on 2020/3/12.
//  Copyright © 2020 王逍遥. All rights reserved.
//

#ifndef snake_hpp
#define snake_hpp

#include <iostream>
#include "wall.h"
#include "food.h"
class Snake{
public:
    Snake(Wall &tempWall,Food &tempFood);
    enum{
       UP = 'w',
       DOWN = 's',
       RIGHT = 'd',
       LEFT='a',
    };
    
    struct Point{
        int x;
        int y;
        Point *next;
    };
    
    void initSnake();
    void destroyPoint();
    void addPoint(int x,int y);
    void delPoint();
    bool move(char key);
    
    Point *pHead;
    Wall &wall;
    Food &food;
	bool isRool;

	//游戏难度
	int getSleepTime();
	int countList();
	// 获取分数
	int getScore();
};

#endif /* snake_hpp */
