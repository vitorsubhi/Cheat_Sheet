#include <stdio.h>

int main()
{
    int n1,n2,n3,media;
    printf("Escreva a idade do primeiro aluno:");
    scanf ("%d",&n1);
    printf("Escreva a idade do segundo aluno:");
    scanf ("%d",&n2);
    printf("Escreva a idade do terceiro aluno:");
    scanf ("%d",&n3);
    media = (n1+n2+n3)/3;
    if (media <= 25)
	{
        printf("Turma Jovem");
    }
	else if (media > 25 && media < 40)
    {
        printf ("Turma Adulta");
    }
	else if (media >= 40)
	{
        printf ("Turma Idosa");
	}
   
	return 0;
}
