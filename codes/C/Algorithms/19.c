#include <stdio.h>

int main()
{
	int n1, n2;
	printf ("Digite o primeiro número:");
	scanf ("%d", &n1);
	printf ("Digite o segundo número:");
	scanf ("%d", &n2);
	if (n1 > n2){
		printf ("O primeiro número é maior do que o segundo.");
	} else {
		printf ("O segundo número é maior do que o primeiro.");
	}
	return 0;
}
