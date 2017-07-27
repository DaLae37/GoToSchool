#include "DataManager.h"

DataManager::DataManager()
{
	ifstream data("Data/Money.txt");
	data >> Dmoney;
	data.close();
	data.open("Data/Pcan.txt");
	data >> Dcanp;
	data.close();
	data.open("Data/Day.txt");
	data >> Dday;
	data.close();
	data.open("Data/First.txt");
	data >> Dfirst;
	data.close();
	data.open("Data/Second.txt");
	data >> Dsecond;
	data.close();
	data.open("Data/Third.txt");
	data >> Dthird;
	data.close();
	data.open("Data/Happy.txt");
	data >> Dhappy;
	data.close();
	data.open("Data/Policy.txt");
	data >> Dpolicy[0];
	data.close();
	data.open("Data/Policy1.txt");
	data >> Dpolicy[1];
	data.close();
	data.open("Data/Policy2.txt");
	data >> Dpolicy[2];
	data.close();
	data.open("Data/Policy3.txt");
	data >> Dpolicy[3];
	data.close();
	data.open("Data/Policy4.txt");
	data >> Dpolicy[4];
	data.close();
	data.open("Data/Policy5.txt");
	data >> Dpolicy[5];
	data.close();
	data.open("Data/Event1.txt");
	data >> Devent[0];
	data.close();
	data.open("Data/Event2.txt");
	data >> Devent[1];
	data.close();
	data.open("Data/Dcon1.txt");
	data >> Dcon[0];
	data.close();
	data.open("Data/Dcon2.txt");
	data >> Dcon[1];
	data.close();
	data.open("Data/Dcon3.txt");
	data >> Dcon[2];
	data.close();
	data.open("Data/Dcon4.txt");
	data >> Dcon[3];
	data.close();
	data.open("Data/Dcon5.txt");
	data >> Dcon[4];
	data.close();
	data.open("Data/Dncon1.txt");
	data >> Dncon[0];
	data.close();
	data.open("Data/Dncon2.txt");
	data >> Dncon[1];
	data.close();
	data.open("Data/Dncon3.txt");
	data >> Dncon[2];
	data.close();
	data.open("Data/Dncon4.txt");
	data >> Dncon[3];
	data.close();
	data.open("Data/Dncon5.txt");
	data >> Dncon[4];
	data.close();
	Dpeople = Dfirst + Dsecond + Dthird;
	Dupmoney = 0;
}

DataManager::~DataManager()
{

}
void DataManager::Reload()
{
	ifstream data("Data/Money.txt");
	data >> Dmoney;
	data.close();
	data.open("Data/Pcan.txt");
	data >> Dcanp;
	data.close();
	data.open("Data/Day.txt");
	data >> Dday;
	data.close();
	data.open("Data/First.txt");
	data >> Dfirst;
	data.close();
	data.open("Data/Second.txt");
	data >> Dsecond;
	data.close();
	data.open("Data/Third.txt");
	data >> Dthird;
	data.close();
	data.open("Data/Happy.txt");
	data >> Dhappy;
	data.close();
	data.open("Data/Policy.txt");
	data >> Dpolicy[0];
	data.close();
	data.open("Data/Policy1.txt");
	data >> Dpolicy[1];
	data.close();
	data.open("Data/Policy2.txt");
	data >> Dpolicy[2];
	data.close();
	data.open("Data/Policy3.txt");
	data >> Dpolicy[3];
	data.close();
	data.open("Data/Policy4.txt");
	data >> Dpolicy[4];
	data.close();
	data.open("Data/Policy5.txt");
	data >> Dpolicy[5];
	data.close();
	data.open("Data/Event1.txt");
	data >> Devent[0];
	data.close();
	data.open("Data/Event2.txt");
	data >> Devent[1];
	data.close();
	data.open("Data/Dcon1.txt");
	data >> Dcon[0];
	data.close();
	data.open("Data/Dcon2.txt");
	data >> Dcon[1];
	data.close();
	data.open("Data/Dcon3.txt");
	data >> Dcon[2];
	data.close();
	data.open("Data/Dcon4.txt");
	data >> Dcon[3];
	data.close();
	data.open("Data/Dcon5.txt");
	data >> Dcon[4];
	data.close();
	data.open("Data/Dncon1.txt");
	data >> Dncon[0];
	data.close();
	data.open("Data/Dncon2.txt");
	data >> Dncon[1];
	data.close();
	data.open("Data/Dncon3.txt");
	data >> Dncon[2];
	data.close();
	data.open("Data/Dncon4.txt");
	data >> Dncon[3];
	data.close();
	data.open("Data/Dncon5.txt");
	data >> Dncon[4];
	data.close();
	Dpeople = Dfirst + Dsecond + Dthird;
}
void DataManager::Save()
{
	ofstream data("Data/Money.txt");
	data << Dmoney;
	data.close();
	data.open("Data/Pcan.txt");
	data << Dcanp;
	data.close();
	data.open("Data/Day.txt");
	data << Dday;
	data.close();
	data.open("Data/First.txt");
	data << Dfirst;
	data.close();
	data.open("Data/Second.txt");
	data << Dsecond;
	data.close();
	data.open("Data/Third.txt");
	data << Dthird;
	data.close();
	data.open("Data/Happy.txt");
	data << Dhappy;
	data.close();
	data.open("Data/Policy.txt");
	data << Dpolicy[0];
	data.close();
	data.open("Data/Policy1.txt");
	data << Dpolicy[1];
	data.close();
	data.open("Data/Policy2.txt");
	data << Dpolicy[2];
	data.close();
	data.open("Data/Policy3.txt");
	data << Dpolicy[3];
	data.close();
	data.open("Data/Policy4.txt");
	data << Dpolicy[4];
	data.close();
	data.open("Data/Policy5.txt");
	data << Dpolicy[5];
	data.close();
	data.open("Data/Event1.txt");
	data << Devent[0];
	data.close();
	data.open("Data/Event2.txt");
	data << Devent[1];
	data.close();
	data.open("Data/Dcon1.txt");
	data << Dcon[0];
	data.close();
	data.open("Data/Dcon2.txt");
	data << Dcon[1];
	data.close();
	data.open("Data/Dcon3.txt");
	data << Dcon[2];
	data.close();
	data.open("Data/Dcon4.txt");
	data << Dcon[3];
	data.close();
	data.open("Data/Dcon5.txt");
	data << Dcon[4];
	data.close();
	data.open("Data/Dncon1.txt");
	data << Dncon[0];
	data.close();
	data.open("Data/Dncon2.txt");
	data << Dncon[1];
	data.close();
	data.open("Data/Dncon3.txt");
	data << Dncon[2];
	data.close();
	data.open("Data/Dncon4.txt");
	data << Dncon[3];
	data.close();
	data.open("Data/Dncon5.txt");
	data << Dncon[4];
	data.close();
}

