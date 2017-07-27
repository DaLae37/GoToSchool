#pragma once
#include "ZeroIScene.h"
#include "MainScene.h"
#include "ZeroSprite.h"
#include "ZeroTextureManager.h"
#include <ZeroSceneManager.h>
class LoadingScene : public ZeroIScene
{
public:
	LoadingScene();
	~LoadingScene();
	void Update(float eTime);
	void Render();
	ZeroSprite *logo;
	ZeroSprite *loading;
	float loadingTime;
};

