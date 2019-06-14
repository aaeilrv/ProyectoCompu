#include <stdio.h>
#include <stdlib.h>

/*cosas por hacer:
-hacer funcion de computadora (AI)
-colocar ! para salir y ficha del jugador cada vez que juega (ya lo puse mas no sirve aaaa)
-hacer funcion de ganar, perder, empatar
-guardar como archivo de texto
-colocar structs en las casillas (aka modificar todo)
-que void AI() comparta char compu
*/

char ficha; //La variable ficha permite escojer con cual ficha se identificara el usuario. Es una variable global puesto que se utiliza en dos funciones
char compu; //La variable compu le asigna a la computadora la ficha contraria a la que escogio el jugador. Si este selecciono X, la ficha de la computadora sera O y viceversa.

//Esta funcion crea el tablero, colocando los numeros del 1 al 9 en cada casilla para identificarlas
void Tablero(char board[3][3]) { 

	printf("\n");

	for(int i = 0; i < 3; i++){

		for(int j = 0; j < 3; j++){

			if(j < 2){
				printf("   %c   |",board[i][j]);
			}

			else{
				printf("   %c",board[i][j]);
			}
		}

		if(i < 2){
			printf("\n-----------------------\n");
		}
	}

}

/*La funcion Option() permite que el usuario escoja la ficha con la que desea identificarse durante el juego, si X u O.
En el caso de escojer una de las dos, la otra automaticamente es asignada a la computadora*/
void Option() {

	printf("\n\nEscoge la ficha con la que deseas jugar: O o X\n");
	scanf("%c",&ficha);

	while(ficha != 'X' && ficha != 'x' && ficha != 'O' && ficha != 'o'){
		printf("\nERROR: esa no es una ficha valida.");
		printf("\nEscoge la ficha con la que deseas jugar: O o X\n");
		fflush(stdin);		
		scanf("%c",&ficha);
	}

	if(ficha == 'x'){
		ficha == 'X';
	}

	if (ficha=='o'){
		ficha == 'O';
	}

	switch(compu){
		case 1: if(ficha == 'X' && ficha == 'x'){
				compu == 'O';
			}
		break;
		case 2: if(ficha == 'O' && ficha == 'o'){
				compu =='X';
			}
		break;
	}	

}

/*La funcion Casilla() permite que el usuario escoja en cual de las casillas desea jugar. En caso de que la casilla ya este ocupada
o salga de los limites del tablero, se le notificara al jugador que debe hacer un movimiento valido*/
void Casilla(char board[3][3]){	

	int choice; /*La variable choice puede ser un numero del 1 al 9 que identifique en cual casilla jugara el usuario.
	Dependiendo de cual escoja, esta variable permitira que las casillas se identifiquen como llenas*/

		//while(choice > '1' || choice < '9'){
		do{
			Tablero(board);
			printf("\n\nEscoje una casilla. Si desea salir del juego presione !: ");
			fflush(stdin);
			scanf("%d",&choice);

			switch(choice){
				
				case 1:
					if(choice == 1 && board[0][0] == '1'){
					board[0][0] = ficha;
					}

				break;

				case 2:
					if (choice == 2 && board[0][1] == '2'){
	       		 	board[0][1] = ficha;
					}

				break;

				case 3:
					if (choice == 3 && board[0][2] == '3'){
	       		 	board[0][2] = ficha;
					}

				break;

				case 4:
					if (choice == 4 && board[1][0] == '4'){
	       		 	board[1][0] = ficha;
					}

				break;

				case 5:
					if (choice == 5 && board[1][1] == '5'){
	       		 	board[1][1] = ficha;
					}

				break;

				case 6:
					if (choice == 6 && board[1][2] == '6'){
	       		 	board[1][2] = ficha;
					}

				break;

				case 7:
					if (choice == 7 && board[2][0] == '7'){
	       		 	board[2][0] = ficha;
					}

				break;

				case 8:
					if (choice == 8 && board[2][1] == '8'){
	       		 	board[2][1] = ficha;
					}

				break;

				case 9:
					if (choice == 9 && board[2][2] == '9'){
	       		 	board[2][2] = ficha;
					}

				break;

				case 10:
					if (choice == '!'){
						printf("Gracias por jugar!");
					}

				break;
			}
		}while(choice > '1' || choice < '9');

		if(choice == '!'){
			printf("Gracias por jugar.");
		}

		//no funciona idk why
		while(choice < '1' && choice > '9'){
			printf("\n\nEscoje una casilla valida: ");
			fflush(stdin);
			scanf("%d",&choice);

		}

}

/*Esta funcion permite que la computadora pueda jugar, haciendo una estrategia de BLABLABLA*/
/*void AI (char board[3][3]){

	srand(time(NULL));

}*/

/*void Ganar(char board[3][3]){

	switch(board[3][3]){
		case 1: if(board[0][0] == board [0][1] && board [0][1] == board [0][2]){
			printf("GANASTE!");
		}
		break;

		case 2:if(board[1][0] == board [1][1] && board [1][1] == board [1][2]){
			printf("GANASTE!");
		}
		break;

		case 3:if(board[2][0] == board [2][1] && board [2][1] == board [2][2]){
			printf("GANASTE!");
		}
		break;

		case 4:if(board[0][0] == board [1][0] && board [1][0] == board [2][0]){
			printf("GANASTE!");
		}
		break;

		case 5:if(board[0][1] == board [1][1] && board [0][1] == board [2][1]){
			printf("GANASTE!");
		}
		break;

		case 6:if(board[2][0] == board [2][1] && board [2][1] == board [2][2]){
			printf("GANASTE!");
		}
		break;

		case 7:if(board[0][0] == board [1][1] && board [1][1] == board [2][2]){
			printf("GANASTE!");
		}
		break;

		case 8:if(board[0][2] == board [1][1] && board [1][1] == board [2][0]){
			printf("GANASTE!");
		}
		break;
	}
}*/

int main (){

system("cls");

char board[3][3] = {
	{'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

Option();

Casilla(board);

//AI(board);

Tablero(board);

//Ganar(board);

return 0;

}