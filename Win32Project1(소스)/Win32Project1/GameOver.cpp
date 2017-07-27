#include "GameOver.h"

GameOver::GameOver()
{
	gameOver = new ZeroSprite("Resource/GameScene/gameOver.png");
	gameOver->SetPos(300, 100);
}

GameOver::~GameOver()
{
}

void GameOver::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYUP)
		isClicked = false;
	if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYDOWN)
	{
		isClicked = true;
		ZeroSceneMgr->ChangeScene(new MainScene());
		return;
	}
}

void GameOver::Render()
{
	ZeroIScene::Render();
	gameOver->Render();
}