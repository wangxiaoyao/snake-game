#pragma once
#include <iostream>
class Wall {
public:
	enum {
		ROW = 20,
		COL = 20,
	};
	// 初始化
	void initWall();
	// 画墙
	void draw();
	// 依据索引设置二维数组的值
	void setWall(int x, int y, char c);
	// 依据所有获取值
	char getWall(int x, int y);

private:
	char gameArray[ROW][COL];
};