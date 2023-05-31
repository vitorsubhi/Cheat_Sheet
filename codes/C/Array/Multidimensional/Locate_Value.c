/*

Construa um programa que leia uma matriz 2 x 7. O programa deverá fazer uma busca de um valor N na matriz e,
omo resultado, escrever a localização (linha, coluna) do elemento. Caso o valor de N não constar na matriz lida,
o programa deverá mostrar uma mensagem de “Elemento não encontrado”.
Obs: O valor de N será fornecido pelo usuário.

*/

#include <stdio.h>

int main()
{
	int i, j, a[2][7], n, count=0;
	for (i = 0; i < 2; i++)
		for (j = 0; j < 7; j++)
		{
			printf ("Digite o valor da posição %d %d: ", i, j);
			scanf ("%d", &a[i][j]);
		}
			
	printf ("Digite o valor de N:");
	scanf ("%d", &n);
	
	for (i = 0; i < 2; i++)
		for (j = 0; j < 7; j++)
			if(a[i][j] == n)
			{
				printf ("Linha %d, Coluna %d\n", i, j);
				count = 1;
			}

	if (!count)
		printf ("Elemento não encontrado");


	return 0;
}
