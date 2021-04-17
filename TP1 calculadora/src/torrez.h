/*
 * torrez.h
 *
 *  Created on:  abr. 2021
 *      Author:
 */

#ifndef TORREZ_H_
#define TORREZ_H_

#include <stdio.h>
#include <stdlib.h>

/** \brief realiza una suma entre dos enteros
 *
 * \param primerNum int primer entero
 * \param segundoNum int segundo entero que se va a sumar
 * \return int devuelve la suma o total entre dos enteros
 *
 */
int sumar(int primerNum, int segundoNum);

/** \brief realiza una resta entre dos enteros
 *
 * \param primerNum int minuendo de la operacion
 * \param segundoNum int sustraendo de la operacion
 * \return int devuelve el resto o la diferencia
 *
 */
int restar(int primerNum, int segundoNum);

/** \brief realiza la multiplicacion entre dos enteros
 *
 * \param primerNum int primer factor de la operacion
 * \param segundoNum int segundo factor de la operacion
 * \return int devuelve el producto entre dos factores
 *
 */
int multiplicar(int primerNum, int segundoNum);

/** \brief realiza la division de dos enteros
 *
 * \param primerNum int dividendo de la operacion
 * \param segundoNum int divisor de la operacion
 * \return float devuelve el cociente entre el dividendo y el divisor
 *
 */
float dividir(int primerNum, int segundoNum);

/** \brief realiza el factorial de un entero
 *
 * \param n int entero a factorizar
 * \return int devuelve el resultado de la factorizacion
 *
 */
int factorial(int n);

#endif /* TORREZ_H_ */
