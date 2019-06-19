#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*cosas por hacer:
-colocar ! para salir y ficha del jugador cada vez que juega (ya lo puse mas no sirve aaaa)
COMO HACER PARA QUE DESPUES DE DECIR EL RESULTADO NO SIGA LLAMANDO A LA FUNCION "OCUPADO"
*/

typedef struct simbolo{
	int marcado; //if marcado == 0 significa que NO esta ocupada, if marcado == 1, significa que ESTA OCUPADA
    char simbolo;
}CASILLA;

CASILLA casilla1 = {0,'1'};
CASILLA casilla2 = {0,'2'};
CASILLA casilla3 = {0,'3'};
CASILLA casilla4 = {0,'4'};
CASILLA casilla5 = {0,'5'};
CASILLA casilla6 = {0,'6'};		
CASILLA casilla7 = {0,'7'};
CASILLA casilla8 = {0,'8'};
CASILLA casilla9 = {0,'9'};

char simbolo; //Either X or O. es global porque no solo se va a usar en una funcion sino en varias
char compu; //si el usuario es X la computadora es O y viceversa

//hace el tablero, los nros del 1 al 9 vienen dados por el valor de casilla(i).simbolo
void Tablero(){

	printf("\n        %c   |   %c   |   %c   ",casilla1.simbolo,casilla2.simbolo,casilla3.simbolo);
	printf("\n     -----------------------");
	printf("\n        %c   |   %c   |   %c   ",casilla4.simbolo,casilla5.simbolo,casilla6.simbolo);
	printf("\n     -----------------------");
	printf("\n        %c   |   %c   |   %c   ",casilla7.simbolo,casilla8.simbolo,casilla9.simbolo);
}

// La persona escoje entre X u O. si los coloca en minuscula se convierten en mayusculas (not rlly aun pero aja)
void Opcion() {

	printf("\n\nEscoge X u O: ");
	scanf("%c",&simbolo);

	while(simbolo != 'X' && simbolo != 'x' && simbolo != 'O' && simbolo != 'o'){
		printf("\nERROR: esa no es una ficha valida.");
		printf("\n\nEscoge X u O: ");
		fflush(stdin);		
		scanf("%c",&simbolo);
	}

	if(simbolo == 'X' || simbolo == 'x'){
		compu = 'O';
	}

	else if(simbolo == 'O' || simbolo == 'o'){
		compu = 'X';
	}
}

