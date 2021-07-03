/*
 * alumnos.h
 *
 *  Created on: 3 jul. 2021
 *
 */

#ifndef ALUMNOS_H_
#define ALUMNOS_H_
#include "LinkedList.h"
typedef struct
{

    int legajo;
    char nombre[20];
    char sexo;

} eAlumnos;

#endif /* ALUMNOS_H_ */
void mostrarAlumno(eAlumnos* a);
void mostrarAlumnos(LinkedList* list);
int ordenarAlumnos(void* alumno1, void* alumno2);
