#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int main(void) {
	setbuf(stdout, NULL);

	int num1;
	int num2;
	int resulSuma;
	int resulResta;
	float resulDivison;
	int resulMultiplicacion;
	long int resulFactorialA;
	long int resulFactorialB;

	menu(&num1,&num2,&resulSuma,&resulResta,&resulDivison,&resulMultiplicacion,&resulFactorialA, &resulFactorialB);


	return EXIT_SUCCESS;
}
