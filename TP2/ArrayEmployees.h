#include "ArraySector.h"
#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}  eEmployee;



#endif // ARRAYEMPLOYEES_H_INCLUDED

/** \brief Menu de opciones
 *
 * \return int devuelve la opcion elegida por el usuario
 *
 */
int menu();
/** \brief Inicializa El vector de empleados
 *
 * \param lista eEmployee*
 * \param len int el tamaño del vector
 * \return int devuelve 1 si no hay error y 0 si hubo alguno
 *
 */
int initEmployees(eEmployee* lista,int len);
/** \brief Busca lugares libres en el vector
 *
 * \param lista eEmployee*
 * \param len int
 * \return int devuelve -1 si no encontro lugar y si encuentra devuelve el indice del lugar
 *
 */
int searchEmpty(eEmployee* lista,int len);
/** \brief Agrega un empleado al vector de empleados
 *
 * \param lista eEmployee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int
 *
 */
int addEmployee(eEmployee* lista,int len,int id,char name[],char lastName[],float salary,int sector);
/** \brief pide datos para agregar empleados ,
 *
 * \param eEmployee*lista
 * \param len int
 * \param listaSector eSector*
 * \param lenSector int
 * \return int devuelve 0 si no pudo agregar y 1 si pudo
 *
 */
int addEmployees(eEmployee*lista,int len,eSector* listaSector,int lenSector);
/** \brief Busca empleados segun el id
 *
 * \param lista eEmployee*
 * \param len int
 * \param id int
 * \return int devuelve -1 si no pudo encontrar empleado y el indice del lugar donde esta si pudo encontrar el empleado
 *
 */
int findEmployeeById(eEmployee* lista,int len,int id);
/** \brief da una baja logica a un empleado segun un id ingresado
 *
 * \param lista eEmployee*
 * \param len int
 * \param id int
 * \return int devuelve -1 si no pudo dar de baja y 1 si pudo
 *
 */
int removeEmployee(eEmployee* lista,int len,int id);
/** \brief Recive un id del usuario
 *
 * \param int*id
 * \return int
 *
 */
int receiveId(int* id);
/** \brief Muestra todos los empleados que estan dados de alta en el vector
 *
 * \param lista eEmployee*
 * \param len int
 * \param listaSector eSector*
 * \param lenSector int
 * \return int devuelve -1 si no hay empleados que mostrar y 1 si muestra empleados
 *
 */
int printEmployees(eEmployee* lista,int len,eSector* listaSector,int lenSector);
/** \brief Muestra un solo empleado
 *
 * \param x eEmployee
 * \param listaSector eSector*
 * \param lenSector int
 * \return void
 *
 */
void printEmployee(eEmployee x,eSector* listaSector, int lenSector);
/** \brief Ordena los empleados segun apellido y sector
 *
 * \param lista eEmployee*
 * \param len int
 * \param order int el orden en el que van a ser ordenados 1: de menor a mayor o 2: de mayor a menor
 * \return int
 *
 */
int sortEmployees(eEmployee* lista, int len, int order);
/** \brief Funcion que muestra los informes
 *
 * \param lista eEmployee*
 * \param len int
 * \param listaSector eSector*
 * \param lenSector int
 * \return void
 *
 */
void reportEmployees(eEmployee* lista,int len,eSector* listaSector,int lenSector);
/** \brief Saca salario total , promedio y cuantos empleados superan el promedio de sueldo
 *
 * \param lista eEmployee*
 * \param len int
 * \return int
 *
 */
int totalSalariesAverageWages(eEmployee* lista,int len);
/** \brief Menu de modificaciones
 *
 * \param void
 * \return int
 *
 */
int modifyMenu(void);
/** \brief Modifica empleado segun la opcion que elija el usuario
 *
 * \param lista eEmployee*
 * \param len int
 * \param listaSector eSector*
 * \param lenSector int
 * \return void
 *
 */
void modifyEmployee(eEmployee* lista,int len,eSector* listaSector,int lenSector);
