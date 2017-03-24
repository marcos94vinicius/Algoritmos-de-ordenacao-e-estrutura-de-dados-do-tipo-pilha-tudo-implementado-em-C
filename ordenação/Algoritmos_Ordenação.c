#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//################ Método de ordenação: InsertionSort ################
void insertion(double *v, int n){

	int i, j; 
	double x;

	for(i=1;i<n;i++){

		x=v[i];
		j=i-1;
		while(x<v[j] && j>=0){

			v[j+1]=v[j];
			j--;
		}
		v[j+1]=x;
	}
}

//################ método de ordenação: QuickSort ################
 /*função que particiona o vetor*/
int particiona(double *v, int inicio, int fim){

	int esquerdo, direito;
	double pivo, aux;
	esquerdo = inicio;
	direito = fim;
	pivo = v[inicio];
	while(esquerdo < direito){
		while(v[esquerdo] <= pivo)
			esquerdo++;

		while(v[direito] > pivo)
			direito--;
		
		if(esquerdo < direito){

			aux = v[esquerdo];
			v[esquerdo] = v[direito];
			v[direito] = aux;
		}
	}
	v[inicio] = v[direito];
	v[direito] = pivo;
	return direito;
}

/*função que ordena o vetor*/
void quick(double *v, int inicio, int fim){

	double pivo;
	if(fim > inicio){

		pivo=particiona(v, inicio, fim);
		quick(v, inicio, (pivo-1));
		quick(v, (pivo+1), fim);
	}
}

//################ método de ordenação: MergeSort ################

//função que ordena
void merge(int *v, int inicio, int meio, int fim){

	int *p, p1, p2, tamanho, i, j, k;
	int fim1 = 0, fim2 = 0;
	tamanho = (fim - inicio + 1);

	p1 = inicio;
	p2 = (meio + 1);

	p = (int *) malloc(sizeof(int));
	if(p != NULL){

		for(i = 0; i < tamanho; i++){

			if(!fim1 && !fim2){

				if(v[p1] < v[p2])
					p[i] = v[p1++];
				else
					p[i] = v[p2++];

				if(p1 > meio) fim = 1;
				if(p2 > fim) fim2 = 1;
			}else{

				if(!fim1)
					p[i] = v[p1++];
				else
					p[i] = v[p2++];
			}
		}

		for(j = 0, k = inicio; j < tamanho; j++, k++)
			v[k] = p[j];
	}
	
	//free(p);
}

//função que pega o elemento do meio como pivô 
void mergeSort(int *v, int inicio, int fim){

	int meio;
	int x;
	
	if(inicio < fim){

		x = (int)((inicio + fim)/2);
		meio = (int) x;
		mergeSort(v, inicio, meio);
		mergeSort(v, meio+1, fim);
		merge(v, inicio, meio, fim);
	}
}

//função principal
main(){

	int vet[10];
	printf("Digite 10 números: ");
	int i;
	for(i=0;i<10;i++)
		scanf("%d", &vet[i]);

	mergeSort(vet, 0, 9);

	for(i=0;i<10;i++)
		printf("%d\n", vet[i]);

	return 0;
}
