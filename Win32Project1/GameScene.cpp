#include "GameScene.h"

GameScene::GameScene()
{
	cursor[0] = new ZeroSprite("Resource/GameScene/cursor.png");
	cursor[1] = new ZeroSprite("Resource/GameScene/cursorclick.png");
	cursor[2] = new ZeroSprite("Resource/GameScene/cursorstruct.png");
	tile = new Tile();
	Linkle = new Number();
	tile->SetScale(0.5);
	for(int i=0; i<6; i++)
	{
		number[i] = new Number();
		monthlySo[i] = new Number();
		policy[i] = new ZeroSprite("Resource/Policy/%d.png", i);
		onpolicy[i] = new ZeroSprite("Resource/Policy/on%d.png", i);
		inpolicy[i] = new ZeroSprite("Resource/Policy/in%d.png", i);
		if (i < 4)
		{
			showEvent[i] = false;
			coco[i] = new Number();
			eventShow[i] = new ZeroSprite("Resource/Event/%d.png",i);
			tree[i] = new ZeroSprite("Resource/Tree/%d.png", i);
			yearNum[i] = new Number();
			moneyNum[i] = new Number();
		}
		if (i < 5)
		{
			read = new Struct();
			money[i] = new Number();
			construct[i] = new Struct();
		}
		if (i < 3)
		{
			LegendOfZelda[i] = new Number();
			Link[i] = new Number();
			happyNum[i] = new Number();
			peopleNum[i] = new Number();
		}
	}
	gameOver = new ZeroSprite("Resource/GameScene/gameOver.png");
	notice = new ZeroSprite("Resource/GameScene/notice.png");
	data = new DataManager();
	menu = new ZeroSprite("Resource/GameScene/menu.png");
	canvas = new ZeroSprite("Resource/GameScene/canvas.png");
	coin = new ZeroSprite("Resource/GameScene/coin.png");
	background = new ZeroSprite("Resource/GameScene/background.png");
	gaze = new ZeroSprite("Resource//GameScene/gaze.png");
	bar = new ZeroSprite("Resource/GameScene/bar.png");
	popup = new ZeroSprite("Resource/GameScene/popup.png");
	policypopup = new ZeroSprite("Resource/GameScene/popup.png");
	chang = new ZeroSprite("Resource/GameScene/chang.png");
	person = new ZeroSprite("Resource/OrangeNumber/person.png");
	percent = new ZeroSprite("Resource/GameScene/percent.png");
	upgradeUI = new ZeroSprite("Resource/GameScene/upgradeUI.png");
	passmonth = new ZeroSprite("Resource/GameScene/passmonth.png");
	goexit = new ZeroSprite("Resource/GameScene/goexit.png");
	gomain = new ZeroSprite("Resource/GameScene/gomain.png");
	schoolpolicy = new ZeroSprite("Resource/GameScene/schoolpolicy.png");
	monthly = new ZeroSprite("Resource/GameScene/monthly.png");
	monthlyS = new ZeroSprite("Resource/GameScene/monthlyS.png");
	yes = new ZeroSprite("Resource/GameScene/yes.png");
	no = new ZeroSprite("Resource/GameScene/no.png");
	wheretrip[0] = new ZeroSprite("Resource/Trip/gang.png");
	wheretrip[1] = new ZeroSprite("Resource/Trip/joo.png");
	wheretrip[2] = new ZeroSprite("Resource/Trip/do.png");
	wheretrip[3] = new ZeroSprite("Resource/Trip/overseas.png");
	onwheretrip[0] = new ZeroSprite("Resource/Trip/ongang.png");
	onwheretrip[1] = new ZeroSprite("Resource/Trip/onjoo.png");
	onwheretrip[2] = new ZeroSprite("Resource/Trip/ondo.png");
	onwheretrip[3] = new ZeroSprite("Resource/Trip/onoverseas.png");
	tripop = new ZeroSprite("Resource/Trip/tripop.png");
	graduate = new ZeroSprite("Resource/PopUp/graduate.png");
	entrance = new ZeroSprite("Resource/PopUp/entrance.png");
	party = new ZeroSprite("Resource/PopUp/party.png");
	canP = new ZeroSprite("Resource/Policy/choice.png");
	overGame = new ZeroSprite("Resource/GameScene/overGame.png");
	conCheck = new ZeroSprite("Resource/GameScene/conCheck.png");
	lucid = new ZeroSprite("Resource/GameScene/lucid.png");
	endYear = new ZeroSprite("Resource/endYear.png");
	endConst = new ZeroSprite("Resource/Struct/complete.png");
	ZeroCameraMgr->SetCameraOn();
	ZeroCameraMgr->SetSpeed(0);
	cameraX = 0;
	cameraY = 0;
	cameraLock = false;
	isGameOver = false;
	popupRender = false;
	noticeRender = false;
	isClicked = false;
	monthlyRender = false;
	policyRender = false;
	tripRender = false;
	partyRender = false;
	graduateRender = false;
	entranceRender = false;
	once = false;
	lucidRender = false;
	lucidonce = false;
	endYearRender = false;
	endConstRender = false;
	time = 0.f;
	year = 0;
	month = 0;
	whereCon = -1;
	gaze->SetScalingCenter(0, gaze->Height()/2);	
}

