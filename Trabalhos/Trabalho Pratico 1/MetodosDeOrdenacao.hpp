#ifndef METODOS_ORDENACAO
#define METODOS_ORDENACAO

void bubbleSort(auto vetor[], int tamanhoVetor, long long int& comparacoes, long long int& movimentacoes);
void insertionSort(auto vetor[], int tamanhoVetor, long long int& comparacoes, long long int& movimentacoes);
void selectionSort(auto vetor[], int tamanhoVetor, long long int&comparacoes, long long int&movimentacoes);
void shellSort(auto vetor[], int tamanhoVetor, long long int& comparacoes, long long int& movimentacoes);
void quickSort(auto vetor[], int esquerda, int direita, long long int& comparacoes, long long int& movimentacoes);

// Merge Sort para números
void merge(auto arr[], int p, int q, int r, long long int& comparacoes, long long int& movimentacoes);
void mergeSort(auto arr[], int l, int r, long long int& comparacoes, long long int& movimentacoes);

// Merge Sort para palavras
void mergeString(auto arr[], int p, int q, int r, long long int& comparacoes, long long int& movimentacoes);
void mergeSortString(auto arr[], int l, int r, long long int& comparacoes, long long int& movimentacoes);

#endif