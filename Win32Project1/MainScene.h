#pragma once
#include "ZeroIScene.h"
#include "GameScene.h"
#include "DataManager.h"
#include "Explanation.h"
#include <ZeroSprite.h>
#include <ZeroSceneManager.h>
#include <ZeroInputManager.h>
class MainScene : public ZeroIScene
{
public:
	MainScene();
	~MainScene();
	void Update(float eTime);
	void Render();
	ZeroSprite *background;
	ZeroSprite *start;
	ZeroSprite *explanation;
	ZeroSprite *cursor[2];
	ZeroSprite *reset;
	bool isClicked;
	DataManager *data;
};

