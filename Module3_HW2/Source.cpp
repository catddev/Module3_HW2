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
		int x = 10 + rand() % 99990;
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
		int n, x;
		printf("\nPerfect numbers within given interval:\n\n");
		for (n = 1; n < 1000; n++)
		{
			x = pow(2, n) - 1;
			if (x == 3 || x == 7 || x == 31)  //�� ���� ������� ����� ��������
			{
				int p = pow(2, (n - 1))*(pow(2, n) - 1);
				printf("%d\n\n", p);
			}
		}	
	}
	break;
	case 5:
	{
		int score = 2 + rand() % 4;
		printf("\n%d\n\n", score);

		switch (score)
		{
		case 2: printf("\nнеудовлетворительно\n\n");
			break;
		case 3: printf("\nудовлетворительно\n\n");
			break;
		case 4: printf("\nхорошо\n\n");
			break;
		case 5: printf("\nотлично\n\n");
			break;
		}
	}
	break;
	case 6:
	{
		int n, x, y, z;
		//x - 440; y - 125, z - 15 
		printf("\nenter number of trips:\t");
		scanf("%d", &n);
		x = n / 60;
		y = n % 60 / 10;
		z = n % 60 % 10;
		//стоимость билетов должна быть минимальна, поэтому исходим из следующих расчетов:
		//4*125(цена билета за 10 поездок)=500, значит если больше 30 поездок, выгоднее купить на 1 билет за 440(цена билета на 60 поездок), чем 4 по 10 поездок
		//(9*15(билет на 1 поездку)=135, значит если больше 8 единичных поездок, выгоднее брать один билет на 10, чем 9 по одной
		//проверку условий обязательно начинать с числа z (кол-во единичных поездок, т.к. разряд +1 переходит с конца)
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
		printf("%d tickets for 60 trips \n%d tickets for 10 trips \n%d tickets for 1 trip\n\n", x, y, z);
	}
	break;
	case 7:
	{
		int n, t1, t5, t10, t20, t60;
		// t1 - 15, t5 - 70, t10 - 125, t20 - 230, t60 - 440
		printf("\nenter number of trips:\t");
		scanf("%d", &n);
		t60 = n / 60;
		t20 = n % 60 / 20;
		t10 = n % 60 % 20 / 10;
		t5 = n % 60 % 20 % 10 / 5;
		t1 = n % 60 % 20 % 10 % 5;

		if (n % 60 > 35) //if 36: 230+125+70+15=440 the same price for 60 trips
		{
			t60 = t60 + 1;
			t20 = 0;
			t10 = 0;
			t5 = 0;
			t1 = 0;
		}
		if (n % 60 % 20 > 17) //if 18: 125+70+15*3=240 > 230(price for 20 trips ticket)
		{
			t20 = t20 + 1;
			t10 = 0;
			t5 = 0;
			t1 = 0;
		}
		if (n % 60 % 20 % 10 > 8) //if 9: 70+15*4=130 > 125(price for 10 trips ticket)
		{
			t10 = t10 + 1;
			t5 = 0;
			t1 = 0;
		}
		printf("%d tickets for 60 trips \n%d tickets for 20 trips \n%d tickets for 10 trips \n%d tickets for 5 trips \n%d tickets for 1 trip\n\n", t60, t20, t10, t5, t1);
	}
	break;
	default:
		printf("\nerror: no tasks\n\n");
	}
	goto start;
}