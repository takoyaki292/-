#include "Player.h"
#include "Novice.h"

Player::Player()
{
	x_=100;
	y_ = 100;
	speedX_ = 5;
	speedY_ = 5;
	r_ = 30;
	isAlive_ = 1;
	
}

void Player::Initaliza(int x, int y, int speedX, int speedY, int r, int isAlive)
{
	x_ = x;
	y_ = y;
	speedX_ = speedX;
	speedY_ = speedY;
	r_ = r;
	isAlive_ = isAlive;
	bullet_=new Bullet(x_, y_, 7, 20, 0);
}

void Player::Update(const char* preKeys, const char* keys)
{	
	if (keys[DIK_A] && preKeys[DIK_A])
	{
		x_ -= speedX_;
	}
	if (keys[DIK_D] && preKeys[DIK_D])
	{
		x_ += speedX_;
	}
	if (keys[DIK_W] && preKeys[DIK_W])
	{
		y_ -= speedY_;
	}
	if (keys[DIK_S] && preKeys[DIK_S])
	{
		y_ += speedY_;
	}

	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE] && bullet_->isShot_ == 0)
	{
		bullet_->isShot_ = 1;
		bullet_->x_ = x_;
		bullet_->y_= y_;
	}
	if (bullet_->isShot_ == 1)
	{
		bullet_->Update();
	}
}

void Player::Draw()
{
	if (isAlive_ == 1)
	{
		Novice::DrawBox(x_ - r_, y_ - r_, r_ * 2, r_ * 2, 0.0f, BLACK, kFillModeSolid);
		if (bullet_->isShot_ == 1)
		{
			bullet_->Draw();
		}
	}
	
	//Novice::ScreenPrintf(0, 0, "x:%d  y:%d", bullet_->x_, bullet_->y_);
}

void Player::SetAlive(int isALive)
{
	isAlive_=isALive;
}

void Player::SetBulletShot(int isShot)
{
	bullet_->isShot_ = isShot;
}
