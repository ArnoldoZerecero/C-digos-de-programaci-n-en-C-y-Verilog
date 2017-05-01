/*Jesús Arnoldo Zerecero Núñez
Universidad Autónoma de Guadalajara
"Operaciones lógicas y manipulación de bits"*/

#include <stdio.h>
int funcion (int, int, int, int);


int main(void)
{
int num1, num2, num3, num4;
int resultado, resta2, resta3, resta4;
printf("Introduzca 4 numeros menores a 255\n");
scanf("%i%i%i%i", &num1, &num2, &num3, &num4);

resultado = funcion (num1, num2, num3, num4);

printf("El codigo es %x\n", resultado);

num1= resultado>>24;

num2= resultado>>16;
resta2= num2>>8;
resta2= resta2<<8;
num2= num2-resta2;

num3= resultado>>8;
resta3= num3>>8;
resta3= resta3<<8;
num3= num3-resta3;

resta4= resultado>>8;
resta4= resta4<<8;
num4= resultado-resta4;

printf("Los numeros iniciales, devueltos desde la funcion, son: %i.%i.%i.%i", num1, num2, num3, num4);

	return 0;
}
int funcion(int num1, int num2, int num3, int num4)
{

int w, x, y, z;

w= num1<<24;
x= num2<<16;
y= num3<<8;
z= w|x|y|num4;
	
return z;
}