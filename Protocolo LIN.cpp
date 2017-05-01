//Jesús Arnoldo Zerecero Núñez, Luis Daniel Castillo Lara
//Protocolo LIN
//Sección del carro elegida: Master Switch de la puerta (movimiento de espejos externos, control de ventanas y  seguros de las puertas)

#include <stdio.h>
#include <conio.h>
#include <windows.h>

struct estructura1{ //Estructura para el encabezado del protocolo
	int Break; //13 bits en 0 y un bit recesivo en 1 (00000000000001)
	int sync; //8 bits, 0x55 hexadecimal (01010101)
	int identifier; //6 bits tienen cierto ID que indica quién debe leer y responder el mensaje, los últimos dos son bits de paridad para verificar errores. Los esclavos están leyendo constantemente este ID esperando a ser llamados.
};
typedef estructura1 Encabezado;

struct estructura2{ //Estructura para la respuesta del esclavo
	int data; //De 8 a 64 bits de mensaje de respuesta, se eligieron solo 8 bits por simplicidad.
	int checksum; //XOR de cada byte del "data" de respuesta, además de los 8 bits del identificador.
};
typedef estructura2 Respuesta;

struct estructuras_anidadas{	//Estructura que abarca el conjunto de todo el datagrama
	Encabezado encabezado;
	Respuesta respuesta;
};
typedef estructuras_anidadas Protocolo;

Protocolo lectura;
Protocolo escritura;

void espejos(void);
void ventanas(void);
void seguros(void);
void Flectura(void);
void Fescritura(int);

FILE* archivo;

int main(void)
{
int opcion, espejos = 0, ventanas= 0, seguros = 1;
while (opcion!=4){
	system("cls"); //Comienza el menú
	printf( "\n¡Bienvenido! Con este programa puede controlar diversas funciones de la puerta de su carro utilizando el protocolo LIN.\n\n\n\nSeleccione la accion que desee realizar:\n1-Mover espejos\n2-Bajar/subir ventanas\n3-Poner/quitar seguros\n4-Salir del programa");
	printf("\n\n\nEste es su carro actualmente:\n\n"); //Muestra las condicines actuales del carro, estas varian segun el "data" de las respuestas de los esclavos
	printf("Los espejos se encuentran posicionados a %i%c sobre el eje horizontal.\n", espejos, 167);
	if (ventanas)
	{
		printf("Las ventanas se encuentran abiertas.\n");
	}
	else
	{
		printf("Las ventanas se encuentran cerradas.\n");
	}

	if (seguros)
	{
		printf("Los seguros estan puestos.\n");
	}
	else
	{
		printf("Los seguros no estan puestos.\n");
	}
	scanf("%i", &opcion);

	if (opcion!=4)
	{
	Fescritura(opcion);
	Flectura();
	archivo= fopen("lin.txt", "rb+"); //Se abre el archivo en modo lectura
	fread(&lectura,sizeof(Protocolo),1,archivo); //Lee el contenido del archivo
		if (lectura.respuesta.data == 00000001) //El maestro registra la acción realizada por el esclavo al leer la respuesta que recibió
		{
			espejos = 15;
		}
		else if (lectura.respuesta.data == 00000010)
		{
			espejos = 30;
		}
		else if (lectura.respuesta.data == 00000100)
		{
			espejos = 45;
		}
		else if (lectura.respuesta.data == 00001000)
		{
			espejos = 60;
		}
		else if (lectura.respuesta.data == 00010000)
		{
			espejos = 75;
		}
		else if (lectura.respuesta.data == 00100000)
		{
			espejos = 90;
		}
		else if (lectura.respuesta.data == 01000000)
		{
			espejos = 0;
		}
		else if (lectura.respuesta.data == 00000011)
		{
			ventanas = 1;
		}
		else if (lectura.respuesta.data == 00000110)
		{
			ventanas = 0;
		}
		else if (lectura.respuesta.data == 00000111)
		{
			seguros = 0;
		}
		else 
		{
			seguros = 1;
		}
fclose(archivo);//Se cierra el archivo
	}
}//Termina el programa
system("cls");
printf("¡Hasta luego!");
getch();
return 0;
}


