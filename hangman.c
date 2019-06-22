#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define Palabras "text.txt"
#define Pistas "text1.txt"
#define Partida "text2.txt"
#define Perdiste "text3.txt"


//Variables globales:

char aux[20]={'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-',};
int y=0;
int vidas=10;
char adivinadas[50];


/*
La funcion palabras crea un archivo de texto con las palabras usadas en el
juego y luego escoge una de ellas al "azar", y devuelve esa palabra escogida.
Tambien crea un archivo de texco con las pistas de cada palabra a adivinar, y
pasa por referencia esa pista.
Parametros: a) char (para escribir cadena de caracteres),
                x[20] <-- arreglo donde esta guardada la letra a adivinar.
            b) char y[20] <-- esta guardada la pista.
Retorno: me retorna la palabra que se va a adivinar en el juego.
Efectos colaterales: me asigna un valor a y[20], que corresponde a la pista de la
palabra a adivinar.
*/

char palabras(char x[20], char y[20]){

  int i, j, numero;

  //La computadora genera un numero al "azar"

  srand(time(NULL));
  numero= rand()%4;
  numero= (rand()%3)+1;

  //Abajo se guardan las palabras a adivinar en el juego en un archivo de texto.

  FILE *words = fopen(Palabras, "w");

     if (words != NULL){
       fprintf(words, "%s\n%s\n%s\n", "casa", "perro", "gato");
       fclose(words);
     }
     else (printf("ERROR\n")); //no se puede abrir el archivo

  // Se escoge una palabra al "azar".

  words= fopen(Palabras,"r");

    if(words==NULL){
      printf("ERROR");
    }
    else{
      for (i=0; i<numero; i++){
        if(!feof(words))
        fscanf(words, "%s" , x);
      }
      fclose(words);
    }

  //Abajo se guardan las pistas de cada palabra a adivinar en un archivo de texto.

  FILE *clues = fopen(Pistas, "w");

    if (clues != NULL){
      fprintf(clues, "%s\n%s\n%s\n", "Tu_vives_en...", "Wuau", "Miau");
      fclose(clues);
    }
    else (printf("ERROR\n"));

    clues = fopen(Pistas, "r");
        if (clues==NULL){
          printf("ERROR\n");
        }
        else{
          for (j=0; j<numero; j++){
            fscanf(clues, "%s", y);
          }
          fclose(clues);
        }

  return *x;
}

/*
La funcion guardar, en el caso que el usuario haya ganado el juego, me imprime
en un archivo de texto unos datos de la partida. El mismo caso sucede si el
usuario perdio.
Parametros: a) char (tipo de variable para escribir cadena de caracteres),
                x[20] <-- arreglo donde esta guardada la letra a adivinar.
            b) int (tipo de variable para escribir un entero)
                z <-- z representa el numero que viene de la funcion adivinar, el
                cual me indica si el usuario gano (z==88) o perdio (z==99)
Efectos colaterales: crea un archivo de texto con los datos de la partida, dependiendo
si el ususario gano o no.
*/

void guardar(char x[20], int z){

  int i;

 //Si z es 88, significa que el usuario perdio

  if(z==88){

    FILE *partidagan = fopen(Partida, "w");
    if(partidagan == NULL){
      printf("ERROR\n"); //No se abrio el documento.
    }

    else {

      fprintf(partidagan, "\n Juego del Ahorcado\n\n");
      fprintf(partidagan, "\n\tPalabra que adivinaste: %s\n", x);
      fprintf(partidagan, "\n\tCantidad de vidas restantes: %d\n", vidas);
      fprintf(partidagan, "\n\tLetras introducidas: ");
      for (i=0; i<strlen(adivinadas); i++){
        fprintf(partidagan, "%c ", adivinadas[i]);
      }
      fprintf(partidagan, "\n\n\tGanaste!");
      fclose(partidagan);
  }
}

 //Si z es 99, significa que el usuario perdio

  if (z==99){

    FILE *partidaper = fopen(Perdiste, "w");
    if (partidaper == NULL){
      printf("ERROR\n"); //no se pudo abrir el archivo.
    }

    else {

      fprintf(partidaper, "\n Juego del Ahorcado\n\n");
      fprintf(partidaper, "\n\tPalabra que no adivino: %s\n", x);
      fprintf(partidaper, "\n\tLetras introducidas: ");
      for (i=0; i<strlen(adivinadas); i++){
        fprintf(partidaper, "%c ", adivinadas[i]);
      }
      fprintf(partidaper, "\n\n\tPerdiste, intentalo de nuevo!");
      fclose(partidaper);
   }
  }
}

