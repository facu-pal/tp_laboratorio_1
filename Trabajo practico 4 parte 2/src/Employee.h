#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief asigna espacio de memoria para un nuevo empleado
 * \return puntero del espacio de memoria
 */
Employee* employee_new();
/** \brief asigna espacio de memoria para em empleado y asigna por parametro los campos de la estructura
 * \param char* idStr
 * \param char* nombreStr
 * \param char* horasTrabajadasStr
 * \param char* sueldo
 * \return puntero del espacio de memoria
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
void employee_delete();

/** \brief asigna el id al campo del empleado
 * \param Employee* this
 * \param int id
 * \return int
 */
int employee_setId(Employee* this,int id);
/** \brief obtiene el id del campo del empleado
 * \param Employee* this
 * \param int id
 * \return int */
int employee_getId(Employee* this,int* id);

/** \brief asigna el nombre al campo del empleado
 * \param Employee* this
 * \param char* nombre
 * \return int
 */
int employee_setNombre(Employee* this,char* nombre);
/** \brief obtiene el nombre trabajadas del campo del empleado
 * \param Employee* this
 * \param char* nombre
 * \return int
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief asigna las horas trabajadas al campo del empleado
 * \param Employee* this
 * \param int horasTrabajadas
 * \return int
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/** \brief obtiene las horas trabajadas del campo del empleado
 * \param Employee* this
 * \param int* horasTrabajadas
 * \return int
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief asigna el sueldo al campo del empleado
 * \param Employee* this
 * \param int sueldo
 * \return int
 */
int employee_setSueldo(Employee* this,int sueldo);
/** \brief obtiene el sueldo del campo del empleado
 * \param Employee* this
 * \param int sueldo
 * \return int
 */
int employee_getSueldo(Employee* this,int* sueldo);


void employee_print(Employee* this);


int employee_sortByHours(void* paramOne, void* paramTwo);
int employee_sortByName(void* paramOne, void* paramTwo);
int employee_sortBySalary(void* paramOne, void* paramTwo);
int employee_sortById(void* paramOne, void* paramTwo);

#endif // employee_H_INCLUDED
