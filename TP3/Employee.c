#include "Employee.h"
#include "stdio.h"
#include <stdlib.h>
#include <string.h>
Employee* employee_new()
{
    Employee* nuevoEmpleado= (Employee*) malloc(sizeof(Employee));


    if(nuevoEmpleado !=NULL)
    {
        nuevoEmpleado->id=0;
        nuevoEmpleado->horasTrabajadas=0;
        strcpy(nuevoEmpleado->nombre,"");
        nuevoEmpleado->sueldo=0;

    }

    return nuevoEmpleado;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* auxEmpleado = employee_new();


    if( auxEmpleado != NULL )
    {
        int id = atoi(idStr);
        employee_setId(auxEmpleado, id);

        int horasTrabajadas = atoi(horasTrabajadasStr);
        employee_setHorasTrabajadas(auxEmpleado, horasTrabajadas);

        int sueldo = atoi(sueldoStr);
        employee_setSueldo(auxEmpleado, sueldo);

        employee_setNombre(auxEmpleado, nombreStr);
    }
    return auxEmpleado;
}
void employee_delete(Employee* empleado)
{
    if(empleado!=NULL)
        free(empleado);
}
int employee_setId(Employee* this,int id)
{
    int todoOk=0;
    if(this!=NULL&&id>0)
    {

            this->id = id;
            todoOk = 1;
    }
    return todoOk;
}
int employee_getId(Employee* this,int* id)
{
    int todoOk = 0;
    if(this!=NULL&&id!=NULL)
    {
        *id = this->id;
        todoOk = 1;
    }
    return todoOk;
}
int employee_setNombre(Employee* this,char* nombre)
{
    int todoOk = 0;
    if(this!=NULL  && strlen(nombre) != 0)
    {
        strcpy( this->nombre, nombre );
        todoOk = 1;
    }
    return todoOk;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int todoOk = 0;
    if(this!=NULL)
    {
        strcpy ( nombre, this->nombre); //
        todoOk = 1;
    }
    return todoOk;
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk=0;
    if(this!=NULL)
    {
        if(horasTrabajadas>0||horasTrabajadas<24)
        {
            this->horasTrabajadas=horasTrabajadas;
            todoOk=1;
        }
    }

    return todoOk;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOk=0;

   if(this!=NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        todoOk=1;
    }
    return todoOk;
}
int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOk = 0;
    if(this!=NULL)
    {
        if(sueldo > 1000 || sueldo <90000)
        {
            this->sueldo = sueldo;
            todoOk = 1;
        }
    }
    return todoOk;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOk = 0;
    if(this!=NULL)
    {
        *sueldo = this->sueldo;
        todoOk = 1;
    }
    return todoOk;
}

int employee_ComparaId(void* empleadoA,void* empleadoB)
{

    int retorno=0;

    Employee* e1;
    Employee* e2;


    if(empleadoA != NULL && empleadoB != NULL)
    {
        e1 = (Employee*)empleadoA;
        e2 = (Employee*)empleadoB;

      if(e1->id > e2->id)
      {
          retorno= 1;
      }
      else if(e1->id < e2->id)
      {
          retorno=-1;
      }

    }
    return retorno;

}
int employee_ComparaNombre(void* empleadoA,void* empleadoB)
{
   int retorno = 0;
    Employee* e1;
    Employee* e2;

    if(empleadoA!=NULL&&empleadoB!=NULL)
    {
        e1=(Employee*)empleadoA;
        e2=(Employee*)empleadoB;
       retorno=strcmp(e1->nombre,e2->nombre);
    }
return retorno;
}
int employee_ComparaHorasTrabajadas(void* empleadoA,void* empleadoB)
{


    int retorno=0;

    Employee* e1;
    Employee* e2;


    if(empleadoA != NULL && empleadoB != NULL)
    {
        e1 = (Employee*)empleadoA;
        e2 = (Employee*)empleadoB;

      if(e1->horasTrabajadas > e2->horasTrabajadas)
      {
          retorno= 1;
      }
      else if(e1->horasTrabajadas < e2->horasTrabajadas)
      {
          retorno=-1;
      }

    }
    return retorno;

}
int employee_ComparaSueldo(void* empleadoA,void* empleadoB)
{

    int retorno=0;

    Employee* e1;
    Employee* e2;


    if(empleadoA != NULL && empleadoB != NULL)
    {
        e1 = (Employee*)empleadoA;
        e2 = (Employee*)empleadoB;

      if(e1->sueldo > e2->sueldo)
      {
          retorno= 1;
      }
      else if(e1->sueldo < e2->sueldo)
      {
          retorno=-1;
      }

    }
    return retorno;
}
