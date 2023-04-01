#pragma once
#include "ZeroIScene.h"
#include <ZeroSprite.h>
class Struct : public ZeroIScene
{
public:
	Struct();
	~Struct();
	void Update(float eTime);
	void Render();
	ZeroSprite *mainSchool;
	ZeroSprite *sideSchool;
	ZeroSprite *cafeteria;
	ZeroSprite *gym;
	ZeroSprite *read[5];
};

