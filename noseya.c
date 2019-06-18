#include <stdio.h>
#include <stdlib.h>

/*cosas por hacer:
-colocar ! para salir y ficha del jugador cada vez que juega (ya lo puse mas no sirve aaaa)
-guardar como archivo de texto

COMO HACER PARA QUE DESPUES DE DECIR EL RESULTADO NO SIGA LLAMANDO A LA FUNCION "OCUPADO"
*/

typedef struct simbolo {
	int marcado; //if marcado == 0 significa que NO esta ocupada, if marcado == 1, significa que ESTA OCUPADA
    char simbolo;
    int choice;
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

//Rellena el tablero
void Ocupado(){	

	char choice;

	do{
		do{
			Tablero();
			printf("\n\n  Jugador = %c      Computadora = %c",simbolo,compu);
			printf("\n\nEscoge una casilla. \nSi deseas salir del juego presiona !: ");
			fflush(stdin);
			scanf("%c",&choice);
		}while(choice < '1' || choice >'9');

		switch(choice){
			case '1': if(choice == '1' && casilla1.marcado == 0){
						//usuario
						casilla1.marcado = 1;
						casilla1.simbolo = simbolo;

						//computadora
						casilla5.marcado = 1;
						casilla5.simbolo = compu;
						//printf("La casilla esta ocupada. Intentalo nuevamente.\n");
						}

			break;

			case '2': if(choice == '2' && casilla2.marcado == 0){

						//usuario
						casilla2.marcado = 1;
						casilla2.simbolo = simbolo;

						//computadora
						casilla9.marcado = 1;
						casilla9.simbolo = compu;
						//printf("La casilla esta ocupada. Intentalo nuevamente.\n");
						}

			break;

			case '3': if(choice == '3' && casilla3.marcado == 0){

						//usuario
						casilla3.marcado = 1;
						casilla3.simbolo = simbolo;

						//computadora
						casilla8.marcado = 1;
						casilla8.simbolo = compu;
						//printf("La casilla esta ocupada. Intentalo nuevamente.\n");
						}

			break;

			case '4': if(choice == '4' && casilla4.marcado == 0){

						//usuario
						casilla4.marcado = 1;
						casilla4.simbolo = simbolo;

						//computadora
						casilla1.marcado = 1;
						casilla1.simbolo = compu;
						//printf("La casilla esta ocupada. Intentalo nuevamente.\n");
						}

			break;

			case '5': if(choice == '5' && casilla5.marcado == 0){

						//usuario
						casilla5.marcado = 1;
						casilla5.simbolo = simbolo;

						//computadora
						casilla7.marcado = 1;
						casilla7.simbolo = compu;
						//printf("La casilla esta ocupada. Intentalo nuevamente.\n");
						}

			break;

			case '6': if(choice == '6' && casilla6.marcado == 0){

						//usuario
						casilla6.marcado = 1;
						casilla6.simbolo = simbolo;

						//computadora
						casilla2.marcado = 1;
						casilla2.simbolo = compu;
						//printf("La casilla esta ocupada. Intentalo nuevamente.\n");
						}

			break;

			case '7': if(choice == '7' && casilla7.marcado == 0){

						//usuario
						casilla7.marcado = 1;
						casilla7.simbolo = simbolo;

						//computadora
						casilla4.marcado = 1;
						casilla4.simbolo = compu;
						//printf("La casilla esta ocupada. Intentalo nuevamente.\n");
						}

			break;

			case '8': if(choice == '8' && casilla8.marcado == 0){

						//usuario
						casilla8.marcado = 1;
						casilla8.simbolo = simbolo;

						//computadora
						//casilla6.marcado = 1;
						casilla6.simbolo = compu;
						//printf("La casilla esta ocupada. Intentalo nuevamente.\n");
						}

			break;

			case '9': if(choice == '9' && casilla8.marcado == 0){

						//usuario
						casilla9.marcado = 1;
						casilla9.simbolo = simbolo;

						//computadora
						casilla3.marcado = 1;
						casilla3.simbolo = compu;
						//printf("La casilla esta ocupada. Intentalo nuevamente.\n");
						}

			break;
			}
	
	}while(casilla1.marcado == 1 || casilla2.marcado == 1 || casilla3.marcado == 1 || casilla4.marcado == 1 || 
	casilla5.marcado == 1 || casilla6.marcado == 1|| casilla7.marcado == 1 || casilla8.marcado == 1 || casilla9.marcado == 1);
}

int Check() {

	if(casilla1.marcado == casilla2.marcado && casilla2.marcado == casilla3.marcado){

		if(casilla1.simbolo == simbolo){
			return 0;
		}

		else {
			return 1;
		}
	}

	else if(casilla4.marcado == casilla5.marcado && casilla5.marcado == casilla6.marcado){

		if(casilla4.simbolo == simbolo){
			return 0;
		}

		else {
			return 1;
		}
	}

	else if(casilla7.marcado == casilla8.marcado && casilla8.marcado == casilla9.marcado){

		if(casilla7.simbolo == simbolo){
			return 0;
		}
		
		else {
			return 1;
		}
	}

	else if(casilla1.marcado == casilla4.marcado && casilla4.marcado == casilla7.marcado){

		if(casilla1.simbolo == simbolo){
			return 0;
		}
		
		else {
			return 1;
		}
	}

	else if(casilla2.marcado == casilla5.marcado && casilla5.marcado == casilla8.marcado){

		if(casilla2.simbolo == simbolo){
			return 0;
		}
		
		else {
			return 1;
		}
	}

	else if(casilla3.marcado == casilla6.marcado && casilla6.marcado == casilla9.marcado){

		if(casilla1.simbolo == simbolo){
			return 0;
		}
		
		else {
			return 1;
		}
	}

	else if(casilla1.marcado == casilla5.marcado && casilla5.marcado == casilla9.marcado){

		if(casilla1.simbolo == simbolo){
			return 0;
		}

		else {
			return 1;
		}
	}

	else if(casilla3.marcado == casilla5.marcado && casilla5.marcado == casilla7.marcado){

		if(casilla3.simbolo == simbolo){
			return 0;
		}
		
		else {
			return 1;
		}
	}

	else {
		return 2;
	}
}

void Finalizar(){ //ACOMODAAAAAAAAAAR

	int result;

	printf("\n¿Deseas guardar tu resultado como un archivo de texto?\n\n(1) Si      (2) no\n");
	scanf("%c",&result);

	if(result == '1'){
		printf("ok");
	}

}


int main(){

	int i,k;

	i = 0;

	Opcion();
	Tablero();

	do{
		system("cls");

		Ocupado();

		k = Check();

	}while(i <= 3 &&  k == 2);
	i++;

	Check();

	return 0;
}
