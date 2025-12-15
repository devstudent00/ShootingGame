#pragma once
#include "../Library/GameObject.h"

class Bullet : public GameObject {
public:
	Bullet();
	Bullet(int x, int y);
	~Bullet();
	void Update() override;
	void Draw() override;
private:
	int hImage;
	VECTOR3 position;

};