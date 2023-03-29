#include "MetodosDeOrdenacao.hpp"

void bubbleSort(auto vetor[], int tamanhoVetor, int* comparacoes, int* movimentacoes) {
    auto aux = vetor[0];

    for(int i = 0; i < tamanhoVetor-1; i++) {
        for(int j = 1; j < tamanhoVetor-i; j++) {
            *comparacoes += 1;

            if(vetor[j] < vetor[j-1]) {
                *movimentacoes += 1;
                aux = vetor[j];
                vetor[j] = vetor[j-1];
                vetor[j-1] = aux;
            }
        }
    }
}

void insertionSort(auto vetor[], int tamanhoVetor, int* comparacoes, int* movimentacoes) {
    int j;
    auto aux = vetor[0];

    for(int i = 1; i < tamanhoVetor; i++) {
        aux = vetor[i];
        j = i-1;

        while(j >= 0 && vetor[j] > aux) {
            *comparacoes += 1;
            *movimentacoes += 1;

            vetor[j+1] = vetor[j];
            j--;
        }
        vetor[j+1] = aux;
    }
}

void selectionSort(auto vetor[], int tamanhoVetor, int* comparacoes, int* movimentacoes) {
    int min;
    auto aux = vetor[0];

    for(int i = 0; i < tamanhoVetor-1; i++) {
        min = i;

        for(int j = i+1; j < tamanhoVetor; j++) {
            *comparacoes += 1;

            if(vetor[j] < vetor[min]) {
                min = j;
            }
        }
        movimentacoes += 1;

        aux = vetor[i];
        vetor[i] = vetor[min];
        vetor[min] = aux;
    }
}


void shellSort(auto vetor[], int tamanhoVetor, int* comparacoes, int* movimentacoes) {
    int i, j, h;
    auto aux = vetor[0];

    for(h = 1; h < tamanhoVetor; h=3*h+1);

    while(h > 1) {
        h = h/3;

        for(i = h; i < tamanhoVetor; i++) {
            aux = vetor[i];
            j = i;

            while(j >= h && vetor[j-h] > aux) {
                *comparacoes += 1;
                *movimentacoes += 1;
                
                vetor[j] = vetor[j-h];
                j = j-h;
            }
            vetor[j] = aux;
        }
    }
}