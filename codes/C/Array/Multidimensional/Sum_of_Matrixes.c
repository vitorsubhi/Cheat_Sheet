/*

Construa um programa que leia duas matrizes 3 x 3. Crie uma terceira matriz a partir dos maiores elementos das matrizes lidas.

*/

#include <stdio.h>

int main()
{
	int i, j, a[3][3], b[3][3], c[3][3];
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			printf ("Digite o valor da posição %d %d: ", i, j);
			scanf ("%d", &a[i][j]);
		}
			
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			printf ("Digite o valor da posição %d %d: ", i, j);
			scanf ("%d", &b[i][j]);
		}

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (a[i][j] > b[i][j])
				c[i][j] = a[i][j];
			else
				c[i][j] = b[i][j];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			printf ("%d ", c[i][j]);
		printf ("\n");
	}

	return 0;
}
