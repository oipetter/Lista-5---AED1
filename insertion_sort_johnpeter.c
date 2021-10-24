#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inser_sort(int *valores);
int verifica(int *valores, int size);

int main(){
    int size;
    do{
        printf("\nInforme o tamanho do vetor:  ");
        scanf("%d",&size);
    }while(size<=0);

    int valores[size];
    int i;
    for(i=0; i<size; i++){
        valores[i] = rand() % 1000;
    };
    inser_sort(valores);
    printf("\n\nVALORES EM ORDEM:");
    for(i=0; i<size; i++){
        printf("\n%d",valores[i]);
    };
    verifica(valores, size);
    return 0;
}

int inser_sort(int *valores){
    int i, j;
    int aux;
    for(i = 1; i<sizeof(valores); i++){
        aux=valores[i];         // variavel aux recebe o valor a direita do primeiro elemento
        j = i-1;                // j recebe o valor mais a esquerda 

        while(( j>=0) && (aux<valores[j])){  // sera verificado se o valor a esquerda (valor 0) é maior que o seu valor a direita (valor do auxiliar)
            valores[j+1]=valores[j];            // neste caso o valor da posição 1 do vetor, recebe o valor da posição zero
            j--;                 // decrementá-se o j, para que ele saia do while
        };
        valores[j+1]=aux;                // o valor zero do vetor recebe o valor que estava a sua direita.
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
