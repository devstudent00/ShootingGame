#pragma once
#include "../Library/GameObject.h"

class Player : public GameObject {
public:
	Player();
	Player(int x, int y);
	~Player();
	void Update() override;
	void Draw() override;
	VECTOR3 GetPostion() { return position; };
	float GetHealth() const;
	void SetHealth(float health);
	void AddHealth(float health);
	void SubtractHealth(float health);
	bool CollidePlayer(VECTOR3 centerPos, float radius); //プレイヤーと特定の座標との当たり判定
private:
	int hImage; //プレイヤー用の画像ハンドル
	VECTOR3 position; //場所
	float health; //体力
	int bulletType = 0;
};