/*
 ============================================================================
 Name        : tp2Abm.c
 Author      : Torrez Martina
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayemployees.h"
#define TAM 1000

int main(void) {
	setbuf(stdout, NULL);
	int idEmpleado=5000;
	    char salir='n';
	    int flag=0;
	    Employee eList[TAM];
	    int orden=0;


	    initEmployees(eList,TAM);


	    do
	    {

	        switch(menu())
	        {
	        case 1:
	            if(addEmployee(eList, TAM, &idEmpleado))
	            {
	                printf("Alta exitosa\n");
	            }
	            else
	            {
	                printf("Hubo un problema al dar de alta\n");
	            }
	            flag=1;
	            system("pause");
	            break;
	        case 2:
	            if(flag==0)
	            {
	                printf("Todavia no puede ingresar a esta opcion debido a que no ingreso ningun empleado\n");
	            }
	            else
	            {
	                modifyEmployee(eList,TAM,idEmpleado);
	            }
	            system ("pause");
	            break;
	        case 3:
	            if(flag==0)
	            {
	                printf("Todavia no puede ingresar a esta opcion debido a que no ingreso ningun empleado\n");
	            }
	            else
	            {
	                if(removeEmployee(eList, TAM, idEmpleado))
	                {
	                    printf("Baja existosa ");
	                }

	            }
	            system ("pause");
	            break;
	        case 4:
	            if(flag==0)
	            {
	                printf("Todavia no puede ingresar a esta opcion debido a que no ingreso ningun empleado\n");
	            }
	            else
	            {
	                sortEmployees(eList,TAM,orden);
	                printEmployees(eList,TAM);
	            }

	            system("pause");
	            break;
	        case 5:
	            if(flag==0)
	            {
	                printf("Todavia no puede ingresar a esta opcion debido a que no ingreso ningun empleado\n");
	            }
	            else
	            {
	                infoSalary(eList,TAM);
	            }
	            system ("pause");
	            break;
	        case 6:
	            printf("Seguro que desea salir? (Si no desea salir presione 'n') ");
	            fflush(stdin);
	            scanf("%c",&salir);
	            break;


	        }

	    }
	    while(salir =='n');

	    return 0;
}
