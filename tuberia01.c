#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define LEER	0
#define ESCRIBIR 1

int main(){
	int descr[2];/*Descriptores de E y S de la tuberia*/
	int bytesleidos;
	 char mensaje[100], *frase="Papi,Me gusta mucho la cancion de Lady Gaga pero no tanto como las clases de Sistemas Operativos.";
	 
	 printf("***Ejemplo de comunicacion entre procesos padre e hijo.****\n\n");
	 pipe(descr);
	 if(fork() == 0){
	 /*seccion de hijo*/
	 close(descr[LEER]);
	 write(descr[ESCRIBIR],frase,strlen(frase));
	 close(descr[ESCRIBIR]);
	}
	else{
	/*seccion del padre*/
	close(descr[ESCRIBIR]);
	bytesleidos = read(descr[LEER],mensaje,100);
	mensaje[bytesleidos]='\0';
	printf("Bytes leidos: %d\n",bytesleidos);
	printf("Mensaje enviado por el Hijo: %s\n",mensaje);
	close(descr[LEER]);
	}
}
