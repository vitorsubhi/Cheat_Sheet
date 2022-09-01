#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	FILE *fp;
	char filename[50];
	int i, j;

	scanf ("%s", &filename[0]);
	fp = fopen (filename, "w");

	scanf ("%d", &j); //Quantidade de números aleatórios a serem gerados.

	srand(time(NULL)); //Gerar sementes aleatórias.
	fprintf (fp, "%d ", j);
	for(i = 0; i < j ; i++)
	{
		printf ("Gerando %d número aleatório.\n", i+1);
		fprintf (fp, "%d ", rand()); //Salvar em arquivo, número gerado.
	}
	printf ("Arquivo %s, com %d números aleatórios gerados.\n", filename, j);
}
