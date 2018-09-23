#include "Lift_lib.h"
#include <Windows.h>

using namespace std;

namespace SLift
{
	//---------------------------------------------------------------------------------
	TLift::TLift()
	{
		level = 0;
		levelPeople = 0;
		levelPeopleNeed = 0;
		levelLift = 0;
		weithMax = 0;
		weithNow = 0;
	}

	//---------------------------------------------------------------------------------
	TLift:: TLift(TLift &L)
	{
		int kol = 30;
		level = L.level;
		weithMax = L.weithMax;
		levelLift = L.levelLift;
		weithNow = L.weithNow;
		if (kol != 0)
		{
			levelPeople = new int [kol];
			for (int i=0; i<kol; i++)
			{
				levelPeople[i]=L.levelPeople[i];
			}
		}
		else
			levelPeople = 0;

		if (kol != 0)
		{
			levelPeopleNeed = new int [kol];
			for (int i=0; i<kol; i++)
			{
				levelPeopleNeed[i]=L.levelPeopleNeed[i];
			}
		}
		else
			levelPeople = 0;
	}

	//---------------------------------------------------------------------------------
	TLift:: TLift(int lvl, int* lvlP, int* lvlPN, int lvlL, int weithM, int wn)
	{
		int kol = 30;
		level=lvl;
		weithMax = weithM;
		levelLift = lvlL;
		weithNow = wn;

		levelPeople = new int [kol];
		for (int i=0; i<kol; i++)
		{
			levelPeople[i] = lvlP[i];
		}

		levelPeopleNeed = new int [kol];
		for (int i=0; i<kol; i++)
		{
			levelPeopleNeed[i] = lvlPN[i];
		}

	}

	//---------------------------------------------------------------------------------
	TLift::~TLift()
	{
		if (levelPeople != 0)
			delete []levelPeople;
		levelPeople=0;

		if(levelPeopleNeed != 0)
			delete []levelPeopleNeed;
		levelPeopleNeed=0;
	}

	//---------------------------------------------------------------------------------
	void TLift::SetLevel(int lvl)
	{
		if (lvl>0)
		{
			level = lvl;
		}
	}

	//---------------------------------------------------------------------------------
	void TLift::SetWeithMax(int wm)
	{
		if (wm>0)
		{
			weithMax = wm;
		}
	}

	//---------------------------------------------------------------------------------
	void TLift::SetLevelLift(int lvlL)
	{
		if (lvlL>0)
		{
			levelLift = lvlL;
		}
	}

	//---------------------------------------------------------------------------------
	int TLift::GetLevel()
	{
		return level;
	}

	//---------------------------------------------------------------------------------
	int TLift::GetWeithMax()
	{
		return weithMax;
	}

	//---------------------------------------------------------------------------------
	int TLift::GetLevelLift()
	{
		return levelLift;
	}

	//---------------------------------------------------------------------------------
	void TLift::LiftClose()
	{
		int i=0;

		while (i=0)
		{
			cout << "���� ����� ���������� ��������.\n������� 1, ���� �������� ������ ������ �� ������ � 0 � ��������������� ������.\n";
			cin >> i;
			Sleep (5000);
		}

	}

	//---------------------------------------------------------------------------------
	void TLift::LiftWeith()
	{
		int weith=0;
		int sumweith=0;
		int j=0;

		cout << "������� ��������� ��� ���� ��������� ����������\n";
		cin >> weith;

		while (j=0)
		{
			sumweith = weithNow + weith;
			SetWeithNow(sumweith);

			if (sumweith > weithMax)
			{
				cout << "����������. ���������� ���������� ��������.\n������ ���������� ��������� ��������� ����� � ��������� ������������ �����.\n";
				cout << "������� ��� ��������� ���������\n";
				cin >> weith;
			}
			else
			{
				j=1;
			}
		}
	}

	//---------------------------------------------------------------------------------
	void TLift::Zapolnenie_Level_People_Need() 
	{ 
		int j = 1; 
		int a = 0; 
		while (j==1) 
		{ 
			cout << "������� ����, �� ������� ��� ���� ��������\n"; 
			cin >> a; 
			for (int k = 1; k < level; k++) 
			{ 
				if (k == a) 
					levelPeopleNeed[k] = 1; 
			} 
			cout << "���� �� ��� ����, ������� �� ������� ������ ����? (1 - ��)\n"; 
			cin >> j; 
		} 
	} 

	//---------------------------------------------------------------------------------
	void TLift:: Zapolnenie_Level_People() 
	{ 
		int j = 1; 
		int a = 0; 
		while (j == 1) 
		{ 
			cout << "������� ����, �� ������� �� ����������\n"; 
			cin >> a; 
			for (int k = 1; k < level; k++) 
			{ 
				if (k == a) 
					levelPeople[k] = 1; 
			} 
			cout << "���� �� ��� ����, ������� �� ������ ������ ������? (1 - ��)\n"; 
			cin >> j; 
		} 
	}

	//---------------------------------------------------------------------------------
	int TLift::Naxojdenie_Max_Etaja()
	{ 
		int i; 
		int a; 
		for (i = level; i > 0; i--) 
		{ 
			if (levelPeopleNeed[i] == 1) 
			{
				a = i; 
				i=0;
			}
		} 
		return a; 
	}

	//---------------------------------------------------------------------------------
	int TLift::FoundMInLevel () 
	{ 
		int max = 0;
		for (int i = 1; i <= level ; i++) 
			if (levelPeopleNeed[i]==1)
			{
				int min = i;
		return min; 
			} 
	} 

	//---------------------------------------------------------------------------------
	void TLift::LiftMovie()
	{

	}

}