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
                printf("(%i)",ar->peso);
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

void GRADOMAX(int gradoMax,Lista *lista,int vertices){
	printf("vertices %i\n",vertices);
	srand (time(NULL));
	int Azar;
	int NumerosAzar[gradoMax+2];
	int j = 0,fstop;
	for(j = 0;j < gradoMax + 1;j++){
		do{
			Azar = rand()%(vertices)+1;
			//printf("Azar %i\n",Azar);
			fstop = buscarNumero(Azar,NumerosAzar,gradoMax);
		}while(fstop);
		NumerosAzar[j] = Azar;
		printf("el numero es :%i\n",NumerosAzar[j]);
	}
	printf("hola\n");
	int i=1;
	while(i < gradoMax + 1){
		insertarArista(lista,NumerosAzar[0],NumerosAzar[i],0);
		insertarArista(lista,NumerosAzar[i],NumerosAzar[0],0);
		i++;
	}
}
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
int totalpesos = 0;
int contarAristas(Lista *lista){
  int **matriz = (int **)malloc(sizeof(int *)*lista->tamano+1);
  for (int i = 0; i < lista->tamano+1; ++i)
  {
    matriz[i] = (int *)malloc(sizeof(int ));
  }
  int i=2 ,j = 1;
  for (int i = 1; i < lista->tamano+1; ++i)
  {
  	j = 0;
  	for (int j = 1; j < lista->tamano+1; ++j)
  	{
  		matriz[i][j] = 0;
  	}
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
                totalpesos = totalpesos + ar->peso;
                printf("totalpesos %i\n",totalpesos);
                if(aux->dato != ar->vrt->dato){
                  contador++;
                  printf("contador %i\n",contador);
                }
                else{
                  ciclo = 1;
                }
              }
              ar=ar->siguiente;
          }
      }
      aux=aux->siguiente;
  }
  for (int i = 1; i < lista->tamano+1; ++i)
  {
  	j = 0;
  	for (int j = 1; j < lista->tamano+1; ++j)
  	{
  		
  		printf(" %i",matriz[i][j]);
  	}
  	printf("\n");
  }
  int count1=0,count2=0;
  i=2 ,j = 1;
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
void ArchivoSalida2(int vertices,int aritas,int ciclo,int gradoGrafo,int gradoMax,int gradoMin,int sumaPesos){
	FILE *archivo;
	archivo = fopen("parametros.out","w");
	fprintf(archivo,"%i",vertices);
	fprintf(archivo,"\n");
	fprintf(archivo,"%i",aritas);
	fprintf(archivo,"\n");
	fprintf(archivo,"%i",ciclo);
	fprintf(archivo,"\n");
	fprintf(archivo,"%i",gradoGrafo);
	fprintf(archivo,"\n");
	fprintf(archivo,"%i",gradoMax);
	fprintf(archivo,"\n");
	fprintf(archivo,"%i",gradoMin);
	fprintf(archivo,"\n");
	fprintf(archivo,"%i",sumaPesos);
	fprintf(archivo,"\n");
}
void ObtenerDatosGrafo(Lista *lista){
  int cantidadVertices,cantidadAristas;
  cantidadVertices = lista->tamano;
  cantidadAristas=contarAristas(lista);
  ObtenerGradoMaxYMin(lista);
  ArchivoSalida2(cantidadVertices,cantidadAristas,ciclo,gradoGrafo,Gmax,Gmin,totalpesos);
}
void AnalizarGrafo(char const *argv[]){
	Lista *lista = (Lista *)malloc(sizeof(Lista));
	inicializar(lista);
  FILE * fp;
  int nMax = 0;
  fp=fopen(argv[2],"r");
   int pesos[100];
   char aux1,aux2;
   int i = 0;
   int x;
   while(aux1 != EOF ){
   		char *numero;
   		aux1 = fgetc(fp);
   		numero = &aux1;
      	//printf("numero %i",atoi(numero));
      	x = atoi(numero);
   		if(aux1== ' '){
   			while(aux1 != '\n' && aux1 != EOF){
   				aux1 = fgetc(fp);
   			}
   		}
   		if(x == 0){
   			printf(" ");
   		}
   		else{
   			//printf("%i \n",x);
   			insertarNodo(lista,x);
   		}
   }
   fclose(fp);
   fp=fopen(argv[2],"r");
   printf("\n\n\n");
   int x1 = 1,x2 = 0,x3;
   while(aux2 != EOF){
    char *numero;
    aux2 = fgetc(fp);
    if(aux2 == ','){
      aux2 = fgetc(fp);
      numero = &aux2;
      x3 = atoi(numero);
      //printf("peso %i",x3);
      insertarArista(lista,x1,x2,x3);
    }
    else if(aux2 == ' '){
      //printf("-");
      aux2 = fgetc(fp);
      numero = &aux2;
      x2 = atoi(numero);
      //printf("peso %i-",x3);
      //printf("numero %i",x2);
      
    }
    if(aux2 == '\n'){
      x1++;
      //printf("\n");
    }
   }
   printf("\n\n\n\n\n\n\n");
   visualizarGrafo(lista);
   fclose(fp);
   ObtenerDatosGrafo(lista);
    //visualizarGrafo(lista);
    //fclose(fp);
}
void insertarPesos(Lista * lista,int ini,int fin,int peso){
	Nodo *aux=lista->inicio;
    Arista  *ar;
    //printf("Nodos\n");
    while(aux!=NULL){
    	if(aux->dato == ini){
    		if(aux->adyacencia!=NULL){
            	ar=aux->adyacencia;
            	while(ar!=NULL){ 
            		if(ar->vrt->dato == fin){
            			if(ar->peso == 0){
            				ar->peso = peso;
            			}
            			else{
            				ar->peso  = ar->peso ;
            			}
            		}
                	ar=ar->siguiente;
            	}
       	 	}
    	}   
        aux=aux->siguiente;
    }
}
void GrafoRegular(int grado,int sumaPesos,int arista){
	int i = 1,j;
	Lista *lista = (Lista *)malloc(sizeof(Lista));
	inicializar(lista);
	while(i <=grado ){
		insertarNodo(lista,i);
		i++;
	}
	i = 1,j = 1;
	int div = sumaPesos / arista;
	printf("el div es %i\n",div);
	int k = 1;
	while(i <= grado){
		j = 1;
		while(j <= grado){
			if(i != j)
			{
				insertarArista(lista,i,j,0);
			}
			j++;
		}
		i++;
	}
	visualizarGrafo(lista);
	i = 1,j = 1,k = 0;
	while(i <= grado){
		j = 1;
		while(j <=grado-k){
			insertarPesos(lista,i,j,div);
			insertarPesos(lista,j,i,div);
			j++;
		}
		k++;
		i++;
	}
	printf("k es %i\n",k);
	i = 2;
	/*
	while(i <=grado){
		insertarPesos(lista,k,i,div+sumaPesos%arista);
		insertarPesos(lista,i,k,div+sumaPesos%arista);
		i++;
	}
	*/
	int L = contarAristas(lista);
	printf("totalpesos %i\n",totalpesos);
	printf("el numero de aristas es %i\n",L);
	visualizarGrafo(lista);
}
void CrearGrafo(char const *argv[],int argc){
	printf("argc %i\n",argc);

	if(argc != 9){
		printf("falta o sobra un dato\n");
		return;
	}
	int i = 0;
	int vertices,aristas,ciclos,regular,gradoMax,gradoMin,sumaPesos;
	while(i < argc){
		printf(" %s\n",argv[i]);
		switch(i){
			case 2:
				vertices = atoi(argv[i]);
			break;
			case 3:
				aristas = atoi(argv[i]);
			break;
			case 4:
				ciclos =  atoi(argv[i]);
			break;
			case 5:
				regular =  atoi(argv[i]);
			break;
			case 6:
				gradoMax =  atoi(argv[i]);
			break;
			case 7:
				gradoMin =  atoi(argv[i]);
			break;
			case 8:
				sumaPesos  =  atoi(argv[i]);
				printf("suma pesos %i\n",sumaPesos);
			break;
		}
		i++;
	}
	if(aristas < vertices-1){
		printf("la cantidad de aristas es menor a la cantidad de vertices-1\n");
		printf("no se puede crear el grafo\n");
		return ;
	}
	printf("regular %i\n",regular);
	if(regular > 1|| regular < 0){
		printf("el numero del grafo regular es distinto de 0 o 1\n");
		printf("no se puede realizar un grafo regular\n");
		return ;
	}
	if(ciclos < 0 || ciclos > 1 ){
		printf("el numero del grafo con ciclos es distinto de 0 o 1\n");
		printf("no se puede realizar un grafo regular\n");
		return ;
	}
	if(regular == 1){
		if(gradoMax != gradoMin){
			printf("el grado maximo y el grado minimo son distintos\n");
			printf("no se puede realizar un grafo regular\n");
			return ;
		}
		else{
			GrafoRegular(gradoMax,sumaPesos,aristas);
			return;
		}
	}
	Lista *lista = (Lista *)malloc(sizeof(Lista));
	inicializar(lista);
	Vertice(vertices,lista);
	GRADOMAX(vertices,lista,gradoMax);
	visualizarGrafo(lista);
}
void Inicio(int funcionalidad,char const *argv[],int argc){
	switch(funcionalidad){
		case 1:
			CrearGrafo(argv,argc);
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