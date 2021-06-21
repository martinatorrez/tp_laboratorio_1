#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"



Employee* employee_new()
{
    Employee* newEmployee = (Employee*) malloc(sizeof(Employee));
    if(newEmployee!=NULL)
    {
        newEmployee->id=0;
        strcpy(newEmployee->nombre, "");
        newEmployee->horasTrabajadas=0;
        newEmployee->sueldo=0;
    }
    return newEmployee;

}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* strSueldo)
{
    Employee* newEmployee = employee_new();
    if(newEmployee!=NULL)
    {
        if(!(employee_setId(newEmployee,atoi(idStr)) &&
                employee_setNombre(newEmployee,nombreStr) &&
                employee_setHorasTrabajadas(newEmployee,atoi(horasTrabajadasStr))&&
                employee_setSueldo(newEmployee,atof(strSueldo))))
        {
            employee_delete(newEmployee);
            newEmployee=NULL;
        }
    }
    return newEmployee;
}

void employee_delete(Employee* p)
{
    free(p);
}

int employee_setId(Employee* this,int id)
{
    int todoOk=0;
    if(this!=NULL&&id>0)
    {
        this->id=id;
        todoOk=1;

    }
    return todoOk;
}
int employee_getId(Employee* this,int* id)
{
    int todoOk=0;
    if(this!=NULL && id!=NULL)
    {
        *id=this->id;
        todoOk=1;
    }
    return todoOk;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int todoOk=0;
    if(this!=NULL&& nombre!=NULL &&strlen(nombre)<20)
    {
        strcpy(this->nombre,nombre);
        todoOk=1;
    }
    return todoOk;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int todoOk=0;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre, this->nombre);
        todoOk=1;
    }
    return todoOk;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk=0;
    if(this!=NULL&& horasTrabajadas>0)
    {
        this->horasTrabajadas=horasTrabajadas;
        todoOk=1;
    }
    return todoOk;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOk=0;
    if(this!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        todoOk=1;
    }
    return todoOk;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOk=0;
    if(this!=NULL&& sueldo>0)
    {
        this->sueldo=sueldo;
        todoOk=1;
    }
    return todoOk;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOk=0;
    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo=this->sueldo;
        todoOk=1;
    }
    return todoOk;
}

int menu()
{
    int option;
    system("cls");
    printf("  ***Menu***   \n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario)\n");
    printf("3. Alta empleado\n");
    printf("4. Modificar datos de empleados\n");
    printf("5. Baja empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
    printf("9.Guardar los datos de los empleados en el archivo data.bin (modo binario)\n");
    printf("10. Salir\n");

    printf("\nIngrese opcion: ");
    fflush(stdin);
    scanf("%d", &option);
    return option;
}

int sortEmployeesByName(void* empleado1, void* empleado2)
{
    Employee* emp1;
    Employee* emp2;
    int retorno=-2;


    emp1 = (Employee*)empleado1;
    emp2 = (Employee*)empleado2;


    if(empleado1 != NULL && empleado2 != NULL)
    {

        retorno = strcmp(emp1->nombre, emp2->nombre);

    }

    return retorno;
}

int listEmployee(Employee* p)
{
    int todoOk=0;
    int idEmployee;
    char nombre[20];
    int horasTrabajadas;
    int sueldo;

    if(p!=NULL&& employee_getId(p, &idEmployee) && employee_getNombre(p, nombre) && employee_getHorasTrabajadas(p, &horasTrabajadas) && employee_getSueldo(p, &sueldo))
    {
        printf("%d  %s  %d   %d\n", idEmployee,nombre,horasTrabajadas,sueldo);
        todoOk=1;
    }
    return todoOk;
}

int buscarMayorId(LinkedList* pArrayListEmployee, int* id)
{
    Employee* aux=NULL;
    int todoOk=0;
    int mayor;

    if(pArrayListEmployee!=NULL)
    {

        for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {

            aux = (Employee*) ll_get(pArrayListEmployee,i);
            if(i==0 || aux->id > mayor)
            {
                mayor=aux->id;
            }
        }
        *id=mayor+1;
        todoOk=1;

    }
    return todoOk;

}



