/*
 * employe.h
 *
 *  Created on: 13 oct 2021
 *      Author: facun
 */

#ifndef EMPLOYE_H_
#define EMPLOYE_H_
typedef struct {
	int idEmployee;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
} Employee;

#define TAME_STRUC 1000

/*brief Para indicar que todas las posiciones en la matriz estan vacias, esta funcian coloca la bandera (isEmpty) en VERDADERO en todas las posiciones de la matriz
 *\param list Employee* Puntero a la variedad de empleados
 *\param len int Longitud de la matriz
 *\return int Return (-1) si Error [Longitud no valida o puntero NULO] - (0) si esta bien*/
int initEmployees(Employee *list, int len);
/** \brief  busca en el campo isEmpty del array, con 0 para saber que esta libre
* \param pArray el puntero al primer array
* \param cantidadDeArray int, a recorrer
* \return int Retorno (-1) si Error, retorna un int de posicion si todo Ok
*/
int buscaLibre(Employee pArray[], int cantidadDeArray);

/*brief agregar en una lista existente de empleados los valores recibidos como parametros en la primera posicion vacia
 *\param array employee* es el punto de mi array del main
* \param len int es la tamanio de array
* \return int Return (-1) si Error [Longitud no valida o puntero NULL o sin espacio libre] - (0) si esta bien*/
int addEmployee(Employee* array,int len, int* contadorId);

/*\Imprime solo un empleado del array.
* \param Empleado Employee*/
void printEmploye(Employee Empleado);

/*\Imprime todos los empleados de la array.
* \param list Employee* para toda la array
* \param len int le pasa el tamanio de la array
* \return int*/
int imprimirEmployees(Employee Empleado[], int len);

/*brief modifica a un empleado
 * param1 empleado[] employe pasa la array
 * param2 posicion int pasa solo la posicion de la array que se quiere modificar*/
int modificaEmployee(Employee Empleado[], int posicion);

/*\brief Busca un empleado en el arrat.
* \param list Employee* pasa la array
* \param len int pasa el tamanio de la array
* \return Return devuelve la ID*/
int  findEmployeeById(Employee Empleado[], int len);

/** \brief Elimina de manera logica (isEmpty Flag en 0) un empleado recibiendo como parametro su Id.
* \param list Employee* pasa la array
* \param posicion int pasa la posicion que se quiere dar de baja
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok*/
int removeEmployee(Employee* list,int posicion);


/** \brief Sort Ordena el array de empleados por apellido y sector de manera ascendente o descendente.
* \param list Employee* pasa toda la array
* \param len int pasa el tamanio de mi arrat
* \param order int le pasa si queres que ordene ascendete(1) o descendete(0)
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok*/
int sortEmployees(Employee* list, int len, int order);


/*brief hace el calculo de cuanto es el promedio de sueldo
 * param1 PromSueldo *float donde se guarda el promedio de sueldo
 * param2 array  employe pasa toda la array
 * param3 len int pasa el tamanio de la array
 * */
void EmployeePromSalario(float* PromSueldo, Employee array[], int len);


/*brief muestra todos los empleados con un sueldo mayor al promedio
 * param1 pPromSueldo *float donde se guarda el promedio de sueldo
 * param2 array  employe pasa toda la array
 * param3 len int pasa el tamanio de la array
 * */
void EmployeesListaSalario(Employee array[], int len, float sueldo);


#endif /* EMPLOYE_H_ */
