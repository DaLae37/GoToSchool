#include "Explanation.h"

Explanation::Explanation()
{
	currentShow = 0;
	background = new ZeroSprite("Resource/MainScene/Background.png");
	for (int i = 1; i <= 10; i++)
		explanation[i-1] = new ZeroSprite("Resource/Explanation/%d.png",i);
	cursor[0] = new ZeroSprite("Resource/GameScene/cursor.png");
	cursor[1] = new ZeroSprite("Resource/GameScene/cursorclick.png");
	next = new ZeroSprite("Resource/Explanation/next.png");
	next->SetPos(1150, 400);
	back = new ZeroSprite("Resource/GameScene/gomain.png");
	back->SetPos(0, 600);
	isClicked = false;
}

Explanation::~Explanation()
{

}

void Explanation::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYDOWN)
	{
		isClicked = true;
		if (next->IsOverlapped(ZeroInputMgr->GetClientPoint()))
			currentShow++;
		if (currentShow > 10)
			currentShow = 0;
		if (back->IsOverlapped(ZeroInputMgr->GetClientPoint()))
		{
			ZeroSceneMgr->ChangeScene(new MainScene);
			return;
		}
	}
	if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYUP)
		isClicked = false;
	for (int i = 0; i < 2; i++)
		cursor[i]->SetPos(ZeroInputMgr->GetClientPoint());
}

void Explanation::Render()
{
	ZeroIScene::Render();
	background->Render();
	explanation[currentShow]->Render();
	next->Render();
	back->Render();
	if (isClicked)
		cursor[1]->Render();
	else
		cursor[0]->Render();
}