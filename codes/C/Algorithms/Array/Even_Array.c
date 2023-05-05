/*

Desenvolva um programa que leia um vetor de 15 posições. Em
seguida o programa deverá contar e escrever quantos valores pares foi
encontrado no vetor lido.

*/

#include <stdio.h>

int main()
{
	int i, v[15], found;

	for (i=0; i<15; i++)
	{
		printf ("Digite o %dº número: ", i+1);
		scanf ("%d", &v[i]);
	}
	
	for (i=0; i<15; i++)
		if (v[i] % 2 == 0)
			found ++;

	printf ("Foram encontrados %d números pares.", found);

	return 0;
}
