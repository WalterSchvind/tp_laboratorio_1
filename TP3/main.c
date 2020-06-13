#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menus.h"

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
    char seguir='s';
    char confirma;
    int flagTxt=0;
    int flagBin=0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
        system("cls");
        switch(menu())
        {
        case 1:
            if(flagTxt==0&&flagBin!=1)
            {
               controller_loadFromText("data.csv",listaEmpleados);
               flagTxt = 1;
            }
            else
            {
                printf("Error. Los datos ya se cargaron\n");
            }

            break;
        case 2:

            if(flagBin==0&&flagTxt!=1)
            {
               controller_loadFromBinary("data.bin",listaEmpleados);
               flagBin=1;
            }
            else
            {
                printf("Error. Los datos ya se cargaron\n");
            }
            break;
        case 3://Alta
            if(flagBin==1||flagTxt==1)
            {
               controller_addEmployee(listaEmpleados);
               flagBin=1;
            }
            else
            {
                printf("Error. No hay datos cargados\n");
            }

            break;
        case 4://Modificar
            if(flagBin==1||flagTxt==1)
            {
               controller_editEmployee(listaEmpleados);
               flagBin=1;
            }
            else
            {
                printf("Error. No hay datos para modificar\n");
            }
            break;
        case 5://Baja
             if(flagBin==1||flagTxt==1)
            {
               controller_removeEmployee(listaEmpleados);
               flagBin=1;
            }
            else
            {
                printf("Error. No hay datos para remover\n");
            }
            break;
        case 6://Listar
             if(flagBin==1||flagTxt==1)
            {
               controller_ListEmployee(listaEmpleados);
               flagBin=1;
            }
            else
            {
                printf("Error. No hay datos para mostrar\n");
            }
            break;
        case 7://Ordenar
             if(flagBin==1||flagTxt==1)
            {
               controller_sortEmployee(listaEmpleados);
               flagBin=1;
            }
            else
            {
                printf("Error. No hay datos para Ordenar\n");
            }
            break;
        case 8://Guardar texto
             if(flagBin==1||flagTxt==1)
            {
               controller_saveAsText("data.csv",listaEmpleados);
               flagBin=1;
            }
            else
            {
                printf("Error. No hay datos para Guardar\n");
            }
            break;
        case 9://Guardar Binario
              if(flagBin==1||flagTxt==1)
            {
               controller_saveAsBinary("data.bin",listaEmpleados);
               flagBin=1;
            }
            else
            {
                printf("Error. No hay datos para Guardar\n");
            }
            break;
        case 10:
            printf("Confirma Salida?: ");
            fflush(stdin);
            scanf("%c",&confirma);
            if ( tolower(confirma)=='s')
            {
                seguir='n';
            }
            break;
        default:
            printf("Error.Elija una opcion valida\n");
        }
        system("pause");
    }
    while(seguir =='s');
    return 0;
}

