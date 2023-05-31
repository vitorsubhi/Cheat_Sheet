/*
Objetivo: Ler um número e determinar se ele é impar, ou se ele é par.
Conhecimento necessário: O que é um número impar? Todo e qualquer número que não tenha um par.
Exemplos de números impar: 1, 3, 5, 7, 9, 11
Como certificar que um número não tenha um par? Se dividirmos um número por 2, e sobrar algum número sem par, logo ele é impar.
Ou seja, se dividirmos um número por 2, e tiver resto, logo ele não é par.

*/

#include <stdio.h>

int main ()
{
    int n1;
    printf ("Digite o número: ");
    scanf ("%d", &n1);

    if (n1 % 2 == 0)
        printf ("O número é par.");
    else
        printf ("O número é impar.");
}
