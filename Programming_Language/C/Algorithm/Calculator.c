#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int menu;
    float number[2], result = 1;
    char operator;
    int i;
    system ("title Calculadora");
    system ("color 0b");
    do {
        system ("cls");
        printf (" __________________________\n");
        printf ("|                          |\n");
        printf ("| 0 - Fechar a calculadora |\n");
        printf ("| 1 - Somar                |\n");
        printf ("| 2 - Subtrair             |\n");
        printf ("| 3 - Multiplicar          |\n");
        printf ("| 4 - Dividir              |\n");
        printf ("| 5 - Exponencial          |\n");
        printf ("| 6 - Fatorial             |\n");
        printf ("|__________________________|\nEscolha:");
        scanf ("%d", &menu);
        system ("cls");

        if (menu >= 1 && menu <= 6) {
            printf ("Digite o primeiro numero:");
            scanf ("%f", &number[0]);
            system ("cls");
            if (menu != 6) {
                printf ("Digite o segundo numero:");
                scanf ("%f", &number[1]);
                system ("cls");

                if (menu == 1){
                    result = number[0] + number[1];
                    operator = '+';
                }
                else if (menu == 2){
                    result = number[0] - number[1];
                    operator = '-';
                }
                else if (menu == 3){
                    result = number[0] * number[1];
                    operator = '*';
                }
                else if (menu == 4){
                    result = number[0] / number[1];
                    operator = '/';
                }
                else if (menu == 5){
                    for (i = 0; i < number[1]; i++)
                        result = result * number[0];
                    operator = '^';
                }

                if (number[1] == 0 && menu == 4)
                    printf ("Falha ao dividir %d por %d\n", number[0], number[1]);
                else
                    printf ("O resultado de %.2f %c %.2f = %.2f\n", number[0], operator, number[1], result);
            } else if (menu == 6){
                for (i = number[0]; i > 1; i--)
                    result = i * result;
                printf ("O resultado de %.2f! = %.2f\n", number[0], result);
            }
            system ("pause");
        }
        result = 1;
    } while (menu != 0);
}