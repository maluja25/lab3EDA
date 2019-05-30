#include <stdlib.h>
#include <stdio.h>
#define Nodo struct Nodo
#define Arista struct Arista
#define Lista struct Lista
Nodo
{
    int dato;
    Nodo *siguiente;
    Arista *adyacencia;    
};
Arista
{
    Nodo *vrt;
    Arista *siguiente;
};
Lista{
    //declaramos el tamano del arreglo 
  int tamano;
  //nodo inicio y nodo fin
  Nodo *inicio;
  Nodo *fin; //por comodidad por si piden el el ultimo dato
};

Nodo*inicio=NULL;
Lista*ini=NULL;
Lista*final=NULL;
void inicializar(Lista *lista){
  // a la lista que ingresa le apuntaremos a inicio y fin un NULL y al tamano = 0;
  lista->inicio = NULL;
  lista->fin = NULL;
  lista->tamano= 0;
}
void insertarNodo(Lista *lista,int N){
    Nodo *aux;
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->dato = N;
    nuevo->siguiente = NULL;
    nuevo->adyacencia = NULL;
    if(lista->tamano == 0){
    lista->inicio = nuevo;
    lista->fin = nuevo;
    lista->tamano++;
    }
    else{
    lista->tamano++;
    lista->fin->siguiente = nuevo;
    lista->fin = nuevo;
  }
}
void agregarArista(Nodo *aux1 , Nodo *aux2 , Arista *nuevo){
    Arista *a;
    if(aux1->adyacencia == NULL){
        aux1->adyacencia = nuevo;
        nuevo->vrt = aux2;
    }else{
        a = aux1->adyacencia;
        while(a->siguiente != NULL){
            a = a->siguiente;
        }
        nuevo->vrt = aux2;
        a->siguiente = nuevo; 
    }
}
void insertarArista(Lista *lista,int ini,int fin){
    Arista *nuevo = (Arista *)malloc(sizeof(Arista));
    nuevo->siguiente = NULL;
    Nodo *aux1,*aux2;
    aux1 = lista->inicio;
    aux2 = lista->inicio;
    while(aux2 != NULL){
        printf("dato %i\n",aux2->dato);
        if(aux2->dato == fin ){
            break;
        }
        aux2 = aux2->siguiente;
    }
    while(aux1 != NULL){
        if(aux1->dato ==ini){
            agregarArista(aux1,aux2,nuevo);
        }
        aux1 = aux1->siguiente;
    }
}
void visualizarGrafo(Lista *lista){
    Nodo *aux=lista->inicio;
    Arista  *ar;
    printf("Nodos\n");
    while(aux!=NULL){   
        printf("%i:    ",aux->dato);
        if(aux->adyacencia!=NULL){
            ar=aux->adyacencia;
            while(ar!=NULL){ 
                printf(" %i",ar->vrt->dato);
                ar=ar->siguiente;
            }
        }
        printf("\n");
        aux=aux->siguiente;
    }
    printf("\n");
}
int main() {
  Lista *lista = (Lista *)malloc(sizeof(Lista));
  inicializar(lista);
  int opcion,N,i;
    printf("Ingrese número de vertices:");
    //scanf("%i",&N);
    N = 3;
    for(i=0;i<N;i++){
        insertarNodo(lista,i);
    }
    insertarArista(lista,0,1);
    insertarArista(lista,0,2);
    insertarArista(lista,1,0);
    insertarArista(lista,1,2);
    insertarArista(lista,2,0);
    insertarArista(lista,2,1);
    visualizarGrafo(lista);
    return 0;
}