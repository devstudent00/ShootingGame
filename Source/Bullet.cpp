#include "Bullet.h"
#include "Screen.h"
#include <assert.h>
#include "Enemy01.h"
#include "Player.h"

Bullet::Bullet()
{
	Bullet(0, 0);
}

Bullet::Bullet(int x, int y)
{
	hImage = LoadGraph("data/images/playerBullet.png");
	assert(hImage > 0);
	position.x = (float)x;
	position.y = (float)y;
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	position.y -= 4.0f;
	if (position.y < -8.0f) {
		DestroyMe();
	}

	//Enemy01との当たり判定
	auto enemies = FindGameObjects<Enemy01>(); //すべての敵を
	for (Enemy01* e : enemies) { 
		if (e->CollideBullet(position, 4.0f)) {
			e->SubtractHealth(1.0);
			DestroyMe();
		}
	}
}

void Bullet::Draw()
{
	//             表示座標                          絵の左上 サイズ

	DrawRectGraph((int)position.x, (int)position.y, 8 * 0, 8 * 0, 8, 8, hImage, true);
}
