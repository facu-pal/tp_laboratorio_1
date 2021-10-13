#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employe.h"
#include "utn.h"

int initEmployees(Employee *list, int len) {
	int i;
	int retorno = -1;
	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			list[i].isEmpty = 0;
			retorno = 0;
		}
	} else {
		retorno = -1;
	}

	return retorno;
}

int buscaLibre(Employee pArray[], int len) {
	int retorno = -1;
	int i;

	if (pArray != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (pArray[i].isEmpty == 0) {
				retorno = i;
				break;
			}
		}

	}
	return retorno;
}

int addEmployee(Employee aEmployee[], int len, int *contadorId) {
	int retorno = -1;
	Employee Empleado;
	int posicion;

	if (aEmployee != NULL && len > 0 && contadorId != NULL) {
		posicion = buscaLibre(aEmployee, len);
		if (posicion == -1) {
			printf("\nNo hay lugares libres");
		} else {
			if ((utn_getString(Empleado.lastName, "Ingrese Apellido:",
					"Error.Ingrese Apellido:", 2) == 0)
					&& (utn_getString(Empleado.name, "Ingrese Nombre:",
							"Error.Ingrese Nombre:", 2) == 0)
					&& (utn_getFlotante(&Empleado.salary,
							"Ingrese salario(entre 1000 y 10000):",
							"Error.Ingrese salario(entre 1000 y 10000):", 1000,
							10000, 2) == 0)
					&& (utn_getInt(&Empleado.sector,
							"Ingrese sector(del 1 al 3):",
							"Error.Ingrese sector (del 1 a 3):", 1, 3, 2) == 0)) {
				Empleado.idEmployee = *contadorId + 1;
				printf("Estos son los datos, desea continuar:");
				printEmploye(Empleado);
				if (utn_getConfirm() == 0) {
					(*contadorId)++;
					Empleado.idEmployee = *contadorId;
					Empleado.isEmpty = 1;
					aEmployee[posicion] = Empleado;
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}
void printEmploye(Employee Empleado) {
	printf("\n %-5d  %-10s %-10s %-5d %-5.2f ", Empleado.idEmployee,
			Empleado.lastName, Empleado.name, Empleado.sector, Empleado.salary);
}
int imprimirEmployees(Employee Empleado[], int len) {
	int i;
	int retorno = -1;

	//CABECERA
	printf("\n\t> LISTADO Empleados\n");
	printf("%5s %10s %10s %8s %5s\n", "ID", "APELLIDO", "NOMBRE", "SECTOR",
			"SUELDO");
	if (Empleado != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (Empleado[i].isEmpty == 0) {
				continue;
			} else {
				printEmploye(Empleado[i]);
				retorno = 0;
			}
		}
	}
	return retorno;
}

int findEmployeeById(Employee Empleado[], int len) {
	int retorno = -1;
	int i;
	int auxID;
	if (Empleado != NULL && len > 0) {
		printf("Ingrese ID del empleado:");
		scanf("%d", &auxID);
		for (i = 0; i < len; i++) {
			if (Empleado[i].idEmployee == auxID && Empleado[i].isEmpty == 1) {
				retorno = i;
				break;
			}
		}
		if (retorno == -1) {
			printf("El numero de ID %d no existe", auxID);
		}
	}
	return retorno;
}

int modificaEmployee(Employee Empleado[], int posicion) {
	int retorno = -1;
	int respuesta;
	Employee auxEmpleado;
	if (Empleado != NULL && posicion != -1) {
		printf("\n\t> LISTADO Empleados\n");
		printf("%5s %10s %10s %8s %5s\n", "ID", "APELLIDO", "NOMBRE", "SECTOR",
				"SUELDO");
		printEmploye(Empleado[posicion]);

		printf("\n¿Que desea modificar?\n");
		printf("1_Apellido \n");
		printf("2_Nombre\n");
		printf("3_Sueldo\n");
		printf("4_Sector\n");
		scanf("%d", &respuesta);

		while (respuesta > 4 || respuesta < 1) {
			printf(
					"\nError. no ingreso una opcion correcta (opciones del 1 al 4)");
			printf("¿Que desea modificar?\n");
			printf("1_Apellido \n");
			printf("2_Nombre\n");
			printf("3_Sueldo\n");
			printf("4_Sector\n");
			scanf("%d", &respuesta);
		}
		switch (respuesta) {
		case 1:
			utn_getString(auxEmpleado.lastName, "Ingrese el nuevo Apellido:",
					"Error. Ingrese el nuevo Apellido:", 1);
			printf("¿Estas seguro que queres cambiar el apellido a %s? ",
					auxEmpleado.lastName);
			if (utn_getConfirm() == 0) {
				strcpy(Empleado[posicion].lastName, auxEmpleado.lastName);
			}
			break;
		case 2:
			utn_getString(auxEmpleado.name, "Ingrese Nombre",
					"Error, ingrese Nombre", 1);
			if (utn_getConfirm() == 0) {
				strcpy(Empleado[posicion].name, auxEmpleado.name);
			}
			break;
		case 3:
			utn_getFlotante(&auxEmpleado.salary,
					"Ingrese salario(entre 1000 y 10000):",
					"Error.Ingrese salario(entre 1000 y 10000):", 1000, 10000,
					2);
			if (utn_getConfirm() == 0) {
				Empleado[posicion].salary = auxEmpleado.salary;
			}
			break;
		case 4:
			utn_getInt(&auxEmpleado.sector,
					"Ingrese al nuevo sector que (sectores del 1 al 3):",
					"Error. Ingrese al nuevo sector que (sectores del 1 al 3):",
					1, 3, 1);
			if (utn_getConfirm() == 0) {
				Empleado[posicion].sector = auxEmpleado.sector;
			}
			break;
		}
		printf("\n\t> LISTADO Empleados\n");
		printf("%5s %10s %10s %8s %5s\n", "ID", "APELLIDO", "NOMBRE", "SECTOR",
				"SUELDO");
		printEmploye(Empleado[posicion]);
		retorno = 0;

	}
	return retorno;
}

int removeEmployee(Employee *list, int posicion) {
	int retorno = -1;
	if (list != NULL && posicion != -1) {

		printEmploye(list[posicion]);
		printf("\n¿Desea borrar el empleado?\n");
		if (utn_getConfirm() == 0) {
			list[posicion].isEmpty = 0;
			retorno = 0;
		}
	}
	return retorno;
}

int sortEmployees(Employee *list, int len, int order) {
	int flagDesordenado = -1;
	int i;
	Employee auxEmpleados;
	int retorno = -1;

	if (list != NULL && len > 0) {
		do {
			flagDesordenado = 0;
			for (i = 0; i < len - 1; i++) {
				if (order == 0) {
					if (strcmp(list[i].lastName, list[i + 1].lastName) > 0) {
						flagDesordenado = 1;
						auxEmpleados = list[i];
						list[i] = list[i + 1];
						list[i + 1] = auxEmpleados;
					} else {
						if (strcmp(list[i].lastName, list[i + 1].lastName) == 0
								&& list[i].sector > list[i + 1].sector) {
							flagDesordenado = 1;
							auxEmpleados = list[i];
							list[i] = list[i + 1];
							list[i + 1] = auxEmpleados;
						}
					}
				} else {
					if (order == 1) {
						if (strcmp(list[i + 1].lastName, list[i].lastName)
								> 0) {
							flagDesordenado = 1;
							auxEmpleados = list[i];
							list[i] = list[i + 1];
							list[i + 1] = auxEmpleados;
						} else {
							if (strcmp(list[i].lastName, list[i + 1].lastName)
									== 0
									&& list[i + 1].sector > list[i].sector) {
								flagDesordenado = 1;
								auxEmpleados = list[i];
								list[i] = list[i + 1];
								list[i + 1] = auxEmpleados;
							}
						}
					}
				}
			}
		} while (flagDesordenado == 0);
		retorno = 0;
	}
	return retorno;
}

void EmployeePromSalario(float *PromSueldo, Employee array[], int len) {
	int i;
	float acumulador = 0;
	float contador = 0;

	if (PromSueldo != NULL && array != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (array[i].isEmpty == 1) {
				acumulador += array[i].salary;
				contador++;
			}
		}
		*PromSueldo = acumulador / contador;
		printf("El salario promedio es: %.2f", *PromSueldo);
	}
}
void EmployeesListaSalario(Employee array[], int len, float sueldo) {
	int i;

	if (array != NULL && len > 0) {
		printf("\n\t> LISTADO Empleados\n");
		printf("%5s %10s %10s %8s %5s\n", "ID", "APELLIDO", "NOMBRE", "SECTOR",
				"SUELDO");
		for (i = 0; i < len; i++) {
			if (array[i].isEmpty == 1 && array[i].salary >= sueldo) {
				printEmploye(array[i]);
			}
		}
	}

}
