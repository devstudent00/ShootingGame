#include "Player.h"
#include <assert.h>
#include "Screen.h"
#include "Bullet.h"

namespace {

}

Player::Player()
{
	Player(Screen::WIDTH / 2, Screen::HEIGHT - 100);
}

Player::Player(int x, int y) {
	hImage = LoadGraph("data/images/player.png");
	position.x = x;
	position.y = y;
	health = 100;
}

Player::~Player()
{
}

void Player::Update()
{
	if (Input::IsKeyOnTrig(KEY_INPUT_SPACE)) {
		new Bullet(position.x+28, position.y+18);
	}

	if (CheckHitKey(KEY_INPUT_W)) {
		position.y -= 5;
		if (position.y < -16.0f) {
			position.y = -16.0f;
		}
	}
	if (CheckHitKey(KEY_INPUT_S)) {
		position.y += 5;
		if (position.y > Screen::HEIGHT - 32.0f - 16.0f) {
			position.y = Screen::HEIGHT - 32.0f - 16.0f;
		}
	}
	if (CheckHitKey(KEY_INPUT_D)) {
		position.x += 5;
		if (position.x > Screen::WIDTH - 32.0f - 16.0f) {
			position.x = Screen::WIDTH - 32.0f - 16.0f;
		}
	}
	if (CheckHitKey(KEY_INPUT_A)) {
		position.x -= 5;
		if (position.x < -16.0f) {
			position.x = -16.0f;
		}
	}
}

void Player::Draw()
{
	//DrawRectGraph(100, 200, 0, 0,    64, 64, hImage, true);
	//            表示座標                絵の左上 サイズ

	DrawRectGraph((int) position.x, (int)position.y, 64*0, 0, 64, 64, hImage, true);
}

float Player::GetHealth() const {
	return health;
}

void Player::SetHealth(float health) {
	if (health >= 0) {
		this->health = health;
	}
}

void Player::AddHealth(float health) {
	this->health += health;
}

void Player::SubtractHealth(float health) {
	if (health >= 0) {
		this->health -= health;
	}
}

bool Player::CollidePlayer(VECTOR3 centerPos, float radius = 4.0f) {
	VECTOR3 myCenter = position + VECTOR3(32, 32, 0);
	VECTOR3 vec = centerPos - myCenter;
	float distance = vec.Size();
	if (distance < radius + 32.0f) {
		return true;
	}
	return false;
}
