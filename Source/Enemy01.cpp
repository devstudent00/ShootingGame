#include "Enemy01.h"
#include "Screen.h"
#include <assert.h>
#include "cmath"
#include "EnemyBullet.h"
#include "PlayScene.h"

using namespace std;

namespace {
	const int amplitude = 5; //振れ幅（※大きくすると幅が大きくなる）
	const float period = 0.5f; //周期（※大きくすると、早くなる）
	float angles = 0.1;
}

Enemy01::Enemy01()
{
	Enemy01("Enemy01", 0, 0);
}

Enemy01::Enemy01(string tag, int x, int y)
 : health(100){
	counter = 0;
	hImage = LoadGraph("data/images/enemy01.png");
	deadImage = LoadGraph("data/images/enemyBroken.png");
	assert(hImage > 0);
	position.x = (float) x;
	position.y = (float) y;
	velocity = VECTOR3(0, 1, 0);
	SetTag("Enemy01");
}

Enemy01::~Enemy01()
{
}

void Enemy01::Update()
{
	if (health <= 0) {
		hImage = deadImage;
		DestroyMe();
	}

	counter++;
	angles += 0.1;
	if (counter >= bulletCount) { //定期的に球を発射
		new EnemyBullet(position.x, position.y);
		velocity.y = GetRand(3) + 1;
		counter = 0;
	}

	velocity.x = cos(angles * period) * amplitude;
	
	position += velocity; //ベクトル分、下に移動する
	if (position.y > Screen::HEIGHT - 16) { //画面外に出たら上に戻る
		position.y = 0;
		velocity.y = 1;
	}
}

void Enemy01::Draw()
{
	//             表示座標                          絵の左上 サイズ

	DrawRectGraph((int)position.x, (int)position.y, 32 * 0, 0, 32, 32, hImage, true);
	DrawCircle(position.x+16, position.y+16, 16, 0xff, 0);;
}

float Enemy01::GetHealth() const {
	return health;
}

void Enemy01::SetHealth(float health) {
	if (health >= 0) {
		this->health = health;
	}
}

void Enemy01::AddHealth(float health) {
	this->health += health;
}

void Enemy01::SubtractHealth(float health) {
	if (health >= 0) {
		this->health -= health;
	}
}

bool Enemy01::CollideBullet(VECTOR3 centerPos, float radius)
{
	// VECTOR3 myCenter = VECTOR3(position.x+16, position.y+16, 0);
	VECTOR3 myCenter = position + VECTOR3(16, 16, 0);
	VECTOR3 vec = centerPos - myCenter;
	float distance = vec.Size();
	if (distance < radius + 16.0f) {
		return true;
	}

	//

	//float y = abs(centerPos.y - position.y);
	//float x = abs(centerPos.x - position.x);
	//float distance = sqrt(y*y + x*x);
	//
	//DrawFormatString(200, 200, GetColor(255, 255, 255), "%f", distance);
	//if (distance < radius) {
	//	return true;
	//}
	

	return false;
}
