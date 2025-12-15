#pragma once
#include "../Library/GameObject.h"

class EnemyBullet : public GameObject {
public:
	EnemyBullet();
	EnemyBullet(int x, int y);
	~EnemyBullet();
	void Update() override;
	void Draw() override;
private:
	int hImage;
	VECTOR3 position;
	VECTOR3 velocity;
};