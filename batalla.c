#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLMAX 5
#define FILMAX 5

int tablero[FILMAX][COLMAX];

void iniciarTablero(void);
void mostrarTablero(void);
void ingresoBarcos(int []);

int main(void){

	system("clear");

	int coord[2];
	char letra[2];
	int numBarcos = 3;

	iniciarTablero();

	for(numBarcos = 0 ; numBarcos < 3 ; numBarcos++){
		mostrarTablero();
		printf("Ingrese BARCO N° %d de 3: \nLETRA(minuscula): ", numBarcos+1);
		
		scanf("%s", letra);
		
		switch(letra[0]){
		    case 'a'  :
		       coord[0] = 0;
		       break; 
		    case 'b'  :
		       coord[0] = 1;
		       break;
		    case 'c'  :
		       coord[0] = 2;
		       break; 
		    case 'd'  :
		       coord[0] = 3;
		       break; 
		    case 'e'  :
		       coord[0] = 4;
		       break;
		}

		printf("NUMERO: ");
		scanf("%d",&coord[1]);
		ingresoBarcos(coord);
	}
	mostrarTablero();

	return 0;
}

void iniciarTablero(){

	int i, j;

	for( i = 0 ; i < FILMAX ; i++ )
		for( j = 0 ; j < COLMAX ; j++)
			tablero[i][j] = '0' ;
}

void mostrarTablero(){

	int i, j;

	printf("\n");
	printf("     Tablero de Matias\n\n");
	printf("     A   B   C   D   E\n");
	printf("   +---+---+---+---+---+");

	for( i = 0 ; i < FILMAX ; i++ ){
		if(i > 0)
			printf("\n   +---+---+---+---+---+");
		printf("\n %d |", i+1);
		for( j = 0 ; j < COLMAX ; j++)
			if(tablero[i][j] == 'X')
				printf("\x1b[31m X \x1b[0m|"); // printf("\x1b[34m X \x1b[0m|");

			else
				printf(" %c |", tablero[i][j]);
	}
    printf("\n");
	printf("   +---+---+---+---+---+");
	printf("\n\n");
}

void ingresoBarcos(int coord []){

	int i, j;

	for( i = 0 ; i < FILMAX ; i++ )
		for( j = 0 ; j < COLMAX ; j++)
			tablero[(coord[1]-1)][coord[0]] = 'X' ;
}