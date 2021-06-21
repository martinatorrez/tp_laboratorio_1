#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
	setbuf(stdout, NULL);
    int option = 0;
    int idEmployee=1001;
    LinkedList* listaEmpleados = ll_newLinkedList();


    if(listaEmpleados==NULL)
    {
        printf("No se pudo crear el linkedlist\n");
    }


    do{
        switch(menu())
        {
            case 1:
                if(controller_loadFromText("data.csv",listaEmpleados))
                {
                  printf("Empleados cargados con exito\n");
                  system("pause");
                }

                break;
            case 2:
            if(controller_loadFromBinary("data.bin", listaEmpleados))
            {
               printf("Empleados cargados con exito\n");
                system("pause");
            }
           break;
            case 3:
             buscarMayorId(listaEmpleados, &idEmployee);
             printf("Ingrese este ID: %d\n", idEmployee);
             if(controller_addEmployee(listaEmpleados))
            {
                printf("Empleado agregado con exito\n");
                system("pause");
            }
            break;
            case 4:
            controller_editEmployee(listaEmpleados);
            system("pause");
                break;
            case 5:
            controller_removeEmployee(listaEmpleados);
            system("pause");
                break;
            case 6:
             controller_ListEmployee(listaEmpleados);
             system("pause");
                break;
            case 7:
            controller_sortEmployee(listaEmpleados);
            controller_ListEmployee(listaEmpleados);
            system("pause");
                break;
            case 8:
            if(controller_saveAsText("data.csv", listaEmpleados))
            {
              printf("Datos guardados con exito\n");
              system("pause");
            }
                break;
            case 9:
              if(!controller_saveAsBinary("data.bin", listaEmpleados))
            {
                 printf("Datos guardados con exito\n");
                 system("pause");
            }
            else
            {
              printf("Error al guardar los datos\n");
              system("pause");
            }
                break;
            case 10:
                printf("Seguro que desea salir? Si no es asi presione 0: \n");
                scanf("%d", &option);
                break;
        }
    }while(option ==0);
    return 0;
}


