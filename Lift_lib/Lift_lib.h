#pragma once
#include <iostream>

namespace SLift
{
	class TLift
	{
	protected:
		int level; //Количество этажей в доме
		int* levelPeople; //Массив где люди нажимают на кнопки
		int* levelPeopleNeed; //Массив куда людям нужно
		int levelLift; //Где лифт стоит
		int weithMax; //максимальный вес
		int weithNow;//Вес сейчас
	public:
		TLift();
		TLift(TLift &L);
		TLift(int lvl, int* lvlP, int* lvlPN, int lvlL, int weithM, int wn);
		~TLift();

		void SetLevel(int lvl);
		void SetWeithMax(int wm);
		void SetLevelLift(int lvlL);
		void SetWeithNow(int wn);

		int GetLevel();
		int GetWeithMax();
		int GetLevelLift();
		int GetWeithNow();

		void LiftCloseOpen(); //Попытка закрыть дверь
		void LiftWeith();//Метод "Выйдете у нас перевес"
		void Zapolnenie_Level_People_Need();
		void Zapolnenie_Level_People();
		int Naxojdenie_Max_Etaja_Visadit();
		int FoundMInLevelVisadit();
		int FoundMaxLevelZabrat();
		void LiftExitPeople();

		void LiftMovieUp();//Основной метод для движения лифта
		void LiftMovieDown();

	};
}


