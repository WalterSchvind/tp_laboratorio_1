#include <stdio.h>

/** \brief Realiza una suma y devuelve el resultado
 *
 * \param a int numero 1
 * \param b int numero 2
 * \return int resultado
 *
 */
int sumar(int a,int b);

/** \brief Realiza una resta y devuelve la diferencia
 *
 * \param a int minuendo
 * \param b int sustraendo
 * \return int diferencia
 *
 */
int restar(int a, int b);

/** \brief Recibe dos numeros enteros los divide y devuelve el resultado en float
 *
 * \param a int dividendo
 * \param b int divisor
 * \return float cociente
 *
 */
float dividir(int a, int b);

/** \brief Realiza una multiplicacion y devuelve el producto
 *
 * \param a int numero 1
 * \param b int numero 2
 * \return int producto
 *
 */
int multiplicar(int a, int b);

/** \brief La funcion realiza el factorial del numero ingresado y la devuelve
 *
 * \param a int numero a factorizar
 * \return int resultado
 *
 */
int factorial(int a);


/** \brief Llama a la funcion que realiza las operaciones y muestra los resultados si ver es 1
 *
 * \param a int numero 1
 * \param b int numero 2
 * \param ver int parametro de control para mostrar(1) o no resultados(0)
 * \return void
 *
 */

void realizarOperacionesAritmeticasYMostrar(int a, int b,int ver);


