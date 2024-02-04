#pragma once

class Bullet
{
public:
	int x_;
	int y_;
	int speed_;
	int r_;
	int isShot_;
public:
	Bullet(int x, int y, int speed, int r, int isShot);
	//void Initaliza();
	void Update();
	void Draw();
	int GetPosX() { return x_; };
	int GetPosY() { return y_; };
};