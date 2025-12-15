#include "EnemyBullet.h"
#include <cassert>
#include "Player.h"
#include "Screen.h"

EnemyBullet::EnemyBullet()
{
	EnemyBullet(0, 0);
}

EnemyBullet::EnemyBullet(int x, int y)
{
	hImage = LoadGraph("data/images/bulet1.png");
	assert(hImage > 0);
	position = VECTOR3(x, y, 0);
	Player* p = FindGameObject<Player>();
	VECTOR3 pPos = p->GetPostion(); //プレイヤーの座標
	velocity = pPos - position;
	// velocity = velocity / velocity.Size(); //正規化
	velocity = velocity.Normalize(); //正規化：長さを1にする
	velocity *= 2.0f;
}

EnemyBullet::~EnemyBullet()
{
}

void EnemyBullet::Update()
{
	position += velocity;

	Player* player = FindGameObject<Player>();
	if (player->CollidePlayer(position, 4.0f)) {
		player->SubtractHealth(1.0f);
		DestroyMe();
	}
	else {
		if (0 > position.x || Screen::WIDTH < position.x || 0 > position.y || Screen::HEIGHT < position.y) {
			DestroyMe();
		}
	}
}

void EnemyBullet::Draw()
{
	DrawRectGraph((int)position.x, (int)position.y, 0, 0, 32, 32, hImage, true);
}
