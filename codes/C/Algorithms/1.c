/*
 1 - Desenvolva um algoritmo em C, onde você receberá um número inteiro
 e mostrará o número digitado.
*/

#include <stdio.h>

int main ()
{
    int numero;
    printf ("Digite um numero inteiro:");
    scanf ("%d", &numero);

    printf ("O número digitado foi: %d", numero);
}
