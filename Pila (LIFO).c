/*Jesús Arnoldo Zerecero Núñez
Universidad Autónoma de Guadalajara
"Lista simplemente enlazada tipo pila"*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct direc{
	char nombre[50];
	struct direc *sig;
};

typedef struct direc direc;

direc **ppio,**final;

void pedirdatos(void);
void insertar(direc *,direc **,direc **);
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
insertar(var,&ppio,&final);        //manda insertar el dato



}

void insertar(direc *i,direc **ppio,direc **final){
struct direc *aux,*ant;

if(!*final){                  //si no existe nada en lista
i->sig=NULL;
*final=i;
*ppio=i;
return;
}
else
{
i->sig=*ppio;
if(final==ppio)
(*ppio)->sig=final;
*ppio=i;

return;
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