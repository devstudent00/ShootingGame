#pragma once
#include "Library/GameObject.h"
class Player : public GameObject {
private:

public:
	Player();
	~Player();

	VECTOR2 postion;
	// VECTOR2 velocity;
	float speed;
	VECTOR2 direction;
	int hImage;

	VECTOR2 GetPostion() { return postion; }
	VECTOR2 SetPostion(VECTOR2 pos) { postion = pos; };
	void Draw() override;
	void Update() override;
};

