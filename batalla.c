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
	int numBarcos = 3;

	iniciarTablero();

	for(numBarcos = 0 ; numBarcos < 3 ; numBarcos++){
		mostrarTablero();
		printf("Ingrese BARCO N° %d de 3: \nLETRA: ", numBarcos+1);
		scanf("%d",&coord[0]);
		printf("NUMERO: ");
		scanf("%d",&coord[1]);
		ingresoBarcos(coord);
	}
	

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
	printf("   +--------------------");

	for( i = 0 ; i < FILMAX ; i++ ){
		if(i > 0)
			printf("\n   ---------------------");
		printf("\n %d |", i+1);
		for( j = 0 ; j < COLMAX ; j++)
			printf(" %c |", tablero[i][j]);
	}
	printf("\n\n");
}

void ingresoBarcos(int coord []){

	int i, j;

	for( i = 0 ; i < FILMAX ; i++ )
		for( j = 0 ; j < COLMAX ; j++)
			tablero[coord[0]][coord[1]] = 'X' ;
}