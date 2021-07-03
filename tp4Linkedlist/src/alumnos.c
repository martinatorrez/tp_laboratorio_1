#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alumnos.h"
void mostrarAlumno(eAlumnos* a)
{

    if(a!=NULL)
    {
        printf("%d  %10s  %c\n", a->legajo, a->nombre, a->sexo);

    }


}
void mostrarAlumnos(LinkedList* list)
{
    eAlumnos* aux=NULL;
    int flag=0;
    int tam=ll_len(list);

    if(list!=NULL)
    {
        printf("Legajo Nombre  Sexo\n");
        for(int i=0; i<tam; i++)
        {
            aux = (eAlumnos*) ll_get(list,i);
            mostrarAlumno(aux);
        }
        flag=1;

    }
    printf("\n\n");
    if(flag==0)
    {
        printf("No hay alumnos para mostrar\n");
    }

}

int ordenarAlumnos(void* alumno1, void* alumno2)
{
    eAlumnos* alumn1;
    eAlumnos* alumn2;
    int retorno=-2;


    alumn1 = (eAlumnos*)alumno1;
    alumn2 = (eAlumnos*)alumno2;


    if(alumno1 != NULL && alumno2 != NULL)
    {

        retorno = strcmp(alumn1->nombre, alumn2->nombre);

    }

    return retorno;
}
