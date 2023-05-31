#include <stdio.h>

int main()
{
    int saque, n100, n50, n10, n5;
    printf ("Qual o valor do saque? ");
    scanf ("%d", &saque);

    n100 = saque/100;
    saque = saque%100;
    n50 = saque/50;
    saque = saque%50;
    n10 = saque/10;
    saque = saque%10;
    n5 = saque/5;

    printf ("Foram entregues %d x 100, %d x 50, %d x 10, %d x 5", n100, n50, n10, n5);
}