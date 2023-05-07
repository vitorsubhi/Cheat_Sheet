/*

Construa um programa que leia uma matriz de tamanho 5 x 5 e escreva
a localização (linha, coluna) do maior valor encontrado na matriz

*/

#include <stdio.h>

int main()
{
	int i, j, m[5][5], maior=0;
	for (i = 0; i < 5; i++)
		for (j = 0; j < 5; j++)
		{
			printf ("Digite o valor da posição %d %d: ", i, j);
			scanf ("%d", &m[i][j]);
		}

	for (i = 0; i < 5; i++)
		for (j = 0; j < 5; j++)
			if (m[i][j] > maior)
				maior = m[i][j];

	printf ("O maior número é: %d", maior);
	return 0;
}
