#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "ArraySector.h"

int initEmployees(eEmployee* lista,int len)
{
    int sePudo=0;
    for(int i=0; i<len; i++)
    {
        lista[i].isEmpty=1;
        sePudo=1;
    }

    return sePudo;
}
int menu()
{
    int opcion;

    system("cls");

    printf("***** M E N U *****\n\n");
    printf("  1. ALTAS\n");
    printf("  2. MODIFICAR\n");
    printf("  3. BAJA\n");
    printf("  4. INFORMAR\n");
    printf("  5. SALIR\n\n");

    printf("Ingrese la accion que desea realizar: ");
    scanf("%d", &opcion);

    return opcion;
}
int searchEmpty(eEmployee* lista,int len)
{
    int indice=-1;

    for(int i=0; i<len; i++)
    {
        if (lista[i].isEmpty == 1)
        {
            indice = i;

            break;
        }
    }
    return indice;
}
int addEmployee(eEmployee* lista,int len,int id,char name[],char lastName[],float salary,int sector)
{
    int indice=searchEmpty(lista,len);
    int todoOk=0;

    if(indice<0)
    {
        printf("No hay lugar para ingresar nuevos empleados!!");
    }
    else
    {

        for(int i=0; i<len; i++)
        {
            if(lista[i].id==id&&lista[i].isEmpty==0)
            {
                id+=1;
            }
        }
        lista[indice].id=id;
        strcpy(lista[indice].name,name);
        strcpy(lista[indice].lastName,lastName);
        lista[indice].salary=salary;
        lista[indice].sector=sector;
        lista[indice].isEmpty=0;

        todoOk=1;
    }

    return todoOk;
}
int addEmployees(eEmployee*lista,int len,eSector* listaSector,int lenSector)
{
    int todoOk=-1;
    char seguir='s';
    int proximoId=1000;
    int nameErr;
    int lastNameErr;
    int salaryErr;
    eEmployee auxEmployee;



    do
    {
        system("cls");
        auxEmployee.id=proximoId;

        nameErr=getName("Ingrese Nombre:","Error.Ingrese nombre valido.\n",4,51,2,auxEmployee.name);

        lastNameErr=getName("Ingrese Apellido:","Error.Ingrese apellido valido.\n",4,51,2,auxEmployee.lastName);

        salaryErr=getFloat("Ingrese sueldo del empleado: ","Error Ingrese sueldo valido.\n",5,9,2,&auxEmployee.salary);

        auxEmployee.sector=menuSectors(listaSector,lenSector);

        if(nameErr!=-1 && lastNameErr!=-1 && salaryErr!=-1)
        {
           addEmployee(lista,len,auxEmployee.id,auxEmployee.name,auxEmployee.lastName,auxEmployee.salary,auxEmployee.sector);
           todoOk=0;
        }
        else
        {
         printf("Error. No se pudo agregar Empleado");
         break;
        }



        printf("Desea seguir agregando empleados?: ");
        fflush(stdin);
        scanf("%c",&seguir);


    }
    while(tolower(seguir)=='s');



    return todoOk;
}
int findEmployeeById(eEmployee* lista,int len,int id)
{
    int indice=-1;

    for(int i=0; i<len; i++)
    {
        if(lista[i].isEmpty==0&&id==lista[i].id)
        {
            indice=i;
            break;
        }

    }

    return indice;
}
int removeEmployee(eEmployee* lista,int len,int id)
{
    int todoOk=-1;
    int indice;

    indice=findEmployeeById(lista,len,id);

    if(indice!=-1)
    {
        lista[indice].isEmpty=1;
        todoOk=1;
    }
    else
    {
        printf("Error.Empleado no existe");
    }
    return todoOk;
}
int receiveId(int* id)
{
    int IdConseguido;
    int todoOk=0;

    printf("Ingrese id: ");
    scanf("%d",&IdConseguido);

    if(IdConseguido>0)
    {
        *id=IdConseguido;
        todoOk=1;
    }
    return todoOk;

}
void printEmployee(eEmployee x,eSector* listaSector, int lenSector)
{
    char nombreSector[20];
    loadSectorName(nombreSector,x.sector,listaSector,lenSector);
    printf("%d\t%s\t\t%4s\t\t%4.2f\t\t%s\n",x.id,x.name,x.lastName,x.salary,nombreSector);
}
int printEmployees(eEmployee* lista,int len,eSector* listaSector,int lenSector)
{
    int todoOk=-1;
    printf("ID\tNombre\t\tApellido\tSueldo\t\tSector\n");
    for(int i=0; i<len; i++)
    {
        if(lista[i].isEmpty==0)
        {
            printEmployee(lista[i],listaSector,lenSector);
            todoOk=0;
        }

    }
    if(todoOk==-1)
    {
        printf("Error.No hay empleados para mostrar");
    }
    return todoOk;
}
int sortEmployees(eEmployee* lista, int len, int order)
{
    int todoOk=-1;
    eEmployee auxEmployee;

    for(int i=0; i<len; i++)
    {
        for(int j=i+1; j<len; j++)
        {
            if(lista[i].isEmpty==0&&lista[j].isEmpty==0)
            {
                switch(order)
                {
                case 1:
                    //divide los sectores segun id de menor a mayor y ordena los empleados segun los apellidos en el mismo orden
                    if(lista[i].sector > lista[j].sector || (lista[i].sector == lista[j].sector && (strcmp(lista[i].lastName, lista[j].lastName)) > 0))
                    {
                        auxEmployee = lista[i];
                        lista[i] = lista[j];
                        lista[j] = auxEmployee;
                        todoOk=1;
                    }
                    break;

                case 2:
                    //divide los sectores segun id de mayor a menor y ordena los empleados segun los apellidos en el mismo orden
                    if(lista[i].sector < lista[j].sector || (lista[i].sector == lista[j].sector && (strcmp(lista[i].lastName, lista[j].lastName)) < 0)) //de mayor a menor sector (agrupa) y apellido (ordena)
                    {
                        auxEmployee = lista[i];
                        lista[i] = lista[j];
                        lista[j] = auxEmployee;
                        todoOk=0;
                    }
                    break;
                }

            }
        }
    }
    return todoOk;
}
int totalSalariesAverageWages(eEmployee* lista,int len)
{
    int todoOk=-1;
    float salariosTotal=0;
    int contadorSalarios=0;
    int contadorEmpleados;
    float promSalarios;

    for(int i=0; i<len; i++)
    {
        if(lista[i].isEmpty==0)
        {
            salariosTotal+=lista[i].salary;
            contadorSalarios++;
            todoOk=1;
        }
    }
    promSalarios = salariosTotal / contadorSalarios;

    for(int i=0; i<len; i++)
    {
        if(lista[i].isEmpty==0&&lista[i].salary>promSalarios)
        {
            contadorEmpleados++;
        }
    }

    printf("El total de salarios es: $%.2f\n",salariosTotal);
    printf("El promedio de salarios es: $%.2f\n",promSalarios);
    printf("La cantidad de empleados que superan el salario promedio es: %d\n",contadorEmpleados);
    return todoOk;
}
void reportEmployees(eEmployee* lista,int len,eSector* listaSector,int lenSector)
{
    sortEmployees(lista,len,1);
    printEmployees(lista,len,listaSector,lenSector);
    totalSalariesAverageWages(lista,len);
}
void modifyEmployee(eEmployee* lista,int len,eSector* listaSector,int lenSector)
{
    int id;
    int indice;
    char auxNombre[20];
    char auxApellido[20];
    float auxSueldo;

    char continuar='s';


    system("cls");
    printf("****Modificar Empleado****\n\n");
    printEmployees(lista,len,listaSector,lenSector);


    printf("Ingrese  ID: ");
    scanf("%d",&id);

    indice=findEmployeeById(lista,len,id);

    if(indice==-1)
    {
        printf("El empleado No existe\n");
    }

    else
    {
        system("cls");
        printEmployee(lista[indice],listaSector,lenSector);
        do
        {
            switch(modifyMenu())
            {
            case 1:
                printf("Ingrese nuevo nombre: ");
                fflush(stdin);
                scanf("%s",auxNombre);
                strcpy(lista[indice].name,auxNombre);
                break;
            case 2:
                printf("Ingrese nuevo apellido: ");
                fflush(stdin);
                scanf("%s",auxApellido);
                strcpy(lista[indice].lastName,auxApellido);
                break;
            case 3:
                printf("Ingrese nuevo sueldo: ");
                scanf("%f",&auxSueldo);
                lista[indice].salary=auxSueldo;

                break;
            case 4:
                lista[indice].sector=menuSectors(listaSector,lenSector);

                break;
            default:
                printf("Error.Opcion no valida");
            }


        printf("Desea continuar modificando?: ");
        fflush(stdin);
        scanf("%c",&continuar);


        }
        while(tolower(continuar)=='s');
    }
}
int modifyMenu(void)
{
    int opcion;


    printf("1.-Nombre\n");
    printf("2.-Apellido\n");
    printf("3.-Salario\n");
    printf("4.-Sector\n");
    printf("Indique que dato desea modificar: ");
    scanf("%d",&opcion);

    return opcion;
}
