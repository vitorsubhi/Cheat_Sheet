#include <stdio.h>

int main ()
{
    int numero;
    printf ("Digite um número: ");
    scanf ("%d", &numero);

    if (numero >= 20 && numero <= 90)
        printf ("%d está no intervalo de [20 a 90]", numero);
    else
        printf ("%d não está no intervalo de [20 a 90]", numero);
}