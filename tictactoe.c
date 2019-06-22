#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//VARIABLES GLOBALES: puesto que son utilizados en más de una función

typedef struct simbolo{
	int marcado; 
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

char simbolo; //Esta variable va a representar el caracter con el cual el usuario desea identificarse a lo largo del juego
char compu; //Esta variable va a representar el caracter con el que la computadora se identificará durante el juego. Su valor va a depender del valor de la variable simbolo
int loop = 0; //Esta variable representará el número de veces que el usuario haga movimientos. Se utilizará al final para imprimir el número de movimientos en un archivo de texto

///////////////////

//FUNCIONES
void Tablero();
void Opcion();
int Check();
void AI();
void User();
void Text();
void Resultado();

int main(){

	system("clear");
	Opcion();
	User();
	Check();
	Resultado();

	return 0;
}

/*
La funcion Tablero crea, como su nombre lo indica, el tablero en el que
se jugará el juego. Ennumerando las casillas del 1 al 9 con respecto a 
los valores iniciales de casillai.simbolo. Durante el juego, mientras el
usuario y la computadora ingresen valores, estos se irán modificando para
mostrarle al usuario el desarollo del juego
Efectos colaterales: me asigna un valor a y[20], que corresponde a la pista de la
palabra a adivinar.
*/
void Tablero(){

	printf("\n        %c   |   %c   |   %c   ",casilla1.simbolo,casilla2.simbolo,casilla3.simbolo);
	printf("\n     -----------------------");
	printf("\n        %c   |   %c   |   %c   ",casilla4.simbolo,casilla5.simbolo,casilla6.simbolo);
	printf("\n     -----------------------");
	printf("\n        %c   |   %c   |   %c   ",casilla7.simbolo,casilla8.simbolo,casilla9.simbolo);
}

/*
La funcion opcion permite que el usuario escoja la ficha con la que desea
identificarse durante el juego: X u O. En caso de que su selección sea distinta
a estas, le pide que vuelva a escoger.
Parametros: a) char (para escribir caracteres),
                simbolo <--- El cual está definido antes como una variable global
                puesto que se utiliza en distintas funciones.
Efectos colaterales: asigna valor a &simbolo
*/
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

/*
La funcion user permite que el usuario escoja la casilla donde desea jugar, asímismo,
luego se dirige a la función AI para alternar el juego, hasta que se cumpla el momento
en el que el jugador gana, pierde, o empata.
Parametros: a) char (para escribir caracteres),
                choice <-- representa la casilla en la que el usuario desea
                colocar su ficha, en caso de que le de el valor de '!', significa
                que quiere salir del juego
 
            b) int (para escribir un número) loop <-- permite que se cuenten las
            	veces que el usuario hizo un movimiento para así imprimirlo al final.
Efectos colaterales: modifica los valores iniciales de casillai.simbolo y casilla1.marcado
*/
void User(){

	char choice;

	do{

		loop++;

		do{
			Tablero();
			printf("\n\n  Jugador = %c      Computadora = %c",simbolo,compu);
			printf("\n\nEscoge una casilla. \nSi deseas salir del juego presiona !: ");
			fflush(stdin);
			scanf("%c",&choice);
		}while(choice < '!' || choice > '9');

	switch(choice){
			case '1': if(choice == '1'){

						system("clear");

						if(casilla1.marcado == 1){
							printf("\nLa casilla esta ocupada. Intentalo de nuevo\n");
						}

						else if(casilla1.marcado == 0){
							casilla1.marcado = 1;
							casilla1.simbolo = simbolo;

							AI();
						}
					}
			break;

			case '2': if(choice == '2'){

						system("clear");

						if(casilla2.marcado == 1){
							printf("\nLa casilla esta ocupada. Intentalo de nuevo\n");
						}

						else if(casilla2.marcado == 0){
							casilla2.marcado = 1;
							casilla2.simbolo = simbolo;

							AI();
						}	
					}	
			break;

			case '3': if(choice == '3'){

						system("clear");

						if(casilla3.marcado == 1){
							printf("\nLa casilla esta ocupada. Intentalo de nuevo\n");
						}

						else if(casilla3.marcado == 0){
							casilla3.marcado = 1;
							casilla3.simbolo = simbolo;

							AI();
						}	
					}	
			break;

			case '4': if(choice == '4'){

						system("clear");

						if(casilla4.marcado == 1){
							printf("\nLa casilla esta ocupada. Intentalo de nuevo\n");
						}

						else if(casilla4.marcado == 0){
							casilla4.marcado = 1;
							casilla4.simbolo = simbolo;

							AI();
						}
					}		
			break;

			case '5': if(choice == '5'){

						system("clear");

						if(casilla5.marcado == 1){
							printf("\nLa casilla esta ocupada. Intentalo de nuevo\n");
						}

						else if(casilla5.marcado == 0){
							casilla5.marcado = 1;
							casilla5.simbolo = simbolo;

							AI();
						}	
					}	
			break;

			case '6': if(choice == '6'){

						system("clear");

						if(casilla6.marcado == 1){
							printf("\nLa casilla esta ocupada. Intentalo de nuevo\n");
						}

						else if(casilla6.marcado == 0){
							casilla6.marcado = 1;
							casilla6.simbolo = simbolo;

							AI();	
						}	
					}	
			break;

			case '7': if(choice == '7'){

						system("clear");

						if(casilla7.marcado == 1){
							printf("\nLa casilla esta ocupada. Intentalo de nuevo\n");
						}

						else if(casilla7.marcado == 0){
							casilla7.marcado = 1;
							casilla7.simbolo = simbolo;

							AI();	
						}	
					}		
			break;

			case '8': if(choice == '8'){

						system("clear");

						if(casilla8.marcado == 1){
							printf("\nLa casilla esta ocupada. Intentalo de nuevo\n");
						}

						else if(casilla8.marcado == 0){
							casilla8.marcado = 1;
							casilla8.simbolo = simbolo;

							AI();

						}	
					}		
			break;

			case '9': if(choice == '9'){

						system("clear");

						if(casilla9.marcado == 1){
							printf("\nLa casilla esta ocupada. Intentalo de nuevo\n");
						}

						else if(casilla9.marcado == 0){
							casilla9.marcado = 1;
							casilla9.simbolo = simbolo;
							AI();
						}	
					}		
			break;

			case '!': if(choice == '!'){
							printf("\nHasta luego!");
							exit(0);
						}

			break;
			
			case '0': if(choice < '1' || choice >'9'){

							system("clear");
							printf("\nLa casilla no es valida\n ");
						}		
			}	
	
	}while(Check() != 0 && Check() != 1);
}

/*
La funcion AI crea un archivo de texto con las palabras usadas en el
juego y luego escoge una de ellas al "azar", y devuelve esa palabra escogida.
Tambien crea un archivo de texco con las pistas de cada palabra a adivinar, y
pasa por referencia esa pista.
Parametros: a) int (para escribir un numero),
                random<-- esta variable representa la casilla en la que la 
                computadora introducira una ficha, la cual va a ser escogida
                por medio de la funcion rand()
 
            b) int (para escribir un número) k <-- permite que se vuelvan a 
           		escoger valores random en caso de que el número arrojado coincida
           		con un número de casilla donde k != 1 (es decir, casillas ocupadas)
Efectos colaterales: asigna nuevos valores a casillai.marcado y casilla1.simbolo 
dependiendo de los valores que arroje la función rand()
*/
void AI(){

	int random,k;

	srand(time(NULL));

	do{
		random = rand() % 9 + 1;  //de esta manera solo producira numeros del 1 al 9

		k = 0; //al cambiar el valor de k a 1, significará que la casilla está ocupada. Cuando el loop detecte que ya está ocupada, volverá a comenzar hasta conseguir un espacio
		
		if (random == 1 && casilla1.marcado == 0){
			casilla1.marcado = 1;
			casilla1.simbolo = compu;
			k = 1;
		}

		if (random == 2 && casilla2.marcado == 0){
			casilla2.marcado = 1;
			casilla2.simbolo = compu;
			k = 1;
		}

		if (random == 3 && casilla3.marcado == 0){
			casilla2.marcado = 1;
			casilla2.simbolo = compu;
			k = 1;
		}

		if (random == 4 && casilla4.marcado == 0){
			casilla4.marcado = 1;
			casilla4.simbolo = compu;
			k = 1;
		}

		if (random == 5 && casilla5.marcado == 0){
			casilla5.marcado = 1;
			casilla5.simbolo = compu;
			k = 1;
		}

		if (random == 6 && casilla6.marcado == 0){
			casilla6.marcado = 1;
			casilla6.simbolo = compu;
			k = 1;
		}

		if (random == 7 && casilla7.marcado == 0){
			casilla7.marcado = 1;
			casilla7.simbolo = compu;
			k = 1;
		}

		if (random == 8 && casilla8.marcado == 0){
			casilla8.marcado = 1;
			casilla8.simbolo = compu;
			k = 1;
		}

		if (random == 9 && casilla9.marcado == 0){
			casilla9.marcado = 1;
			casilla9.simbolo = compu;
			k = 1;
		}		

	}while(k == 0);
}

/*
La funcion check revisa las distintas condiciones en el que el jugador puede
ganar, perder, o empatar. De acuerdo a esto, puede retornar tres valores distintos
que son evaluados a continuación por la función Resultado()

Retorno: a)Si retorna 0: implica que se ha cumplido una de las ocho posibles condiciones
			para que el jugador haya ganado
		 b)Si retorna 1: implica que se ha cumplido una de las ocho posibles condiciones
			para que el jugador haya perdido.
		 c)Si retorna 2: significa que el tablero está lleno y no se cumplieron las
		 	condiciones para que ganase o perdiese.
*/
int Check() {


	if(casilla1.marcado == casilla2.marcado && casilla2.marcado == casilla3.marcado){

		if(casilla1.simbolo == simbolo && casilla2.simbolo == simbolo && casilla3.simbolo && simbolo){
			return 0;
		}

		if(casilla1.simbolo == compu && casilla2.simbolo == compu && casilla3.simbolo == compu){
			return 1;
		}
	}

	if(casilla4.marcado == casilla5.marcado && casilla5.marcado == casilla6.marcado){

		if(casilla4.simbolo == simbolo && casilla5.simbolo == simbolo && casilla6.simbolo == simbolo){
			return 0;
		}

		if(casilla4.simbolo == compu && casilla5.simbolo == compu && casilla6.simbolo == compu){
			return 1;
		}
	}

	if(casilla7.marcado == casilla8.marcado && casilla8.marcado == casilla9.marcado){

		if(casilla7.simbolo == simbolo && casilla8.simbolo == simbolo && casilla9.simbolo == simbolo){
			return 0;
		}
		
		if(casilla7.simbolo == compu && casilla8.simbolo == compu && casilla9.simbolo == compu){
			return 1;
		}
	}

	if(casilla1.marcado == casilla4.marcado && casilla4.marcado == casilla7.marcado){

		if(casilla1.simbolo == simbolo & casilla4.simbolo == simbolo && casilla7.simbolo == simbolo){
			return 0;
		}
		
		if(casilla1.simbolo == compu && casilla4.simbolo == compu && casilla7.simbolo == compu){
			return 1;
		}
	}

	if(casilla2.marcado == casilla5.marcado && casilla5.marcado == casilla8.marcado){

		if(casilla2.simbolo == simbolo && casilla5.simbolo == simbolo && casilla8.simbolo == simbolo){
			return 0;
		}
		
		if(casilla2.simbolo == compu && casilla5.simbolo == compu && casilla8.simbolo == compu){
			return 1;
		}
	}

	if(casilla3.marcado == casilla6.marcado && casilla6.marcado == casilla9.marcado){

		if(casilla3.simbolo == simbolo && casilla6.simbolo == simbolo && casilla9.simbolo == simbolo){
			return 0;
		}
		
		if(casilla3.simbolo == compu && casilla6.simbolo == compu && casilla9.simbolo == compu){
			return 1;
		}
	}

	if(casilla1.marcado == casilla5.marcado && casilla5.marcado == casilla9.marcado){

		if(casilla1.simbolo == simbolo && casilla5.simbolo == simbolo && casilla9.simbolo == simbolo){
			return 0;
		}

		if(casilla1.simbolo == compu && casilla5.simbolo == compu && casilla9.simbolo == compu){
			return 1;
		}
	}

	if(casilla3.marcado == casilla5.marcado && casilla5.marcado == casilla7.marcado){

		if(casilla3.simbolo == simbolo && casilla5.simbolo == simbolo && casilla7.simbolo == simbolo){
			return 0;
		}
		
		if(casilla3.simbolo == compu && casilla5.simbolo == compu && casilla7.simbolo == compu){
			return 1;
		}
	}

	else {
		return 2;
	}
}

/*
La funcion Resultado toma los valores retornados por Check() y dependiendo de éstos, le
informa al usuario sobre el resultado del juego: si ganó, perdió o empató, y le pregunta
si desea crear un archivo de texto donde se muestren estos resultados. En caso de una respuesta
negativa, termina el juego automáticamente
Parametros: a) int (para escribir números),
                result <-- representa la decision del jugador de si guardar sus
                resultados como un archivo de texto o no. EN caso afirmativo,
                se dirigira a la funcion Text(); En caso negativo, se finalizara
                automaticamente el juego
Efectos colaterales: Informa al usuario sobre su estátus al finalizar el juego.
*/
void Resultado(){

	int result;

	if(Check() == 0){

		do{
			Tablero();
			printf("\n\nFelicidades, Ganaste!");
			printf("\nDeseas guardar tu resultado como archivo de texto?");
			printf("\n             1. si              2. no             ");
			fflush(stdin);		
			scanf("%d",&result);

			if(result == 1){
				Text();
				printf("\nArchivo guardado. Hasta luego!");
				exit(0);
			}

			else if (result == 2){
				printf("\nHasta luego!");
				exit(0);
			}

			else if (result != 1 || result != 2){
				printf("\nEsa no es una opcion valida");
			}

		}while(result != 1 || result != 2);	
	}

	else if(Check() == 1){

		do{
			Tablero();
			printf("\n\nLo lamento. Perdiste :(");
			printf("\nDeseas guardar tu resultado como archivo de texto?");
			printf("\n             1. si              2. no             ");
			fflush(stdin);		
			scanf("%d",&result);

			if(result == 1){
				Text();
				printf("\nArchivo guardado. Hasta luego!");
				exit(0);
			}

			else if (result == 2){
				printf("\nHasta luego!");
				exit(0);	
			}

			else if (result != 1 || result != 2){
				printf("\nEsa no es una opcion valida");
			}

		}while(result != 1 || result != 2);	
	}

	else if(Check() == 2){

		do{
			Tablero();
			printf("\n\nHa sido un empate");
			printf("\nDeseas guardar tu resultado como archivo de texto?");
			printf("\n             1. si              2. no             ");
			fflush(stdin);		
			scanf("%d",&result);

			if(result == 1){
				Text();
				printf("\nArchivo guardado. Hasta luego!");
				exit(0);	
			}

			else if (result == 2){
				printf("\nHasta luego!");
				exit(0);	
			}

			else if (result != 1 || result != 2){
				printf("\nEsa no es una opcion valida");
			}

		}while(result != 1 || result != 2);	
	}	
}

/*
La funcion Text tiene como trabajo crear un archivo de texto si el usuario así lo desea.
Efectos colaterales: un archivo de texto con el resultado de la partida, los movimientos
realizados por el usuario, el nombre del juego, y el tablero al momento final.
*/
void Text() {	

	FILE *fent;
	fent = fopen("resultadotictactoe.txt","w");

	if(fent == NULL){
        printf("ERROR: no se puede crear archivo\n");
        }

    else{

		fprintf(fent,"        JUEGO DE LA VIEJA\n");

		fprintf(fent,"\n        %c   |   %c   |   %c   ",casilla1.simbolo,casilla2.simbolo,casilla3.simbolo);
		fprintf(fent,"\n     -----------------------");
		fprintf(fent,"\n        %c   |   %c   |   %c   ",casilla4.simbolo,casilla5.simbolo,casilla6.simbolo);
		fprintf(fent,"\n     -----------------------");
		fprintf(fent,"\n        %c   |   %c   |   %c   ",casilla7.simbolo,casilla8.simbolo,casilla9.simbolo);

		fprintf(fent,"\n\nTotal de jugadas realizadas: %d",loop);

		if(Check() == 0){
						fprintf(fent,"\n\nGANASTE!");
					}

		else if(Check() == 1){
						fprintf(fent,"\n\nPERDISTE!");
					}

		else if(Check() == 2){
						fprintf(fent,"\n\nJUEGO EMPATADO");
					}
		}

		fclose(fent);
}