#include "LoadingScene.h"

LoadingScene::LoadingScene()
{
	logo = new ZeroSprite("Resource/ZeroEngine_.png");
	logo->SetScale(0.65);
	logo->SetPosY(200);
	loading = new ZeroSprite("Resource/loading.png");
	ZeroTexMgr->LoadTextureFromFile("Resource/MainScene/Explanation.png");
	ZeroTexMgr->LoadTextureFromFile("Resource/MainScene/Start.png");
	ZeroTexMgr->LoadTextureFromFile("Resource/Number/0.png");
	ZeroTexMgr->LoadTextureFromFile("Resource/Number/1.png");
	ZeroTexMgr->LoadTextureFromFile("Resource/Number/2.png");
	ZeroTexMgr->LoadTextureFromFile("Resource/Number/3.png");
	ZeroTexMgr->LoadTextureFromFile("Resource/Number/4.png");
	ZeroTexMgr->LoadTextureFromFile("Resource/Number/5.png");
	ZeroTexMgr->LoadTextureFromFile("Resource/Number/6.png");
	ZeroTexMgr->LoadTextureFromFile("Resource/Number/7.png");
	ZeroTexMgr->LoadTextureFromFile("Resource/Number/8.png");
	ZeroTexMgr->LoadTextureFromFile("Resource/Number/9.png");;
	ZeroTexMgr->LoadTextureFromFile("Resource/GameScene/month.png");
	ZeroTexMgr->LoadTextureFromFile("Resource/GameScene/year.png");
	ZeroTexMgr->LoadTextureFromFile("Resource/GameScene/cursorclick.png");
	ZeroTexMgr->LoadTextureFromFile("Resource/GameScene/cursor.png");
	ZeroTexMgr->LoadTextureFromFile("Resource/GameScene/cursorstruct.png");
	loadingTime = 0.f;
}

LoadingScene::~LoadingScene()
{
}

void LoadingScene::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	loadingTime += eTime;
	if (loadingTime > 2.f)
	{
		ZeroSceneMgr->ChangeScene(new MainScene());
		return;
	}
}

void LoadingScene::Render()
{
	ZeroIScene::Render();
	loading->Render();
	logo->Render();
}