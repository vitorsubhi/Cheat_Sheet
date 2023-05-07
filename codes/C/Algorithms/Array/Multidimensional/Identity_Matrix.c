/*

Construa um programa que declare uma matriz 5 x 5. Preencha com 1 a diagonal principal e com 0 os demais elementos (matriz identidade).
Como resultado escreva a matriz obtida

*/

#include <stdio.h>

int main()
{
	int i, j, m[5][5], maior=0;
	for (i = 0; i < 5; i++)
		for (j = 0; j < 5; j++)
			if (i == j)
				m[i][j] = 1;
			else
				m[i][j] = 0;

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
			printf ("%d ", m[i][j]);
		printf ("\n");
	}

	return 0;
}
