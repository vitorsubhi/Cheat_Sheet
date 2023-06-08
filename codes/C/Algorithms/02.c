#include <stdio.h>

int main ()
{
    char nome[50];
    printf ("Digite o seu nome:");
    scanf ("%50s", nome);

    printf ("Seja bem-vindo(a) %s.", nome);
}