//Rellena el tablero con la ficha que ingresa el usuario. Si la ficha esta repetida le informa para que coloque otra
void Ocupado(){	

	char choice;

	do{
		do{
			Tablero();
			printf("\n\n  Jugador = %c      Computadora = %c",simbolo,compu);
			printf("\n\nEscoge una casilla. \nSi deseas salir del juego presiona !: ");
			fflush(stdin);
			scanf("%c",&choice);
		}while(choice < '1' || choice > '9');

	switch(choice){
			case '1': if(choice == '1'){

						if(casilla1.marcado == 1){
							printf("\nLa casilla esta ocupada. Intentalo de nuevo\n");
						}

						else if(casilla1.marcado == 0){
							casilla1.marcado = 1;
							casilla1.simbolo = simbolo;
						}

						system("cls");
					}
			break;

			case '2': if(choice == '2'){

						if(casilla2.marcado == 1){
							printf("\nLa casilla esta ocupada. Intentalo de nuevo\n");
						}

						else if(casilla2.marcado == 0){
							casilla2.marcado = 1;
							casilla2.simbolo = simbolo;
						}	

						system("cls");
					}	
			break;

			case '3': if(choice == '3'){

						if(casilla3.marcado == 1){
							printf("\nLa casilla esta ocupada. Intentalo de nuevo\n");
						}

						else if(casilla3.marcado == 0){
							casilla3.marcado = 1;
							casilla3.simbolo = simbolo;
						}	

						system("cls");
					}	
			break;

			case '4': if(choice == '4'){

						if(casilla4.marcado == 1){
							printf("\nLa casilla esta ocupada. Intentalo de nuevo\n");
						}

						else if(casilla4.marcado == 0){
							casilla4.marcado = 1;
							casilla4.simbolo = simbolo;
						}

						system("cls");
					}		
			break;

			case '5': if(choice == '5'){

						if(casilla5.marcado == 1){
							printf("\nLa casilla esta ocupada. Intentalo de nuevo\n");
						}

						else if(casilla5.marcado == 0){
							casilla5.marcado = 1;
							casilla5.simbolo = simbolo;
						}	

						system("cls");
					}	
			break;

			case '6': if(choice == '6'){

						if(casilla6.marcado == 1){
							printf("\nLa casilla esta ocupada. Intentalo de nuevo\n");
						}

						else if(casilla6.marcado == 0){
							casilla6.marcado = 1;
							casilla6.simbolo = simbolo;
						}	

						system("cls");
					}	
			break;

			case '7': if(choice == '7'){

						if(casilla7.marcado == 1){
							printf("\nLa casilla esta ocupada. Intentalo de nuevo\n");
						}

						else if(casilla7.marcado == 0){
							casilla7.marcado = 1;
							casilla7.simbolo = simbolo;
						}	

						system("cls");
					}		
			break;

			case '8': if(choice == '8'){

						if(casilla8.marcado == 1){
							printf("\nLa casilla esta ocupada. Intentalo de nuevo\n");
						}

						else if(casilla8.marcado == 0){
							casilla8.marcado = 1;
							casilla8.simbolo = simbolo;
						}	

						system("cls");
					}		
			break;

			case '9': if(choice == '9'){

						if(casilla9.marcado == 1){
							printf("\nLa casilla esta ocupada. Intentalo de nuevo\n");
						}

						else if(casilla9.marcado == 0){
							casilla9.marcado = 1;
							casilla9.simbolo = simbolo;
						}	

						system("cls");
					}		
			break;
			}	
	
	}while(casilla1.marcado == 1 || casilla2.marcado == 1 || casilla3.marcado == 1 || casilla4.marcado == 1 ||
	casilla5.marcado == 1 || casilla6.marcado == 1 || casilla7.marcado == 1 || casilla8.marcado == 1 || casilla9.marcado == 1);
}

//Rellena el tablero con la ficha de la computadora (not rlly aun pero aja)
void AI(){

	int random,k;

	srand(time(NULL));

	do{
		random = rand() % 10;

		k = 0;

		if(casilla1.marcado == 1 || casilla2.marcado == 1 || casilla3.marcado == 1 || casilla4.marcado == 1 || 
		casilla5.marcado == 1 || casilla6.marcado == 1|| casilla7.marcado == 1 || casilla8.marcado == 1 || casilla9.marcado == 1){

			k = 1;

		}

	}while(k = 1);

	switch(random){
		case '1': if (random == 1){
					casilla1.simbolo = compu;
					casilla1.marcado = 1;
				}
		break;

		case '2': if (random == 2){
					casilla2.simbolo = compu;
					casilla2.marcado = 1;
				}
		break;

		case '3': if (random == 3){
					casilla3.simbolo = compu;
					casilla3.marcado = 1;
				}
		break;

		case '4': if (random == 4){
					casilla4.simbolo = compu;
					casilla4.marcado = 1;
				}
		break;

		case '5': if (random == 5){
					casilla5.simbolo = compu;
					casilla5.marcado = 1;
				}
		break;

		case '6': if (random == 6){
					casilla6.simbolo = compu;
					casilla6.marcado = 1;
				}
		break;

		case '7': if (random == 7){
					casilla7.simbolo = compu;
					casilla7.marcado = 1;
				}
		break;

		case '8': if (random == 8){
					casilla8.simbolo = compu;
					casilla8.marcado = 1;
				}
		break;

		case '9': if (random == 9){
					casilla9.simbolo = compu;
					casilla9.marcado = 1;
				}
		break;
	}
}

