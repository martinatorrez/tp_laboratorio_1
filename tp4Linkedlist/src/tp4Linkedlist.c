/*
 ============================================================================
 Name        : tp4Linkedlist.c
 Author      : Torrez Martina
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "alumnos.h"


int main(void) {
	setbuf(stdout, NULL);
	LinkedList* lista=ll_newLinkedList();

	    eAlumnos alumno1= {546, "Julio", 'm'};
	    eAlumnos alumno2= {547, "Maria", 'f'};
	    eAlumnos alumno3= {548, "Monica", 'f'};
	    eAlumnos alumno4= {549, "Luis", 'm'};
	    eAlumnos alumno5={550, "Laura", 'f'};
	    eAlumnos alumno6={551, "Jorge", 'm'};
	    eAlumnos alumno7={552, "Romina",'f'};
	    eAlumnos alumno8={553, "Carolina",'f'};
	    eAlumnos* alumnoEliminado;
	    int tamLista;

	    ll_add(lista, &alumno1);
	    ll_add(lista, &alumno2);
	    ll_add(lista, &alumno3);
	    ll_add(lista, &alumno4);
	    ll_add(lista, &alumno5);
	    ll_add(lista, &alumno8);

	    tamLista=ll_len(lista);
	    if(ll_isEmpty(lista))
	    {
	        printf("La lista esta vacia");
	    }
	    else
	    {
	        printf("Alumnos en la lista: %d\n", tamLista);
	        mostrarAlumnos(lista);

	        printf("Ordeno a los alumnos alfabeticamente:\n");
	        ll_sort(lista, ordenarAlumnos,1);
	        mostrarAlumnos(lista);

	        printf("Se encuentra el alumno 4 en la lista?\n");
	        if(ll_contains(lista, &alumno4))
	        {
	            printf("Si\n");
	           printf("\n");
	        }
	        else
	        {
	            printf("No\n");
	            printf("\n");
	        }

	        printf("Copio la lista de los alumnos en una nueva:\n");
	        LinkedList* listaCopiada = ll_clone(lista);
	        if(ll_containsAll(listaCopiada,lista))
	        {
	          printf("Lista copiada con exito. Muestro los alumnos:\n");
	          mostrarAlumnos(listaCopiada);
	          printf("\n\n");
	        }
	        else
	        {
	            printf("La lista no se copio correctamente\n");
	            printf("\n");
	        }

	        printf("Elimino a un alumno de la primera lista: \n");
	        ll_remove(lista,1);
	        mostrarAlumnos(lista);

	        printf("Elimino a otro alumno y muestro a quien elimine:\n");
	        alumnoEliminado=ll_pop(lista, 0);
	        mostrarAlumno(alumnoEliminado);
	        printf("\n");

	        printf("Agrego a un alumno entre los indices 3 y 4 en la primer lista:\n");
	        ll_push(lista,3,&alumno6);
	        mostrarAlumnos(lista);

	        printf("Piso los datos de un alumno con otros datos: \n");
	        ll_set(lista,2, &alumno7);
	        mostrarAlumnos(lista);

	        printf("Elimino a todos los alumnos en la lista copiada:\n");
	        ll_clear(listaCopiada);
	        mostrarAlumnos(listaCopiada);

	        printf("Elimino la lista copiada\n");
	        if(!ll_deleteLinkedList(listaCopiada))
	        {
	            printf("Lista eliminada\n");
	        }
	        else
	        {
	          printf("No se pudo eliminar la lista\n");
	        }


	    }



	    return 0;
}
