/*Jesús Arnoldo Zerecero Núñez
Universidad Autónoma de Guadalajara
"Uso de apuntadores a estructuras"*/

#include <stdio.h> 
#include <stdlib.h> 
 	struct Alumno{
		int numAlumno;
		char nombre[100];
		int expUAG;
		float calificaciones [3];
	};
	
void menu(void);
void capturaDatos(struct Alumno *apuntador);
void consulta(struct Alumno *apuntador);


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

void capturaDatos(struct Alumno *apuntador)
{
int y=0, z=0;
static int x = 0;

while (z < x)
{
	*apuntador++;
	z++;
}

		printf("\nIntroduzca numero de alumno entre 1 y 10:\n");
		scanf("%i", &apuntador->numAlumno);
		printf("Introduzca nombre del estudiante:\n");
		scanf("%s",apuntador->nombre);
		printf("Introduzca numero de expediente del alumno:\n");
		scanf("%i", &apuntador->expUAG);
		do
		{
			printf("Introduzca 3 calificaciones:\n");
			scanf("%f", &apuntador->calificaciones[y]);
			y++;
		} while (y!=3);
	x++;
return;
}

void consulta(struct Alumno *apuntador)
{
int alumno, x=0;
	printf("Introduzca numero de alumno para consultar:\n");
	scanf("%i", &alumno);
	
	do
	{
	 if (alumno == apuntador->numAlumno)
		{
			printf("\nNombre del alumno #%i: %s\n", alumno, apuntador->nombre);
			printf("Numero de expediente del alumno #%i: %i\n", alumno, apuntador->expUAG);
			printf("Promedio final del alumno #%i: %f\n", alumno, (apuntador->calificaciones[0]+apuntador->calificaciones[1]+apuntador->calificaciones[2])/3);
		}
	else
	{
	}
	x++;
	*apuntador++;
	}while (x!=5);
printf("\nTermino la consulta de datos\n");
return;
}