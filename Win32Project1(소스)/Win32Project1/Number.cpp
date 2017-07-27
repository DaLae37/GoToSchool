#include "Number.h"

Number::Number()
{
	for (int i = 0; i < 10; i++)
	{
		number[i] = new ZeroSprite("Resource/Number/%d.png", i);
		coinnumber[i] = new ZeroSprite("Resource/YellowNumber/%d.png", i);
		studentnumber[i] = new ZeroSprite("Resource/OrangeNumber/O%d.png", i);
	}
}

Number::~Number()
{

}

void Number::Update(float eTime)
{
	ZeroIScene::Update(eTime);
}

void Number::Render()
{
	ZeroIScene::Render();
}