#include "Enemy.h"
#include "Novice.h"

Enemy::Enemy()
{
	x_ = 100;
	y_ = 100;
	speedX_ = 5;
	r_ = 30;
	isAlive_ = 1;
}

void Enemy::Initaliza(int x, int y, int speedX, int r, int isAlive,int timer)
{
	x_ = x;
	y_ = y;
	speedX_ = speedX;
	r_ = r;
	isAlive_ = isAlive;
	timer_ = timer;
}

void Enemy::Update()
{
	if (isAlive_ == 1)
	{
		x_ += speedX_;
		if (x_ - r_ <= 0 || x_ + r_ >= 1280)
		{
			speedX_ *= -1;
		}
	}
	
	if (isAlive_ == 0)
	{
		timer_++;
		if (timer_ >= 60)
		{
			isAlive_ = 1;
		}
	}
}

void Enemy::Draw()
{
	if (isAlive_ == 1)
	{
		Novice::DrawEllipse(x_, y_, r_, r_, 0.0f, RED, kFillModeSolid);
	}
	
}

void Enemy::SetAlive(int isAlive)
{
	isAlive_ = isAlive;
}


