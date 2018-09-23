#pragma once
#include <iostream>

namespace SLift
{
	class TLift
	{
	protected:
		int level; //���������� ������ � ����
		int* levelPeople; //������ ��� ���� �������� �� ������
		int* levelPeopleNeed; //������ ���� ����� �����
		int levelLift; //��� ���� �����
		int weithMax; //������������ ���
		int weithNow;//��� ������
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

		void LiftCloseOpen(); //������� ������� �����
		void LiftWeith();//����� "������� � ��� �������"
		void Zapolnenie_Level_People_Need();
		void Zapolnenie_Level_People();
		int Naxojdenie_Max_Etaja_Visadit();
		int FoundMInLevelVisadit();
		int FoundMaxLevelZabrat();
		void LiftExitPeople();

		void LiftMovieUp();//�������� ����� ��� �������� �����
		void LiftMovieDown();

	};
}


