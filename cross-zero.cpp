#include <stdio.h>
#include <conio.h>
#include <iostream>

void mas_out(int **a, int n);
int **mas_memory(int n);
void mas_memory_out(int **a, int n);
int proverka(int **a, int n);
void mas_null(int **a, int n);

int main(void) {
	setlocale(LC_ALL, ".1251");
	int **a = mas_memory(3);
	mas_null(a, 3);
	int *b = new int[3 * 3 + 1];
	int dl = 3 * 3 + 1;
	int i, z, hod = 0, rez = 0;
	for (i = 0; i < 10; i++) b[i] = i + 1;

	char *n[10] = { "a1","a2","a3","b1","b2","b3","c1","c2","c3","Сдаться" };

	mas_out(a, 3);
	printf("\n");
	for (i = 0; i < dl - 1; i++) {
		if (hod % 2 == 0) printf("%d. Поставить X в ячейку %s\n", i + 1, n[i]);
		else printf("%d. Поставить O в ячейку %s\n", i + 1, n[i]);
	}
	printf("%d. %s\n\n", dl, n[dl - 1]);

	for (;;) {
		scanf_s("%d", &z);
		if (z > dl) printf("\nВыберете ещё раз действие\n\n");
		else if (z == dl) printf("\nВы вышли. Спасибо за игру!\n");
		else {
			switch (b[z - 1]) {
			case(1):
				if (hod % 2 == 0) a[0][0] = 1;
				else a[0][0] = 2;
				mas_out(a, 3);
				break;
			case(2):
				if (hod % 2 == 0) a[0][1] = 1;
				else a[0][1] = 2;
				mas_out(a, 3);
				break;
			case(3):
				if (hod % 2 == 0) a[0][2] = 1;
				else a[0][2] = 2;
				mas_out(a, 3);
				break;
			case(4):
				if (hod % 2 == 0) a[1][0] = 1;
				else a[1][0] = 2;
				mas_out(a, 3);
				break;
			case(5):
				if (hod % 2 == 0) a[1][1] = 1;
				else a[1][1] = 2;
				mas_out(a, 3);
				break;
			case(6):
				if (hod % 2 == 0) a[1][2] = 1;
				else a[1][2] = 2;
				mas_out(a, 3);
				break;
			case(7):
				if (hod % 2 == 0) a[2][0] = 1;
				else a[2][0] = 2;
				mas_out(a, 3);
				break;
			case(8):
				if (hod % 2 == 0) a[2][1] = 1;
				else a[2][1] = 2;
				mas_out(a, 3);
				break;
			case(9):
				if (hod % 2 == 0) a[2][2] = 1;
				else a[2][2] = 2;
				mas_out(a, 3);
				break;
			case(10):
				printf("\nВы вышли\n");
				break;
			}
			rez = proverka(a, 3);
			if (rez == 1) {
				printf("\n* * *\n\nВыиграл 1 игрок\n");
				break;
			}
			else if (rez == 2) {
				printf("\n* * *\n\nВыиграл 2 игрок\n");
				break;
			}
			else if (rez == 3) {
				printf("\n* * *\n\nНичья\n");
				break;
			}
			else {
				hod++;
				for (i = z - 1; i < dl - 1; i++)
					b[i] = b[i + 1];
				for (i = z - 1; i < dl - 1; i++)
					n[i] = n[i + 1];
				dl--;

				printf("\n");
				for (i = 0; i < dl - 1; i++) {
					if (hod % 2 == 0) printf("%d. Поставить X в ячейку %s\n", i + 1, n[i]);
					else printf("%d. Поставить O в ячейку %s\n", i + 1, n[i]);
				}
				printf("%d. %s\n\n", dl, n[dl - 1]);
			}
		}
	}
	mas_memory_out(a, 3);
	_getch();
}

int **mas_memory(int n) {
	int **a = new int*[n];
	for (int i = 0; i < n; i++) a[i] = new int[n];
	return a;
}

void mas_memory_out(int **a, int n) {
	for (int i = 0; i<n; i++) delete(a[i]);
	delete[] a;
}

void mas_out(int **a, int n) {
	printf("     1   2   3\n");
	//так как всего 3х3, то быквы тоже три, если больше, то массив буков и там уже по i
	for (int i = 0; i < n; i++) {
		printf("   +---+---+---+\n");
		if (i == 0) printf(" a ");
		else if (i == 1) printf(" b ");
		else printf(" c ");
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1) printf("| X ");
			else if (a[i][j] == 2) printf("| O ");
			else printf("|   ");
		}
		printf("|\n");
	}
	printf("   +---+---+---+\n");
}

int proverka(int **a, int n) {
	int i,j,rez=0;
	if ((a[0][0] == 1&& a[1][1] ==1&& a[2][2] == 1) || (a[0][2] ==1&& a[1][1] ==1&& a[2][0] == 1)) rez=1;
	else if ((a[0][0] ==2&& a[1][1] ==2&& a[2][2] == 2) || (a[0][2] ==2&& a[1][1] ==2&& a[2][0] == 2)) rez=2;
	else {
		for (i = 0; i < n; i++) {
			if ((a[i][0] == 1&&a[i][1] ==1&& a[i][2] == 1) || (a[0][i] ==1&& a[1][i] == 1&& a[2][i] == 1)) rez=1;
			else if ((a[i][0] == 2 && a[i][1] == 2 && a[i][2] == 2) || (a[0][i] ==2 && a[1][i] ==2 && a[2][i] == 2)) rez=2;
			else rez= 0;
		}
	}
	int k=0;
	if (rez == 0) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (a[i][j] != 0) k++;
			}
		}
	}
	if (k == n*n) rez = 3;

	return rez;
	
}

void mas_null(int **a, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) a[i][j] = 0;
	}
}
