#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<math.h>
#include<time.h>
#include <Windows.h>

void main()
{

	setlocale(LC_ALL, "Rus");

	srand(time(NULL));

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int tn = 0;

start:

	printf("task number:\t");
	scanf("%d", &tn);

	switch (tn)
	{
	case 1:
	{
		int h, m, s;
		s = 0 +rand()% 86400;
		printf("\n%d seconds passed\n\n", s);
		h = s / 3600;
		m = (s % 3600) / 60;
		s = s % 3600 % 60;
		printf("%d hours %d minutes %d seconds\n\n", h, m, s);
	}
	break;
	case 2:
	{
		int x = 10 + rand() % 99999;
		printf("\n%d\n\n", x);
		int x1, x2, x3, x4, x5;
		
		if (x / 10000 != 0)
		{
			x1 = x % 10;
			x = x / 10;
			x2 = x % 10;
			x = x / 10;
			x3 = x % 10;
			x = x / 10;
			x4 = x % 10;
			x = x / 10;
			x5 = x % 10;
			printf("%d%d%d%d%d\n\n", x1, x2, x3, x4, x5);
		}
		else if (x / 1000 != 0)
		{
			x1 = x % 10;
			x = x / 10;
			x2 = x % 10;
			x = x / 10;
			x3 = x % 10;
			x = x / 10;
			x4 = x % 10;
			printf("%d%d%d%d\n\n", x1, x2, x3, x4);
		}
		else if (x / 100 != 0)
		{
			x1 = x % 10;
			x = x / 10;
			x2 = x % 10;
			x = x / 10;
			x3 = x % 10;
			printf("%d%d%d\n\n", x1, x2, x3);
		}
		else if (x / 10 != 0)
		{
			x1 = x % 10;
			x = x / 10;
			x2 = x % 10;
			printf("%d%d\n\n", x1, x2);
		}
	}
	break;
	case 3:
	{
		int n, x1, x2, x3, x4, x5;
		printf("\nenter 5-digit number:\t");
		scanf("%d", &n);
		if (n > 9999 && n < 100000)
		{
			x1 = n % 10;
			n = n / 10;
			x2 = n % 10;
			n = n / 100;
			x4 = n % 10;
			n = n / 10;
			x5 = n % 10;

			if (x1 == x5&&x2 == x4) printf("\ntrue, palindrom!\n\n");
			else printf("\nfalse, not a palindrom!\n\n");
		}
		else ("error, please enter only 5-digit number\n\n");
	}
	break;
	case 4:
	{
		/*int n, x;*/
		
	}
	break;
	case 5:
	{
		int score = 2 + rand() % 4;
		printf("\n%d\n\n", score);

		switch (score)
		{
		case 2: printf("\n�������������������\n\n");
			break;
		case 3: printf("\n�����������������\n\n");
			break;
		case 4: printf("\n������\n\n");
			break;
		case 5: printf("\n�������\n\n");
			break;
		}
	}
	break;
	case 6:
	{
		int n, x, y, z;
		printf("\nenter number of trips:\t");
		scanf("%d", &n);
		x = n / 60;
		y = n % 60 / 10;
		z = n % 60 % 10;
		//��������� ������� ������ ���� ����������, ������� ������� �� ��������� ��������:
		//4*125(���� ������ �� 10 �������)=500, ������ ���� ������ 30 �������, �������� ������ �� 1 ����� �� 440(���� ������ �� 60 �������), ��� 4 �� 10 �������
		//(9*15(����� �� 1 �������)=135, ������ ���� ������ 8 ��������� �������, �������� ����� ���� ����� �� 10, ��� 9 �� �����
		//�������� ������� ����������� �������� � ����� z (���-�� ��������� �������, �.�. ������ +1 ��������� � �����)
		if (z > 8)
		{
			y = y + 1;
			z = 0;
		}
		if (y > 3)
		{
			x = x + 1;
			y = 0;
			z = 0;
		}
		printf("%d tickets for 60 trips, %d tickets for 10 trips, %d tickets for 1 trip\n\n", x, y, z);
	}
	break;
	case 7:
	{

	}
	break;
	default:
		printf("\nerror: no tasks\n\n");
	}
	goto start;
}