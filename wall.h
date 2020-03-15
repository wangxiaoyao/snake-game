#pragma once
#include <iostream>
class Wall {
public:
	enum {
		ROW = 20,
		COL = 20,
	};
	// ��ʼ��
	void initWall();
	// ��ǽ
	void draw();
	// �����������ö�ά�����ֵ
	void setWall(int x, int y, char c);
	// �������л�ȡֵ
	char getWall(int x, int y);

private:
	char gameArray[ROW][COL];
};