void Flectura(){
	archivo= fopen("lin.txt", "rb+"); //Se abre el archivo en modo lectura
	fread(&lectura,sizeof(Protocolo),1,archivo); //Lee el contenido del archivo

	if(lectura.encabezado.identifier == 10000001 || lectura.encabezado.identifier == 10000010 || lectura.encabezado.identifier == 01000011 || lectura.encabezado.identifier == 10000100 || lectura.encabezado.identifier == 01000101 || lectura.encabezado.identifier == 01000110 || lectura.encabezado.identifier == 10000111) //Si se decidió mover los espejos
	{
		fclose(archivo); //Se cierra el archivo
		espejos();
	}
	else if (lectura.encabezado.identifier == 10001000 || lectura.encabezado.identifier == 01001001) //Si se decidió abrir/cerrar las ventanas
	{
		fclose(archivo); //Se cierra el archivo
		ventanas();
	}
	else	//Si se decidió poner/quitar los seguros
	{
		fclose(archivo); //Se cierra el archivo
		seguros();
	}
return;
}

void espejos(){
	archivo= fopen("lin.txt", "rb+"); //Se abre el archivo en modo lectura
	fread(&lectura,sizeof(Protocolo),1,archivo); //Lee el contenido del archivo
	if(lectura.encabezado.identifier == 10000001)
	{
		 fclose(archivo); //Se cierra el archivo
		 escritura.respuesta.data = 00000001; //Valor aleatorio de 8 bits
		 escritura.respuesta.checksum = (escritura.encabezado.identifier^escritura.respuesta.data); //XOR entre el ID y la respuesta
		 system("cls");
		 printf("Los espejos exteriores se han movido 15%c sobre su eje horizontal", 167); //Mensaje de acción realizada por el esclavo
		 getch();
	 }
	else if (lectura.encabezado.identifier == 10000010)
	{
		 fclose(archivo); //Se cierra el archivo
		 escritura.respuesta.data = 00000010; //Valor aleatorio de 8 bits
		 escritura.respuesta.checksum = (escritura.encabezado.identifier^escritura.respuesta.data); //XOR entre el ID y la respuesta
		 system("cls");
		 printf("Los espejos exteriores se han movido 15%c sobre su eje horizontal", 167); //Mensaje de acción realizada por el esclavo
		 getch();
	 }
	else if (lectura.encabezado.identifier == 01000011)
	{
		 fclose(archivo); //Se cierra el archivo
		 escritura.respuesta.data = 00000100; //Valor aleatorio de 8 bits
		 escritura.respuesta.checksum = (escritura.encabezado.identifier^escritura.respuesta.data); //XOR entre el ID y la respuesta
		 system("cls");
		 printf("Los espejos exteriores se han movido 15%c sobre su eje horizontal", 167); //Mensaje de acción realizada por el esclavo
		 getch();
	 }
	else if (lectura.encabezado.identifier == 10000100)
	{
		 fclose(archivo); //Se cierra el archivo
		 escritura.respuesta.data = 00001000; //Valor aleatorio de 8 bits
		 escritura.respuesta.checksum = (escritura.encabezado.identifier^escritura.respuesta.data); //XOR entre el ID y la respuesta
		 system("cls");
		 printf("Los espejos exteriores se han movido 15%c sobre su eje horizontal", 167); //Mensaje de acción realizada por el esclavo
		 getch();
	 }
	else if (lectura.encabezado.identifier == 01000101)
	{
		 fclose(archivo); //Se cierra el archivo
		 escritura.respuesta.data = 00010000; //Valor aleatorio de 8 bits
		 escritura.respuesta.checksum = (escritura.encabezado.identifier^escritura.respuesta.data); //XOR entre el ID y la respuesta
		 system("cls");
		 printf("Los espejos exteriores se han movido 15%c sobre su eje horizontal", 167); //Mensaje de acción realizada por el esclavo
		 getch();
	 }
	else if (lectura.encabezado.identifier == 01000110)
	{
		 fclose(archivo); //Se cierra el archivo
		 escritura.respuesta.data = 00100000; //Valor aleatorio de 8 bits
		 escritura.respuesta.checksum = (escritura.encabezado.identifier^escritura.respuesta.data); //XOR entre el ID y la respuesta
		 system("cls");
		 printf("Los espejos exteriores se han movido 15%c sobre su eje horizontal", 167); //Mensaje de acción realizada por el esclavo
		 getch();
	 }
	else
	{
		 fclose(archivo); //Se cierra el archivo
		 escritura.respuesta.data = 01000000; //Valor aleatorio de 8 bits
		 escritura.respuesta.checksum = (escritura.encabezado.identifier^escritura.respuesta.data); //XOR entre el ID y la respuesta
		 system("cls");
		 printf("Los espejos han vuelto a su posicion inicial"); //Mensaje de acción realizada por el esclavo
		 getch();
	 }

	archivo= fopen("lin.txt", "ab+"); //Se abre el archivo para escritura
	fwrite(&escritura,sizeof(Protocolo),1,archivo); //Se escribe la estructura de respuesta en el archivo
	fclose(archivo); //Se cierra el archivo
return;
}


