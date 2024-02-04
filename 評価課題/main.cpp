#include <Novice.h>
#include "Enemy.h"
#include "Bullet.h"
#include "Player.h"

const char kWindowTitle[] = "GT";

enum Scane
{
	TITLE,
	GAME,
	OVER,
	CLAER
};
int scane = 0;
// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};
	Enemy* enemy = new Enemy();
	Player* player = new Player();
	int playerTimer = 0;
	int timer = 0;
	int isF = 0;
	int isE = 0;
	int distX;
	int distY;
	int dist;
	int r;

	int eX;
	int eY;
	int e;
	int eR;

	int titlerGH = Novice::LoadTexture("./TITLE.png");
	int claerGH = Novice::LoadTexture("./CLAER.png");
	int overGH = Novice::LoadTexture("./OVER.png");

	
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		switch (scane)
		{
		case TITLE:
			player->Initaliza(300, 300, 5, 5, 50, 1);
			enemy->Initaliza(100, 100, 5, 30, 1, playerTimer);
			playerTimer = 0;
			timer = 0;
			if (keys[DIK_2] && !preKeys[DIK_2])
			{
				scane = GAME;

			}
			if (keys[DIK_3] && !preKeys[DIK_3])
			{
				scane = OVER;
			}
			if (keys[DIK_4] && !preKeys[DIK_4])
			{
				scane = CLAER;
			}
			break;
		case GAME:
			enemy->Update();
			player->Update(preKeys, keys);
			distX = player->GetPosX() - enemy->GetPosX();
			distY = player->GetPosY() - enemy->GetPosY();
			dist = (distX * distX) + (distY * distY);
			r = enemy->GerRadius() + player->GetRadaius();

			eX = player->GetBulletPosX() - enemy->GetPosX();
			eY = player->GetBulletPosY() - enemy->GetPosY();
			e = (eX * eX) + (eY * eY);
			eR = enemy->GerRadius() + player->GetBulletRadaius();

			if (dist <= r * r)
			{
				isF = 1;
			}

			if (e <= eR * eR)
			{
				isE = 1;
			}
			if (isF == 1)
			{

				if (playerTimer >= 120)
				{
					player->SetAlive(1);
					playerTimer = 0;
					isF = 0;
				}
				else
				{
					playerTimer++;
					player->SetAlive(0);
				}
			}
			if (isE == 1)
			{

				if (timer >= 120)
				{
					enemy->SetAlive(1);
					timer = 0;
					isE = 0;
				}
				else
				{
					timer++;
					enemy->SetAlive(0);
				}
			}
			if (keys[DIK_1] && !preKeys[DIK_1])
			{
				scane = TITLE;
			}
			if (keys[DIK_3] && !preKeys[DIK_3])
			{
				scane = OVER;
			}
			if (keys[DIK_4] && !preKeys[DIK_4])
			{
				scane = CLAER;
			}
			break;
		case OVER:
			if (keys[DIK_1] && !preKeys[DIK_1])
			{
				scane = TITLE;
			}
			if (keys[DIK_2] && !preKeys[DIK_2])
			{
				scane = GAME;
			}
			if (keys[DIK_4] && !preKeys[DIK_4])
			{
				scane = CLAER;
			}
			break;
		case CLAER:
			if (keys[DIK_1] && !preKeys[DIK_1])
			{
				scane = TITLE;
			}
			if (keys[DIK_2] && !preKeys[DIK_2])
			{
				scane = GAME;
			}
			if (keys[DIK_3] && !preKeys[DIK_3])
			{
				scane = OVER;
			}
		}
		
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		switch (scane)
		{
		case TITLE:
			Novice::DrawSprite(0, 0, titlerGH, 1, 1, 0.0f, WHITE);
			break;
		case GAME:
			player->Draw();
			enemy->Draw();
			break;
		case OVER:
			Novice::DrawSprite(0, 0, overGH, 1, 1, 0.0f, WHITE);
			break;
		case CLAER:
			Novice::DrawSprite(0, 0, claerGH, 1, 1, 0.0f, WHITE);
			break;
		}
		
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}
	delete enemy;
	delete player;
	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
