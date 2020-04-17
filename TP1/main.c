#include <stdio.h>
#include <stdlib.h>
#include "OperacionesAritmeticas.h"

int main()
{
    int num1;
    int num2;
    int flagNum1=0;
    int flagNum2=0;
    int flagOpAr=0;
    int opcion;


    do
    {

        if(flagNum1==1)
        {
            printf("1) Ingresar primer numero(numero actual= %d)\n",num1);
        }
        else
        {
            printf("1) Ingresar primer numero\n");
        }
        if(flagNum2==1)
        {
            printf("2) Ingresar segundo numero(numero actual= %d)\n",num2);
        }
        else
        {
            printf("2) Ingresar segundo numero\n");
        }

        printf("3) Realizar operaciones aritmeticas\n");
        printf("4) Ver resultados de las operaciones\n");
        printf("5) Salir\n");
        printf("Elija la operacion que desea hacer: ");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            printf("Ingrese un numero: ");
            scanf("%d", &num1);
            flagNum1=1;
            break;
        case 2:
            printf("Ingrese un numero: ");

            fflush(stdin);

            scanf("%d",&num2);

            flagNum2=1;
            break;
        case 3:
            if(flagNum1==1&&flagNum2==1)
            {
                realizarOperacionesAritmeticasYMostrar(num1,num2,0);
                flagOpAr=1;
            }
            else
            {
                printf("Se debe ingresar dos numeros antes de calcular!!!\n\n");
            }
            break;
        case 4:
            if(flagOpAr==1)
            {
                realizarOperacionesAritmeticasYMostrar(num1,num2,1);

            }
            else
            {
                printf("Necesito realizar las cuentas antes de mostrar resultados!!!\n\n");
            }
            break;
        case 5:
            printf("Chau\n\n");
            break;

        default:
            printf("Opcion Incorrecta!!\n\n");
        }


        system("pause");
        system("cls");


    }
    while(opcion!=5);
    return 0;
}
