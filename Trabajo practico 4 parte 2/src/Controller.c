#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayListEmployee) {
	int retorno = -1;
	int auxParser;
	FILE *pArchivoTexto;
	pArchivoTexto = fopen(path, "r");
	if (pArchivoTexto == NULL) {
		printf("Este archivo no existe");
	} else {
		auxParser = parser_EmployeeFromText(pArchivoTexto,pArrayListEmployee);
		if (auxParser == 0) {
			fclose(pArchivoTexto);
			printf("Se lleyo correctamenta el archivo, y se cerro\n");
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee){

		int retorno=-1;
		int auxParser;

		if(path!=NULL && pArrayListEmployee!=NULL)
		{
			FILE *pFile=fopen(path,"rb");
			auxParser = parser_EmployeeFromBinary(pFile,pArrayListEmployee);
			if(auxParser ==0)
			{
				printf("Archivo bien leido. Cerrado correctamente\n");
				retorno=0;
				fclose(pFile);
			}
			else
			{
				printf("No se pudo leer el archivo\n");
				retorno=-1;
			}
		}
		return retorno;
	}


int controller_getMaxId(LinkedList *pArrayListEmployee) {
	int retorno = -1;
	int lenLinkedlist;
	int auxId;
	int idMax = 0;
	Employee *pEmpleado;

	if (pArrayListEmployee != NULL) {
		lenLinkedlist = ll_len(pArrayListEmployee);
		for (int i = 0; i < lenLinkedlist; i++) {
			pEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
			employee_getId(pEmpleado, &auxId);
			if (idMax < auxId) {
				idMax = auxId;
			}
		}
		retorno = idMax;
	}
	return retorno;
}






/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int lentLinkedList;
	int auxId;
	char auxNombre[1024];
	int auxHorasTrabajadas;
	int auxSueldo;
	Employee* auxEmpleado;
	if(pArrayListEmployee != NULL)
	{
		lentLinkedList = ll_len(pArrayListEmployee);

		printf("Id		Nombre		  Horas trabajadas	        Sueldo\n");
		for(int i = 0; i < lentLinkedList; i++)
		{
			auxEmpleado = ll_get(pArrayListEmployee,i);
			employee_getId(auxEmpleado,&auxId);
			employee_getNombre(auxEmpleado,auxNombre);
			employee_getHorasTrabajadas(auxEmpleado,&auxHorasTrabajadas);
			employee_getSueldo(auxEmpleado,&auxSueldo);
			printf("%-5d		%-15s		%4d			%-10d\n",auxId,auxNombre,auxHorasTrabajadas,auxSueldo);

		}
	}



    return retorno;
}





