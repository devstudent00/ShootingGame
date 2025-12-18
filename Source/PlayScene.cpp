#include "PlayScene.h"
#include "Player.h"
#include "Enemy01.h"
#include "Bullet.h"
#include "Screen.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include "../ImGui/imgui.h"
#include "../GameUtil.h"
#include "EnemyBullet.h"

float bulletCount = 60;

namespace {
	Player* player;
	Enemy01* enemy01;
	std::list<EnemyBullet*> enemyBullets;
}

PlayScene::PlayScene()
{
	time = 0;
	new Player(Screen::WIDTH / 2, Screen::HEIGHT - 100);
	new Enemy01("Enemy01_01", 400, 100);
	new Enemy01("Enemy01_02", 1000, 100);

	player = FindGameObject<Player>();
	enemy01 = FindGameObject<Enemy01>();
	enemyBullets = FindGameObjects<EnemyBullet>(); //list
	
}

PlayScene::~PlayScene()
{
}

void PlayScene::Update()
{
	time += (Time::DeltaTime()*60);
	if (CheckHitKey(KEY_INPUT_T)) {
		SceneManager::ChangeScene("TITLE");
	}
}

void PlayScene::Draw()
{
	GameUtil::DrawFixText(DrawType::RIGHT, Screen::WIDTH, 0, GetColor(255, 255, 255), GetColor(0, 0, 0),
		std::string("åªç›ÇÃëÃóÕ: " + std::to_string(player->GetHealth()))
	);
	DrawString(0, 0, "PLAY SCENE", GetColor(255, 255, 255));
	DrawString(100, 400, "Push [T]Key To Title", GetColor(255, 255, 255));

	DrawGUI();
}

void PlayScene::DrawGUI() {
	ImGui::Begin("Debug");
	ImGui::Text("PlayerHealth: %.2f", player->GetHealth());
	ImGui::Text("Time: %.2f", time);
	ImGui::Text("EnemyBullet: %d", enemyBullets.size());
	ImGui::SliderFloat("float", &bulletCount, 0.0f, 200.0f);

	//äeìGÇÃê›íË
	for (auto enemy : FindGameObjects<Enemy01>()) {
		string tag = enemy->GetTag();
		float health = enemy->GetHealth();
		ImGui::Text("EnemyTag: %s", tag.c_str());
		ImGui::SliderFloat("health", &health, 1.0f, 100.0f);

		enemy->SetHealth(health);
	}
	
	ImGui::End();
}