/*
La funcion chequeo verifica si la letra introducida por el usuario esta en
la palabra a adivinar. Si lo esta, imprime la letra en el orden correspondiente,
Si no lo esta, me resta una vida en la funcion "adivinar".
Parametros: a) char (tipo de variable para escribir cadena de caracteres),
                x[20] <-- arreglo donde esta guardada la letra a adivinar.
            b) char (tipo de variable para escribir un caracter)
                c <-- la letra que introdujo el usuario
Retorno: el numero de veces que la persona adivino correctamente.
Efectos colaterales: me guarda dentro de un arreglo (aux[]) las letras que se han
adivinado correctamente y dentro de un arreglo (adivinadas[]) todas la letras que
han sido introducidas por el ususario.
*/

int chequeo(char c, char x[20]){

  int i,j, z=0;

//Este for chequea si la letra introducida esta contenida en la palabra a adivinar.

  for(i=0; i<(strlen(x)+1); i++){

    if(c == x[i] && c != aux[i] ){

      aux[i]= c;
      y++;

      //A continuacion aseguramos que si el usuario adivino correctamente antes
      //que se acabaran sus vidas, salga del juego.

      if(y==strlen(x)) {
        y=0;
        system("clear");
        for(j=0; j<strlen(x); j++){
        printf("%c", aux[j]);
        }
        adivinadas[strlen(x)]= c;
        printf("\n");
        return 45;
      }

      z++;
    }
  }

//Imprimimos la palabra que contiene las letras adivinadas. Si no ha adivinado
//ningun letra, imprimira ----.

  system("clear");
  for(j=0; j<strlen(x); j++){
  printf("%c", aux[j]);
  }
  printf("\n");

  return z;
}

/*
La funcion menu me muestra que opcion deseo elegir luego de terminar una partida.
Si salir del juego, jugar de nuevo o guardar mis datos en un archivo de texto.
Parametros: a) char (tipo de variable para escribir cadena de caracteres),
                x[20] <-- arreglo donde esta guardada la letra a adivinar.
            b) int (tipo de variable para escribir un entero)
                z <-- z representa el numero que viene de la funcion adivinar, el
                cual me indica si el usuario gano (z==88) o perdio (z==99)
Efectos colaterales: si el usuario escoge la opcion 1, me llama a guardar. Si el
usuario escoge la opcion 2, sale del juego.
*/

void menu(char x[20], int z){

  int t= z;
  char pista[20];
  char palabra[20];
  char opcion;
  int  enter = 0;


  printf("Que desea hacer ahora? Escriba la opcion deseada y presione enter.\n");
  printf(" - 1 - Guardar el resultado de tu partida como un archivo de texto.\n");
  printf(" - ! - Salir del juego.\n");
  scanf("%c", &opcion);
  fflush(stdin);
  system("clear");

  //Opcion 1: guardar en un archivo el resultado de la partida.

  if (opcion == 1){

      guardar(x, t);
      printf("\nArchivo guardado. Gracias por jugar!\n");
      exit(0);
    }

  //Opcion 3: salir del juego.

  if (opcion == '!'){

    printf("Hasta luego!\n");
    exit(0);
  }
}

/*
la funcion adivinar recibe una letra del usuario y se encarga de ver si esta
o no esta dentro de la palabra a adivinar.
Parametros: a) char (tipo de variable para escribir cadena de caracteres),
                x[20] <-- arreglo donde esta guardada la letra a adivinar.
Efectos colaterales: me guarda valores en el arreglo adivinadas[], que corresponderan
a las letras ingresadas por el usuario. Me resta vidas si el usuario ingreso
una letra que no corresponde a la palabra a adivinar.
*/

void adivinar(char x[20]){

  char letra;
  int i, j, z;

  printf("Palabra a adivinar: \n");
  for(z=0; z<strlen(x); z++){
    printf("%c", aux[z]);
  }
  printf("\nVidas iniciales: %d\n", 10);
  printf("Introduzca una letra: \n");
  scanf("%c", &letra);
  adivinadas[0]= letra;
  fflush(stdin);

//Empieza a comprobarse la jugada.

  for(i=0; i<20; i++){
    j= chequeo(letra, x);
    if(j==0){
      vidas--;
      printf("\nVidas restantes: %d\n", vidas);
      if(vidas==0){
        printf("Usted ha perdido.\n");
        menu(x, 99);
        break;
      }
      printf("\nIntroduzca una letra: \n");
      scanf("%c", &letra);
      fflush(stdin);
      adivinadas[i+1]= letra;

     }
    else if(j==45){
      printf("Ganaste!\n");
      menu(x, 88);
      break;
     }

     else {
      printf("Vidas restantes: %d\n", vidas);
      printf("\nIntroduzca una letra: \n");
      scanf("%c", &letra);
      fflush(stdin);
      adivinadas[i+1]= letra;
     }

   }
}


int main(){

  int i=0;
  char palabra[20];
  char pista[20];
  int enter = 0;

  printf("Bienvenido al Juego del Ahorcado!\n");
  printf("Presione enter para empezar.\n");
  while (enter != '\r' && enter != '\n') { enter = getchar(); }
  fflush(stdin);
  system("clear");

  palabra[20]= palabras(palabra, pista);

  printf("La pista es: %s\n", pista);

  adivinar(palabra);


return 0;
}