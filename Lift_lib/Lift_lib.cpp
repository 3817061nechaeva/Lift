#include "Lift_lib.h"
#include <Windows.h>

using namespace std;

namespace SLift
{
	//---------------------------------------------------------------------------------
	TLift::TLift()
	{
		int kol = 30;
		if (kol != 0)
		{
			levelPeople = new int[kol];
			for (int i = 0; i<kol; i++)
			{
				levelPeople[i] = 0;
			}
		}
		level = 0;
		if (kol != 0)
		{
			levelPeopleNeed = new int[kol];
			for (int i = 0; i<kol; i++)
			{
				levelPeopleNeed[i] = 0;
			}
		}
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
		for (int i=0; i<=kol; i++)
		{
			levelPeople[i] = lvlP[i];
		}

		levelPeopleNeed = new int [kol];
		for (int i=0; i<=kol; i++)
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
		if (lvl>=0)
		{
			level = lvl;
		}
	}

	//---------------------------------------------------------------------------------
	void TLift::SetWeithMax(int wm)
	{
		if (wm>=0)
		{
			weithMax = wm;
		}
	}
	//---------------------------------------------------------------------------------
	void TLift::SetLevelLift(int lvlL)
	{
		if (lvlL>=0)
		{
			levelLift = lvlL;
		}
	}
	//---------------------------------------------------------------------------------
	void TLift::SetWeithNow(int wn)
	{
		if (wn>=0)
		{
			levelLift = wn;
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
	void TLift::LiftCloseOpen()
	{
		int i=0;

		while (i=0)
		{
			cout << "Открытие/Закрытие дверей\n";
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

		cout << "Введите суммарный вес всех вошедших пассажиров\n";
		cin >> weith;

		while (j=0)
		{
			sumweith = weithNow + weith;
			SetWeithNow(sumweith);

			if (sumweith > weithMax)
			{
				cout << "Перегрузка. Невозможно продолжать движение.\nПросим последнего зашедшего пассажира выйти и дождаться освобождения лифта.\n";
				cout << "Введите вес вышедшего пассажира\n";
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
			cout << "Введите этаж, на который вам надо приехать\n"; 
			cin >> a; 
			for (int k = 0; k <= level; k++) 
			{ 
				if (k == a) 
					levelPeopleNeed[k] = 1; 
			} 
			cout << "Есть ли ещё люди, которые не выбрали нужный этаж? (1 - да)\n"; 
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
			cout << "Введите этаж, на котором вы находитесь\n"; 
			cin >> a; 
			for (int k = 0; k <= level; k++) 
			{ 
				if (k == a) 
					levelPeople[k] = 1; 
			} 
			cout << "Есть ли ещё люди, которые не нажали кнопку вызова? (1 - да)\n"; 
			cin >> j; 
		} 
	}

	//---------------------------------------------------------------------------------
	int TLift::Naxojdenie_Max_Etaja_Visadit()
	{ 
		int i; 
		int a = 0; 
		for (i = level; i >= 0; i--) 
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
	int TLift::FoundMInLevelVisadit() 
	{ 
		int min = 0;
		for (int i = 0; i <= level ; i++) 
			if (levelPeopleNeed[i]==1)
			{
				min = i;
			} 
		return min;
	} 
	//---------------------------------------------------------------------------------
	int TLift::FoundMaxLevelZabrat()
	{
		int i;
		int a = 0;
		for (i = level; i >= 0; i--)
		{
			if (levelPeople[i] == 1)
			{
				a = i;
				i = 0;
			}
		}
		return a;
	}
	//---------------------------------------------------------------------------------
	void TLift::LiftExitPeople()
	{
		int weith = 0;
		int sumweith = 0;
		int j = 0;

		cout << "Введите суммарный вес всех вышедших пассажиров\n";
		cin >> weith;

		while (j = 0)
		{
			sumweith = weithNow - weith;
			SetWeithNow(sumweith);
		}
	}
	//---------------------------------------------------------------------------------
	void TLift::LiftMovieUp()
	{
		levelLift = 0;
		weithNow = 0;
		Zapolnenie_Level_People();
		for (int i = 0; i <= FoundMaxLevelZabrat(); i++)
		{
			if (levelPeople[i] == 1)
			{
				levelPeople[i] = 0;
				levelLift = i;
				cout << "Лифт приехал на " << i << "этаж\n";
				LiftCloseOpen();
				if (levelPeopleNeed[i] == 1)
				{
					levelPeopleNeed[i] = 0;
					LiftExitPeople();
				}
				LiftWeith();
				Zapolnenie_Level_People_Need();
				LiftCloseOpen();
			}
		}
		for (int i = FoundMaxLevelZabrat(); i <= Naxojdenie_Max_Etaja_Visadit(); i++)
		{
			if (levelPeopleNeed[i] == 1)
			{
				levelLift = i;
				cout << "Лифт приехал на " << i << "этаж\n";
				LiftCloseOpen();
				levelPeopleNeed[i] = 0;
				LiftExitPeople();
				LiftCloseOpen();
			}
		}
	}
	void TLift::LiftMovieDown()
	{
		int i;
		if (FoundMaxLevelZabrat() <= Naxojdenie_Max_Etaja_Visadit())
			i = Naxojdenie_Max_Etaja_Visadit();
		else
			i = FoundMaxLevelZabrat();
		for (i; i <= FoundMInLevelVisadit(); i++)
		{
			if (levelPeople[i] == 1)
			{
				levelPeople[i] = 0;
				levelLift = i;
				cout << "Лифт приехал на " << i << "этаж\n";
				LiftCloseOpen();
				if (levelPeopleNeed[i] == 1)
				{
					levelPeopleNeed[i] = 0;
					LiftExitPeople();
				}
				LiftWeith();
				Zapolnenie_Level_People_Need();
				LiftCloseOpen();
			}
		}
	}
}