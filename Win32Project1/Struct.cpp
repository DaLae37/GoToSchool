#include "Struct.h"

Struct::Struct()
{
	mainSchool = new ZeroSprite("Resource/Struct/school.png");
	sideSchool = new ZeroSprite("Resource/Struct/sideschool.png");
	cafeteria = new ZeroSprite("Resource/Struct/cafeteria.png");
	gym = new ZeroSprite("Resource/Struct/gym.png");
	for (int i = 0; i < 5; i++)
		read[i] = new ZeroSprite("Resource/Struct/%d.png", i);
}

Struct::~Struct()
{

}

void Struct::Update(float eTime)
{
	ZeroIScene::Update(eTime);	
}

void Struct::Render()
{
	ZeroIScene::Render();
}