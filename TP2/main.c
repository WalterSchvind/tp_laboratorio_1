#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "ArraySector.h"
#define TAM 1000
#define TAMSEC 5


int main()
{
    eEmployee listaEmpleados[TAM];
    eSector listaSectores[TAMSEC]={ {1, "Sistemas"},
                                    {2, "RRHH"},
                                    {3, "Ventas"},
                                    {4, "Compras"},
                                    {5, "Contable"}};

    char seguir='s';
    char confirma;
    int auxId;
    int flagAlta=0;


    initEmployees(listaEmpleados,TAM);
    //addSectors(listaSectores,TAMSEC); Funcion si quiero Agregar Sectores manualmente

    do
    {

        switch(menu())
        {
        case 1:
            addEmployees(listaEmpleados,TAM,listaSectores,TAMSEC);
            flagAlta=1;

            break;
        case 2:
            if(flagAlta==1)
            {
                modifyEmployee(listaEmpleados,TAM,listaSectores,TAMSEC);
            }
            else
            {
                printf("Debe ingresar algun empleado\n");
            }

            break;
        case 3:

            if(flagAlta==1)
            {
                if(receiveId(&auxId)!=-1)
                {
                    removeEmployee(listaEmpleados,TAM,auxId);
                }
                else
                {
                    printf("Error. Id ingresado invalido");
                }
            }
            else
            {
                printf("Debe ingresar algun empleado\n");
            }


            break;
        case 4:

            if(flagAlta==1)
            {
                reportEmployees(listaEmpleados,TAM,listaSectores,TAMSEC);
            }
            else
            {
                printf("Debe ingresar algun empleado\n");
            }



            break;
        case 5:
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
    while(seguir=='s');

    return 0;
}
