#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int cantLeido;
	char buffer[4][128];
	Employee *pAuxEmpleado = NULL;

	if (pFile != NULL && pArrayListEmployee != NULL) {
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1],buffer[2], buffer[3]);
		do {
			cantLeido = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0],	buffer[1], buffer[2], buffer[3]);
			if (cantLeido < 4) {
				employee_delete(pAuxEmpleado);
				retorno = -1;
				break;
			} else {
				pAuxEmpleado = employee_newParametros(buffer[0], buffer[1],	buffer[2], buffer[3]);
				if (pAuxEmpleado != NULL) {
					ll_add(pArrayListEmployee, pAuxEmpleado);
					retorno = 0;
				}
			}
		} while (!feof(pFile));
	}

	return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE *pFile, LinkedList *pArrayListEmployee) {
	int retorno = -1;
	int cantLeido;
	Employee *AuxEmploye = NULL;

	if (pFile != NULL && pArrayListEmployee != NULL) {
		do {
			AuxEmploye = employee_new();
			if (AuxEmploye != NULL) {
				cantLeido = fread(AuxEmploye, sizeof(Employee), 1, pFile);
				if (cantLeido != 1) {
					employee_delete(AuxEmploye);
					break;
				} else {
					ll_add(pArrayListEmployee, AuxEmploye);
					retorno = 0;
				}
			}
		} while (!feof(pFile));
	}
	return retorno;
}
