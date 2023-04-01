#pragma once
#include "ZeroIScene.h"
#include "ZeroSprite.h"
#include "ZeroSceneManager.h"
#include "MainScene.h"

class GameOver : public ZeroIScene
{
public:
	GameOver();
	~GameOver();
	void Update(float eTime);
	void Render();
	bool isClicked;
	ZeroSprite *gameOver;
};

