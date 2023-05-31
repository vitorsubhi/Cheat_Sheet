/*

Construa um programa que leia um vetor de 15 posições e em
seguida um valor N qualquer. O programa deverá fazer uma busca pelo
valor de N no vetor lido e informar a posição (índice do vetor) em que N
foi encontrado ou se não foi encontrado.

*/

#include <stdio.h>

int main()
{
	int i, n, v[15], found;

	for (i=0; i<15; i++)
	{
		printf ("Digite o %dº número: ", i+1);
		scanf ("%d", &v[i]);
	}
	
	printf ("Digite o valor de N: ");
	scanf ("%d", &n);

	for (i=0; i<15; i++)
		if (v[i] == n)
		{
			printf ("Valor encontrado na posição %d\n", i);
			found = 1;
		}
	
	if (!found)
		printf ("Valor não encontrado");

	return 0;
}
