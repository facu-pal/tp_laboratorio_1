
#ifndef MENU_H_
#define MENU_H_

/* brief va a ver un menu de opciones donde ingresando cada opcion va a realizar un proceso difirente (opcion 1 y 2 carga la variable
 * opcion 3 llama a todas las funciones de operaciones y las ejecuta, opcion 4 muestra todos los resultados de la operaciones y opcion 5 cierra el programa)
 * param1 recibe el primer número entero, para realizar las operaciones
 * param2 recibe el segundo número entero,para realizar las operaciones
 * param3 es donde se va a guardar la suma de los 2 numeros ingresados
 * param4 es donde se va a guardar la resta de los 2 numeros ingresados
 * param5 es donde se va a guardar la division de los 2 numeros ingresados
 * param6 es donde se va a guardar la multiplicacion de los 2 numeros ingresados
 * param7 es donde se va a guardar el factorial del primer numeros ingresados
 * param8 es donde se va a guardar el factorial del segundo numeros ingresados
 */
void menu(int* num1, int* num2, int* resulSuma,int* resulResta,float* resulDivison,int* resulMultiplicacion,long int* resulFactorialA,long int* resulFactorialB );

#endif /* MENU_H_ */