GameScene::~GameScene()
{

}

void GameScene::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	if (isGameOver == false)
	{
		if (data->Dhappy > 0)
			gaze->SetScale(1 * (float)data->Dhappy / 100, 1);
		else
			isGameOver = true;
		year = (data->Dday - 1) / 12;
		if (data->Dday > 12)
			month = data->Dday - year * 12;
		else
			month = data->Dday;
		if (once == false)
		{
			switch (month)
			{
			case 2:
				data->Graduate();
				graduateRender = true;
				break;
			case 3:
				data->Entrance();
				entranceRender = true;
				break;
			case 5:
				tripRender = true;
				break;
			case 8:
				howHappy = rand() % 11 + 10;
				data->Dhappy += howHappy;
				partyRender = true;
				break;
			case 9:
				data->Dhappy -= howHappy;
				break;
			default:
				break;
			}
			if (data->Dhappy < 0)
				isGameOver = true;
			if (month == 4 && data->Dhappy >= 70)
				if (rand() % 2 + 1 == 1)
					if (data->Dpolicy[0] == 0 || data->Dpolicy[1] == 0 || data->Dpolicy[2] == 0 || data->Dpolicy[3] == 0 || data->Dpolicy[4] == 0 || data->Dpolicy[5] == 0)
						data->Dcanp += 1;
			once = true;
		}
		if (year < 3)
			graduateRender = false;
		if (data->Dmoney > 99999)
			data->Dmoney = 99999;
		if (data->Dhappy > 100)
			data->Dhappy = 100;
		ZeroCameraMgr->SetPos(cameraX, cameraY);
		if (ZeroInputMgr->GetKey('H') == INPUTMGR_KEYDOWN)
		{
			data->Dcanp += 1;
			data->Save();
		}
		if (ZeroInputMgr->GetKey('A') == INPUTMGR_KEYDOWN)
		{
			data->Dmoney += 10000;
			data->Save();
		}
		if (ZeroInputMgr->GetKey('Y') == INPUTMGR_KEYDOWN)
		{
			data->Dhappy += 10;
			data->Save();
		}
		if (ZeroInputMgr->GetKey('W') == INPUTMGR_KEYDOWN)
		{
			data->Dhappy -= 10;
			if (data->Dhappy < 0)
			{
				isGameOver = true;
				return;
			}
		}
		if (ZeroInputMgr->GetKey(VK_ESCAPE) == INPUTMGR_KEYDOWN)
		{
			switch (cameraLock)
			{
			case true:
				cameraLock = false;
				break;
			case false:
				cameraLock = true;
				break;
			}
			End();
		}
		if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYDOWN)
		{
			isClicked = true;
			if (monthly->IsOverlapped(ZeroInputMgr->GetClientPoint()))
				monthlyRender = false;
			if (endYear->IsOverlapped(ZeroInputMgr->GetClientPoint()))
				endYearRender = false;
			if (endConst->IsOverlapped(ZeroInputMgr->GetClientPoint()))
				endConstRender = false;
			if (noticeRender)
				if (upgradeUI->IsOverlapped(ZeroInputMgr->GetClientPoint()))
					lucidRender = true;
			if (tripRender)
			{
				if (data->Dmoney - 4000 >= 0)
				{
					switch (checkChoice())
					{
					case 0:
						data->Dmoney -= 4000;
						data->Dhappy += 10;
						tripRender = false;
						break;
					case 1:
						data->Dmoney -= 4000;
						data->Dhappy += 10;
						tripRender = false;
						break;
					case 2:
						data->Dmoney -= 10000;
						data->Dhappy += 15;
						tripRender = false;
						break;
					case 3:
						data->Dmoney -= 20000;
						data->Dhappy += 20;
						tripRender = false;
						break;
					default:
						break;
					}
					if (data->Dmoney < 0)
					{
						data->Reload();
						tripRender = true;
					}
				}
				else
				{
					data->Dhappy -= 10;
					tripRender = false;
				}
			}
			if (policyRender)
			{
				int v;
				switch (checkPolicy())
				{
				case 0:
					data->Dcanp -= 1;
					data->Dpolicy[0] += 1;
					data->Dhappy += 10;
					v = 0;
					break;
				case 1:
					data->Dcanp -= 1;
					data->Dpolicy[1] += 1;
					v = 1;
					break;
				case 2:
					data->Dcanp -= 1;
					data->Dpolicy[2] += 1;
					v = 2;
					break;
				case 3:
					data->Dcanp -= 1;
					data->Dpolicy[3] += 1;
					v = 3;
					break;
				case 4:
					data->Dcanp -= 1;
					data->Dpolicy[4] += 1;
					v = 4;
					break;
				case 5:
					data->Dcanp -= 1;
					data->Dpolicy[5] += 1;
					v = 5;
					break;
				default:
					break;
				}
				if (data->Dcanp < 0)
				{
					data->Reload();
					data->Dpolicy[v] = 0;
				}
				else
					data->Save();
			}
			if (menu->IsOverlapped(ZeroInputMgr->GetClientPoint()))
				popupRender = true;
			if (passmonth->IsOverlapped(ZeroInputMgr->GetClientPoint()) && tripRender == false && data->Dcanp == 0)
				Event();
		}
		if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYUP)
		{
			isClicked = false;
			if (onStruct() && popupRender == false && noticeRender == false && lucidRender == false)
			{
				noticeRender = true;
				tmp = whereCon;
				switch (tmp)
				{
				case 0:
					tmps = SIDE_PRICE;
					break;
				case 1:
					tmps = MAIN_PRICE;
					break;
				case 2:
					tmps = SIDE_PRICE;
					break;
				case 3:
					tmps = CAFE_PRICE;
					break;
				case 4:
					tmps = GYM_PRICE;
					break;
				default:
					break;
				}
			}
			if (lucidRender)
			{
				if (yes->IsOverlapped(ZeroInputMgr->GetClientPoint()))
				{
					if (data->Dmoney - tmps >= 0)
					{
						if (data->Dcon[tmp] != 0)
							data->Dncon[tmp] += 3;
						data->Dmoney -= tmps;
						if (data->Dcon[tmp] == 0)
						{
							data->Dcon[tmp] += 1;
							endConstRender = true;
						}
					}
					lucidRender = false;
					noticeRender = false;
					data->Save();
				}
				if (no->IsOverlapped(ZeroInputMgr->GetClientPoint()))
				{
					lucidRender = false;
					noticeRender = false;
				}
			}
			if (popupRender)
			{
				if (gomain->IsOverlapped(ZeroInputMgr->GetClientPoint()))
				{
					ZeroCameraMgr->SetCameraOff();
					ZeroSceneMgr->ChangeScene(new MainScene());
					ShowCursor(true);
					return;
				}
				else if (goexit->IsOverlapped(ZeroInputMgr->GetClientPoint()))
				{
					PostQuitMessage(0);
					return;
				}
				else if (schoolpolicy->IsOverlapped(ZeroInputMgr->GetClientPoint()))
					policyRender = true;
			}
		}
		SetPos();
		MoveMap(eTime);
		Canvas();
		CloseCheck();
	}
	else
	{
		ZeroCameraMgr->SetPos(0, 0);
		if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYUP)
			isClicked = false;
		if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYDOWN)
		{
			isClicked = true;
			ZeroCameraMgr->SetCameraOff();
			ZeroSceneMgr->ChangeScene(new MainScene());
			return;
		}
		for (int i = 0; i < 3; i++)
			cursor[i]->SetPos(ZeroInputMgr->GetClientPoint() + ZeroCameraMgr->Pos());
	}
}

