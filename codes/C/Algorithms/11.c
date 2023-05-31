#include <stdio.h>

int main()
{
    char turno;
    printf ("Digite o caracter correspondente ao turno de estudo:");
    scanf (" %c", &turno);

    if (turno == 'm')
    {
        printf ("Bom dia");
    }
    else if (turno == 'v')
    {
        printf ("Boa Tarde!");
    }
    else if (turno == 'n')
    {
        printf ("Boa Noite");
    }
    else {
        printf ("Valor inválido!");
    }
}