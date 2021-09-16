#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"


void menu(int *num1, int *num2, int *resulSuma, int *resulResta,float *resulDivison, int *resulMultiplicacion,long int *resulFactorialA,long int *resulFactorialB) {
	setbuf(stdout, NULL);

	int menu = 0;//esta variable es para saber a que opcion del menu desea ingresar
	int flagNum1 = 0; //esta bandera es para saber si ingreso el primer numero y saber si puede entre a la opcion 3
	int flagNum2 = 0; //esta bandera es para saber si ingreso el segundo numero y saber si puede entre a la opcion 3
	int FlagCalculo = 0; //esta bandera es para saber si ya realizo los calculos
	int flagDivisionCero = 0; //esta bandera es para saber si el segundo numero(el divisor) ingreso un 0 le salga un mensaje de que no se puede dividir por 0

	do {
		if(flagNum1 != 0){
			printf("\n 1. Ingrese el primer operador (A=%d) \n",*num1);
		}else{
			printf("\n 1. Ingrese el primer operador (A=X) \n");
		}
		if(flagNum2 != 0){
			printf(" 2. Ingrese el segundo operador (B=%d) \n",*num2);
;
		}else{
			printf(" 2. Ingrese el segundo operador (B=Y) \n");
		}

		printf(" 3. Calcular todas las operaciones \n");
		printf(" 4. Informar resultado \n");
		printf(" 5. Salir \n");

		scanf("%d", &menu);
		switch (menu) {
		case 1:
			printf(" ¿Que numero desea ingresar para el primer operador? \n");
			scanf("%d", num1);
			flagNum1 = 1;
			break;
		case 2:
			printf(" ¿Que numero desea ingresar para el segundo operador? \n");
			scanf("%d", num2);
			flagNum2 = 2;
			break;
		case 3:
			if (flagNum1 == 0) {
				printf("Ingrese un numero en la primera opcion");
			} else if (flagNum2 == 0) {
				printf("Ingrese un numero en la segunda opcion");
			} else {
				printf(" a) Calcular la suma (%d + %d) \n", *num1, *num2);
				sumar(*num1, *num2, resulSuma);
				printf(" b) Calcular la resta (%d - %d) \n", *num1, *num2);
				restar(*num1, *num2, resulResta);
				printf(" c) Calcular la division (%d / %d) \n", *num1, *num2);
				if(*num2 == 0){
					flagDivisionCero = 1;
				}else{
					division(*num1, *num2,resulDivison);
					flagDivisionCero=0;
				}
				printf(" d) Calcular la multiplicacion (%d * %d) \n", *num1,*num2);
				multiplicacion(*num1, *num2, resulMultiplicacion);
				printf(" e) Calcular el factorial del primer numero (%d) \n",*num1);
				factorial(*num1, resulFactorialA);
				printf(" f) Calcular el factorial del segundo numero (%d) \n",*num2);
				factorial(*num2, resulFactorialB);
				FlagCalculo = 1;
			}

			break;
		case 4:
			if (FlagCalculo == 0) {
				printf("Primero debe calcular (opcion 3).");
			} else {
				printf(" a) el resultado de (%d+%d) es: %d\n", *num1, *num2, *resulSuma);
				printf(" b) El resultado de (%d-%d) es: %d\n", *num1, *num2, *resulResta);
				if(flagDivisionCero == 1){
					printf(" c) No es posible dividir por cero \n");
				}else{
					printf(" c) El resultado de (%d/%d) es: %.2f \n", *num1, *num2,*resulDivison);
				}
				printf(" d) El resultado de (%d*%d) es: %d\n", *num1, *num2,*resulMultiplicacion);
				printf(" e) El factorial de %d es: %li y El factorial de %d es: %li  \n",*num1, *resulFactorialA,*num2, *resulFactorialB);
			}
			break;
		case 5:
			break;
		default:
			printf("No elegiste ninguna opcion \n");
		}
	} while (menu != 5);

}
