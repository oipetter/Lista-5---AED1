#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void selection_sort (int *vet, int size);
int verifica(int *valores, int size);

int main(){
    int i,size;
    do{
        printf("\n\nInforme o tamanho do vetor:  ");
        scanf("%d",&size);
    }while(size<=0);

    int vet[size];
    for(i=0; i<size; i++){
        vet[i] = rand() % 200;
    };
    selection_sort(vet, size);
    
    printf("\nVALORES ORDENADOS:");
    for(i=0; i<size; i++){
        printf("\n%d",vet[i]);
    };
    verifica(vet, size);
    return 0;
}

void selection_sort (int *vet, int size){
    int i, j, menor, troca;
    for(i=0; i<size; i++){      // for utilizado para procurar o menor elemento em relação a variavel i
        menor=i;             // menor recebe o valor de i para que seja realizada comparações

        for(j=i+1; j<size; j++){   // verifica o elemento a frente do i, ou seja a proxima variavel do vetor
            if(vet[j]<vet[menor]){
                menor=j;   // se o elemento da frente é menor que o elemento anterior, então este elemento da frente será o primeiro
            };
        };
        if(i != menor){   // se o valor utilizado para i for diferente do "menor " elemento, então  o vet[j] é menor que o vet[menor] e deve ser feita uma troca de ordem
            troca=vet[i];    // troca recebe o valor inicial original
            vet[i]=vet[menor];  // primeiro item do vetor recebe o elemento que estava a sua frente
            vet[menor]=troca;   // vetor que estava a frente recebe o valor de seu antecessor
        };
    };
}

int verifica(int *valores, int size){
    int i=1;
    int j=0;
    do{
        if(i==size){
            printf("\n\nVERIFICADO E A ARVORE ESTA CORRETA\n\n");
            exit(1);
        }else{
            if(valores[j]>valores[i]){
                printf("\n\nERRO NA ARVORE\n\n");
                exit(1);
            };
        };
        j++;
        i++;
    }while(j<size);
    printf("\n\nARVORE CORRETA\n");
}