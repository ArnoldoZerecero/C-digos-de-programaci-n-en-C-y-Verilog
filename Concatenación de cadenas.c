/*Jesús Arnoldo Zerecero Núñez
Universidad Autónoma de Guadalajara
"Concatenación de cadenas"*/
#include <stdio.h>
void funcion (char *, char *);

int main(void)
{
char cad1[50], cad2[50];
printf("Introduzca 2 palabras\n");
gets (cad1);
gets (cad2);

funcion(cad1, cad2);
	puts (cad1);
return 0;
}

void funcion (char *cad1, char *cad2)
{
	while (*cad1)
		{ 
			*cad1++;
		}
		
	while (*cad2)
		{ 
			*cad1= *cad2;
			*cad1++;
			*cad2++;
		}
	printf("Las cadenas combinadas son:  ");

return;
}