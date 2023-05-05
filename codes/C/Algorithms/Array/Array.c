/*
Construa um programa que leia um vetor de 12 posições e atribua o valor 0 para todos
os elementos que possuírem valores negativos.
*/

#include <stdio.h>

int main()
{
	int i, v[12];
	for (i = 0; i < 12; i++)
	{
		printf ("Digite o %dº número: ", i+1);
		scanf ("%d", &v[i]);
		if (v[i] < 0)
			v[i] = 0;
	}

	for (i = 0; i < 12; i++)
		printf ("%d ", v[i]);
	return 0;
}
