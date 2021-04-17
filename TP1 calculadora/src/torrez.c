/*
 * torrez.c
 *
 *  Created on:  abr. 2021
 *      Author:
 */

int sumar(int primerNum, int segundoNum)
{
    int resultado;

    resultado = primerNum + segundoNum;
    return resultado;
}

int restar(int primerNum, int segundoNum)
{
    int resultado;

    resultado= primerNum - segundoNum;
    return resultado;
}

float dividir(int primerNum, int segundoNum)
{
    float resultado;

    resultado= (float) primerNum / segundoNum;
    return resultado;
}
int multiplicar(int primerNum, int segundoNum)
{
    int resultado;
    resultado = primerNum * segundoNum;
    return resultado;
}

int factorial(int n)
{
    int fact=1;

    for(int i= 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}


