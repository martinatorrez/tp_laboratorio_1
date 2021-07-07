#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include <string.h>
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* f=fopen(path, "r");
    if(f==NULL)
    {
        printf("No se pudo abrir\n");
        exit(1);
    }
    else
    {
        parser_EmployeeFromText(f, pArrayListEmployee);
    }


    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* f=fopen(path, "rb");
    if(f==NULL)
    {
        printf("No se pudo abrir\n");
        exit(1);
    }
    else
    {
        parser_EmployeeFromBinary(f,pArrayListEmployee);
    }


    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* aux=NULL;
    int todoOk=0;
    int flag=0;

    if(pArrayListEmployee!=NULL)
    {
        printf("ID  Nombre  Horas trabajadas  Sueldo\n");
        for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {

            aux= (Employee*) ll_get(pArrayListEmployee,i);
            listEmployee(aux);
            flag=1;
            todoOk=1;
        }
        printf("\n\n");
        if(flag==0)
        {
            printf("No hay empleados para mostrar\n");
        }
    }
    return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* idEmployee)
{
    Employee* auxEmpleado=employee_new();
    char nombre[158];
    int horasTrabajadas;
    int sueldo;


    printf("***Alta empleados**\n");

    printf("Ingrese el nombre del empleado: ");
    fflush(stdin);
    gets(nombre);

    while(!employee_setNombre(auxEmpleado,nombre))
    {
        printf("ERROR. Reingrese el nombre del empleado: ");
        fflush(stdin);
        gets(nombre);
    }

    printf("Ingrese las horas trabajadas: ");
    scanf("%d", &horasTrabajadas);
    while(!employee_setHorasTrabajadas(auxEmpleado,horasTrabajadas))
    {
        printf("ERROR. Reingrese las horas trabajadas: ");
        scanf("%d", &horasTrabajadas);
    }

    printf("Ingrese el sueldo del empleado: ");
    scanf("%d",  &sueldo);
    while(!employee_setSueldo(auxEmpleado,sueldo))
    {
        printf("Error. Reingrese el sueldo del empleado: ");
        scanf("%d",  &sueldo);
    }

    auxEmpleado->id=*idEmployee;
    *idEmployee=*idEmployee+1;
    ll_add(pArrayListEmployee,auxEmpleado);
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* aux=NULL;
    Employee* auxEmpleado=NULL;
    int idBuscado;
    char afirmo;
    int opcion;
    char confirma;
    int nuevoId;
    char nuevoNombre[128];
    int nuevasHorasTrabajadas;
    int nuevoSueldo;

    controller_ListEmployee(pArrayListEmployee);
    printf("Ingrese el ID del empleado a modificar: ");
    scanf("%d", &idBuscado);

    for(int i=0; i<ll_len(pArrayListEmployee); i++)
    {
        aux = (Employee*) ll_get(pArrayListEmployee,i);

        if (aux->id==idBuscado)
        {
            listEmployee(aux);
            printf("Seguro que quiere modificar al empleado? Presione s\n");
            fflush(stdin);
            scanf("%c", &afirmo);
            break;
        }

    }
    if(afirmo=='s')
    {
        system("pause");
        printf("Ingrese 1 si quiere modificar el id\n");
        printf("Ingrese 2 si quiere modificar el nombre\n");
        printf("Ingrese 3 si quiere modificar las horas trabajadas\n");
        printf("Ingrese 4 si quiere modificar el sueldo\n");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            printf("Ingrese el nuevo ID del empleado: ");
            scanf("%d", &nuevoId);
            printf("Confirma el cambio? Presione s: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma=='s')
            {
                for(int i = 0; i< ll_len(pArrayListEmployee); i++)
                {
                    auxEmpleado = (Employee*) ll_get(pArrayListEmployee,i);
                    if(auxEmpleado->id == nuevoId)
                    {
                        while(auxEmpleado->id == nuevoId)
                        {
                            printf("ERROR. id ya cargado en el sistema. reingrese:");
                            scanf("%d",&nuevoId);
                        }
                    }

                }
                aux->id= nuevoId;
            }

            else
            {
                printf("Cambio cancelado");
            }
            break;
        case 2:
            printf("Ingrese nuevo Nombre: ");
            fflush(stdin);
            gets(nuevoNombre);
            printf("Confirma el cambio? Presione s: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma=='s')
            {
                strcpy(aux->nombre,nuevoNombre);
            }
            else
            {
                printf("Cambio cancelado");
            }
            break;
        case 3:
            printf("Ingrese las horas trabajadas del empleado: ");
            scanf("%d", &nuevasHorasTrabajadas);
            printf("Confirma el cambio? Presione s");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma=='s')
            {
                aux->horasTrabajadas=nuevasHorasTrabajadas;
            }
            else
            {
                printf("Cambio cancelado");
            }
            break;
        case 4:
            printf("Ingrese el sueldo del empleado: ");
            scanf("%d", &nuevoSueldo);
            printf("Confirma el cambio? Presione s");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma=='s')
            {
                aux->sueldo=nuevoSueldo;
            }
            else
            {
                printf("Cambio cancelado");
            }
            break;

        }

    }
    return 1;
}



/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* aux=NULL;
    int idBuscado;
    int indice;
    char opcion;

    controller_ListEmployee(pArrayListEmployee);
    printf("Ingrese el ID del empleado a dar de baja: ");
    scanf("%d", &idBuscado);

    for(int i=0; i<ll_len(pArrayListEmployee); i++)
    {
        aux = (Employee*) ll_get(pArrayListEmployee,i);
        if (aux->id==idBuscado)
        {

            printf("Confirma baja? Presione 's'");
            fflush(stdin);
            scanf("%c", &opcion);
            indice=i;
            if(opcion== 's')
            {
                ll_remove(pArrayListEmployee,indice);
                employee_delete(aux);
                printf("Baja exitosa\n");
            }
            else
            {
                printf("Baja cancelada\n");
            }

        }

    }


    return 1;
}



/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    printf("Empleados ordenados alfabeticamente de forma descendente\n");

    ll_sort(pArrayListEmployee,sortEmployeesByName,1);

    return 1;

}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    Employee* aux;

    FILE* f= fopen(path, "w");
    if(f==NULL)
    {
        printf("No se pudo abrir\n");
    }
    fprintf(f,"Id,nombre,horasTrabajadas,sueldo\n");
    for(int i=0; i<ll_len(pArrayListEmployee); i++)
    {
        aux=ll_get(pArrayListEmployee,i);
        if(aux!=NULL)
        {
            fprintf(f,"%d,%s,%d,%d\n",
                    aux->id,
                    aux->nombre,
                    aux->horasTrabajadas,
                    aux->sueldo);
            todoOk=1;
        }
    }
    fclose(f);



    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    int cant;


    FILE* f= fopen(path, "wb");
    if(f==NULL)
    {
        printf("No se pudo abrir\n");
    }

    for(int i=0; i<ll_len(pArrayListEmployee); i++)
    {
        cant=fwrite(ll_get(pArrayListEmployee,i), sizeof(Employee),1,f);
        if(cant<1)
        {
            todoOk=1;
        }

    }
    fclose(f);



    return todoOk;
}


