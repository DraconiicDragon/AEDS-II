#include <iostream>

using namespace std;

void BSM(int v[], int n, int* comparacoes, int* movimentacoes) {
    int aux;
    for(int i = 0; i < n-1; i++) {
        for(int j = 1; j < n-i; j++) {
            comparacoes+=1;
            if(v[j] < v[j-1]) {
                *movimentacoes+=1;
                aux = v[j];
                v[j] = v[j-1];
                v[j-1] = aux;
            }
        }
    }
}

void BSMD(int v[], int n, int* comparacoes, int* movimentacoes) {
    int aux;
    for(int i = 0; i < n-1; i++) {
        for(int j = 1; j < n-i; j++) {
            comparacoes+=1;
            if(v[j] > v[j-1]) {
                *movimentacoes+=1;
                aux = v[j];
                v[j] = v[j-1];
                v[j-1] = aux;
            }
        }
    }
}


int main() {
    int comparacoes = 0, movimentacoes = 0;
    int v[] = {8, 11, 20, 5, 17, 30, 14, 15, 28, 19};

    cout << "Vetor Original" << endl;
    for(int i : v) {
       cout << i << " ";
    }

    
    BSM(v, 10, &comparacoes, &movimentacoes);
    cout << endl << endl << "Vetor Ordenado - Trocas : " << movimentacoes << endl;
    for(int i : v) {
       cout << i << " ";
    } 

    int v2[] = {8, 11, 20, 5, 17, 30, 14, 15, 28, 19};
    movimentacoes = 0;
    BSMD(v2, 10, &comparacoes, &movimentacoes);
    cout << endl << endl << "Vetor Ordenado Decrescente - Trocas : " << movimentacoes << endl;
    for(int i : v2) {
       cout << i << " ";
    }
    cout << endl;

    return 0;
}