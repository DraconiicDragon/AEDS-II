#include <iostream>

using namespace std;

int bubbleSort(int v[], int n, int* comparacoes, int* movimentacoes) {
    int aux;
    for(int i = 0; i < n-1; i++) {
        for(int j = 1; j < n-i; j++) {
            if(v[j] < v[j-1]) {
                aux = v[j];
                v[j] = v[j-1];
                v[j-1] = aux;
            }
        }
    }
}

int main() {
    int v[] = {5,4,3,2,1};
    int n = 5;
    int comparacoes, movimentacoes;

    bubbleSort(v, n, &comparacoes, &movimentacoes);
    for(int i : v){
        cout << i << " ";
    }
    return 0;
}