#include <stdio.h>
#include <conio.h>

// Функции для выполнения операций над множествами
// Параметры:
// XA - указатель на массив значений характеристической функции для мн. A
// XB - указатель на массив значений характеристической функции для мн. B
// n - количество элементов (мощность) универсального множества
// Xres - указатель на массив значений характеристической функции результата
// Результат помещается в массив Xres

void sl(bool *XA, bool *XB, int n, bool *Xres);	// Сложение
void pr(bool *XA, bool *XB, int n, bool *Xres);	// Пересечение
void rz(bool *XA, bool *XB, int n, bool *Xres);	// Разность
void sr(bool *XA, bool *XB, int n, bool *Xres);	// Симметрическая
												// разность

main ()
{
	int i, n;				// n - мощность универсального мн.
	char *U;				// универсальное множество
	bool *XA, *XB, *Xres;	// характеристические функции

	printf("n = ");
	scanf("%d", &n);
	
	// Реакция на неправильный ввод мощности U
	if(n <= 0 )
	{
		printf("\nWrong n");
		getch();
		return 0;
	}

	// Создание динамических массивов на основе n
	U = new char[n];
	XA = new bool[n];
	XB = new bool[n];
	Xres = new bool[n];

	// Заполнение универсального множества
	printf("\nU = ");
	for(i = 0; i < n; i++)
		scanf(" %c", &(U[i]));

	// Ввод характеристической функции множества A
	printf("\nXA = ");
	for(i = 0; i < n; i++)
		scanf(" %d", &(XA[i]));

	// Ввод характеристической функции множества B
	printf("\nXB = ");
	for(i = 0; i < n; i++)
		scanf(" %d", &(XB[i]));

	// Ввод номера операции
	printf("\nSelect the operation (sl - 1, pr - 2, rz - 3, sr - 4) ");
	scanf(" %d", &i);

	// Реакция на неправильный номер операции
	if(i < 1 || i > 4)
	{
		printf("\nWrong input");
		getch();
		return 0;
	}

	// Выполнение операции в соответствии с ее номером
	switch(i)
	{
	case 1:
		sl(XA, XB, n, Xres);
		break;
	
	case 2:
		pr(XA, XB, n, Xres);
		break;

	case 3:
		rz(XA, XB, n, Xres);
		break;

	case 4:
		sr(XA, XB, n, Xres);
		break;
	}

	// Вывод характеристической функции результата
	printf("\nAnswer:\nXres = ");
	for(i = 0; i < n; i++)
		printf("%d ", Xres[i]);

	// Вывод множества - результата операции
	printf("\nC = {");
	for(i = 0; i < n; i++)
		if(Xres[i]) printf("%c ", U[i]);
	printf("}");
	getch();

	// Очистка памяти, отведенной под динамические массивы
	delete U, XA, XB, Xres;
	return 0;
}

void sl(bool *XA, bool *XB, int n, bool *Xres)
{
	int i;
	bool max;
	for(i = 0; i < n; i++)
	{
		max = XA[i];
		if(XB[i] > max) max = XB[i];
		Xres[i] = max;
	}
	return;
}

void pr(bool *XA, bool *XB, int n, bool *Xres)
{
	int i;
	bool min;
	for(i = 0; i < n; i++)
	{
		min = XA[i];
		if(XB[i] < min) min = XB[i];
		Xres[i] = min;
	}
	return;
}

void rz(bool *XA, bool *XB, int n, bool *Xres)
{
	int i;
	bool max;
	for(i = 0; i < n; i++)
	{
		max = 0;
		if(XA[i] - XB[i] > max) max = XA[i] - XB[i];
		Xres[i] = max;
	}
	return;
}

void sr(bool *XA, bool *XB, int n, bool *Xres)
{
	int i;
	bool max;
	for(i = 0; i < n; i++)
	{
		max = XA[i] - XB[i];
		if(XB[i] - XA[i] > max) max = XB[i] - XA[i];
		Xres[i] = max;
	}
	return;
}