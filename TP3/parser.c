#include "parser.h"


int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee = employee_new();
    int r;
    int i = 0;
    char idAux[50];
    char nombreAux[50];
    char horasTrabajadasAux[50];
    char sueldoAux[50];

    r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreAux,horasTrabajadasAux,sueldoAux);
    while(!feof(pFile))
    {
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreAux,horasTrabajadasAux,sueldoAux);
        if(r==4)
        {
            auxEmployee = employee_newParametros(idAux,nombreAux, horasTrabajadasAux, sueldoAux);
            ll_add(pArrayListEmployee, auxEmployee );
            i++;
        }
    }
    printf("Se cargaron %d empleados a la lista (modo texto)\n", i);

    return i;


}


int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{

    Employee employeeAux;
    int i = 0;

    fread(&employeeAux, sizeof(Employee), 1, pFile);

    while(!feof(pFile))
    {
        Employee *employeeNew = employee_new();
        employee_setId(employeeNew,employeeAux.id);
        employee_setHorasTrabajadas(employeeNew,employeeAux.horasTrabajadas);
        employee_setNombre(employeeNew,employeeAux.nombre);
        employee_setSueldo(employeeNew,employeeAux.sueldo);
        i ++;
        ll_add(pArrayListEmployee, employeeNew);
        fread(&employeeAux, sizeof(Employee), 1, pFile);
    }
    printf("Se cargaron %d empleados a la lista (modo binario) \n", i);
    return 1;
}
