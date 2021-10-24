#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int ini, int fim, int *vet);
void intercala(int ini, int metade, int fim, int *vet);
int verifica(int *valores, int size);

int main(){
    int size;
    do{
        printf("\n\nInforme o tamanho do vetor:  ");
        scanf("%d",&size);
    }while(size<=0);

    int vet[size];
    int i;
    for(i=0; i<size; i++){
        vet[i]= rand() % 400;
    };
    merge(0, size, vet);
    printf("\n\nVALORES EM ORDEM:");
    for(i=0; i<size; i++){
        printf("\n%d",vet[i]);
    };
    verifica(vet, size);
    return 0;
}

void merge(int ini, int fim, int *vet){
    if(ini<fim-1){
        int metade=(ini+fim)/2;   // encontro a metade do vetor
        merge(ini, metade, vet);   // ordena a prmeira metade
        merge(metade, fim, vet);    // ordena a segunda metade
        intercala(ini, metade, fim, vet);   // ordena unidicando as metades
    };
}

void intercala(int ini, int metade, int fim, int *vet){
    int i, j, k, *w;
    w=malloc((fim-ini) * sizeof(int));  // ponteiro auxiliar
    i=ini;
    j=metade;
    k=0;
    while(i<metade && j<fim){
        if(vet[i] <= vet[j]){   // valores menores que a metade
            w[k++] = vet[i++];
        }else{
            w[k++] = vet[j++];  // valores maiores que a metade
        };
    };

    while(i<metade){
        w[k++] = vet[i++];   // caso a segunda parte já esteja completa
    };
    while(j<fim){               // caso a primeira parte esteja completa
        w[k++] = vet[j++];
    };
    for(i=ini; i<fim; i++){    // transportá-se os valores para o ponteiro que esta no main
        vet[i] = w[i-ini];
    };
    free(w);
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