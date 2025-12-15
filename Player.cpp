#include "Player.h"
#include "Library//myDxLib.h"
#include "Source/Screen.h"
#include <cassert>
#include "Library/Input.h"
#include <DxLib.h>

namespace {
	enum DIR {
		LEFT, UP, RIGHT, DOWN
	};
	VECTOR2 dir[4] = {
		{-1, 0},
		{0, -1},
		{1, 0},
		{0, 1}
	};
}


Player::Player() 
	: postion(Screen::WIDTH / 2, Screen::HEIGHT / 2),
		speed(2.0f),
		direction(-1, 0){
	hImage = LoadGraph(".\\data\\images\\player.png");
}

Player::~Player() {
}

void Player::Draw() {
	if (direction.x == dir[UP].x && direction.y == dir[UP].y) {
		DrawGraph(postion.x, postion.y, hImage, false);
	}
	else if (direction.x == dir[DOWN].x && direction.y == dir[DOWN].y) {
		DrawGraph(postion.x, postion.y, hImage, false);
	}
	else if (direction.x == dir[LEFT].x && direction.y == dir[LEFT].y) {
		DrawGraph(postion.x, postion.y, hImage, false);
	}
	else if (direction.x == dir[RIGHT].x && direction.y == dir[RIGHT].y) {
		DrawGraph(postion.x, postion.y, hImage, false);
	}
	//DrawRectExtendGraph();
}

void Player::Update() {

	if (Input::IsKeyOnTrig(KEY_INPUT_LEFT)) {
		direction = dir[LEFT];
	}
	else if (Input::IsKeyOnTrig(KEY_INPUT_UP)) {
		direction = dir[UP];
	}
	else if (Input::IsKeyOnTrig(KEY_INPUT_RIGHT)) {
		direction = dir[RIGHT];
	}
	else if (Input::IsKeyOnTrig(KEY_INPUT_DOWN)) {
		direction = dir[DOWN];
	}

	postion.x = postion.x + speed * direction.x;
	postion.y = postion.y + speed * direction.y;
}
