#include "Controller.h"


int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    FILE *pArchivo;

    if((pArchivo = fopen(path, "r"))==NULL)
    {
        printf("No se puedo leer\n");
        fclose(pArchivo);
        exit(EXIT_FAILURE);
    }
    else
    {

        parser_EmployeeFromText(pArchivo, pArrayListEmployee);
        todoOk=1;



    }
    fclose(pArchivo);

    return todoOk;
}
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    FILE *pArchivo = fopen(path, "rb");
    if(pArchivo == NULL)
    {
        printf("El archivo no se pudo cargar.\n");
        fclose(pArchivo);
        exit(EXIT_FAILURE);

    }
    else
    {
        parser_EmployeeFromBinary(pArchivo, pArrayListEmployee);
        todoOk=1;
    }
    fclose(pArchivo);
    return todoOk;
}
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* newEmployees = employee_new();
    int todoOk = 0;
    char idAux[50];
    char nombreAux[50];
    char horasTrabajadasAux[50];
    char sueldoAux[50];
    int lenList = ll_len(pArrayListEmployee);
    int auxIntID;
    int flag=0;

    if(pArrayListEmployee !=NULL)
    {
        printf("Ingrese el id: ");
        scanf("%s",idAux);
        auxIntID=atoi(idAux);
        for( int i = 0; i <lenList ; i++ )
        {
            newEmployees = (Employee*)ll_get(pArrayListEmployee, i);
            if( newEmployees->id == auxIntID)
            {
                printf("Ese ID ya esta en uso!\n");
                flag=1;
                break;

            }

        }
        if(flag!=1)
        {
            printf("Ingrese el nombre: ");
            fflush(stdin);
            gets(nombreAux);
            printf("Ingrese las horas trabajadas: ");
            fflush(stdin);
            gets(horasTrabajadasAux);
            printf("Ingrese el sueldo: ");
            fflush(stdin);
            gets(sueldoAux);
            newEmployees = employee_newParametros(idAux, nombreAux, horasTrabajadasAux, sueldoAux);
            ll_add(pArrayListEmployee, newEmployees);
        }

        todoOk=1;
    }


    return todoOk;
}
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee *auxEmployee;
    char nombreAux[50];
    int idAuxInt;
    int sueldoAuxiliar;
    int horasTrabajadasAux;
    int len = ll_len(pArrayListEmployee);
    int salir=0;

    if(pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        idAuxInt = getInt("Ingrese el ID que desea modificar:  ");
        system("cls");
        for( int i = 0; i <len ; i++ )
        {

            auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);
            if( idAuxInt == auxEmployee->id )
            {
                do
                {

                    switch(menuModificaciones())
                    {
                    case 1:
                        printf("Ingrese el nuevo nombre: ");
                        fflush(stdin);
                        gets(nombreAux);
                        employee_setNombre(auxEmployee, nombreAux);
                        break;
                    case 2:
                        horasTrabajadasAux=getInt("Ingrese horas trabajadas");
                        employee_setHorasTrabajadas(auxEmployee, horasTrabajadasAux);
                        break;
                    case 3:
                        sueldoAuxiliar = getInt("Ingrese nuevo salario \n");
                        employee_setSueldo(auxEmployee, sueldoAuxiliar);
                        break;
                    case 4:
                        salir = 4;
                        break;
                    default:
                        printf("Opcion invalida");
                        break;
                    }
                }
                while(salir != 4);

            }
        }

    }
    return 1;
}
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{

    Employee* auxEmployee;
    int listLen = ll_len(pArrayListEmployee);

    int idAux;
    int todoOk=0;

    if(pArrayListEmployee !=NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        idAux = getInt("Ingrese ID  a remover: ");

        for(int i=0; i<listLen; i++)
        {
            auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);

            if(auxEmployee->id == idAux)
            {
                ll_remove(pArrayListEmployee, i);
                printf("Empleado borrado con exito!\n");
                employee_delete(auxEmployee);
                todoOk=1;
                break;
            }
        }
        if( auxEmployee->id != idAux)
        {
            printf("Ese Id no existe.\n");
        }

    }

    return todoOk;
}
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleadoAux;
    int todoOk = 0;
    int idAux;
    char nombreAux[50];
    int horasTrabajadasAux;
    int sueldoAux;
    int lenList = ll_len(pArrayListEmployee);
    int i;
    if(pArrayListEmployee!=NULL)
    {
        if(lenList>0)
        {
            printf(" Id------Nombre-----Horas trabajadas---Sueldo \n");

            for(i = 0; i < lenList; i++)
            {
                empleadoAux = (Employee*)ll_get(pArrayListEmployee, i);
                employee_getId(empleadoAux, &idAux);
                employee_getNombre(empleadoAux,nombreAux);
                employee_getHorasTrabajadas(empleadoAux,&horasTrabajadasAux);
                employee_getSueldo(empleadoAux,&sueldoAux);
                printf("%5d  %10s %10d  %15d\n",idAux, nombreAux, horasTrabajadasAux, sueldoAux);
            }

            todoOk = 1;

        }
        else
        {
            printf("No se cargaron los datos.\n");
        }
    }
    return todoOk;
}
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{

    int todoOk=0;
    if(pArrayListEmployee != NULL)
    {

        switch(menuOrdenamiento())
        {
        case 1:
            ll_sort(pArrayListEmployee, employee_ComparaId, 1);
            break;
        case 2:
            ll_sort(pArrayListEmployee, employee_ComparaNombre, 1);
            break;
        case 3:
            ll_sort(pArrayListEmployee, employee_ComparaHorasTrabajadas, 1);
            break;
        case 4:
            ll_sort(pArrayListEmployee, employee_ComparaSueldo, 1);
            break;

        }
        todoOk=1;


    }
    return todoOk;
}
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    int listLen = ll_len(pArrayListEmployee);
    Employee* pEmpleadoAux;
    FILE* pArchivo = fopen(path, "w");

    if(pArchivo != NULL)
    {

        fprintf(pArchivo, "id,nombre,horasTrabajadas,sueldo\n");

        if(pArrayListEmployee!=NULL)
        {
            for(int i = 0; i < listLen; i++)
            {
                pEmpleadoAux = (Employee*)ll_get(pArrayListEmployee, i);
                fprintf(pArchivo, "%d,%s,%d,%d\n", pEmpleadoAux->id, pEmpleadoAux->nombre, pEmpleadoAux->horasTrabajadas, pEmpleadoAux->sueldo);
            }
            printf("Archivo guardado con exito\n");
        }
        fclose(pArchivo);
        todoOk= 1;
    }
    else
    {
        printf("Error guardar archivo\n");
    }
    return todoOk;
}
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    Employee* pEmployeeAux;
    FILE* pArchivo = fopen(path, "wb");

    int listLen = ll_len(pArrayListEmployee);

    if(pArchivo == NULL)
    {

        printf("Error al guardar\n");

    }

    if(pArrayListEmployee!=NULL)
    {
        for(int i = 0; i < listLen; i++)
        {
            pEmployeeAux = (Employee*)ll_get(pArrayListEmployee, i);
            fwrite(pEmployeeAux,sizeof(Employee), 1, pArchivo);
        }
        printf("Archivo .bin guardado\n");
        todoOk=1;
    }
    fclose(pArchivo);
    return todoOk;
}

