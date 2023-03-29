#include <iostream>

using namespace std;


void insertionSort(int vetor[], int tamanhoVetor, int* comparacoes, int* movimentacoes) {
    int aux, j;

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

int main() {
    int v[] = {5,4,3,2,1};
    int n = 5;
    int comparacoes, movimentacoes;

    insertionSort(v, n, &comparacoes, &movimentacoes);
    for(int i : v){
        cout << i << " ";
    }
    return 0;
}