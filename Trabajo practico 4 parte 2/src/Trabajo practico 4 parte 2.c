#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

//Palmieri Facundo
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout, NULL);
	int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do {

		if (utn_getInt(&option," Menu tp4 parte 2:\n"
				"1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
				"2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n"
				"3. Alta de empleado\n"
				"4. Modificar datos de empleado\n"
				"5. Baja de empleado\n"
				"6. Listar empleados\n"
				"7. Ordenar empleados\n"
				"8. Testear las funciones que faltan de la linkedlist\n"
				"9. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
				"10. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n"
				"11. Salir\n"
				"Selecionar opcion :","Error. Menu:\n"
				"1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
				"2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n"
				"3. Alta de empleado\n"
				"4. Modificar datos de empleado\n"
				"5. Baja de empleado\n"
				"6. Listar empleados\n"
				"7. Ordenar empleados\n"
				"8. Testear las funciones que faltan de la linkedlist\n"
				"9. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
				"10. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n"
				"11. Salir\n"
				"Selecionar opcion(del 1 al 10):", 1, 10, 3) == 0) {
			switch (option) {
			case 1:
				printf("\n \n ");

				if(ll_len(listaEmpleados) == 0){
				controller_loadFromText("data.csv", listaEmpleados);
				}else{
					printf("Hay datos en la lista de empleados,¿desea guardarlos?");
					if(utn_getConfirm() == 0){
						controller_saveAsText("dataBackUp.csv", listaEmpleados);
						printf("El archivo se llama 'dataBackUp.csv'\n");
					}
					controller_loadFromText("data.csv", listaEmpleados);
				}
				printf("\n \n ");
				break;
			case 2:
				printf("\n \n ");

				if (ll_len(listaEmpleados) == 0) {
					if (controller_loadFromBinary("dataBin.bin", listaEmpleados) == -1) {
						printf(	"No se pudo leer el archivo, por favor primero guarde en formato binaro opcion 9 \n");
					}
				} else {
					printf(
							"Hay datos en la lista de empleados,¿desea guardarlos?");
					if (utn_getConfirm() == 0) {
						controller_saveAsText("dataBackUp.bin", listaEmpleados);
						printf("El archivo se llama 'dataBackUp.bin'\n");
					}
					if (controller_loadFromBinary("dataBin.bin", listaEmpleados)== -1) {
						printf(	"No se pudo leer el archivo, por favor primero guarde en formato binaro opcion 9 \n");
					}
				}
				printf("\n \n ");
				break;
			case 3:
				printf("\n \n ");

				controller_addEmployee(listaEmpleados);
				printf("\n \n ");

				break;
			case 4:
				printf("\n \n ");

				if (ll_len(listaEmpleados) != 0) {
				controller_editEmployee(listaEmpleados);
				}else{
					printf("No hay datos en la lista para editarlos, por favor ingrese dato\n");
				}
				printf("\n \n ");
				break;
			case 5:
				printf("\n \n ");

				if (ll_len(listaEmpleados) != 0) {
					controller_removeEmployee(listaEmpleados);
				} else {
					printf("No hay datos en la lista para eliminarlos, por favor ingrese dato\n");
				}
				printf("\n \n ");

				break;
			case 6:
				printf("\n \n ");

				if (ll_len(listaEmpleados) != 0) {
					controller_ListEmployee(listaEmpleados);
				} else {
					printf(	"No hay datos en la lista para mostrarlos, por favor ingrese dato\n");
				}
				printf("\n \n ");

				break;
			case 7:
				printf("\n \n ");

				if (ll_len(listaEmpleados) != 0) {
					controller_sortEmployee(listaEmpleados);
				} else {
					printf(	"No hay datos en la lista para ordenarlos, por favor ingrese datos \n");
				}
				printf("\n \n ");

				break;
			case 8:
				 controller_testTPSinParametros();
				break;
			case 9:
				printf("\n \n ");

				if (ll_len(listaEmpleados) != 0) {
					controller_saveAsText("data.csv", listaEmpleados);
				} else {
					printf(	"No hay datos la lista para guardar, por favor ingrese datos\n");
				}
				printf("\n \n ");

				break;
			case 10:
				printf("\n \n ");

				if(ll_len(listaEmpleados) != 0){
					controller_saveAsBinary("dataBin.bin", listaEmpleados);
				}else{
					printf("No hay datos la lista para guardar, por favor ingrese datos\n");
				}
				printf("\n \n ");

				break;
			case 11:
				printf("\n \n ");
				employee_delete(listaEmpleados);
				printf("Fin de la aplicacion.\n");
				printf("\n \n ");

				break;
			}
		}
	} while (option != 11);

    return 0;
}
