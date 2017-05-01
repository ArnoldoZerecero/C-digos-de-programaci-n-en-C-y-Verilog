/*Jesús Arnoldo Zerecero Núñez
Universidad Autónoma de Guadalajara
"Ejemplo de arreglos de estructuras"*/
#include <stdio.h> 
#include <stdlib.h> 
 	struct Alumno{
		int numAlumno;
		char nombre[100];
		int expUAG;
		float calificaciones [3];
	};
	
void menu(void);
void capturaDatos(struct Alumno cadena[]);
void consulta(struct Alumno cadena[]);

int main(void)
{

menu();
return 0;
}

void menu()
{
int opcion;
	struct Alumno cadena[5];
	
do
{
printf("1.Capturar datos de alumnos\n2.Consultar por numero de alumno\n3.Salir del programa\n");
scanf("%i", &opcion);

switch(opcion)
{
	case 1:
	capturaDatos(cadena);
	break;
	case 2:
	consulta(cadena);
	break;
	case 3:
	exit(0);
	break;
	default:
	printf("Opcion no valida\n");
	break;
}
}while (opcion!=3);
return;
}

void capturaDatos(struct Alumno cadena[])
{
static int x=0;
int y=0;

		printf("\nIntroduzca numero de alumno entre 1 y 10:\n");
		scanf("%i", &cadena[x].numAlumno);
		printf("Introduzca nombre del estudiante:\n");
		scanf("%s",&cadena[x].nombre);
		printf("Introduzca numero de expediente del alumno:\n");
		scanf("%i", &cadena[x].expUAG);
		do
		{
			printf("Introduzca 3 calificaciones:\n");
			scanf("%f", &cadena[x].calificaciones[y]);
			y=y+1;
		} while (y!=3);
	x++;
return;
}

void consulta(struct Alumno cadena[])
{
int alumno, x=0;
	printf("Introduzca numero de alumno para consultar:\n");
	scanf("%i", &alumno);
	
	do
	{
	 if (alumno == cadena[x].numAlumno)
		{
			printf("\nNombre del alumno #%i: %s\n", alumno, cadena[x].nombre);
			printf("Numero de expediente del alumno #%i: %i\n", alumno, cadena[x].expUAG);
			printf("Promedio final del alumno #%i: %f\n", alumno, (cadena[x].calificaciones[0]+cadena[x].calificaciones[1]+cadena[x].calificaciones[2])/3);
		}
	else
	{
	}
	x=x+1;
	}while (x!=5);
printf("\nTermino la consulta de datos\n");
return;
}