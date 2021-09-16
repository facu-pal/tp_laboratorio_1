#include <stdio.h>
#include <stdlib.h>

void sumar(int num1, int num2, int* resulSuma){
	*resulSuma = num1 + num2 ;
}

void restar(int num1, int num2, int* resulResta){
	*resulResta = num1- num2;
}

void division(int num1,int num2,float* resulDivison){
	*resulDivison =  (float) num1 /num2;
}

void multiplicacion(int num1,int num2,int* resulMultiplicacion){
	*resulMultiplicacion = num1 * num2;
}

void factorial(int num1,long int* resulFactorialA){

	int i;
	*resulFactorialA = 1;
	for(i = 1;i<=num1; i++){
		*resulFactorialA *= i;
	}
}