void ventanas(){
	archivo= fopen("lin.txt", "rb+"); //Se abre el archivo en modo lectura
	fread(&lectura,sizeof(Protocolo),1,archivo); //Lee el contenido del archivo
	if(lectura.encabezado.identifier == 10001000)
	{
		 fclose(archivo); //Se cierra el archivo
		 escritura.respuesta.data = 00000011; //Valor aleatorio de 8 bits
		 escritura.respuesta.checksum = (escritura.encabezado.identifier^escritura.respuesta.data); //XOR entre el ID y la respuesta
		 system("cls");
		 printf("Las ventanas han sido abiertas"); //Mensaje de acción realizada por el esclavo
		 getch();
	 }
	else 
	{
		 fclose(archivo); //Se cierra el archivo
		 escritura.respuesta.data = 00000110; //Valor aleatorio de 8 bits
		 escritura.respuesta.checksum = (escritura.encabezado.identifier^escritura.respuesta.data); //XOR entre el ID y la respuesta
		 system("cls");
		 printf("Las ventanas han sido cerradas"); //Mensaje de acción realizada por el esclavo
		 getch();
	 }
	archivo= fopen("lin.txt", "ab+"); //Se abre el archivo para escritura
	fwrite(&escritura,sizeof(Protocolo),1,archivo); //Se escribe la estructura de respuesta en el archivo
	fclose(archivo); //Se cierra el archivo
return;
}

