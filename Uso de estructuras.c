/*Jesús Arnoldo Zerecero Núñez
Universidad Autónoma de Guadalajara
"Uso de estructuras"*/

#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"

struct fecha x;
int main (void)
{
char actividad[50], lugar[50];

printf("Actividad: ");
gets(actividad);

printf("Lugar: ");
gets(lugar);

printf("Anio: ");
scanf("%i", &x.anio);
printf("Mes: ");
scanf("%i", &x.mes);
printf("Dia: ");
scanf("%i", &x.dia);
printf("Horas: ");
scanf("%i", &x.horas);
printf("Minutos: ");
scanf("%i", &x.minutos);

system("cls");

printf("Agendado para el %i/%i/%i a las %i:%i:\n %s en %s", x.dia, x.mes, x.anio, x.horas, x.minutos, actividad, lugar);

return 0;
}