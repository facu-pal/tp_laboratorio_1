#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employe.h"
#include "utn.h"

int main(void) {
	setbuf(stdout, NULL);
	Employee emplados[TAME_STRUC];
	int menu;
	int cantEmpleados = 0; //esta variable es para saber si hay empleados
	int contEmpleados = 0; //esta variable es para saber cual es el siguiente numero de id que le tocaria al proximo empleado
	int idEmpleadoBuscar = -1; //esta variable se utiliza para la busqueda de la id de un empleado
	int submenu;
	float auxFloat;
	int criterio;


	initEmployees(emplados, TAME_STRUC);

	do {
		printf("\nmenu\n");
		printf("1_Ingresar un empleado\n");
		printf("2_Modificar un empleado\n");
		printf("3_ Bajar un empleado\n");
		printf("4_informar\n");
		printf("5_Salir\n");
		scanf("%d", &menu);

		switch (menu) {
		case 1://alta
			if (addEmployee(emplados, TAME_STRUC, &contEmpleados) == 0) {
				printf("Carga exitosa\n");
				cantEmpleados++;
				imprimirEmployees(emplados, TAME_STRUC);
			}
			break;
		case 2://modificar
			if (cantEmpleados > 0) {
				imprimirEmployees(emplados, TAME_STRUC);
				printf("\n");
				idEmpleadoBuscar = findEmployeeById(emplados, TAME_STRUC);
				modificaEmployee(emplados, idEmpleadoBuscar);
				idEmpleadoBuscar = -1;
			} else {
				printf("Error.No hay empleados, porfavor ingrese algun empleado(opcion 1)");
			}

			break;
		case 3://baja
			if (cantEmpleados > 0) {
				imprimirEmployees(emplados, TAME_STRUC);
				printf("\n");
				idEmpleadoBuscar = findEmployeeById(emplados, TAME_STRUC);
				removeEmployee(emplados,idEmpleadoBuscar);
				cantEmpleados--;
				idEmpleadoBuscar = -1;
			} else {
				printf("Error.No hay empleados, porfavor ingrese empleado(opcion 1)");
			}
			break;
		case 4:

			if (cantEmpleados > 0) {
				do {
					if (utn_getInt(&submenu,
							"\n1.Informar empleados \n2.Listado de empleados con salario mayor al promedio\n3.Salir",
							"Error, Ingrese una opcion del 1 o 2.", 1, 3, 2)
							== 0) {
						switch (submenu) {
						case 1:
							utn_getInt(&criterio,"Ingrese 0(cero) para ordenar de forma descendente o 1(uno) para de forma asendente \n","Error.Ingrese 0(cero) para ordenar de forma descendente o 1(uno) para de forma asendente\n",0,1,2);
							sortEmployees(emplados, TAME_STRUC, criterio);
							imprimirEmployees(emplados, TAME_STRUC);
							break;
						case 2:
							EmployeePromSalario(&auxFloat, emplados,TAME_STRUC);
							EmployeesListaSalario(emplados, TAME_STRUC,auxFloat);
							break;
						}
					}
				} while (submenu != 3);
			} else {
				printf(
						"Error.No hay empleados, porfavor ingrese empleado(opcion 1)");
			}
			break;
		case 5:
			break;
		default:
			printf("No elegiste ninguna opcion \n");
		}

	} while (menu != 5);

	return EXIT_SUCCESS;
}
