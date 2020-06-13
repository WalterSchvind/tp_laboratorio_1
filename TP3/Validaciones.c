#include "Validaciones.h"
int getString(char* msg, char* msgError, int min, int max, int reintentos, char* resultado)
{
    int todoOk=-1;
    char auxChar[max+10];

    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            printf("%s",msg);   //no poner salto de linea, se va a pasar en el mensaje por valor
            fflush(stdin);
            gets(auxChar);

            if(strlen(auxChar)>=min && strlen(auxChar)<max)    // tamaño (max) =cantidad de elementos (strlen) + 1(\0)
            {
                strncpy(resultado,auxChar,max);
                todoOk=0;
                break;
            }
            printf("%s",msgError);
            reintentos--;
        }
        while((reintentos)>=0);
    }
    return todoOk;
}

int getName(char* msg, char* msgError, int min, int max, int reintentos, char* resultado)
{
    int todoOk=-1;
    char auxChar[max];

    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,min,max,reintentos,auxChar)) //==0
            {
                if(isValidName(auxChar)==1)
                {
                    strncpy(resultado,auxChar,max);
                    todoOk=0;
                    break;
                }
                else
                {
                    printf("%s",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return todoOk;
}
int isValidName(char* stringRecibido)
{
    int todoOk=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0; stringRecibido[i]!='\0'; i++)
    {
        if(stringRecibido[i]<'A' || (stringRecibido[i]>'Z' && stringRecibido[i]<'a') || stringRecibido[i]>'z')
        {
            todoOk=0;
            break;
        }
    }
    return todoOk;
}
int getInt(char* mensaje)
{
    char auxiliarChar[10];
    int enteroADevolver;

    printf("%s", mensaje);
    scanf("%s", auxiliarChar);
    fflush(stdin);
    enteroADevolver = atoi(auxiliarChar);

    while(enteroADevolver == 0)
    {
        printf("%s", "Valor invalido. Ingrese un numero \n");
        scanf("%s", auxiliarChar);
        fflush(stdin);
        enteroADevolver = atoi(auxiliarChar);
    }

    return enteroADevolver;

}
int getUnsignedInt (char* msg,char* msgError,int minSize,int maxSize,int reintentos,int* input)
{
    int todoOk=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr))
            {
                if(isValidNumber(bufferStr)==1)
                {
                    *input=atoi(bufferStr);
                    todoOk=0;
                    break;
                }
                else
                {
                    printf("%s",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return todoOk;
}

int isValidNumber(char* stringRecibido)     //podrìa necesitar parametros para validar max y min
{
    int todoOk=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0; stringRecibido[i]!='\0'; i++)
    {
        if(stringRecibido[i]<'0' || stringRecibido[i]>'9')
        {
            todoOk=0;
            break;
        }
    }
    return todoOk;
}


int getFloat(char* msg, char* msgError, int minSize, int maxSize, int reintentos, float* input)
{
    int todoOk=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,minSize,maxSize,reintentos,bufferStr)) //==0 sin errores !0
            {
                if(isValidFloatNumber(bufferStr)==1)
                {
                    *input=atof(bufferStr); // atof array to float
                    todoOk=0;
                    break;
                }
                else
                {
                    printf("%s", msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return todoOk;
}

int isValidFloatNumber(char* stringRecibido)
{
    int todoOk=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0; stringRecibido[i]!='\0'; i++)
    {
        if((stringRecibido[i]<'0' || stringRecibido[i]>'9') && (stringRecibido[i]!='.'))
        {
            todoOk=0;
            break;
        }
    }
    return todoOk;
}
