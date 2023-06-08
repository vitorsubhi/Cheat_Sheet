#include <stdio.h>
#include <string.h>

int main ()
{
    char senha[7];
    printf ("Digite a senha: ");
    scanf ("%7s", senha);

    if (strcmp(senha, "eh4nois") == 0)
        printf ("Acesso permitido");
    else
        printf ("Você não tem acesso ao sistema");
}