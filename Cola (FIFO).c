/*Jesús Arnoldo Zerecero Núñez
Universidad Autónoma de Guadalajara
"Lista simplemente enlazada tipo cola"*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct direc{
	char nombre[50];
	struct direc *sig;
};

typedef struct direc direc;

direc *ppio,*final;

void pedirdatos(void);
void mostrar(void);


void main(void){
int cont;

clrscr();
for(cont=0;cont<4;cont++)
	pedirdatos();
	mostrar();
	getch();
return;

}


void pedirdatos(){

direc *var;
int cont;

var=(direc *)malloc(sizeof(direc)); //asinga espacio memoria
gets(var->nombre);                  //pide el dato

if (ppio == NULL)
{
	ppio = var;
	final = var;
}
else
{
	final->sig = var;
	final = var;
}
}


void mostrar(){
direc *p;                    //muestra toda la lista
p=ppio;
while(p)
{puts(p->nombre);
p=p->sig;
}

}