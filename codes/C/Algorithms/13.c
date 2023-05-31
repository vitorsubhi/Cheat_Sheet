#include <stdio.h>

int main()
{
    int numero, c, d, u;
    scanf ("%d", &numero);
    printf ("Digite um número menor do que 1000:");
    if (numero < 1000){
        c = numero/100;
        d = (numero%100)/10;
        u = numero%10;

        printf ("%d centenas, %d dezenas, %d unidades", c, d, u);
    }
    else{
        printf ("Numero invalido");
    }
}
