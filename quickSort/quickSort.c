#include<stdio.h>
#include<stdlib.h>

void display(int *input, int tam){
   for(int i=0;i<tam;i++){
     printf("\ndisplay[%d]: %d ", i,input[i]);
   }
   printf("\n");
}

int split(int *input,int first,int last){
    int aux;
    int pivot = input[last];
    //printf("%d\n",pivot);
    int j = (first-1);

    for(int i = first;i<=(last-1);i++){
        if(input[i]<=pivot){
            j++;
            aux = input[j];
            input[j] = input[i];
            input[i] = aux;
        }
    }

     for(int i = (last-1); i>j;i--){
       input[i+1]=input[i];
     }
     input[j+1] = pivot;

    //display(input,8);
    return (j+1);
}

void quicksort(int *input,int first,int last){
  int pivot;
  if(last > first){
    pivot = split(input,first,last);
    //printf("\n pivot: %d \n", pivot);
    quicksort(input,first,pivot-1);
    quicksort(input,pivot+1,last);
  }
}



int main(){
  int *vetor;
  int tamanho;
  scanf("%d", &tamanho);

  vetor = (int*)malloc(tamanho * sizeof(int));
  for(int i = 0; i < tamanho; i++){
    scanf("%d",&vetor[i]);
  }
  quicksort(vetor,0,tamanho-1);
  display(vetor,tamanho);

  free(vetor);
}
