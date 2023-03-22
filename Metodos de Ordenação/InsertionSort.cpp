#include <iostream>

using namespace std;

void insertionSort(int v[], int n, int* comparacoes, int* movimentacoes) {
    int aux, j;
    for(int i = 1; i < n; i++) {
        aux = v[i];
        j = i-1;
        while(j >= 0 && v[j] > aux) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = aux;
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