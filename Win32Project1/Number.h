#pragma once
#include "ZeroIScene.h"
#include <ZeroSprite.h>
class Number : public ZeroIScene
{
public:
	Number();
	~Number();
	void Update(float eTime);
	void Render();
	ZeroSprite *number[10];
	ZeroSprite *coinnumber[10];
	ZeroSprite *studentnumber[10];
};

