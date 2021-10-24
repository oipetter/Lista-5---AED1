#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verifica(int *vet, int inicio, int fim);
void quick_sort(int *vet, int inicio, int fim);
int ver_arv(int *vet, int size);

int main(){
    int size;
    do{
        printf("\n\nInforme o tamanho do vetor:  ");
        scanf("%d",&size);
    }while(size<=0);

    int vet[size];
    int i;
    for(i=0; i<size; i++){
        vet[i]= rand() % 1000;
    };
    quick_sort(vet, 0, size);
   
    printf("\n\nVALORES EM ORDEM:");
    for(i=0; i<size; i++){
        printf("\n%d",vet[i]);
    };
    ver_arv(vet,size);
    return 0;
}

void quick_sort(int *vet, int inicio, int fim){
    int pivo;
    if(fim > inicio){
        pivo = verifica(vet, inicio, fim);  // VERIFICA é uma função que ira identificar o primeiro elemento e ordenar os menores que ele a esquerda e maiores a direita
        quick_sort(vet, inicio, pivo-1);  // por meio da recursão, organiza-se os elementos que estão antes do pivo (por isso o pivo-1)
        quick_sort(vet, pivo+1, fim);     // por meio da recursão, organiza-se os elementos que estão a frente do pivo (por isso o pivo+1)
    };
}

int verifica(int *vet, int inicio, int fim){
    int esquerda=inicio;
    int direita=fim;
    int pivo=vet[inicio];
    int auxiliar;   //ajudará na troca de valores

    while(esquerda<direita){
        while( vet[esquerda] <= pivo){
            esquerda ++;    // se valor da esquerda for menor ou igual ao pivo, anda-se uma casa em sentido ao fim
        };
        while( vet[direita] > pivo){
            direita--;     // se valor a direita for maior que o pivo, anda-se uma casa em sentido ao inicio
        };
        if( esquerda < direita){   // realiza-se a troca de valores
            auxiliar = vet[esquerda];     // aux armazena valor que consta a esquerda na verificação
            vet[esquerda] = vet[direita];   // unidade de memoria a esquerda agora armazena o valor que estava a frente do pivo (vindo pela direita)
            vet[direita] = auxiliar;   // assim como aconteceu com o o valor a esquerda, agora o valor a direita recebe o valor de aux que era anteriormente a esquerda do pivo
        };
    };

        /** ao sair deste while, quer dizer que o valor da direita é menor que o pivo
         e que a varivael direita é menor que a esquerda, então transfere-se o valor do pivo para a unidade de memoria que esta na direita
         e o valor que estava na direita para o inicio do vetor **/

    vet[inicio] = vet[direita];  
    vet[direita] = pivo;
    return direita;
}

int ver_arv(int *vet, int size){
    int i=1;
    int j=0;
    do{
        if(i==size){
            printf("\n\nVERIFICADO E A ARVORE ESTA CORRETA\n\n");
            exit(1);
        }else{
            if(vet[j]>vet[i]){
                printf("\n\nERRO NA ARVORE\n\n");
                exit(1);
            };
        };
        j++;
        i++;
    }while(j<size);
    printf("\n\nARVORE CORRETA\n");
}