void DataManager::Reset()
{
	ofstream data("Data/Money.txt");
	data << 10000;
	data.close();
	data.open("Data/Pcan.txt");
	data << 0;
	data.close();
	data.open("Data/Day.txt");
	data << 1;
	data.close();
	data.open("Data/First.txt");
	data << 0;
	data.close();
	data.open("Data/Second.txt");
	data << 0;
	data.close();
	data.open("Data/Third.txt");
	data << 0;
	data.close();
	data.open("Data/Happy.txt");
	data << 50;
	data.close();
	data.open("Data/Policy.txt");
	data << 0;
	data.close();
	data.open("Data/Policy1.txt");
	data << 0;
	data.close();
	data.open("Data/Policy2.txt");
	data << 0;
	data.close();
	data.open("Data/Policy3.txt");
	data << 0;
	data.close();
	data.open("Data/Policy4.txt");
	data << 0;
	data.close();
	data.open("Data/Policy5.txt");
	data << 0;
	data.close();
	data.open("Data/Event1.txt");
	data << 0;
	data.close();
	data.open("Data/Event2.txt");
	data << 0;
	data.close();
	data.open("Data/Dcon1.txt");
	data << 0;
	data.close();
	data.open("Data/Dcon2.txt");
	data << 0;
	data.close();
	data.open("Data/Dcon3.txt");
	data << 0;
	data.close();
	data.open("Data/Dcon4.txt");
	data << 0;
	data.close();
	data.open("Data/Dcon5.txt");
	data << 0;
	data.close();
	data.open("Data/Dncon1.txt");
	data << 0;
	data.close();
	data.open("Data/Dncon2.txt");
	data << 0;
	data.close();
	data.open("Data/Dncon3.txt");
	data << 0;
	data.close();
	data.open("Data/Dncon4.txt");
	data << 0;
	data.close();
	data.open("Data/Dncon5.txt");
	data << 0;
	data.close();
}

void DataManager::EndTurn()
{
	Dday += 1;
	Dupmoney = Dhappy * 5 + rand() % 101 + 1;
	if (Dpolicy[0] != 0)
		Dupmoney += Dupmoney / 5;
	Dmoney += Dupmoney;
	for (int i = 0; i < 5; i++)
		if (Dncon[i] != 0)
			Dncon[i]--;
	Save();
}

void DataManager::Entrance()
{
	int youth = Dhappy * 2 + rand() % 101;;
	if (Dpolicy[1] != 0)
		youth += youth / 10;
	if (Dpolicy[2] != 0)
		youth += youth / 5;
	else
		youth = Dhappy * 2 + rand() % 101;
	Dthird = Dsecond;
	Dsecond = Dfirst;
	Dfirst = youth;
	Save();
	Reload();
}

void DataManager::Graduate()
{
	Dthird = 0;
	Save();
	Reload();
}

void DataManager::EndYear()
{
	if (Dhappy != 100)
		endMoney = Dhappy * 100;
	else
		endMoney = 9900;
}