void GameScene::Render()
{
	ZeroIScene::Render();
	background->Render();
	tile->Render();
	if (data->Dncon[0] != 0)
		read->read[3]->Render();
	else if (data->Dcon[0] != 0)
		construct[1]->sideSchool->Render();
	if (data->Dncon[1] != 0)
		read->read[2]->Render();
	else if (data->Dcon[1] != 0)
		construct[0]->mainSchool->Render();
	if (data->Dncon[2] != 0)
		read->read[4]->Render();
	else if (data->Dcon[2] != 0)
		construct[2]->sideSchool->Render();
	if (data->Dncon[3] != 0)
		read->read[0]->Render();
	else if (data->Dcon[3] != 0)
		construct[3]->cafeteria->Render();
	if (data->Dncon[4] != 0)
		read->read[1]->Render();
	else if (data->Dcon[4] != 0)
		construct[4]->gym->Render();
	if (month == 12 || month == 1 || month == 2)
		tree[0]->Render();
	else if (month == 3 || month == 4 || month == 5)
		tree[1]->Render();
	else if (month == 6 || month == 7 || month == 8)
		tree[2]->Render();
	else
		tree[3]->Render();
	if (cameraLock)
		menu->Render();
	canvas->Render();
	number[0]->number[2]->Render();
	number[1]->number[0]->Render();
	number[2]->number[year / 10]->Render();
	number[3]->number[year % 10]->Render();
	number[4]->number[month / 10]->Render();
	number[5]->number[month % 10]->Render();
	money[0]->coinnumber[data->Dmoney / 10000]->Render();
	money[1]->coinnumber[data->Dmoney / 1000 % 10]->Render();
	money[2]->coinnumber[data->Dmoney / 100 % 10]->Render();
	money[3]->coinnumber[data->Dmoney / 10 % 10]->Render();
	money[4]->coinnumber[data->Dmoney % 10]->Render();
	Link[0]->studentnumber[data->Dpeople / 100]->Render();
	Link[1]->studentnumber[data->Dpeople / 10 % 10]->Render();
	Link[2]->studentnumber[data->Dpeople % 10]->Render();
	coin->Render();
	bar->Render();
	gaze->Render();
	if (gaze->IsOverlapped(ZeroInputMgr->GetClientPoint()))
	{
		chang->Render();
		if(data->Dhappy>=100)
			LegendOfZelda[0]->number[data->Dhappy / 100]->Render();
		if(data->Dhappy >= 10)
			LegendOfZelda[1]->number[data->Dhappy / 10 % 10]->Render();
		LegendOfZelda[2]->number[data->Dhappy % 10]->Render();
		percent->Render();
	}
	person->Render();
	passmonth->Render();
	if (monthlyRender)
	{
		monthly->Render();
		monthlyS->Render();
		monthlySo[0]->number[month / 10]->Render();
		monthlySo[1]->number[month % 10]->Render();
		monthlySo[2]->number[data->Dupmoney / 1000]->Render();
		monthlySo[3]->number[data->Dupmoney / 100 % 10]->Render();
		monthlySo[4]->number[data->Dupmoney / 10 % 10]->Render();
		monthlySo[5]->number[data->Dupmoney % 10]->Render();
	}
	if (tripRender)
	{
		tripop->Render();
		for (int i = 0; i < 4; i++)
		{
			if (wheretrip[i]->IsOverlapped(ZeroInputMgr->GetClientPoint()))
				onwheretrip[i]->Render();
			else
				wheretrip[i]->Render();
		}
	}
	if (policyRender)
	{
		policypopup->Render();
		for (int i = 0; i < 6; i++)
		{
			if (data->Dpolicy[i] != 0)
				inpolicy[i]->Render();
			else if (policy[i]->IsOverlapped(ZeroInputMgr->GetClientPoint()))
				onpolicy[i]->Render();
			else
				policy[i]->Render();
		}
	}
	if (noticeRender)
	{
		if (data->Dncon[tmp] != 0)
		{
			notice->Render();
			Linkle->number[data->Dncon[tmp]]->Render();
		}
		else
		{
			conCheck->Render();
			upgradeUI->Render();
			if (lucidRender)
			{
				lucid->Render();
					coco[0]->number[tmps / 1000]->Render();
					coco[1]->number[tmps / 100 % 10]->Render();
					coco[2]->number[tmps / 10 % 10]->Render();
					coco[3]->number[tmps % 10]->Render();
				
				yes->Render();
				no->Render();
			}
		}
	}
	if (popupRender)
	{
		popup->Render();
		goexit->Render();
		gomain->Render();
		schoolpolicy->Render();
	}
	if (partyRender)
		party->Render();
	if (graduateRender)
		graduate->Render();
	if (entranceRender)
		entrance->Render();
	if (data->Dcanp != 0)
		canP->Render();
	if (endConstRender)
		endConst->Render();
	for (int i = 0; i < 4; i++)
		if (showEvent[i])
			eventShow[i]->Render();
	if (endYearRender)
	{
		int a = year - 1;
		endYear->Render();
		peopleNum[0]->number[data->Dpeople / 100]->Render();
		peopleNum[1]->number[data->Dpeople / 10 % 10]->Render();
		peopleNum[2]->number[data->Dpeople % 10]->Render();
		happyNum[0]->number[data->Dhappy / 100]->Render();
		happyNum[1]->number[data->Dhappy / 10 % 10]->Render();
		happyNum[2]->number[data->Dhappy % 10]->Render();
		moneyNum[0]->number[data->endMoney / 1000]->Render();
		moneyNum[1]->number[data->endMoney / 100 % 10]->Render();
		moneyNum[2]->number[data->endMoney / 10 % 10]->Render();
		moneyNum[3]->number[data->endMoney % 10]->Render();
		yearNum[0]->number[2]->Render();
		yearNum[1]->number[0]->Render();
		yearNum[2]->number[yeartmp / 10]->Render();
		yearNum[3]->number[yeartmp % 10]->Render();
	}
	if (isGameOver)
		gameOver->Render();
	if (overStruct() && popupRender == false)
		cursor[2]->Render();
	else if (isClicked)
		cursor[1]->Render();
	else
		cursor[0]->Render();
}
void GameScene::MoveMap(float e)
{
	if (cameraLock == false)
	{
		if ((ZeroInputMgr->GetClientPoint().x < 100) && (ZeroInputMgr->GetClientPoint().x > 0) && cameraX > -1375)
			cameraX -= 500 * e;
		if ((ZeroInputMgr->GetClientPoint().x < 1280) && (ZeroInputMgr->GetClientPoint().x > 1180) && cameraX < 0)
			cameraX += 500 * e;
		if ((ZeroInputMgr->GetClientPoint().y < 100) && (ZeroInputMgr->GetClientPoint().y > 0) && cameraY > -300)
			cameraY -= 500 * e;
		if ((ZeroInputMgr->GetClientPoint().y < 720) && (ZeroInputMgr->GetClientPoint().y > 620) && cameraY < 0)
			cameraY += 500 * e;
	}
}

