/*
 ============================================================================
 Name        : TP1.c
 Author      : Martina Torrez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "torrez.h"


int main()
{ 	setbuf(stdout, NULL);
	char salir='n';
    int opcion;
    int operandoX=0;
    int operandoY=0;
    int flagOperando=0;
    int flagOtroOp=0;
    int flagCalculos=0;
    int resultadoSuma;
    int resultadoResta;
    float resultadoDivision;
    int resultadoMultiplicacion;
    int resultadoFactX;
    int resultadoFactY;

    do
    {
        system("cls");
        printf("Calculadora\n\n");
        printf("1. Ingrese primer operando (A = %d)\n", operandoX);
        printf("2. Ingrese el segundo operando (B = %d)\n", operandoY);
        printf("3. Calcular operaciones\n");
        printf("4. Mostrar resultados\n");
        printf("5. Salir");


        printf("\nIngrese opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
            printf("Ingrese el primer operando: ");
            scanf("%d", &operandoX);
            flagOperando=1;
            system("pause");
            break;
            case 2:
            if(flagOperando)
            {
                printf("Ingrese el segundo operando: ");
                scanf("%d", &operandoY);
                flagOtroOp=1;

            }
            else
            {
                printf("Debe ingresar el primer operando antes de ingresar el segundo\n");
                system("pause");
            }
            break;
            case 3:
            if(flagOperando && !flagOtroOp)
            {
                printf("ESPERE. Solo ingreso un operando. Necesita ingresar otro\n");
                system("pause");
            }
            else if (flagOperando && flagOtroOp)
            {
                printf("Realizando calculos...\n\n");
                printf("a. Calculando suma (%d+%d)\n", operandoX, operandoY);
                resultadoSuma=sumar(operandoX,operandoY);
                printf("b. Calculando resta(%d+%d)\n", operandoX, operandoY);
                resultadoResta=restar(operandoX,operandoY);
                printf("c. Calculando division (%d/%d)\n", operandoX, operandoY);
                resultadoDivision=dividir(operandoX,operandoY);
                printf("d. Calculando multiplicacion(%d*%d)\n", operandoX, operandoY);
                resultadoMultiplicacion=multiplicar(operandoX,operandoY);
                printf("e. Calculando factoriales de %d y %d\n", operandoX, operandoY);
                resultadoFactX= factorial(operandoX);
                resultadoFactY=factorial(operandoY);
                system("pause");
                flagOperando=0;
                flagOtroOp=0;
                flagCalculos=1;
            }
            else
            {
                printf("ESPERE. No ingreso ningun operando\n");
                system("pause");
            }

            break;
            case 4:
              if(flagCalculos==1)
                {
                    printf("a. El resultado de %d+%d es: %d\n", operandoX, operandoY, resultadoSuma);
                    printf("b. El resultado de %d - %d es: %d\n", operandoX, operandoY, resultadoResta);
                   if(operandoY==0)
                    {
                        printf("c. No es posible dividir por cero\n");
                    }
                   else
                   {
                       printf("c. El resultado de %d / %d es: %.2f\n", operandoX, operandoY, resultadoDivision);
                   }

                   printf("d. ?El resultado de %d * %d es: %d\n", operandoX, operandoY, resultadoMultiplicacion);
                  if(operandoX<0 || operandoX>12)
                  {
                    printf("e. No es posible factorizar el numero %d\n", operandoX);
                  }
                  else
                 {
                     printf("e.El factorial de %d es %d\n", operandoX, resultadoFactX);
                 }

                  if(operandoY < 0 || operandoY > 12)
                {
                    printf("No se puede factorizar el numero %d\n", operandoY);
                }
                else
                {
                    printf("El factorial de %d es %d\n", operandoY, resultadoFactY);
                }
                   system("pause");
                }
              else
            {
                printf("Todavia no realizo ningun calculo...");
                system("pause");
            }


            break;
            case 5:
                printf("Seguro que quiere salir? Si no quiere salir presione 'n' ");
                fflush(stdin);
                salir=getchar();


            break;

        }

    }while(salir =='n');
    return 0;
}




