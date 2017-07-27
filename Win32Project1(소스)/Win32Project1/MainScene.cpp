#include "MainScene.h"

MainScene::MainScene()
{
	ShowCursor(false);
	cursor[0] = new ZeroSprite("Resource/GameScene/cursor.png");
	cursor[1] = new ZeroSprite("Resource/GameScene/cursorclick.png");
	background = new ZeroSprite("Resource/MainScene/Background.png");
	start = new ZeroSprite("Resource/MainScene/Start.png");
	start->SetPos(100, 500);
	explanation = new ZeroSprite("Resource/MainScene/Explanation.png");
	explanation->SetPos(100, 600);
	reset = new ZeroSprite("Resource/MainScene/reset.png");
	reset->SetPos(1150, 650);
	data = new DataManager();
	isClicked = false;
}

MainScene::~MainScene()
{
}

void MainScene::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYDOWN)
	{
		isClicked = true;
		if (start->IsOverlapped(ZeroInputMgr->GetClientPoint()))
		{
			ZeroSceneMgr->ChangeScene(new GameScene());
			return;
		}
		else if (explanation->IsOverlapped(ZeroInputMgr->GetClientPoint()))
		{
			ZeroSceneMgr->ChangeScene(new Explanation);
			return;
		}
		else if(reset->IsOverlapped(ZeroInputMgr->GetClientPoint()))
			data->Reset();
	}
	if(ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYUP)
		isClicked = false;
	for (int i = 0; i < 2; i++)
		cursor[i]->SetPos(ZeroInputMgr->GetClientPoint());
}

void MainScene::Render()
{
	ZeroIScene::Render();
	background->Render();
	start->Render();
	explanation->Render();
	reset->Render();
		if (isClicked)
			cursor[1]->Render();
		else
			cursor[0]->Render();
}