void GameScene::Canvas()
{
	for (int i = 0; i < 4; i++)
		eventShow[i]->SetPos(ZeroCameraMgr->Pos().x, ZeroCameraMgr->Pos().y + i * 100);
	menu->SetPos((ZeroCameraMgr->Pos().x + 1100), (ZeroCameraMgr->Pos().y) + 10);
	canvas->SetPos((ZeroCameraMgr->Pos().x) + 500, (ZeroCameraMgr->Pos().y));
	number[0]->number[2]->SetPos((ZeroCameraMgr->Pos().x) + 530, (ZeroCameraMgr->Pos().y) + 45);
	number[1]->number[0]->SetPos((ZeroCameraMgr->Pos().x) + 550, (ZeroCameraMgr->Pos().y) + 45);
	number[2]->number[year / 10]->SetPos((ZeroCameraMgr->Pos().x) + 570, (ZeroCameraMgr->Pos().y) + 45);
	number[3]->number[year % 10]->SetPos((ZeroCameraMgr->Pos().x) + 590, (ZeroCameraMgr->Pos().y) + 45);
	number[4]->number[month / 10]->SetPos((ZeroCameraMgr->Pos().x) + 680, (ZeroCameraMgr->Pos().y) + 45);
	number[5]->number[month % 10]->SetPos((ZeroCameraMgr->Pos().x) + 700, (ZeroCameraMgr->Pos().y) + 45);
	money[0]->coinnumber[data->Dmoney / 10000]->SetPos((ZeroCameraMgr->Pos().x) + 120, (ZeroCameraMgr->Pos().y) + 640);
	money[1]->coinnumber[data->Dmoney / 1000 % 10]->SetPos((ZeroCameraMgr->Pos().x) + 140, (ZeroCameraMgr->Pos().y) + 640);
	money[2]->coinnumber[data->Dmoney / 100 % 10]->SetPos((ZeroCameraMgr->Pos().x) + 160, (ZeroCameraMgr->Pos().y) + 640);
	money[3]->coinnumber[data->Dmoney / 10 % 10]->SetPos((ZeroCameraMgr->Pos().x) + 180, (ZeroCameraMgr->Pos().y) + 640);
	money[4]->coinnumber[data->Dmoney % 10]->SetPos((ZeroCameraMgr->Pos().x) + 200, (ZeroCameraMgr->Pos().y) + 640);
	coin->SetPos((ZeroCameraMgr->Pos().x) + 40, (ZeroCameraMgr->Pos().y) + 630);
	gaze->SetPos((ZeroCameraMgr->Pos().x) + 20, (ZeroCameraMgr->Pos().y) + 25);
	chang->SetPos((ZeroCameraMgr->Pos().x) + 50, (ZeroCameraMgr->Pos().y) + 50);
	if (data->Dhappy > 0)
	{
		LegendOfZelda[0]->number[data->Dhappy / 100]->SetPos((ZeroCameraMgr->Pos().x) + 70, (ZeroCameraMgr->Pos().y) + 50);
		LegendOfZelda[1]->number[data->Dhappy / 10 % 10]->SetPos((ZeroCameraMgr->Pos().x) + 90, (ZeroCameraMgr->Pos().y) + 50);
		LegendOfZelda[2]->number[data->Dhappy % 10]->SetPos((ZeroCameraMgr->Pos().x) + 110, (ZeroCameraMgr->Pos().y) + 50);
	}
	else
	{
		LegendOfZelda[0]->number[0]->SetPos((ZeroCameraMgr->Pos().x) + 70, (ZeroCameraMgr->Pos().y) + 50);
		LegendOfZelda[1]->number[0]->SetPos((ZeroCameraMgr->Pos().x) + 90, (ZeroCameraMgr->Pos().y) + 50);
		LegendOfZelda[2]->number[0]->SetPos((ZeroCameraMgr->Pos().x) + 110, (ZeroCameraMgr->Pos().y) + 50);
	}
	percent->SetPos((ZeroCameraMgr->Pos().x) + 130, (ZeroCameraMgr->Pos().y) + 50);
	bar->SetPos((ZeroCameraMgr->Pos().x) + 20, (ZeroCameraMgr->Pos().y) + 25);
	popup->SetPos((ZeroCameraMgr->Pos().x) + 50, (ZeroCameraMgr->Pos().y) + 50);
	person->SetPos((ZeroCameraMgr->Pos().x) + 50, (ZeroCameraMgr->Pos().y) + 130);
	Link[0]->studentnumber[data->Dpeople / 100]->SetPos((ZeroCameraMgr->Pos().x) + 150, (ZeroCameraMgr->Pos().y) + 127);
	Link[1]->studentnumber[data->Dpeople / 10 % 10]->SetPos((ZeroCameraMgr->Pos().x) + 170, (ZeroCameraMgr->Pos().y) + 127);
	Link[2]->studentnumber[data->Dpeople % 10]->SetPos((ZeroCameraMgr->Pos().x) + 190, (ZeroCameraMgr->Pos().y) + 127);
	if (popupRender)
	{
		popup->SetPos((ZeroCameraMgr->Pos().x) + 500, (ZeroCameraMgr->Pos().y + 130));
		goexit->SetPos((ZeroCameraMgr->Pos().x) + 600, (ZeroCameraMgr->Pos().y + 500));
		gomain->SetPos((ZeroCameraMgr->Pos().x) + 600, (ZeroCameraMgr->Pos().y + 400));
		schoolpolicy->SetPos((ZeroCameraMgr->Pos().x) + 600, (ZeroCameraMgr->Pos().y + 300));
	}
	if (noticeRender)
	{
		Linkle->number[data->Dncon[tmp]]->SetPos(ZeroCameraMgr->Pos().x + 400, ZeroCameraMgr->Pos().y + 500);
		notice->SetPos(ZeroCameraMgr->Pos().x + construct[whereCon]->mainSchool->Width() / 2, ZeroCameraMgr->Pos().y + construct[whereCon]->mainSchool->Height() / 2);
		conCheck->SetPos((ZeroCameraMgr->Pos().x) + 600, (ZeroCameraMgr->Pos().y + 300));
		upgradeUI->SetPos((ZeroCameraMgr->Pos().x) + 600, (ZeroCameraMgr->Pos().y + 300));
	}
	if (policyRender)
	{
		policypopup->SetPos(ZeroCameraMgr->Pos().x + 100, ZeroCameraMgr->Pos().y + 50);
		for (int i = 0; i < 6; i++)
		{
			policy[i]->SetPos((ZeroCameraMgr->Pos().x + 130), (ZeroCameraMgr->Pos().y) + 100 + i * 70);
			onpolicy[i]->SetPos((ZeroCameraMgr->Pos().x + 130), (ZeroCameraMgr->Pos().y) + 100 + i * 70);
			inpolicy[i]->SetPos((ZeroCameraMgr->Pos().x + 130), (ZeroCameraMgr->Pos().y) + 100 + i * 70);
		}
	}
	if (tripRender)
	{
		tripop->SetPos(ZeroCameraMgr->Pos().x + 500, ZeroCameraMgr->Pos().y + 130);
		wheretrip[0]->SetPos(ZeroCameraMgr->Pos().x + 500, ZeroCameraMgr->Pos().y + 300);
		onwheretrip[0]->SetPos(ZeroCameraMgr->Pos().x + 500, ZeroCameraMgr->Pos().y + 300);
		wheretrip[1]->SetPos(ZeroCameraMgr->Pos().x + 700, ZeroCameraMgr->Pos().y + 300);
		onwheretrip[1]->SetPos(ZeroCameraMgr->Pos().x + 700, ZeroCameraMgr->Pos().y + 300);
		wheretrip[2]->SetPos(ZeroCameraMgr->Pos().x + 500, ZeroCameraMgr->Pos().y + 370);
		onwheretrip[2]->SetPos(ZeroCameraMgr->Pos().x + 500, ZeroCameraMgr->Pos().y + 370);
		wheretrip[3]->SetPos(ZeroCameraMgr->Pos().x + 700, ZeroCameraMgr->Pos().y + 370);
		onwheretrip[3]->SetPos(ZeroCameraMgr->Pos().x + 700, ZeroCameraMgr->Pos().y + 370);
	}
	if (lucidRender)
	{
		lucid->SetPos(ZeroCameraMgr->Pos().x + 700, ZeroCameraMgr->Pos().y + 370);
		coco[0]->number[tmps / 1000]->SetPos(ZeroCameraMgr->Pos().x + 900, ZeroCameraMgr->Pos().y + 500);
		coco[1]->number[tmps / 100 % 10]->SetPos(ZeroCameraMgr->Pos().x + 920, ZeroCameraMgr->Pos().y + 500);
		coco[2]->number[tmps / 10 % 10]->SetPos(ZeroCameraMgr->Pos().x + 940, ZeroCameraMgr->Pos().y + 500);
		coco[3]->number[tmps % 10]->SetPos(ZeroCameraMgr->Pos().x + 960, ZeroCameraMgr->Pos().y + 500);
		yes->SetPos(ZeroCameraMgr->Pos().x + 700, ZeroCameraMgr->Pos().y + 550);
		no->SetPos(ZeroCameraMgr->Pos().x + 925, ZeroCameraMgr->Pos().y + 550);
	}
	party->SetPos((ZeroCameraMgr->Pos().x + 500), (ZeroCameraMgr->Pos().y + 300));
	entrance->SetPos((ZeroCameraMgr->Pos().x + 500), (ZeroCameraMgr->Pos().y + 300));
	graduate->SetPos((ZeroCameraMgr->Pos().x + 500), (ZeroCameraMgr->Pos().y + 300));
	canP->SetPos(ZeroCameraMgr->Pos().x + 500, ZeroCameraMgr->Pos().y + 200);
	if (monthlyRender)
	{
		monthly->SetPos((ZeroCameraMgr->Pos().x + 100), (ZeroCameraMgr->Pos().y + 200));
		monthlyS->SetPos((ZeroCameraMgr->Pos().x + 100), (ZeroCameraMgr->Pos().y + 200));
		monthlySo[0]->number[month / 10]->SetPos(ZeroCameraMgr->Pos().x + 250, ZeroCameraMgr->Pos().y + 250);
		monthlySo[1]->number[month % 10]->SetPos(ZeroCameraMgr->Pos().x + 270, ZeroCameraMgr->Pos().y + 250);
		monthlySo[2]->number[data->Dupmoney / 1000]->SetPos(ZeroCameraMgr->Pos().x + 260, ZeroCameraMgr->Pos().y + 300);
		monthlySo[3]->number[data->Dupmoney / 100 % 10]->SetPos(ZeroCameraMgr->Pos().x + 280, ZeroCameraMgr->Pos().y + 300);
		monthlySo[4]->number[data->Dupmoney / 10 % 10]->SetPos(ZeroCameraMgr->Pos().x + 300, ZeroCameraMgr->Pos().y + 300);
		monthlySo[5]->number[data->Dupmoney % 10]->SetPos(ZeroCameraMgr->Pos().x + 320, ZeroCameraMgr->Pos().y + 300);
	}
	overGame->SetPos(ZeroCameraMgr->Pos().x + 100, ZeroCameraMgr->Pos().y + 100);
	passmonth->SetPos((ZeroCameraMgr->Pos().x) + 1100, (ZeroCameraMgr->Pos().y) + 570);
	gameOver->SetPos(100, 100);
	if (endYearRender)
	{
		endYear->SetPos(ZeroCameraMgr->Pos().x + 450, ZeroCameraMgr->Pos().y + 100);
		peopleNum[0]->number[data->Dpeople / 100]->SetPos(ZeroCameraMgr->Pos().x + 680, ZeroCameraMgr->Pos().y + 312);
		peopleNum[1]->number[data->Dpeople / 10 % 10]->SetPos(ZeroCameraMgr->Pos().x + 700, ZeroCameraMgr->Pos().y + 312);
		peopleNum[2]->number[data->Dpeople % 10]->SetPos(ZeroCameraMgr->Pos().x + 720, ZeroCameraMgr->Pos().y + 312);
		happyNum[0]->number[data->Dhappy / 100]->SetPos(ZeroCameraMgr->Pos().x + 720, ZeroCameraMgr->Pos().y + 382);
		happyNum[1]->number[data->Dhappy / 10 % 10]->SetPos(ZeroCameraMgr->Pos().x + 740, ZeroCameraMgr->Pos().y + 382);
		happyNum[2]->number[data->Dhappy % 10]->SetPos(ZeroCameraMgr->Pos().x + 760, ZeroCameraMgr->Pos().y + 382);
		moneyNum[0]->number[data->endMoney / 1000]->SetPos(ZeroCameraMgr->Pos().x + 640, ZeroCameraMgr->Pos().y + 480);
		moneyNum[1]->number[data->endMoney / 100 % 10]->SetPos(ZeroCameraMgr->Pos().x + 660, ZeroCameraMgr->Pos().y + 480);
		moneyNum[2]->number[data->endMoney / 10 % 10]->SetPos(ZeroCameraMgr->Pos().x + 680, ZeroCameraMgr->Pos().y + 480);
		moneyNum[3]->number[data->endMoney % 10]->SetPos(ZeroCameraMgr->Pos().x + 700, ZeroCameraMgr->Pos().y + 480);
		yearNum[0]->number[2]->SetPos(ZeroCameraMgr->Pos().x + 620, ZeroCameraMgr->Pos().y + 145);
		yearNum[1]->number[0]->SetPos(ZeroCameraMgr->Pos().x + 640, ZeroCameraMgr->Pos().y + 145);
		yearNum[2]->number[yeartmp / 10]->SetPos(ZeroCameraMgr->Pos().x + 660, ZeroCameraMgr->Pos().y + 145);
		yearNum[3]->number[yeartmp % 10]->SetPos(ZeroCameraMgr->Pos().x + 680, ZeroCameraMgr->Pos().y + 145);
	}
		endConst->SetPos(ZeroCameraMgr->Pos().x + 700, ZeroCameraMgr->Pos().y + 100);
	for (int i = 0; i < 3; i++)
		cursor[i]->SetPos(ZeroInputMgr->GetClientPoint() + ZeroCameraMgr->Pos());
}

