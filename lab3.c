#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <math.h>

#define MAX_LIN 1000
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
	int peso;
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
void insertarArista(Lista *lista,int ini,int fin,int peso){
    Arista *nuevo = (Arista *)malloc(sizeof(Arista));
    nuevo->siguiente = NULL;
    nuevo->peso = peso;
    Nodo *aux1,*aux2;
    aux1 = lista->inicio;
    aux2 = lista->inicio;
    while(aux2 != NULL){
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
                //printf(" %i",ar->peso);
                ar=ar->siguiente;
            }
        }
        printf("\n");
        aux=aux->siguiente;
    }
    printf("\n");
}
int buscarNumero(int numero,int arreglo[],int tam){
	int i,stop = 0;
	for (int i = 0;(i < tam && stop == 0); ++i)
	{
		if(arreglo[i] == numero){
			stop = 1;
		}
	}
	return stop;
}
/*
void regular(Lista *lista ,int vertices){
	for (int i = 0; i < vertices ; ++i)
	{
		for (int j = 0; j < vertices; ++j)
		{
			if(j == i){
				j++;
			}
			insertarArista(lista,N,NumerosAzar[j]);
		}
	}
}
*/
/*
void GRADOMAX(int gradoMax,Lista *lista,int vertices){
	srand (time(NULL));
	int Azar;
	int NumerosAzar[gradoMax+1];
	int j = 0,fstop;
	for(j = 0;j < gradoMax + 1;j++){
		do{
			Azar = rand()%(vertices);
			fstop = buscarNumero(Azar,NumerosAzar,gradoMax);
		}while(fstop);
		NumerosAzar[j] = Azar;
		//printf("el numero es :%i\n",NumerosAzar[j]);
	}
	int i=1;
	while(i < gradoMax + 1){
		insertarArista(lista,NumerosAzar[0],NumerosAzar[i]);
		insertarArista(lista,NumerosAzar[i],NumerosAzar[0]);
		i++;
	}
}
*/
void Vertice(int vertices,Lista *lista){
	int i;
	for(i=1;i<vertices+1;i++){
        insertarNodo(lista,i);
    }
}
/*
int CrearGrafo(char argv[],int argc){
	return 0;
}
*/
int n,m;
int ciclo = 0;
int gradoGrafo = 0;
int contarAristas(Lista *lista){
  int **matriz = (int **)malloc(sizeof(int *)*lista->tamano+1);
  for (int i = 0; i < lista->tamano+1; ++i)
  {
    matriz[i] = (int *)malloc(sizeof(int ));
  }
  Nodo *aux=lista->inicio;
  Arista  *ar;
  int contador = 0;
  while(aux!=NULL){   
        if(aux->adyacencia!=NULL){
          ar=aux->adyacencia;
          while(ar!=NULL){ 
              if(matriz[aux->dato][ar->vrt->dato] == 0 || matriz[ar->vrt->dato][aux->dato] == 0){
                matriz[aux->dato][ar->vrt->dato] = 1;
                matriz[ar->vrt->dato][aux->dato] = 1;
                if(aux->dato != ar->vrt->dato)
                  contador++;
                else{
                  ciclo = 1;
                }
              }
              ar=ar->siguiente;
          }
      }
      aux=aux->siguiente;
  }
  int count1=0,count2=0;
  int i=2 ,j = 1;
  while(j <=lista->tamano){
      if(matriz[1][j] == 1){
        count1++;
      }
      j++;
  }
  //printf("count1 %i \n\n",count1);
  while(i < lista->tamano){
    j = 1;
    count2 = 0;
    while(j <=lista->tamano){
      if(matriz[i][j] == 1){
        count2++;
      }
      j++;
    }
    i++;
    //printf("count2 %i\n",count2);
  }
  return contador;
}
int Gmax = 0;
int Gmin = 1;
void ObtenerGradoMaxYMin(Lista *lista){
  int GradosNodos[lista->tamano+1];
  Nodo *aux=lista->inicio;
  Arista  *ar;
  while(aux!=NULL){   
        GradosNodos[aux->dato] = 0;
        if(aux->adyacencia!=NULL){
            ar=aux->adyacencia;
            while(ar!=NULL){ 
                GradosNodos[aux->dato]++;
                ar=ar->siguiente;
            }
        }
        aux=aux->siguiente;
  }
  int i = 1;
  while(i < lista->tamano+1){
    if(GradosNodos[i] > Gmax){
      Gmax = GradosNodos[i];
    }
    if(GradosNodos[i] <= Gmin){
      Gmin = GradosNodos[i];
    }
    i++;
  }
  printf("el grado maximo es : %i\n",Gmax);
  printf("el grado minimo es : %i\n",Gmin);

}
void Pesos(char const *argv[]){
  FILE * fp;
  int nMax = 0;
  fp=fopen(argv[2],"r");
  char linea[MAX_LIN], *p;
   // val es la variable que almacenara cada dato de la linea en dato entero para posteriormente guardarla en la matriz
   int val;
   // aqui reservamos memoria para la matriz con la funcion calloc
   int **matriz= (int **) calloc(1000, sizeof(int*)) ;
   //inicializamos m con valor -1
   int pesos[100];
   char aux;
   int i = 0;
   int x;
   while(aux != EOF){
    char *numero;
    aux = fgetc(fp);
    if(aux == ' '){
      aux = fgetc(fp);
      numero = &aux;
      printf("numero %i",atoi(numero));
      x = atoi(numero);
    }
    if(aux == '\n'){
      printf("\n");
    }
    if(aux == ','){
      aux = fgetc(fp);
      numero = &aux;
      //printf("numero %i\n",atoi(numero));
      x = atoi(numero);
      pesos[i] = x;
      i++;
    }
   }
}
void ObtenerDatosGrafo(Lista *lista){
  int cantidadVertices,cantidadAristas;
  cantidadVertices = lista->tamano;
  printf("la cantidadVertices %i\n",cantidadVertices);
  cantidadAristas=contarAristas(lista);
  printf("la cantidadAristas %i\n",cantidadAristas);
  printf("ciclo %i\n",ciclo);
  printf("gradoGrafo %i\n",gradoGrafo);
  ObtenerGradoMaxYMin(lista);
  //SumaPesosGrafo(lista);
}
void AnalizarGrafo(char const *argv[]){
	FILE * fp;
  int nMax = 0;
	fp=fopen(argv[2],"r");
	char linea[MAX_LIN], *p;
   // val es la variable que almacenara cada dato de la linea en dato entero para posteriormente guardarla en la matriz
   int val;
   // aqui reservamos memoria para la matriz con la funcion calloc
   int **matriz= (int **) calloc(1000, sizeof(int*)) ;
   Lista *lista = (Lista *)malloc(sizeof(Lista));
   //inicializamos m con valor -1
   m=-1;
   while (fgets(linea, MAX_LIN, fp)!=NULL){
     m=m+1;
     //aqui reservamos memoria para cada uno de los espacios de la matriz
     //printf("La linea es : %s\n", linea);
     matriz[m] = (int *) calloc(MAX_LIN, sizeof(int));
     p = strtok(linea," ");
     n=-1;
     while(p != NULL) {
       n=n+1;
       //con sscanf le damos le asignamos a val el valor que contiene p para posteriormente asigarle val a matriz en la posicion m,n
       sscanf(p,"%i",&val);
       //printf("%d\n",val);
       if(n > nMax){
        nMax = n;
       }
       matriz[m][n] = val;
       p=strtok(NULL," ");
       if(n == 0){
       	insertarNodo(lista,matriz[m][n]);
       } 
     }
   }
    Pesos(argv);
   	int i = 1;
   	while(i <=5){
   		int j = 1;
   		while(j <= nMax){
   			//printf("%i ",matriz[i-1][j]);
   			if(matriz[i-1][j] > 0){
   				insertarArista(lista,matriz[i-1][0],matriz[i-1][j],0);
   			}
   			j++;
   		}
   		printf("\n");
   		i++;
   	}
    ObtenerDatosGrafo(lista);
    //visualizarGrafo(lista);
    fclose(fp);
}
void Inicio(int funcionalidad,char const *argv[],int argc){
	switch(funcionalidad){
		case 1:
			//CrearGrafo(argv);
			return ;
		break;
		case 2:
			AnalizarGrafo(argv);
		break;
    default:
      printf("ERROR \n");
      printf("El numero que va a continuacion del nombre del programa tiene que ser un 1(CrearGrafo) o 2(AnalizarGrafo) \n");
      printf("por favor cambiarlo\n");
    break;
	}
}
int main(int argc, char const *argv[])
{
	int funcionalidad,vertices,aristas,ciclos,Kregular,gradoMax,gradoMin,sumaPesos;
	funcionalidad = atoi(argv[1]);
	//printf("funcionalidad %i\n",funcionalidad);
	Inicio(funcionalidad,argv,argc);
	
	//CrearGrafo(vertices,aristas,ciclos,Kregular,gradoMax,gradoMin,sumaPesos);
	printf("\n");
	return 0;
}