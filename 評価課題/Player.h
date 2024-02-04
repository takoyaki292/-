#pragma once
#include "Bullet.h"

class Player
{
public:

	Player();
	void Initaliza(int x, int y, int speedX, int speedY, int r, int isAlive);
	void Update(const char* preKeys, const char* keys);
	void Draw();
	int GetPosX() { return x_; };
	int GetPosY() { return y_; };
	int GetBulletPosX() { return bullet_->x_; };
	int GetBulletPosY() { return bullet_->y_; };
	void SetAlive(int isALive);
	void SetBulletShot(int isShot);
	int GetRadaius() { return r_; };
	int GetBulletRadaius() { return bullet_->r_; };
private:
	Bullet* bullet_;
	int x_;
	int y_;
	int speedX_;
	int speedY_;
	int r_;
	int isAlive_;
};