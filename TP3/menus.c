#include "menus.h"



int menu()
{
    int opcion;
    printf("***** M E N U *****\n\n");
    printf(" 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf(" 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    printf(" 3. Alta de empleado\n");
    printf(" 4. Modificar datos de empleado\n");
    printf(" 5. Baja de empleado\n");
    printf(" 6. Listar empleados\n");
    printf(" 7. Ordenar empleados(Tarda unos segundos)\n");
    printf(" 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf(" 9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    printf(" 10. Salir\n");
    printf("Ingrese la accion que desea realizar: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}
int menuModificaciones()
{
    int opcion;
    printf("***** MODIFICACIONES *****\n\n");
    printf(" 1. Nombre\n");
    printf(" 2. Horas trabajadas\n");
    printf(" 3. Salario\n");
    printf(" 4. Salir\n");
    printf("Elija una opcion:");
    scanf("%d",&opcion);

    return opcion;
}
int menuOrdenamiento()
{
    int opcion;
    printf("***** ORDENAMIENTO *****\n\n");
    printf(" 1. Empleados ordenados por ID\n");
    printf(" 2. Empleados ordenados por Nombre\n");
    printf(" 3. Empleados ordenados por Horas trabajadas\n");
    printf(" 4. Empleados ordenados por Sueldo\n");
    printf("Elija una opcion:");
    scanf("%d",&opcion);

    return opcion;
}

