#include <stdio.h>
#include <stdlib.h>
#include "tictactoe.h"
#include "hangman.h"

/*
la funcion bienvenida crea un mensaje de bienvenida al usuario, con la identificacíón
de los programadores del juego así como de la materia y el trimestre cursado.

*/
void Bienvenida(){

	printf("\n");
	printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");

	printf("\nProyecto de CI2125-27 Enero-Marzo 2019\n\n");
	printf("Programadoras:\nAstrid Pinango & Valeria Vera\n\n");

	printf("Presiona ENTER para continuar: ");
	getchar(); 
}

/*
la funcion Menu le muestra al usuario las tres posibles opciones que tiene para seguir
	1. Ir al juego de la vieja
	2. ir al juego de ahorcado
	3. salir
Dependiendo de cuál escoja, será redirigido a un juego o habrá salido del menú.
Parametros: a) int (tipo de variable para escribir números),
                juego <-- permite al jugador seleccionar una de las tres opciones
                permitidas
Efectos colaterales: llama a una función que dirige al usuario hacia un juego o termina
el proceso.
*/
void Menu(){

	int juego;

	do{

		printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
		printf("*-*-*                   ESCOJE UN JUEGO:                *-*-*\n");
		printf("-*-*-      1._ La Vieja           2._ El Ahorcado       -*-*-\n");
		printf("*-*-*                      3. salir                     *-*-*\n");
		printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");

		scanf("%d",&juego);

		
		if(juego == 1){
			tictactoe(); //ir al juego de la vieja
		}

		if(juego == 2){
			hangman();
		}

		if (juego == 3){
			printf("Hasta luego!");
			exit(0);
		}

	}while(juego < 1 | juego > 3);
}

int main() {
	
	system("clear");

	Bienvenida();

	Menu();

	return 0;
}