//chequea si se gana, pierde o empata (cuando logre salir del fuckin loop)
int Check() {

	if(casilla1.marcado == casilla2.marcado && casilla2.marcado == casilla3.marcado){

		if(casilla1.simbolo == simbolo){
			return 0;
		}

		else if(casilla1.simbolo ==ficha){
			return 1;
		}
	}

	else if(casilla4.marcado == casilla5.marcado && casilla5.marcado == casilla6.marcado){

		if(casilla4.simbolo == simbolo){
			return 0;
		}

		else if(casilla4.simbolo ==ficha){
			return 1;
		}
	}

	else if(casilla7.marcado == casilla8.marcado && casilla8.marcado == casilla9.marcado){

		if(casilla7.simbolo == simbolo){
			return 0;
		}
		
		else if(casilla7.simbolo ==ficha){
			return 1;
		}
	}

	else if(casilla1.marcado == casilla4.marcado && casilla4.marcado == casilla7.marcado){

		if(casilla1.simbolo == simbolo){
			return 0;
		}
		
		else if(casilla1.simbolo ==ficha){
			return 1;
		}
	}

	else if(casilla2.marcado == casilla5.marcado && casilla5.marcado == casilla8.marcado){

		if(casilla2.simbolo == simbolo){
			return 0;
		}
		
		else if(casilla2.simbolo ==ficha){
			return 1;
		}
	}

	else if(casilla3.marcado == casilla6.marcado && casilla6.marcado == casilla9.marcado){

		if(casilla3.simbolo == simbolo){
			return 0;
		}
		
		else if(casilla3.simbolo ==ficha){
			return 1;
		}
	}

	else if(casilla1.marcado == casilla5.marcado && casilla5.marcado == casilla9.marcado){

		if(casilla1.simbolo == simbolo){
			return 0;
		}

		else if(casilla1.simbolo ==ficha){
			return 1;
		}
	}

	else if(casilla3.marcado == casilla5.marcado && casilla5.marcado == casilla7.marcado){

		if(casilla3.simbolo == simbolo){
			return 0;
		}
		
		else if(casilla3.simbolo ==ficha){
			return 1;
		}
	}

	else {
		return 2;
	}
}

//Crea un archivo de texto con los resultados de la partida
void Text() {	

	switch(result){
		case '1': if(result == 0){

				}
		break;

		case '2': if(result == 1){

				}
		break;

		case '3': if(result ==3){

				}
		break;
	}
}

/*Le dice al jugador si gano, perdio o empato.
Ademas pregunta si desea obtener un archivo de texto con su resultado. En caso afirmativo, se va a la funcion Text();*/
void Resultado(){

	int result;

	if(Check() == 0){

		do{
			printf("\nFelicidades, Ganaste!");
			printf("\nDeseas guardar tu resultado como archivo de texto?");
			printf("\n             1. si              2. no             ");
			fflush(stdin);		
			scanf("%d",&result);

			if(result == 1){
				Text();
			}

			else if (result == 2){
				printf("Gracias por jugar!");
			}

			else if (result != 1 || result != 2){
				printf("Esa no es una opcion valida");
			}

		}while(result != 1 || result != 2);	
	}

	else if(Check() == 1){

		do{
			printf("\nLo lamento. Perdiste :(");
			printf("\nDeseas guardar tu resultado como archivo de texto?");
			printf("\n             1. si              2. no             ");
			fflush(stdin);		
			scanf("%d",&result);

			if(result == 1){
				Text();
			}

			else if (result == 2){
				printf("Gracias por jugar!");
			}

			else if (result != 1 || result != 2){
				printf("Esa no es una opcion valida");
			}

		}while(result != 1 || result != 2);	
	}

	else if(Check() != 0 || Check() != 1){

		do{
			printf("\nHa sido un empate");
			printf("\nDeseas guardar tu resultado como archivo de texto?");
			printf("\n             1. si              2. no             ");
			fflush(stdin);		
			scanf("%d",&result);

			if(result == 1){
				Text();
			}

			else if (result == 2){
				printf("Gracias por jugar!");
			}

			else if (result != 1 || result != 2){
				printf("Esa no es una opcion valida");
			}

		}while(result != 1 || result != 2);	
	}	
}

int main(){

	system("cls");
	Opcion();
	Ocupado();
	AI();
	Check();
	Resultado();

	return 0;
}
