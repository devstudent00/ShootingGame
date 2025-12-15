#pragma once
#include "../Library/GameObject.h"

class Enemy01 : public GameObject {
public:
	Enemy01();
	Enemy01(int x, int y);
	~Enemy01();
	void Update() override;
	void Draw() override;

	float GetHealth() const;
	void SetHealth(float health);
	void AddHealth(float health);
	void SubtractHealth(float health);

	bool CollideBullet(VECTOR3 centerPos, float radius);
private:
	int hImage;
	VECTOR3 position;
	VECTOR3 velocity; //•ûŒü
	int counter;
	int health;
};