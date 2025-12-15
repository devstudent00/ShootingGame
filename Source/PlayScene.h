#pragma once
#include "../Library/SceneBase.h"
#include "Player.h"
#include "Enemy01.h"

extern float bulletCount;

/// <summary>
/// ゲームプレイのシーンを制御する
/// </summary>
class PlayScene : public SceneBase
{
public:
	PlayScene();
	~PlayScene();
	void Update() override;
	void Draw() override;
	void DrawGUI();
private:
	float time;
};
