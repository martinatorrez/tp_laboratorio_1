#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayemployees.h"
#include "validations.h"

int menu()
{
    int opcion;

        system("cls");
        printf("ABM empleados\n\n");
        printf("1. Alta empleado\n");
        printf("2. Modificar empleado\n");
        printf("3. Baja empleados\n");
        printf("4. Listas empleados alfabeticamente\n");
        printf("5. Informe salarios\n");
        printf("6. Salir\n");

        printf("\nIngrese opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);
        return opcion;
}


/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 *
 * \param lista[] Employee Pointer to array of employees

 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee lista[], int len)
{
    int todoOk= -1;
    if(lista!=NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            lista[i].isEmpty=1;
            todoOk=0;
        }

    }

    return todoOk;
}
/** \brief Search for a position in the array that is empty
 *
 * \param lista[] Employee
 * \param len int Employee Pointer to array of employees
 * \return int Return (-1) if Error
 *
 */
int searchFreeSpace(Employee lista[], int len)
{
    int indice=-1;
    for(int i=0; i<len; i++)
    {
        if(lista[i].isEmpty)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
/** \brief add in a existing list of employees a new one in the first empty position
 *
 * \param lista[] Employee
 * \param len int
 * \param pId int* assigns an ID to the employee
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 *
 */
int addEmployee(Employee lista[],int len, int* pId)
{
    int todoOk=0;
    Employee newEmployee;
    int indice;

    if(lista!=NULL&& len>0&& pId!=NULL)
    {
        indice=searchFreeSpace(lista,len);

        if(indice==-1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {

            while(!getStringLetras("Ingrese el nombre del empleado: ",newEmployee.name))
                {
                    printf ("El nombre solo tiene que contener letras. Reingrese\n");

                }

             while(!getStringLetras("Ingrese el apellido del empleado: ",newEmployee.lastName))
                {
                    printf ("El apellido solo tiene que contener letras. Reingrese\n");

                }


            printf("Ingrese el salario: ");
            scanf("%f", &newEmployee.salary);

            printf("Ingrese el id del sector al que pertenece: ");
            scanf("%d", &newEmployee.sector);

            newEmployee.id= *pId;
            newEmployee.isEmpty=0;
            *pId=*pId+1;
            lista[indice]=newEmployee;
            todoOk=1;

        }
    }
    return todoOk;
}

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param lista[] Employee
 * \param len int
 * \param id int
 * \return int Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]

 *
 */
int findEmployeeById(Employee lista[], int len, int id)
{
    int indice=-1;


    for(int i=0; i<len; i++)
    {
        if(lista[i].id == id)
        {
            indice = i;
            break;
        }
    }


    return indice;
}

/** \brief  Remove a Employee by Id (put isEmpty Flag in 1)

 *
 * \param lista[] Employee
 * \param len int
 * \param idEmployee int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee lista[], int len, int idEmployee)
{
    int todoOk=-1;
    int indice;
    char confirma;
    if(lista!=NULL&& len>0)
    {
        printEmployees(lista,len);
        printf("Ingrese el ID del empleado que quiere dar de baja: ");
        scanf("%d", &idEmployee);

        indice=findEmployeeById(lista, len,idEmployee);

        if(indice==-1)
        {
            printf("El empleado no existe\n");
        }
        else
        {

            printf("Confirma baja? Presione 's'");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma== 's')
            {
                lista[indice].isEmpty=1;
                todoOk=0;

            }
            else
            {
                printf("Baja cancelada");
            }

        }
    }
    return todoOk;
}

/** \brief  Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param lista[] Employee
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOW
 * \return int  Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee lista[], int len, int order)
{
    Employee aux;
    int todoOk=-1;
    printf("Ingrese 1 si quiere ordenar por sector de A a Z o ingrese 0 si quiere ordenar de Z a A: ");
    scanf("%d", &order);

    if(order==1)
    {
        for(int i=0; i<len; i++)
        {
            for(int j = i + 1; j < len; j++)
            {
                if(lista[i].sector> lista[j].sector||(lista[i].sector == lista[j].sector &&strcasecmp(lista[i].lastName, lista[j].lastName)>0))
                {
                    aux=lista[i];
                    lista[i]=lista[j];
                    lista[j]=aux;
                }
            }

        }
        todoOk=0;
    }
    if(order==0)
    {
        for(int i=0; i<len; i++)
        {
            for(int j = i + 1; j < len; j++)
            {
                if(lista[i].sector> lista[j].sector||(lista[i].sector == lista[j].sector &&strcasecmp(lista[i].lastName, lista[j].lastName)<0))
                {
                    aux=lista[i];
                    lista[i]=lista[j];
                    lista[j]=aux;
                }
            }

        }
        todoOk=0;
    }
    return todoOk;
}

/** \brief print one employee
 *
 * \param oneEmployee Employee
 * \param len int
 * \return int
 *
 */
int printEmployee(Employee oneEmployee, int len)
{

    printf("%d  %s  %s  %f  %d\n", oneEmployee.id, oneEmployee.lastName, oneEmployee.name, oneEmployee.salary, oneEmployee.sector);
    return 0;
}

/** \brief print the content of employees array
 *
 * \param lista[] Employee
 * \param length int
 * \return int
 *
 */
int printEmployees(Employee lista[], int length)
{
    printf("***List of employees***\n");
    printf("ID  Last name  Name  Salary  Sector\n\n");

    for(int i=0; i<length; i++)
    {
        if(!lista[i].isEmpty)
        {
            printEmployee(lista[i], length);
        }
    }

    return 0;
}

/** \brief modifies an employee after find its ID
 *
 * \param lista[] Employee
 * \param len int
 * \param idEmployee int
 * \return int
 *
 */
int modifyEmployee(Employee lista[], int len, int idEmployee)
{
    int indice;
    char confirma;
    int opcion;
    Employee aux;
    if(lista!=NULL&& len>0)
    {
        printEmployees(lista,len);
        printf("Ingrese el ID del empleado que quiere modificar: ");
        scanf("%d", &idEmployee);

        indice=findEmployeeById(lista, len,idEmployee);

        if(indice==-1)
        {
            printf("El empleado no existe\n");
        }
        else
        {

            system("pause");
            printf("Ingrese 1 si quiere modificar el nombre\n");
            printf("Ingrese 2 si quiere modificar el apellido\n");
            printf("Ingrese 3 si quiere modificar el salario\n");
            printf("Ingrese 4 si quiere modificar el sector\n");
            scanf("%d", &opcion);

            switch(opcion)
            {
            case 1:
                printf("Ingrese el nombre del empleado: ");
                fflush(stdin);
                gets(aux.name);
                printf("Confirma el cambio? Presione s: ");
                fflush(stdin);
                scanf("%c", &confirma);
                if(confirma=='s')
                {
                    strcpy(lista[indice].name, aux.name);
                }
                else
                {
                    printf("Cambio cancelado");
                }
                break;
            case 2:
                printf("Ingrese el apellido del empleado: ");
                fflush(stdin);
                gets(aux.lastName);
                printf("Confirma el cambio? Presione s");
                fflush(stdin);
                scanf("%c", &confirma);
                if(confirma=='s')
                {
                    strcpy(lista[indice].lastName, aux.lastName);
                }
                else
                {
                    printf("Cambio cancelado");
                }
                break;
            case 3:
                printf("Ingrese el salario del empleado: ");
                scanf("%f", &aux.salary);
                printf("Confirma el cambio? Presione s");
                fflush(stdin);
                scanf("%c", &confirma);
                if(confirma=='s')
                {
                    lista[indice].salary=aux.salary;
                }
                else
                {
                    printf("Cambio cancelado");
                }
                break;
            case 4:
                printf("Ingrese el sector del empleado: ");
                scanf("%d", &aux.sector);
                printf("Confirma el cambio? Presione s");
                fflush(stdin);
                scanf("%c", &confirma);
                if(confirma=='s')
                {
                    lista[indice].sector=aux.sector;
                }
                else
                {
                    printf("Cambio cancelado");
                }
                break;

            }



        }
    }
    return 0;
}

/** \brief add all the salaries and take the average of them
 *
 * \param lista[] Employee
 * \param len int
 * \return int
 *
 */
int infoSalary(Employee lista[], int len)
{
    float allSalaries=0;
    int contadorEmpleados=0;
    float promSalaries;
    int empleadosMasPromedio=0;
    for(int i=0;i<len;i++)
    {
        if(lista[i].isEmpty==0)
        {
            allSalaries+=lista[i].salary;
            (contadorEmpleados)++;
            promSalaries=allSalaries/contadorEmpleados;
        }
    }

     for(int j=0;j<len;j++)
        {
            if(lista[j].salary>promSalaries)
            {
                empleadosMasPromedio = empleadosMasPromedio + 1;
            }
        }

    printf("Total sueldos: %2.f\n", allSalaries);
    printf("Promedio de los sueldos: %2.f\n", promSalaries);
    printf("La cantidad de empleados que superan el promedio es: %d\n", empleadosMasPromedio);
    return 0;
}


