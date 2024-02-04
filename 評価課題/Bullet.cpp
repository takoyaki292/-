#include "Bullet.h"
#include "Novice.h"

Bullet::Bullet(int x, int y, int speed, int r, int isShot)
{
	x_ = x;
	y_ = y;
	speed_ = speed;
	r_ = r;
	isShot_ = isShot;
}

void Bullet::Update()
{
	y_ -= speed_;
	if (y_ < 0 - r_)
	{
		isShot_ = 0;
	}
}

void Bullet::Draw()
{
	if (isShot_ == 1)
	{
		Novice::DrawEllipse(x_, y_, r_, r_, 0.0f, BLACK, kFillModeSolid);
	}
}


