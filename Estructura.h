#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct ListaNumeros{
  int cantidad;
  int tamano;  
  int *arreglo;
}lista;

lista *CreaListaNumerosVacia(int TAMANOMAX){
    lista *aux;

    aux = (lista*)malloc(sizeof(lista));
    aux->tamano = TAMANOMAX;
    aux->arreglo = (int*)malloc(sizeof(int)*aux->tamano);
    return (aux);
}

lista *CreaListaNumerosLlena(lista *Lista){
    srand(time(NULL));
    lista *aux;
    aux = Lista;
    int i;

    for (i=0; i < aux->tamano; i++) {
        aux->arreglo[i] = rand()%10000;
        aux->cantidad++;
    }

    return (aux);
}

lista *CreaListaNumerosyOrden(lista *Lista){
	srand(time(NULL));
	lista *aux;
	aux = Lista;
	int i,j,tmp;

    for (i = 0; i < aux->tamano; i++){
        aux->arreglo[i] = rand()%10000 + rand()%100000;
        aux->cantidad++;
    }

    for (i = 0; i < aux->tamano; i++){
      for(j = 0; j < aux->tamano; j++){
        if(aux->arreglo[i] < aux->arreglo[j]){
          tmp = aux->arreglo[i];
          aux->arreglo[i] = aux->arreglo[j];
          aux->arreglo[j] = tmp;
        }
      }
    }

  return (aux);
}