/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList *pArrayListEmployee) {
	int retorno = -1;
	Employee *pAuxEmpleado = NULL;
	int auxId;
	char auxNombre[128];
	int auxHoras;
	int auxSueldo;

	if (pArrayListEmployee != NULL) {
		if (ll_isEmpty(pArrayListEmployee) == 1) {
			printf("Va a crear una nueva lista \n");
			auxId = 1;
				pAuxEmpleado = employee_new();
				if (pAuxEmpleado != NULL) {
					if (utn_getString(auxNombre, "Ingrese nombre del empleado:",	"Error ingrese nombre valido:\n", 2) == 0
							&& utn_getInt(&auxHoras, "Ingrese horas trabajadas,minimo 1 maximo 1000:","Error ingrese numero valido,minimo 1 maximo 1000:\n",	1, 1000, 2) == 0
							&& utn_getInt(&auxSueldo,  "Ingrese sueldo,minimo 1000, maximo 500000:","Error numero valido,minimo 1000, maximo 500000:", 1000, 500000,2) == 0) {

						if (employee_setId(pAuxEmpleado, auxId) == 0
								&& employee_setNombre(pAuxEmpleado, auxNombre)	== 0
								&&	employee_setHorasTrabajadas(pAuxEmpleado,auxHoras) == 0
								&& employee_setSueldo(pAuxEmpleado, auxSueldo)== 0) {

							ll_add(pArrayListEmployee, pAuxEmpleado);
							employee_print(pAuxEmpleado);
							printf("Carga exitosa\n");
							retorno = 0;
						} else {
							printf("Error al cargar empleado\n");
						}
					}
				}

		} else {
			auxId = controller_getMaxId(pArrayListEmployee);
			pAuxEmpleado = employee_new();
			if (pAuxEmpleado != NULL) {
				if (utn_getString(auxNombre, "Ingrese nombre del empleado:",	"Error, ingrese nombre valido:\n", 2) == 0
						&& utn_getInt(&auxHoras, "Ingrese horas trabajadas,,minimo 1 maximo 1000:","Error ingrese numero valido,minimo 1 maximo 1000:\n",1, 1000, 2) == 0
						&& utn_getInt(&auxSueldo, "Ingrese sueldo,minimo 1000, maximo 500000:","Error numero valido,minimo 1000, maximo 500000:", 1000, 500000,2) == 0) {
					if (employee_setId(pAuxEmpleado, (auxId + 1)) == 0
							&& employee_setNombre(pAuxEmpleado, auxNombre) == 0
							&& employee_setHorasTrabajadas(pAuxEmpleado,
									auxHoras) == 0
							&& employee_setSueldo(pAuxEmpleado, auxSueldo)
									== 0) {
						ll_add(pArrayListEmployee, pAuxEmpleado);
						employee_print(pAuxEmpleado);
						printf("Carga exitosa\n");
						retorno = 0;
					} else {
						printf("Error al cargar empleado\n");
					}
				}
			}
		}
	}
	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList *pArrayListEmployee) {
	int retorno = -1;
	int largoLinkedlist;
	int i;
	char bufferName[1024];
	int bufferHoras;
	int bufferSueldo;
	int bufferId;
	int auxId;
	int maxId;
	int opcion = 0;
	Employee *pEmpleado;

	if (pArrayListEmployee != NULL) {

		largoLinkedlist = ll_len(pArrayListEmployee);
		for (int i = 0; i < largoLinkedlist; i++) {
			pEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
			employee_getId(pEmpleado, &auxId);
			if (auxId > maxId) {
				maxId = auxId;
			}
		}

		printf("¿Desea ver la lista de empleados?");
		if (utn_getConfirm() == 0) {
			controller_ListEmployee(pArrayListEmployee);
		}

		utn_getInt(&auxId, "Ingrese el id del empleado a modificar.\n","No ingreso un id valido.\n", 0, maxId, 3);

		for (i = 0; i < largoLinkedlist; i++) {
			pEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
			employee_getId(pEmpleado, &bufferId);

			employee_getNombre(pEmpleado, bufferName);
			employee_getHorasTrabajadas(pEmpleado, &bufferHoras);
			employee_getSueldo(pEmpleado, &bufferSueldo);

			if (bufferId == auxId) {
				printf("Se modificara el empleado con estos datos: Nombre : %s  Horas trabajadas: %d  Sueldo: %d,\n", bufferName, bufferHoras, bufferSueldo);

				printf("¿Desea continuar modificando los datos?");

				if (utn_getConfirm() == 0) {
					printf("1- Nombre\n");
					printf("2- Horas de trabajo\n");
					printf("3- Sueldo\n");
					printf("4- Salir\n");
					printf("Ingrese opcion: ");
					fflush(stdin);
					scanf("%d", &opcion);
					switch (opcion) {
					case 1:

						if (utn_getString(bufferName,"Ingrese el nuevo nombre del empleado:","Error ingrese nombre valido:\n", 2)==0) {
							if (utn_getConfirm() == 0) {
								employee_setNombre(pEmpleado, bufferName);
								retorno = 0;
							} else {
								printf("Edición cancelada\n");
							}
						}

						break;

					case 2:
						if (utn_getInt(&bufferHoras,"Ingrese las nuevas horas trabajadas,minimo 1 maximo 1000:", "Error ingrese numero valido,minimo 1 maximo 1000:\n",1, 1000, 2) == 0) {
							if (utn_getConfirm() == 0) {
								employee_setHorasTrabajadas(pEmpleado, bufferHoras);
								retorno = 0;
							} else {
								printf("Edición cancelada\n");
							}
						}
						break;
					case 3:
						if (utn_getInt(&bufferSueldo,"Ingrese el nuevo sueldo,minimo 1000, maximo 500000:", "Error numero valido,minimo 1000, maximo 500000:",1000, 500000, 2) == 0) {
							if (utn_getConfirm() == 0) {
								employee_setSueldo(pEmpleado, bufferSueldo);
								retorno = 0;
							} else {
								printf("Edición cancelada\n");
							}
						}
						break;
					case 4:
						printf("Salio de modificar\n");

						break;
					default:
						printf("Opcion invalida\n");

					}
				} else {
					printf("No se modifico ningun dato.\n");
					break;

				}
			}
		}
	}
	return retorno;
}


/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList *pArrayListEmployee) {
	int retorno = -1;
	int largoLinkedlist;
	int i;
	char bufferName[1024];
	int bufferHoras;
	int bufferSueldo;
	int bufferId;
	int auxId;
	int maxId;
	Employee *pEmpleado;

	if (pArrayListEmployee != NULL) {

		largoLinkedlist = ll_len(pArrayListEmployee);
		for (int i = 0; i < largoLinkedlist; i++) {
			pEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
			employee_getId(pEmpleado, &auxId);
			if (auxId > maxId) {
				maxId = auxId;
			}
		}

		printf("¿Desea ver la lista de empleados?");
		if (utn_getConfirm() == 0) {
			controller_ListEmployee(pArrayListEmployee);
		}

		utn_getInt(&auxId, "Ingrese el id del empleado a eliminar.\n","No ingreso un id valido.\n", 0, maxId, 3);

		for (i = 0; i < largoLinkedlist; i++) {
			pEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
			employee_getId(pEmpleado, &bufferId);

			if (bufferId == auxId) {
				employee_getNombre(pEmpleado, bufferName);
				employee_getHorasTrabajadas(pEmpleado, &bufferHoras);
				employee_getSueldo(pEmpleado, &bufferSueldo);
				printf("¿Desea eliminar al empleado?\n");
				printf("Nombre:%s horas trabajadas: %d . Sueldo:%d", bufferName,bufferHoras, bufferSueldo);

				if (utn_getConfirm() == 0) {
					ll_remove(pArrayListEmployee, i);
					break;
				} else {
					printf("No se elimino ningun empleado.\n");
					break;

				}
			}
		}
	}

	return retorno;
}





