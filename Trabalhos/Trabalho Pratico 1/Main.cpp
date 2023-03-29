#include <iostream>
#include "FuncoesMain.cpp"

#include <fstream>

using namespace std;

int main() {

    char endereco[10];
    int vetor[10];
    
    lerArquivo(vetor, endereco);

    // int vetorInt[] = {790, 2, 131, 292, 135};
    // string vetorString[] = {"BAGAGEIRO", "NUMA", "NUCLEO", "EPIGRAFE", "CANDIDA"};

    // int comparacoes = 0, movimentacoes = 0;

    // shellSort(vetorInt, 5, &comparacoes, &movimentacoes);
    // shellSort(vetorString, 5, &comparacoes, &movimentacoes);

    // for(auto i : vetorInt) {
    //     cout << i << " ";
    // }
    // cout << endl;
    // for(auto i : vetorString) {
    //     cout << i << " ";
    // }
    return 0;
}