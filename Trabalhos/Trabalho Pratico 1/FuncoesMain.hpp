#ifndef FUNCOES_MAIN
#define FUNCOES_MAIN

#include <iostream>
using namespace std;


// Preenche o vetor com os dados do arquivo
void lerArquivo(auto vetor[], string endereco, int tamanho);

// Imprime na tela os resultados do teste do método
void gerarResultado(double tempo, long long int comparacoes, long long int movimentacoes, string tipoArquivo, int tamanho, string nomeMetodo);

// Retorna o tamanho do vetor de acordo com a instância escolhida
int definirTamanhoVetor(int opcaoInstancia);

// Retorna o nome da instância escolhida
string definirEndereco(int opcaoInstancia);

// Chama o método escolhido para as instâncias de palavras
void chamarMetodoEscolhidoString(int metodo, int tamanho, string endereco);

// Chama o método escolhido para as instâncias de números
void chamarMetodoEscolhidoInteiro(int metodo, int tamanho, string endereco);

// Imprime o menu contendo todos os métodos
void imprimirMenuMetodos();

// Imprime o menu contendo todos as intâncias
void imprimirMenuInstancias();

#endif