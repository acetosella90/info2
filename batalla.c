#include <stdio.h>
#include <stdlib.h>

#define COLMAX 5
#define FILMAX 5

int tablero[FILMAX][COLMAX];

void iniciarTablero(void);

void mostrarTablero(void);

int main(void){

	system("clear");



	iniciarTablero();
	mostrarTablero();

	return 0;
}

void iniciarTablero(){

	int i, j;

	for( i = 0 ; i < FILMAX ; i++ )
		for( j = 0 ; j < COLMAX ; j++)
			tablero[i][j] = 0 ;
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
			printf(" %d |", tablero[i][j]);
	}
	printf("\n\n");
}