#pragma once
#include "ZeroIScene.h"
#include "ZeroSprite.h"
#include "ZeroInputManager.h"
#include "DataManager.h"
class SchoolPolicy : public ZeroIScene
{
public:
	SchoolPolicy();
	~SchoolPolicy();
	void Update(float eTime);
	void Render();
	DataManager *data;
};