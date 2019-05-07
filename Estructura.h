#include <stdlib.h>
#include <time.h>

typedef struct ListaNumeros{
	int cantidad;
	int tamano;
	int *arreglo;
}lista;

/* Inicializa las variables, entrega memoria al arreglo */
lista *CreaListaNumerosVacia(int MAXT){
    lista *aux;

    aux = (lista*)malloc(sizeof(lista));
    aux->tamano = MAXT;
    aux->arreglo = (int*)malloc(sizeof(int)*aux->tamano);
    return (aux);
}

/* Rellena el arreglo con 1000 num random */
lista *CreaListaNumerosLlena(lista *Lista){
    srand(time(NULL));
    lista *aux;
    aux = Lista;
    int i;

    for (i=0; i<aux->tamano; i++) {
        aux->arreglo[i] = rand()%10000;
        aux->cantidad++;
    }

    return (aux);
}

int BusquedaSecuencial(lista *Lista,int numero){
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

lista *CreaListaNumerosyOrden(lista *Lista){
  srand(time(NULL));
  lista *aux;
  aux = Lista;
  int i,j,k,tmp;

    for (i = 0; i < aux->tamano; i++){
        aux->arreglo[i] = rand()%10000 + rand()%100000;
        aux->cantidad++;
    }

    for (j = 0; j < aux->tamano; j++){
      for(k = 0; k < aux->tamano; k++){
        if(aux->arreglo[j] < aux->arreglo[k]){
          tmp = aux->arreglo[j];
          aux->arreglo[j] = aux->arreglo[k];
          aux->arreglo[k] = tmp;
        }
      }
    }

  return (aux);
}

int BusquedaBinaria(lista *Lista, int numero){
	lista *aux;
	aux = Lista;
	int inf,sup,mitad;

	inf = 0;
	sup = aux->tamano - 1;
	mitad = (sup + 1)/2;

	while(aux->arreglo[mitad] != numero && inf<sup){
		if(aux->arreglo[mitad] > numero){
			sup = mitad -1;
		}else{
			inf = mitad + 1;
		}
		mitad = (inf+sup)/2;
	}

	if(aux->arreglo[mitad] == numero){
		return 1;
	}
	return 0;
}

int CompararParaQuicksort(const void *p, const void *q){
	int x, y;
	x = *(int *) p;
	y = *(int *) q;
	if(x < y){
		return -1;
	}
	if(x == y ){
		return 0;
	}
	return 1;
}

lista *CreaListaNumerosQuicksort(lista *Lista){
    lista *aux;
    aux = Lista;
    int i,tmp;
    
    for (i = 0; i < aux->tamano; i++){
        aux->arreglo[i] = rand()%10000 + rand()%100000;
        tmp = i + 1;
        qsort(aux->arreglo,tmp,sizeof(int),&CompararParaQuicksort);
    }

    aux->cantidad = aux->tamano;

}

/* Eliminar lista */
lista *EliminarListaNumeros(lista *Lista){
    lista *aux;
    aux = Lista;

    free(aux->arreglo);
    free(aux);
    aux->cantidad = 0;

}

void ImprimirListaNumeros(lista *Lista){
    lista *aux;
    aux = Lista;
    int i;

    if(aux->tamano != 0){
      for (i = 0; i < aux->tamano; i++) {
        printf("%i\n",aux->arreglo[i]);
      }
    }
}
