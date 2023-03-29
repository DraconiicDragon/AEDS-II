#include <iostream>

using namespace std;

void shellSort(int vetor[], int tamanhoVetor, int* comparacoes, int* movimentacoes) {
    int i, j, aux, h;

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


int main() {
    int v[] = {5,4,3,2,1};
    int n = 5;
    int comparacoes, movimentacoes;

    shellSort(v, n, &comparacoes, &movimentacoes);
    for(int i : v){
        cout << i << " ";
    }
    return 0;
}