#include<stdio.h>
#include<stdlib.h>

void merge(int input[], int first,int mid, int last){

  int tam = last - first + 1;
  int auxinput[tam];
  int i = first;
  int j = mid + 1;
  int aux = 0;

  while(mid >= i && last >= j){
 		if(input[i] <= input[j]){
      	 auxinput[aux] = input[i];
            i++;
    }
		else{
       	  auxinput[aux] = input[j];
          j++;
    }
		aux++;
 	}
	while(mid >= i){
    	auxinput[aux] = input[i];
    	aux++;
    	i++;
 	}
 	while(last >= j){
    	auxinput[aux] = input[j];
    	aux++;
    	j++;
 	}
  aux = first;
 	while(aux <= last){
    	input[aux] = auxinput[aux-first];
      aux++;
  }
}

void mergeSort(int input[], int first, int last){
    if (first < last){
        int mid = (first + last)/2;

        mergeSort(input, first, mid);
        mergeSort(input, mid+1, last);
        merge(input, first, mid, last);
     }
 }

 void display(int *input, int tam){
   for(int i=0;i<tam;i++){
     printf("\ndisplay[%d]: %d ", i,input[i]);
   }
   printf("\n");
 }

int main(){
  int *vetor;
  int tamanho;
  scanf("%d", &tamanho);

  vetor = (int*)malloc(tamanho * sizeof(int));
  for(int i = 0; i < tamanho; i++){
    scanf("%d",&vetor[i]);
  }

  mergeSort(vetor,0,tamanho-1);
  display(vetor,tamanho);

  free(vetor);
}
