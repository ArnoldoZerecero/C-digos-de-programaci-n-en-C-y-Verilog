#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct direc{
char nombre[50];
struct direc *sig, *ant;
};

typedef struct direc direc;

direc **ppio,**final;

void pedirdatos(void);
void insertar(direc *,direc **,direc **);
void mostrar(int);
void mostrartodo();


void main(void){
int cont;
int mover;

clrscr();
for(cont=0;cont<4;cont++)
{
pedirdatos();
printf("\n\n");
mostrartodo();
}
do
{
	printf("Si desea avanzar la lista, presione <1>, si desea atrasarla, presione <0>, si desea salir, presione <2>\n");
	scanf("%i", &mover);
	switch (mover)
	{
		case 0: mostrar(mover);
		break;
		
		case 1: mostrar(mover);
		break;
		
		case 2: return;
		break;
	}
} while (mover!= 2);
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
i->ant=NULL;
return;


}

if(strcmp(i->nombre,(*ppio)->nombre)<0)      //si es menor al primel elemento
{i->sig=*ppio;
i->ant=NULL;
if(final==ppio)
(*ppio)->sig=final;
(*ppio)->ant=i;

*ppio=i;

return;
}

if(strcmp(i->nombre,(*final)->nombre)>0) //si va al final de la lista
{i->sig=NULL;
i->ant=*final;
(*final)->sig=i;
if(final==ppio)
(*ppio)->sig=*final;
(*ppio)->ant=NULL;
*final=i;
return;
}

ant=*ppio;
aux=(*ppio)->sig;

do{                              //Busca en posicion central va

if(strcmp(i->nombre,aux->nombre)<=0){  //verifica si es menor al siguiente elemento de la posicion actual
i->sig=aux;
ant->sig=i;
return;
}
else{ ant=aux; //si no se recorre al siguiente elemento
aux=aux->sig;
}

}while(ant!=*final);


}

void mostrar(int mover){
direc *p, *ant, *sig;                    //muestra toda la lista


	if (mover)
	{
	p=ppio;
	puts(p->nombre);
	getch();
	while(p){
	p=p->sig;
	puts(p->nombre);}
	getch();
	return;
	}
	else
	{
	p=final;
	puts(p->nombre);
	getch();
	while(p)
	{
	p=p->ant;
	puts(p->nombre);
	getch();
	}
	return;
	}
return;
}

void mostrartodo(){
direc *p;                    //muestra toda la lista
p=ppio;
while(p)
{puts(p->nombre);
p=p->sig;
}

}
