#include <stdlib.h>
#include <stdio.h>
#define Nodo struct Nodo
#define Arista struct Arista
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

Nodo *inicio=NULL;
void insertarNodo(){
	Nodo *aux;
	Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
	printf("ingrese un vertice\n");
	int numero;
	scanf("%i",&nuevo->dato);
	nuevo->siguiente = NULL;
	nuevo->adyacencia = NULL;
	if(inicio ==NULL){
		aux = nuevo;
	}else{
		aux = inicio;
		while(aux->siguiente != NULL){
			aux = aux->siguiente;
		}
		aux->siguiente = nuevo;
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
void insertarArista(){
	int ini,fin;
	Arista *nuevo = (Arista *)malloc(sizeof(Arista));
	Nodo *aux1,*aux2;
	if(inicio == NULL){
		printf("ERROR..\n");
	}
	printf("agregue el nodo inicio y nodo fin \n");
	//scanf("%i %i ",&ini,&fin);
	ini = 1;
	fin = 2;
	aux1 = inicio;
	aux2 = inicio;
	while(aux2 != NULL){
		if(aux2->dato == fin ){
			break;
		}
		aux2 = aux2->siguiente;
	}
	if(aux2 == NULL){
		printf("ERROR....\n");
	}
	while(aux1 ==NULL){
		if(aux1->dato ==ini){
			agregarArista(aux1,aux2,nuevo);
		}
		aux1 = aux1->siguiente;
	}
	if(aux1 == NULL){
		printf("ERROR....\n");
	}
}
void visualizarGrafo(){
    Nodo *aux=inicio;
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
int main(int argc, char const *argv[])
{
	int opcion,N,i;
	printf("Ingrese número de vertices:");
    scanf("%i",&N);
    for(i=0;i<N;i++){
    	insertarNodo();
	}
	int x = 1;
	while(x == 1){
		printf("-----------\n");
        printf(" 1. Insertar Vertice                 \n");
        printf(" 2. Insertar Arista                  \n");
        printf(" 3. Mostrar Listas                   \n");
        printf("------------\n");
        printf("Escoge opcion:");
        scanf("%i",&opcion);
        printf("la opcion es :%i\n",opcion);
        if(opcion == 1){
        	insertarNodo();
        }
        if(opcion == 2){
        	insertarArista();
        }
        if(opcion == 3){
        	visualizarGrafo();
        	x = 2;
        }
	}
    return 0;
}
