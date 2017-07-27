#include "SchoolPolicy.h"

SchoolPolicy::SchoolPolicy()
{
	data = new DataManager();
}

SchoolPolicy::~SchoolPolicy()
{
}

void SchoolPolicy::Update(float eTime)
{
	ZeroIScene::Update(eTime);
}

void SchoolPolicy::Render()
{
	ZeroIScene::Render();
}