#pragma once
#include <ZeroIScene.h>
#include <ZeroSprite.h>
class Tile : public ZeroIScene
{
private:
	int tileList[10][15] ={
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,1,1,1,1,1,1,1,1,1,0,0,0 },
	{ 0,0,0,1,1,1,1,1,1,1,1,1,0,0,0 },
	{ 0,0,0,1,1,1,1,1,1,1,1,1,0,0,0 },
	{ 0,0,0,1,1,1,1,1,1,1,1,1,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
	};
	int arrayW;
	int arrayH;
public:
	Tile();
	~Tile();
	void Update(float eTime);
	void Render();
	ZeroSprite *oneTile[150];
	ZeroSprite *top[2];
	ZeroSprite *left[3];
};