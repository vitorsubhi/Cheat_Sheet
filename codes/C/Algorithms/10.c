#include <stdio.h>
#include <string.h>

int main ()
{
    float p1, p2, p3, a;
    printf ("Digite o valor de p1:");
    scanf ("%f", &p1);

    printf ("Digite o valor de p2:");
    scanf ("%f", &p2);

    printf ("Digite o valor de p3:");
    scanf ("%f", &p3);

    if (p1 < p2 && p1 < p3)
        printf ("Compre p1");
    else if (p2 < p1 && p2 < p3)
        printf ("Compre p2");
    else
        printf ("Compre p3");
}