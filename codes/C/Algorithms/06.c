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