/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList *pArrayListEmployee) {
	int retorno = -1;
	int opcion;
	if (pArrayListEmployee != NULL) {
		printf("1.Ordenar por Nombre.\n");
		printf("2.Ordenar por Salario.\n");
		printf("3.Ordenar por Horas de trabajo.\n");
		printf("4.Ordenar por id.\n");

		utn_getInt(&opcion, "Selecione una opcion.\n","Selecione una opcion.\n", 1, 4, 3);
		switch (opcion) {
		case 1:
			if (ll_sort(pArrayListEmployee, employee_sortByName, 1) == 0) {
				printf("Se ordeno la lista por nombre\n");
			}

			break;
		case 2:
			if (ll_sort(pArrayListEmployee, employee_sortBySalary, 1) == 0) {
				printf("Se ordeno la lista por salario\n");
			}

			break;
		case 3:
			if (ll_sort(pArrayListEmployee, employee_sortByHours, 1) == 0) {
				printf("Se ordeno la lista por horas trabajadas\n");
			}

			break;
		case 4:
			if (ll_sort(pArrayListEmployee, employee_sortById, 1) == 0) {
				printf("Se ordeno la lista por horas trabajadas\n");
			}

			break;

		}
		retorno = 0;
	}

	printf("¿Desea ver la lista de empleados?");
	if(utn_getConfirm() == 0){
		controller_ListEmployee(pArrayListEmployee);
	}

	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee){
	int retorno = -1;
	int lenArrayEmploye = 0;
	char auxNombre[1024];
	int auxBufferInt[3];

	FILE* pFileTexto;
	pFileTexto = fopen(path, "w");
	Employee* pEmployee=NULL;

	if(pArrayListEmployee!=NULL && path != NULL)
	{
		lenArrayEmploye = ll_len(pArrayListEmployee);

		if(pFileTexto != NULL)
		{
			fprintf(pFileTexto,"id,nombre,horasTrabajadas,sueldo\n");
			for(int i = 0 ; i < lenArrayEmploye; i++)
			{
				pEmployee = ll_get(pArrayListEmployee,i);
				employee_getId(pEmployee,&auxBufferInt[0]);
				employee_getNombre(pEmployee,auxNombre);
				employee_getHorasTrabajadas(pEmployee,&auxBufferInt[1]);
				employee_getSueldo(pEmployee,&auxBufferInt[2]);
				fprintf(pFileTexto,"%d,%s,%d,%d\n",auxBufferInt[0],auxNombre,auxBufferInt[1],auxBufferInt[2]);
			}
			printf("EL archivo se guardo exitosamente\n");
			retorno = 0;
	        }else
	        {
	        	printf("Hubo un error al guardar el archivo\n");
	        }
	}
	fclose(pFileTexto);
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int i;
	int len;

	FILE *pArchivoBinario = NULL;
	Employee *pEmpleado = NULL;

	if (pArrayListEmployee != NULL && path != NULL) {
		len = ll_len(pArrayListEmployee);
		pArchivoBinario = fopen(path, "wb");

		if (pArchivoBinario != NULL) {
			for (i = 0; i < len; i++) {
				pEmpleado = (Employee*) ll_get(pArrayListEmployee, i);

				if (pEmpleado != NULL) {
					fwrite(pEmpleado, sizeof(Employee), 1, pArchivoBinario);
				}
			}
			retorno = 0;
			printf("El archivo se guardo exitosamente.\n");
		} else {
			printf("Error en el guardado de el archivo binario.\n");
		}
		fclose(pArchivoBinario);
	}
	return retorno;
}


int controller_testTP(LinkedList* pArrayListEmployee)
{
	int exito = 0;
	int contains;
	LinkedList* clon;


	if(pArrayListEmployee!=NULL)
	{
		clon = ll_newLinkedList();

		clon = ll_clone(pArrayListEmployee);

		controller_ListEmployee(pArrayListEmployee);
		printf("\nLista Clonada.\n");

		contains = ll_containsAll(pArrayListEmployee,clon);
		if(contains == 1){
			printf("\n Las 2 lista tienen los mismos elemento\n");
		}else if(contains == 0){
			printf("\n Las 2 lista no tienen los mismos elemento\n");
		}


		printf("---Delete---");
		if(ll_deleteLinkedList(clon)==0)
		{
			printf("Lista eliminada\n");
		}	else	{
			printf("Lista no eliminada");
		}

		exito = 1;
	}

	return exito;
}
