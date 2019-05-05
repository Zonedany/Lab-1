#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANOMAX 10;

typedef struct ListaNumeros{
  int cantidad;  //Cantidad actual de elementos que posee el arreglo, si cantidad == tamano ->lista esta llena
  int tamano;    //Cantidad total de elementos que posee el arreglo, tamano max
  int *arreglo;	 //Inicio arreglo pos 0
}lista;

lista *CreaListaNumerosVacia(){ //Inicializando las variables
    lista *aux;					//Variable tmporal o aux

    aux = (lista*)malloc(sizeof(lista));		//Linux	== lista *aux = (lista *)malloc(sizeof(lista));

    aux->tamano = TAMANOMAX;
    //Espacio de memoria por el tamano del arreglo
    aux->arreglo =(int*)malloc(sizeof(int)*aux->tamano);
    return (aux);				//Retorna lista auxiliar con las variables actualizadas
}

lista *CreaListaNumerosLlena(lista *Lista){
    srand(time(NULL));
    lista *aux;
    aux = Lista;
    int i;

    for (i = 0; i < aux->tamano; i++) {
        aux->arreglo[i] = rand()%10;
        aux->cantidad++;
    }

    return (aux);
}

int EliminaListaNumeros(lista *Lista){
    lista *aux;
    aux = Lista;

    aux->cantidad = 0;
    aux->tamano = 0;
    aux->arreglo = NULL;

    printf("\n\n Lista Eliminada");
}

int BuscaNumerosEnListaNumeros(lista *Lista,int numero){
    lista *aux;
    aux = Lista;
    int i;

    for(i = 0; i < aux->tamano; i++){
      if(aux->arreglo[i] == numero){
        return i;
      }
    }

    return -1;
}

void ImprimirListaNumeros(lista *Lista){
    lista *aux;
    aux = Lista;
    int i;

    if(aux->tamano != 0){
      for (i = 0; i < aux->tamano; i++) {
       // printf("\n %i",aux->arreglo[i]);
      }
    }
}
