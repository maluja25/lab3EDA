#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>







int **matriz;
int Aristas(int aristas,int **matriz){

}
int Vertice(int vertices,int **matriz){
	for (int i = 0; i < vertices; ++i)
	{
		for (int j = 0; j < vertices; ++j)
		{
			printf("%i",matriz[i][j]);
		}
		printf("\n");
	}
}
/*
int regular(Kregular){
	switch(Kregular){
		case 0:
			return 1;
		break;
		case 1:
			if(gradoMax != gradoMin){
				return 0;
			}
		break;
		default:
			return 0;
		break;
	}
}
*/
int EstaEnLista(int **matriz,int posi,int posj){
	srand (time(NULL));
	if(matriz[posi][posj] == 1){
		posj = rand() % posi;
		return 1;
	}
	return 0;
}
int GRADOMAX(int gradoMax,int **matriz,int vertices){
	srand (time(NULL));
	int *lista = (int *)malloc(sizeof(int )*gradoMax);
	int numero = rand() % vertices;
	int Azar;
	printf("el numero aleatoro es :%i\n",numero);
	for (int i = 0; i < gradoMax; ++i)
	{

		Azar = rand() % vertices;
		printf("l %i\n",EstaEnLista(matriz,numero,Azar));
		if(EstaEnLista(matriz,numero,Azar) == 1){
			Azar = rand() % numero;
		}else{
			Azar = Azar;
		}
		matriz[numero][Azar] = 1;
		printf("%i\n",Azar);
		lista[i] = Azar;
	}
}
int GRADOMIN(int gradoMin,int **matriz,int vertices){
	srand (time(NULL));
	int *lista = (int *)malloc(sizeof(int )*gradoMin);
	int numero = rand() % vertices+1;
	int Azar;
	printf("el numero aleatoro es :%i\n",numero);
	for (int i = 0; i < gradoMin; ++i)
	{

		Azar = rand() % vertices+1;
		matriz[numero][Azar] = 1;
		printf("%i\n",Azar);
		lista[i] = Azar;
	}
}
int CrearGrafo(int vertices,int aristas,int ciclos , int Kregular ,int gradoMax,int gradoMin,int sumaPesos){
	int  **matriz = (int  **) calloc(1000, sizeof(int*));
	for (int i = 0; i < vertices; ++i)
	{
		matriz[i] = (int  *) calloc(1000, sizeof(int )) ;
	}
	Vertice(vertices,matriz);
	GRADOMAX(gradoMax,matriz,vertices);
	Vertice(vertices,matriz);
	//GRADOMIN(gradoMin,matriz,vertices);
	//Vertice(vertices,matriz);
	return 0;

}
int main(int argc, char const *argv[])
{
	int vertices,aristas,ciclos,Kregular,gradoMax,gradoMin,sumaPesos;
	for (int i = 1; i < argc ; ++i)
	{
		switch(i){
			case 1:
				printf("el numero que indica la funcion %s\n",argv[i]);
			break;
			case 2:
				vertices = atoi(argv[i]);
				printf("el numero que indica la cantidad de vertices %s\n",argv[i]);
			break;
			case 3:
				aristas = atoi(argv[i]);
				printf("el numero que indica la cantidad de aristas %s\n",argv[i]);
			break;
			case 4:
				ciclos = atoi(argv[i]);
				printf("el numero que indica grafo con ciclos o sin ciclos %s\n",argv[i]);
			break;
			case 5:
				Kregular = atoi(argv[i]);
				printf("el numero que indica grafo regular o no regular %s\n",argv[i]);
			break;
			case 6:
				gradoMax = atoi(argv[i]);
				printf("el numero que indica el grado maximo del grafo %s\n",argv[i]);
			break;
			case 7:
				gradoMin = atoi(argv[i]);
				printf("el numero que indica el grado minimo del grafo %s\n",argv[i]);
			break;
			case 8:
				sumaPesos = atoi(argv[i]);
				printf("el numero que indica la suma total de los pesos %s\n",argv[i]);
			break;
		}
	}
	CrearGrafo(vertices,aristas,ciclos,Kregular,gradoMax,gradoMin,sumaPesos);
	printf("\n");
	return 0;
}