#include "Lift_lib.h"
#include <iostream>

using namespace std;
using namespace SLift;

void main()
{
	setlocale(LC_ALL, "Rus");
	TLift A;
	int etagi;
	int ves;
	int gde_stoit_lift;
	int i = 1;
	cout << "������� ���-�� ������\n";
	cin >> etagi;
	A.SetLevel(etagi);
	cout << "������� ������������ ���\n";
	cin >> ves;
	A.SetWeithMax(ves);
	cout << "������� ��������� �����\n";
	cin >> gde_stoit_lift;
	A.SetLevelLift(gde_stoit_lift);
	while (i == 1)
	{
		A.LiftMovieUp();
		A.LiftMovieDown();
		cout << "������� 0, ���� ������ ��� ����������\n";
		cin >> i;
	}
}
