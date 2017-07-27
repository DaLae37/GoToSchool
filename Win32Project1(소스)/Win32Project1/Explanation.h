#pragma once
#include "ZeroIScene.h"
#include "ZeroSceneManager.h"
#include "ZeroSprite.h"
#include "ZeroInputManager.h"
#include "MainScene.h"
class Explanation : public ZeroIScene
{
public:
	Explanation();
	~Explanation();
	ZeroSprite *explanation[10];
	ZeroSprite *next;
	ZeroSprite *back;
	ZeroSprite *cursor[2];
	ZeroSprite *background;
	bool isClicked;
	int currentShow;
	void Update(float eTime);
	void Render();
};