void seguros(){
	archivo= fopen("lin.txt", "rb+"); //Se abre el archivo en modo lectura
	fread(&lectura,sizeof(Protocolo),1,archivo); //Lee el contenido del archivo
	if(lectura.encabezado.identifier == 01001010)
	{
		 fclose(archivo); //Se cierra el archivo
		 escritura.respuesta.data = 00000111; //Valor aleatorio de 8 bits
		 escritura.respuesta.checksum = (escritura.encabezado.identifier^escritura.respuesta.data); //XOR entre el ID y la respuesta
		 system("cls");
		 printf("Los seguros se quitaron"); //Mensaje de acción realizada por el esclavo
		 getch();
	 }
	else 
	{
		 fclose(archivo); //Se cierra el archivo
		 escritura.respuesta.data = 00001110; //Valor aleatorio de 8 bits
		 escritura.respuesta.checksum = (escritura.encabezado.identifier^escritura.respuesta.data); //XOR entre el ID y la respuesta
		 system("cls");
		 printf("Los seguros han sido puestos"); //Mensaje de acción realizada por el esclavo
		 getch();
	 }
	archivo= fopen("lin.txt", "ab+"); //Se abre el archivo para escritura
	fwrite(&escritura,sizeof(Protocolo),1,archivo); //Se escribe la estructura de respuesta en el archivo
	fclose(archivo); //Se cierra el archivo
return;
}


 void Fescritura(int opcion){
static int indice = 0; //Cada que se llame a esta opcion, el indice se incrementa, definiendo asi los diferentes angulos de posición para los espejos
static int ventana = 0; //Cada que se llame a esta opcion, el indice cambia de 0 a 1, para abrir las ventanas si estan cerradas o viceversa
static int seguros = 0; //Cada que se llame a esta opcion, el indice cambia de 0 a 1, para poner los seguros si no estan puestos y viceversa
if (opcion == 1) //Opcion para mover espejos
	{
		if(indice == 0)
		{
			 escritura.encabezado.Break = 00000000000001;
			 escritura.encabezado.sync = 01010101;
			 escritura.encabezado.identifier = 10000001; //ID numero "1", con paridad impar (bits mas significativos P0= 0, P1=1)
			 indice++;
		 }
		else if (indice == 1)
		{
			 escritura.encabezado.Break = 00000000000001;
			 escritura.encabezado.sync = 01010101;
			 escritura.encabezado.identifier = 10000010; //ID numero "2", con paridad impar (bits mas significativos P0= 0, P1=1)
			indice++;
		 }
		else if (indice == 2)
		{
			 escritura.encabezado.Break = 00000000000001;
			 escritura.encabezado.sync = 01010101;
			 escritura.encabezado.identifier = 01000011; //ID numero "3", con paridad par (bits mas significativos P0= 1, P1=0)
			 indice++;
		 }
		else if (indice == 3)
		{
			 escritura.encabezado.Break = 00000000000001;
			 escritura.encabezado.sync = 01010101;
			 escritura.encabezado.identifier = 10000100; //ID numero "4", con paridad impar (bits mas significativos P0= 0, P1=1)
			 indice++; 
		 }
		else if (indice == 4)
		{
			 escritura.encabezado.Break = 00000000000001;
			 escritura.encabezado.sync = 01010101;
			 escritura.encabezado.identifier = 01000101; //ID numero "5", con paridad par (bits mas significativos P0= 1, P1=0)
			 indice++;
		 }
		else if (indice == 5)
		{
			 escritura.encabezado.Break = 00000000000001;
			 escritura.encabezado.sync = 01010101;
			 escritura.encabezado.identifier = 01000110; //ID numero "6", con paridad par (bits mas significativos P0= 1, P1=0)
			 indice++;
		 }
		else
		{
			 escritura.encabezado.Break = 00000000000001;
			 escritura.encabezado.sync = 01010101;
			 escritura.encabezado.identifier = 10000111; //ID numero "7", con paridad impar (bits mas significativos P0= 0, P1=1)
			 indice = 0;
		 }
	}
else if (opcion == 2) //Opcion para abrir/cerrar ventanas
	{
		if(ventana == 0)
	{
		 escritura.encabezado.Break = 00000000000001;
		 escritura.encabezado.sync = 01010101;
		 escritura.encabezado.identifier = 10001000; //ID numero "8", con paridad impar (bits mas significativos P0= 0, P1=1)
		 ventana = 1;
	 }
	else 
	{
		 escritura.encabezado.Break = 00000000000001;
		 escritura.encabezado.sync = 01010101;
		 escritura.encabezado.identifier = 01001001; //ID numero "9", con paridad par (bits mas significativos P0= 1, P1=0)
		ventana = 0;
	 }
	}
else //Opcion para poner/quitar seguros
	{
		if(seguros == 0)
	{
		 escritura.encabezado.Break = 00000000000001;
		 escritura.encabezado.sync = 01010101;
		 escritura.encabezado.identifier = 01001010; //ID numero "10", con paridad par (bits mas significativos P0= 1, P1=0)
		 seguros = 1;
	 }
	else 
	{
		 escritura.encabezado.Break = 00000000000001;
		 escritura.encabezado.sync = 01010101;
		 escritura.encabezado.identifier = 10001011; //ID numero "11", con paridad impar (bits mas significativos P0= 0, P1=1)
		seguros = 0;
	 }
	}
	archivo= fopen("lin.txt", "wb+"); //Se abre/crea el archivo binario
	fwrite(&escritura,sizeof(Protocolo),1,archivo); //Se escribe la estructura de encabezado en el archivo
	fclose(archivo); //Se cierra el archivo
return;
 }
