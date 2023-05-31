/*

Construa um programa que leia um vetor de 12 posições. Em seguida, some o valor do
primeiro elemento no segundo, o valor do segundo no terceiro e assim por diante. Como
resultado, escreva o vetor obtido.

*/

#include <stdio.h>

int main()
{
	int i, v[12];

	for (i=0; i<12; i++)
	{
		printf ("Digite o %dº número: ", i+1);
		scanf ("%d", &v[i]);
	}
	
	int n = v[0];
	for (i=1; i<12; i++)
	{
		v[i] = v[i] + n;
		n = v[i];
	}

	for (i=0; i<12; i++)
		printf ("%d ", v[i]);

	return 0;
}
