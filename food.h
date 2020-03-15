//
//  food.hpp
//  snake-game
//
//  Created by 王逍遥 on 2020/3/12.
//  Copyright © 2020 王逍遥. All rights reserved.
//

#ifndef food_hpp
#define food_hpp

#include <iostream>
#include "wall.h"
#include <ctime>

class Food{
public:
    Food(Wall &tempWall);
    
    void setFood();
    
    int foodX;
    int foodY;
    Wall &wall;
};


#endif /* food_hpp */
