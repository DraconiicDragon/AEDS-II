#include <fstream>
#include <iostream>


#include "FuncoesMain.hpp"
#include "MetodosDeOrdenacao.cpp"

using namespace std;

void lerArquivo(auto vetor[], char endereco[]) {
    ifstream arqEntrada("./Instancias-TP1/ListaAleatoria-1000.txt");
    int i = 0;
    arqEntrada >> i;
    cout << i;
}

