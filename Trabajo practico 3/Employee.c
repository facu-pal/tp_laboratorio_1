#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "utn.h"


Employee* employee_new(){
	Employee *empleado;
	empleado = (Employee*) malloc(sizeof(Employee));
	if (empleado != NULL) {
		empleado->id = 0;
		strcpy(empleado->nombre, "");
		empleado->horasTrabajadas = 0;
		empleado->sueldo = 0;
	}
	return empleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr){
	Employee *empleado = employee_new();

	if (empleado != NULL) {
		employee_setId(empleado, atoi(idStr));
		employee_setNombre(empleado, nombreStr);
		employee_setHorasTrabajadas(empleado, atoi(horasTrabajadasStr));
		employee_setSueldo(empleado, atoi(sueldoStr));
	}
	return empleado;
}
void employee_delete(Employee* this){
	free(this);
}

int employee_setId(Employee* this,int id){
	int retorno = -1;
	if (this != NULL) {
		this->id = id;
		retorno = 0;
	}
	return retorno;
}
int employee_getId(Employee* this,int* id){
	int retorno = -1;
	if (this != NULL && id != NULL) {
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int employee_setNombre(Employee* this,char* nombre){
	int retorno = -1;
	if (this != NULL) {
		strcpy(this->nombre, nombre);
		retorno = 0;
	}
	return retorno;
}
int employee_getNombre(Employee* this,char* nombre){
	int retorno = -1;

	if (this != NULL && nombre != NULL) {
		strcpy(nombre, this->nombre);
		retorno = 0;
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
	int retorno = -1;
	if (this != NULL) {
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
	int retorno = -1;
	if (this != NULL && horasTrabajadas != NULL) {
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo){
	int retorno = -1;

	if (this != NULL) {
		this->sueldo = sueldo;
		retorno = 0;
	}
	return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo){
	int retorno = -1;
	if (this != NULL && sueldo != NULL) {
		*sueldo = this->sueldo;
		retorno = 0;
	}
	return retorno;
}

void employee_print(Employee* this)
{
	int auxId;
	int auxHoras;
	int auxSueldo;
	char auxNombre[128];
	if(employee_getId(this, &auxId)==0 && employee_getNombre(this, auxNombre)==0 &&  employee_getHorasTrabajadas(this, &auxHoras)==0 && employee_getSueldo(this, &auxSueldo)==0)
	{
		printf("Id: %d - Nombre: %s - Horas Trabajadas: %d - Sueldo: %d\n",auxId, auxNombre,auxHoras,auxSueldo);
	}
}

int employee_sortByName(void* paramOne, void* paramTwo)
{
    char bufferNameA[1024];
    char bufferNameB[1024];
    int retorno = -1;

    if(paramOne!=NULL && paramTwo!=NULL)
    {
		employee_getNombre(paramOne,bufferNameA);
		employee_getNombre(paramTwo,bufferNameB);

		if(strcmp(bufferNameA,bufferNameB)>0)
		{
			retorno = 1;
		}
    }

    return retorno;
}

/** \brief compara por horas trabajadas
 * \param void* paramOne
 * \param void* paramTwo
 * \return int
 */
int employee_sortByHours(void* paramOne, void* paramTwo)
{
    int retorno = -1;
    Employee* pEmpleadoOne;
    Employee* pEmpleadoTwo;

    if(paramOne!=NULL && paramTwo!=NULL)
    {
    	pEmpleadoOne = (Employee*)paramOne;
    	pEmpleadoTwo = (Employee*)paramTwo;
        if(pEmpleadoOne->horasTrabajadas > pEmpleadoTwo->horasTrabajadas)
        {
        	retorno = 1;
        }

    }
    return retorno;
}

/** \brief compara por salario
 * \param void* paramOne
 * \param void* paramTwo
 * \return int
 */
int employee_sortBySalary(void* paramOne, void* paramTwo)
{
    int retorno = -1;
    Employee* pEmpleadoOne;
    Employee* pEmpleadoTwo;

    if(paramOne!=NULL && paramTwo!=NULL)
    {
    	pEmpleadoOne = (Employee*)paramOne;
    	pEmpleadoTwo = (Employee*)paramTwo;
        if(pEmpleadoOne->sueldo > pEmpleadoTwo->sueldo)
        {
        	retorno = 1;
        }

    }
    return retorno;
}


/** \brief compara por id
 * \param void* paramOne
 * \param void* paramTwo
 * \return int
 */
int employee_sortById(void* paramOne, void* paramTwo)
{
    int retorno = -1;
    Employee* pEmpleadoOne;
    Employee* pEmpleadoTwo;

    if(paramOne!=NULL && paramTwo!=NULL)
    {
    	pEmpleadoOne = (Employee*)paramOne;
    	pEmpleadoTwo = (Employee*)paramTwo;
        if(pEmpleadoOne->id > pEmpleadoTwo->id)
        {
        	retorno = 1;
        }

    }
    return retorno;
}