void GameScene::SetPos()
{
	background->SetPos(-1375, -300);
	construct[0]->mainSchool->SetPos(-290,-458);
	construct[1]->sideSchool->SetPos(-710, -458);
	construct[2]->sideSchool->SetPos(135, -458);
	construct[3]->cafeteria->SetPos(-1190, -310);
	construct[4]->gym->SetPos(360, -465);
	read->read[2]->SetPos(-290, -458);
	read->read[3]->SetPos(-710, -458);
	read->read[4]->SetPos(135, -458);
	read->read[0]->SetPos(-1190, -310);
	read->read[1]->SetPos(360, -465);
	for (int i = 0; i < 4; i++)
		tree[i]->SetPos(480, 230);
}
bool GameScene::overStruct()
{
	for (int i = 0; i < 4; i++)
	{
		if (tile->oneTile[46 + i * 15]->IsOverlapped(ZeroInputMgr->GetClientPoint()) || tile->oneTile[47 + i * 15]->IsOverlapped(ZeroInputMgr->GetClientPoint()))
		{
			return true;
		}
		else if (tile->oneTile[57 + i * 15]->IsOverlapped(ZeroInputMgr->GetClientPoint()) || tile->oneTile[58 + i * 15]->IsOverlapped(ZeroInputMgr->GetClientPoint()))
		{
			return true;
		}
	}
	for (int i = 0; i < 9; i++)
	{
		if (i < 3 && tile->oneTile[18 + i]->IsOverlapped(ZeroInputMgr->GetClientPoint()) || tile->oneTile[33 + i]->IsOverlapped(ZeroInputMgr->GetClientPoint()))
		{
			return true;
		}
		else if (i < 6 && tile->oneTile[18 + i]->IsOverlapped(ZeroInputMgr->GetClientPoint()) || tile->oneTile[33 + i]->IsOverlapped(ZeroInputMgr->GetClientPoint()))
		{
			return true;
		}
		else if (i < 9 && tile->oneTile[18 + i]->IsOverlapped(ZeroInputMgr->GetClientPoint()) || tile->oneTile[33 + i]->IsOverlapped(ZeroInputMgr->GetClientPoint()))
		{
			return true;
		}
	}
	return false;
}
bool GameScene::onStruct()
{
	for (int i = 0; i < 4; i++)
	{
		if (tile->oneTile[46 + i * 15]->IsOverlapped(ZeroInputMgr->GetClientPoint()) || tile->oneTile[47 + i * 15]->IsOverlapped(ZeroInputMgr->GetClientPoint()))
		{
			whereCon = 3;
			return true;
		}
		else if (tile->oneTile[57 + i * 15]->IsOverlapped(ZeroInputMgr->GetClientPoint()) || tile->oneTile[58 + i * 15]->IsOverlapped(ZeroInputMgr->GetClientPoint()))
		{
			whereCon = 4;
			return true;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (tile->oneTile[18 + i]->IsOverlapped(ZeroInputMgr->GetClientPoint()) || tile->oneTile[33 + i]->IsOverlapped(ZeroInputMgr->GetClientPoint()))
		{
			whereCon = 0;
			return true;
		}
	}
	for (int i = 3; i < 6; i++)
	{
		if (tile->oneTile[18 + i]->IsOverlapped(ZeroInputMgr->GetClientPoint()) || tile->oneTile[33 + i]->IsOverlapped(ZeroInputMgr->GetClientPoint()))
		{
			whereCon = 1;
			return true;
		}
	}
	for (int i = 6; i<9; i++)
	{
		if (tile->oneTile[18 + i]->IsOverlapped(ZeroInputMgr->GetClientPoint()) || tile->oneTile[33 + i]->IsOverlapped(ZeroInputMgr->GetClientPoint()))
		{
			whereCon = 2;
			return true;
		}
	}
	return false;
}
int GameScene::checkChoice()
{
	for (int i = 0; i < 4; i++)
		if (onwheretrip[i]->IsOverlapped(ZeroInputMgr->GetClientPoint()))
			return i;
	return -1;
}
int GameScene::checkPolicy()
{
	for (int i = 0; i < 6; i++)
		if (onpolicy[i]->IsOverlapped(ZeroInputMgr->GetClientPoint()))
			return i;
	return -1;
}
void GameScene::Event()
{
	End();
	once = false;
	monthlyRender = true;
	if (month == 4 || month == 6 || month == 9 || month == 10 || month == 11)
	{
		if (rand() % 101 + 1 <= 5)
		{
			data->Dhappy -= 15;
			showEvent[0] = true;
		}
	}
	if (data->Dhappy < 40)
	{
		if (rand() % 10 + 1)
		{
			data->Dthird -= rand() % 106 + 5;
			data->Dhappy -= 10;
			showEvent[1] = true;
		}
	}
	if (month == 4 && data->Devent[0] == 0)
	{
		if (rand() % 101 + 50 <= 50)
		{
			data->Devent[0] = 3;
			showEvent[2] = true;
		}
	}
	if (data->Dpolicy[5] != 0)
	{
		if (rand() % 10001 + 1 < data->Dpeople && data->Devent[1] && month == 8)
			data->Devent[1] = 1;
		showEvent[3] = true;
	}
	if (data->Dhappy < 0)
		isGameOver = true;
	for (int i = 0; i < 5; i++)
		if (data->Dncon[i] == 1)
			endConstRender = true;
	if (month == 12)
	{
		yeartmp = year;
		endYearRender = true;
		data->EndYear();
	}
	data->EndTurn();
	data->Reload();
}
void GameScene::CloseCheck()
{
	if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYDOWN)
	{
		if (policypopup->IsOverlapped(ZeroInputMgr->GetClientPoint()))
			policyRender = false;
		if (party->IsOverlapped(ZeroInputMgr->GetClientPoint()))
			partyRender = false;
		if (graduate->IsOverlapped(ZeroInputMgr->GetClientPoint()))
			graduateRender = false;
		if (entrance->IsOverlapped(ZeroInputMgr->GetClientPoint()))
			entranceRender = false;
		if (notice->IsOverlapped(ZeroInputMgr->GetClientPoint()) || conCheck->IsOverlapped(ZeroInputMgr->GetClientPoint()) && lucidRender == false)
			noticeRender = false;
	}
}

void GameScene::End()
{
	popupRender = false;
	noticeRender = false;
	monthlyRender = false;
	policyRender = false;
	entranceRender = false;
	graduateRender = false;
	partyRender = false;
	endConstRender = false;
	for (int i = 0; i < 4; i++)
		showEvent[i] = false;
}