#include <iostream>

using namespace std;


void selectionSort(int vetor[], int tamanhoVetor, int* comparacoes, int* movimentacoes) {
    int min, aux;

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

int main() {
    int v[] = {5,4,3,2,1};
    int n = 5;
    int comparacoes, movimentacoes;

    selectionSort(v, n, &comparacoes, &movimentacoes);
    for(int i : v){
        cout << i << " ";
    }
    return 0;
}