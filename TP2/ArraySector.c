#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArraySector.h"



int addSectors(eSector* listaSector,int lenSector)
{
    int todoOk=-1;
    for(int i=0;i<lenSector;i++)
    {
        printf("Ingrese nombre del sector %d: ",i+1);
        scanf("%s",listaSector[i].descripcion);
        listaSector[i].idSector=i+1;
        listaSector[i].isEmpty=0;
        todoOk=1;
    }
    return todoOk;
}
int menuSectors(eSector* listaSector,int lenSector)
{
    int eleccion;

    for(int i=0;i<lenSector;i++)
    {
        printf("%d.-%s\n",listaSector[i].idSector,listaSector[i].descripcion);
    }

    printf("Elija Sector:");
    scanf("%d",&eleccion);

    return eleccion;
}
int loadSectorName(char sectorName[],int id,eSector* listaSector,int lenSector)
{

int todoOk=-1;


    for(int i=0;i<lenSector;i++)
    {
        if(listaSector[i].idSector==id)
        {
            strcpy(sectorName,listaSector[i].descripcion);
            todoOk=1;
        }
    }


    return todoOk;
}
