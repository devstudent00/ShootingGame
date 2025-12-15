#include "TitleScene.h"
#include "../GameUtil.h"
#include "Screen.h"

TitleScene::TitleScene()
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Update()
{
	if (CheckHitKey(KEY_INPUT_P)) {
		SceneManager::ChangeScene("PLAY");
	}
	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		SceneManager::Exit();
	}
	DebugPrintf("%f\n", Time::DeltaTime());
}


void TitleScene::Draw()
{
	extern const char* Version();
	GameUtil::DrawFixText(DrawType::CENTER, Screen::WIDTH / 2, Screen::HEIGHT / 2, GetColor(255, 255, 255), GetColor(0, 0, 0), "ゲームを開始するには[P]キーを押してください。");

	DrawString(0, 20, Version(), GetColor(255,255,255));
	DrawString(0, 0, "TITLE SCENE", GetColor(255,255,255));
	DrawFormatString(100, 100, GetColor(255,255,255), "%4.1f", 1.0f / Time::DeltaTime());
	//DrawString(100, 400, "Push [P]Key To Play", GetColor(255, 255, 255));
}
