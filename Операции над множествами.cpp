#include <stdio.h>
#include <conio.h>

// ������� ��� ���������� �������� ��� �����������
// ���������:
// XA - ��������� �� ������ �������� ������������������ ������� ��� ��. A
// XB - ��������� �� ������ �������� ������������������ ������� ��� ��. B
// n - ���������� ��������� (��������) �������������� ���������
// Xres - ��������� �� ������ �������� ������������������ ������� ����������
// ��������� ���������� � ������ Xres

void sl(bool *XA, bool *XB, int n, bool *Xres);	// ��������
void pr(bool *XA, bool *XB, int n, bool *Xres);	// �����������
void rz(bool *XA, bool *XB, int n, bool *Xres);	// ��������
void sr(bool *XA, bool *XB, int n, bool *Xres);	// ��������������
												// ��������

main ()
{
	int i, n;				// n - �������� �������������� ��.
	char *U;				// ������������� ���������
	bool *XA, *XB, *Xres;	// ������������������ �������

	printf("n = ");
	scanf("%d", &n);
	
	// ������� �� ������������ ���� �������� U
	if(n <= 0 )
	{
		printf("\nWrong n");
		getch();
		return 0;
	}

	// �������� ������������ �������� �� ������ n
	U = new char[n];
	XA = new bool[n];
	XB = new bool[n];
	Xres = new bool[n];

	// ���������� �������������� ���������
	printf("\nU = ");
	for(i = 0; i < n; i++)
		scanf(" %c", &(U[i]));

	// ���� ������������������ ������� ��������� A
	printf("\nXA = ");
	for(i = 0; i < n; i++)
		scanf(" %d", &(XA[i]));

	// ���� ������������������ ������� ��������� B
	printf("\nXB = ");
	for(i = 0; i < n; i++)
		scanf(" %d", &(XB[i]));

	// ���� ������ ��������
	printf("\nSelect the operation (sl - 1, pr - 2, rz - 3, sr - 4) ");
	scanf(" %d", &i);

	// ������� �� ������������ ����� ��������
	if(i < 1 || i > 4)
	{
		printf("\nWrong input");
		getch();
		return 0;
	}

	// ���������� �������� � ������������ � �� �������
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

	// ����� ������������������ ������� ����������
	printf("\nAnswer:\nXres = ");
	for(i = 0; i < n; i++)
		printf("%d ", Xres[i]);

	// ����� ��������� - ���������� ��������
	printf("\nC = {");
	for(i = 0; i < n; i++)
		if(Xres[i]) printf("%c ", U[i]);
	printf("}");
	getch();

	// ������� ������, ���������� ��� ������������ �������
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