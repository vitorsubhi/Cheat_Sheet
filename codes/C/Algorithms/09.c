#include <stdio.h>

int main()
{
	char c;
	printf ("Digite um caracter: ");
	scanf ("%c", &c);

	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
	{
		printf ("%c é uma vogal.", c);
	} else
	{
		printf ("%c é uma consoante.", c);
	}
	return 0;
}
