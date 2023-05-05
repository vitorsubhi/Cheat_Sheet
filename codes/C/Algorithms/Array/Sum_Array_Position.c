/*

Construa um programa que leia um vetor de 10 posições. Em seguida leia dois valores quaisquer X e Y,
correspondentes a duas posições no vetor. Como resultado, o programa deverá escrever a soma dos valores
encontrados nas posições X e Y

*/

#include <stdio.h>

int main()
{
	int i, v[10], x, y;
	for (i=0; i<10; i++)
	{
		printf ("Digite o %dº número: ", i+1);
		scanf ("%d", &v[i]);
	}

	printf ("Digite o 1º valor: ");
	scanf ("%d", &x);

	printf ("Digite o 2º valor: ");
	scanf ("%d", &y);

	if (x > 0 && x < 11 && y >0 && y < 11)
		printf ("%d", v[x]+v[y]);
	else
		printf ("Valor inesperado");
	
	return 0;
}
