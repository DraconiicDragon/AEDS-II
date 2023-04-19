#include "MetodosDeOrdenacao.hpp"

#include <iostream>

using namespace std;

void bubbleSort(auto vetor[], int tamanhoVetor, long long int& comparacoes, long long int& movimentacoes) {
    auto aux = vetor[0];
    int troca;

    for(int i = 0; i < tamanhoVetor-1; i++) {  
        troca = 0;
        for(int j = 1; j < tamanhoVetor-i; j++) {
            comparacoes += 1;
            if(vetor[j] < vetor[j-1]) {
                movimentacoes += 1;
                aux = vetor[j];
                vetor[j] = vetor[j-1];
                vetor[j-1] = aux;
                troca = 1;
            }
        }
        if(troca == 0) {
            break;
        }
    }
}

void insertionSort(auto vetor[], int tamanhoVetor, long long int& comparacoes, long long int& movimentacoes) {
    int j;
    auto aux = vetor[0];

    for(int i = 1; i < tamanhoVetor; i++) {
        aux = vetor[i];
        j = i-1;

        comparacoes += 1;
        while(j >= 0 && vetor[j] > aux) {
            comparacoes += 1;
            movimentacoes += 1;

            vetor[j+1] = vetor[j];
            j--;
        }
        vetor[j+1] = aux;
    }
}

void selectionSort(auto vetor[], int tamanhoVetor, long long int&comparacoes, long long int&movimentacoes) {
    int min;
    auto aux = vetor[0];

    for(int i = 0; i < tamanhoVetor-1; i++) {
        min = i;

        for(int j = i+1; j < tamanhoVetor; j++) {
            comparacoes += 1;

            if(vetor[j] < vetor[min]) {
                min = j;
                movimentacoes += 1;
            }
        }
        

        aux = vetor[i];
        vetor[i] = vetor[min];
        vetor[min] = aux;
    }
}

void shellSort(auto vetor[], int tamanhoVetor, long long int& comparacoes, long long int& movimentacoes) {
    int i, j, h;
    auto aux = vetor[0];

    for(h = 1; h < tamanhoVetor; h=3*h+1);

    while(h > 1) {
        h = h/3;

        for(i = h; i < tamanhoVetor; i++) {
            aux = vetor[i];
            j = i;

            while(j >= h && vetor[j-h] > aux) {
                comparacoes += 2;
                movimentacoes += 1;
                
                vetor[j] = vetor[j-h];
                j = j-h;
            }
            vetor[j] = aux;
        }
    }
}

void quickSort(auto vetor[], int esquerda, int direita, long long int& comparacoes, long long int& movimentacoes) {
    auto aux = vetor[0];
    int i = esquerda, j = direita;
    auto pivo = vetor[(esquerda+direita)/2];

    while(i <= j) {
        comparacoes += 1;
        while(vetor[i] < pivo) {
            comparacoes += 1;
            i++;
        }
        comparacoes += 1;
        while(vetor[j] > pivo){
            comparacoes += 1;
            j--;
        }
        
        if(i <= j) {
            movimentacoes += 1;
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++;
            j--;
        }
    }
    if(esquerda < j) {
        quickSort(vetor, esquerda, j, comparacoes, movimentacoes);
    }
    if(i < direita) {
        quickSort(vetor, i, direita, comparacoes, movimentacoes);
    }
}

void merge(auto arr[], int p, int q, int r, long long int& comparacoes, long long int& movimentacoes) {

  int n1 = q - p + 1;
  int n2 = r - q;

  int* L = new int[n1];
  int* M = new int[n2];

  for (int i = 0; i < n1; i++) {
    L[i] = arr[p + i];
    movimentacoes+=1;
  }
  for (int j = 0; j < n2; j++) {
    M[j] = arr[q + 1 + j];
    movimentacoes+=1;
  }

  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  while (i < n1 && j < n2)
  {
    comparacoes += 1;
    if (L[i] <= M[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  while (i < n1)
  {
    movimentacoes+=1;
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    movimentacoes+=1;
    arr[k] = M[j];
    j++;
    k++;
  }
  delete[] L;
  delete[] M;
}

void mergeSort(auto arr[], int l, int r, long long int& comparacoes, long long int& movimentacoes) {
  if (l < r)
  {
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m, comparacoes, movimentacoes);
    mergeSort(arr, m + 1, r, comparacoes, movimentacoes);

    merge(arr, l, m, r, comparacoes, movimentacoes);
  }
}

void mergeString(auto arr[], int p, int q, int r, long long int& comparacoes, long long int& movimentacoes) {

  int n1 = q - p + 1;
  int n2 = r - q;

  string* L = new string[n1];
  string* M = new string[n2];

  for (int i = 0; i < n1; i++) {
    L[i] = arr[p + i];
    movimentacoes+=1;
  }
  for (int j = 0; j < n2; j++) {
    M[j] = arr[q + 1 + j];
    movimentacoes+=1;
  }

  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  while (i < n1 && j < n2)
  {
    comparacoes += 1;
    if (L[i] <= M[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  while (i < n1)
  {
    movimentacoes+=1;
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    movimentacoes+=1;
    arr[k] = M[j];
    j++;
    k++;
  }
  delete[] L;
  delete[] M;
}

void mergeSortString(auto arr[], int l, int r, long long int& comparacoes, long long int& movimentacoes) {
  if (l < r)
  {
    int m = l + (r - l) / 2;

    mergeSortString(arr, l, m, comparacoes, movimentacoes);
    mergeSortString(arr, m + 1, r, comparacoes, movimentacoes);

    mergeString(arr, l, m, r, comparacoes, movimentacoes);
  }
}