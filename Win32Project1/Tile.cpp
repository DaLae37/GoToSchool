#include "Tile.h"

Tile::Tile()
{
	for (int i = 0; i < 3; i++)
	{
		if (i < 2)
		{
			top[i] = new ZeroSprite("Resource/Tile/top.png");
			top[i]->SetPos(-1110 + i*1550, 150);
		}
		left[i] = new ZeroSprite("Resource/Tile/left.png");
		left[i]->SetPos(-650 + i * 420,0);
	}
	arrayW = 0;
	arrayH = 0;
	for (int i = 0; i < 150; i++)
	{
		if (i % 15 == 0 && i!=0)
		{
			arrayW = 0;
			arrayH++;
		}
		if (tileList[arrayH][arrayW] ==0)
			oneTile[i] = new ZeroSprite("Resource/Tile/Tile.png");
		else
			oneTile[i] = new ZeroSprite("Resource/Tile/grassTile.png");
		arrayW++;
		if (i < 15)
			oneTile[i]->SetPos(-970 + i * 140, -78);
		else if (i < 30)
			oneTile[i]->SetPos(-1015 + (i - 15) * 140, 0);
		else if (i < 45)
			oneTile[i]->SetPos(-1060 + (i - 30) * 140, 78);
		else if (i < 60)
			oneTile[i]->SetPos(-1105 + (i - 45) * 140, 156);
		else if (i < 75)
			oneTile[i]->SetPos(-1150 + (i - 60) * 140, 234);
		else if (i < 90)
			oneTile[i]->SetPos(-1195 + (i - 75) * 140, 312);
		else if (i < 105)
			oneTile[i]->SetPos(-1240 + (i - 90) * 140, 390);
		else if (i < 120)
			oneTile[i]->SetPos(-1285 + (i - 105) * 140, 468);
		else if (i < 135)
			oneTile[i]->SetPos(-1330 + (i - 120) * 140, 546);
		else
			oneTile[i]->SetPos(-1375 + (i - 135) * 140, 624);
		PushScene(oneTile[i]);
	}
}

Tile::~Tile()
{

}

void Tile::Update(float eTime)
{
	ZeroIScene::Update(eTime);
}

void Tile::Render()
{
	ZeroIScene::Render();
	for (int i = 0; i < 150; i++)
		oneTile[i]->Render();
	for (int i = 0; i < 3; i++)
	{
		if (i < 2)
			top[i]->Render();
		left[i]->Render();
	}
}