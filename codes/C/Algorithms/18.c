#include <stdio.h>

int main()
{
    int n1;
    printf ("Digite um número inteiro: ");
    scanf ("%d", &n1);
    if (n1 < 0)
    {
        printf ("Número negativo");
    }
    else if (n1 > 0)
    {
        printf ("Número positivo");
    }
    else
    {
        printf ("Zero");
    }
    return 0;
}