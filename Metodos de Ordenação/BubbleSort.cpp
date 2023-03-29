#include <iostream>

using namespace std;

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

int main() {
    string v[] = {"eb","ea","c","b","a"};
    int n = 5;
    int comparacoes, movimentacoes;

    bubbleSort(v, n, &comparacoes, &movimentacoes);
    for(auto i : v){
        cout << i << " ";
    }
    return 0;
}