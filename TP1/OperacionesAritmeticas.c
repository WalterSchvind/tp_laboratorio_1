#include "OperacionesAritmeticas.h"

int sumar(int a,int b)
{
    int resultado;

    resultado = a + b;

    return resultado;
}

int restar(int a, int b)
{
    int resultado;

    resultado = a - b;

    return resultado;
}

float dividir(int a, int b)
{
    float resultado;
    if(b!=0)
    {
        resultado = (float) a / b;
    }

    return resultado;
}

int multiplicar(int a, int b)
{
    int resultado;

    resultado = a * b;

    return resultado;
}

int factorial(int a)
{
    int resultado;

    if(a>=0)
    {
        if (a == 0||a==1)
        {
            resultado = 1;
        }

        else
        {
            resultado = a* factorial(a-1);
        }
    }
    else
    {
        resultado=-1;
    }

    return resultado;

}

void realizarOperacionesAritmeticasYMostrar(int a, int b,int ver)
{
    int suma;
    int diferencia;
    int producto;
    int cociente;
    int fact1;
    int fact2;

    suma = sumar(a,b);
    diferencia = restar(a,b);
    producto = multiplicar(a,b);
    cociente = dividir(a,b);
    fact1 = factorial(a);
    fact2 = factorial(b);

    if(ver==0)
    {
        printf("Realizando Operaciones\n");
        printf("Suma de %d + %d\n", a,  b);
        printf("Resta de %d - %d\n", a,  b);
        printf("Division de %d / %d\n", a, b);
        printf("Multiplicacion de %d * %d\n", a, b);
        printf("Factorial de %d\n", a);
        printf("Factorial de %d\n", b);
    }
    else
    {
        printf("Resulado de la suma de %d + %d = %d\n",a,b,suma);
        printf("Diferencia de la resta de %d - %d = %d\n",a,b,diferencia);
        printf("Producto de la multiplicacon de %d * %d = %d\n",a,b,producto);
        if (b==0)
        {
            printf("No se puede dividir por 0\n");
        }
        else
        {
            printf("Cociente de la division de %d / %d = %d\n",a,b,cociente);
        }
        if(fact1==-1)
        {
            printf("No se puede sacar el factorial de un numero menor que 0\n");
        }
        else
        {
            printf("Factorial de %d = %d\n",a,fact1);
        }
        if(fact2==-1)
        {
            printf("No se puede sacar el factorial de un numero menor que 0\n");
        }
        else
        {
            printf("Factorial de %d = %d\n",b,fact2);
        }

    }
}

