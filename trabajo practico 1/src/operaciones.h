#ifndef OPERACIONES_H_
#define OPERACIONES_H_

/* brief calcula la suma de 2 numeros enteros
 * param1 recibe un número entero, para sumar
 * param2 recibe un número entero para sumar
 * param3 recibe la direccion de la variable para guardar el resultado suma*/
void sumar(int num1, int num2, int* resulSuma);

/* brief calcula la resta de 2 numeros enteros
 * param1 recibe el primer número entero, para restar
 * param2 recibe el segundo número entero para restar
 * param3 recibe la direccion de la variable para guardar el resultado de la resta */
void restar(int num1, int num2, int* resulResta);

/* brief calcula la division de 2 numeros enteros, y lo devuelve como un float
 * param1 recibe el primer número entero, para dividiendo
 * param2 recibe el segundo número entero para divisior
 * param3 recibe la direccion de la variable para guardar el resultado de la divsion y lo guarda como un float */
void division(int num1,int num2,float* resulDivison);

/* brief hago la multiplicacion de 2 numeros enteros
 * param1 recibe el primer número entero, para multiplicacion
 * param2 recibe el segundo número entero para multiplicacion
 * param3 recibe la direccion de la variable para guardar el resultado de la multiplicacion */
void multiplicacion(int num1,int num2,int* resulMultiplicacion);

/* brief hago el factoreo del primer numero entero
 * param1 recibe el primer número entero, para hacer el factoreo
 * param2 recibe la direccion de la variable para guardar el resultado del factoreo */
void factorial(int num1,long int* resulFactorialA);




#endif /* OPERACIONES_H_ */
