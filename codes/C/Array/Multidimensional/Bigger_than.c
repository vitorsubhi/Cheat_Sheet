/*

Desenvolva um programa que leia uma matriz 6 x 6 e escreva quantos valores maiores que N ela possui.
Obs: O valor de N será fornecido pelo usuário

*/

#include <stdio.h>

int main()
{
	int i, j, a[6][6], n, count=0;
	for (i = 0; i < 6; i++)
		for (j = 0; j < 6; j++)
		{
			printf ("Digite o valor da posição %d %d: ", i, j);
			scanf ("%d", &a[i][j]);
		}
			
	printf ("Digite o valor de N: ");
	scanf ("%d", &n);
	
	for (i = 0; i < 6; i++)
		for (j = 0; j < 6; j++)
			if(a[i][j] > n)
				count ++;

	printf("Existem %d números maiores do que %d", count, n);

	return 0;
}
