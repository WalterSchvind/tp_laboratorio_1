#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Crea un espacio en memoria dinamica para guardar un empleado
 *
 * \return Employee* devuelve el empleado con datos vacios
 *
 */
Employee* employee_new();

/** \brief Crea empleados con parametros dados, que deber ser casteados
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee* devuelve el empleado con parametros creados
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);

/** \brief Libera el espacio de un empleado dado de baja
 *
 * \param this Employee*
 * \return void
 *
 */
void employee_delete(Employee* empleado);


/** \brief settea el id a un empleado
 *
 * \param this Employee*
 * \param id int
 * \return int
 *
 */
int employee_setId(Employee* this,int id);
/** \brief consigue el id de un empleado
 *
 * \param this Employee*
 * \param id int*
 * \return int 0 si es NULL 1 si realizo la operacion
 *
 */
int employee_getId(Employee* this,int* id);

/** \brief settea el nombre a un empleado
 *
 * \param this Employee*
 * \param nombre char*
 * \return int 0 si es NULL 1 si realizo la operacion
 *
 */
int employee_setNombre(Employee* this,char* nombre);
/** \brief consigue el nombre de un empleado
 *
 * \param this Employee*
 * \param nombre char*
 * \return int 0 si es NULL 1 si realizo la operacion
 *
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief settea las horas trabajadas de un empleado
 *
 * \param this Employee*
 * \param horasTrabajadas int
 * \return int 0 si es NULL 1 si realizo la operacion
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/** \brief consigue las horas trabajadas de un empleado
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int 0 si es NULL 1 si realizo la operacion
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief settea el sueldo a un empleado
 *
 * \param this Employee*
 * \param sueldo int
 * \return int 0 si es NULL 1 si realizo la operacion
 *
 */
int employee_setSueldo(Employee* this,int sueldo);
/** \brief consigue el sueldo de un empleado
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int 0 si es NULL 1 si realizo la operacion
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief Compara el sueldo de dos empleados
 *
 * \param empleadoA void*
 * \param empleadoB void*
 * \return int devuelve 1 si a es mayor que b, -1 si a es menor que b y  0 si a es igual a b
 *
 */
int employee_ComparaSueldo(void* empleadoA,void* empleadoB);
/** \brief Compara las horas trabajadas de dos empleados
 *
 * \param empleadoA void*
 * \param empleadoB void*
 * \return int devuelve 1 si a es mayor que b, -1 si a es menor que b y  0 si a es igual a b
 *
 */
int employee_ComparaHorasTrabajadas(void* empleadoA,void* empleadoB);
/** \brief Compara el nombre de dos empleados por codigo ASCII
 *
 *
 * \param empleadoA void*
 * \param empleadoB void*
 * \return int devuelve 1 si a es mayor que b, -1 si a es menor que b y  0 si a es igual a b
 *
 */
int employee_ComparaNombre(void* empleadoA,void* empleadoB);
/** \brief Compara el id de dos empleados
 *
 * \param empleadoA void*
 * \param empleadoB void*
 * \return int devuelve 1 si a es mayor que b, -1 si a es menor que b y  0 si a es igual a b
 *
 */
int employee_ComparaId(void* empleadoA,void* empleadoB);

#endif // employee_H_INCLUDED
