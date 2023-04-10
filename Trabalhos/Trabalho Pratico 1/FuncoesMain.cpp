#include <fstream>
#include <iostream>
#include <ctime>

#include "FuncoesMain.hpp"
#include "MetodosDeOrdenacao.cpp"

using namespace std;

void lerArquivo(auto vetor[], string endereco, int tamanho) {
    ifstream arqEntrada("./Instancias-TP1/"+endereco);
    auto num = vetor[0];
    for(int i = 0; i < tamanho; i++) {
        arqEntrada >> num;
        vetor[i] = num;
    }
    arqEntrada.close();
}

void gerarResultado(double tempo, long long int comparacoes, long long int movimentacoes, string tipoArquivo, int tamanho, string nomeMetodo) {
    system("cls");
    cout << nomeMetodo << " - " << tipoArquivo << " " << tamanho << endl;
    cout << "Tempo: " << tempo << "s" << endl;
    cout << "Comparacoes: " << comparacoes << endl;
    cout << "Movimentacoes: " << movimentacoes << endl;
    cout << endl;
}

int definirTamanhoVetor(int opcaoInstancia) {
    if(opcaoInstancia == 1 || opcaoInstancia == 3 || opcaoInstancia == 5) {
        return 29855;
    } else if(opcaoInstancia == 2 || opcaoInstancia == 4 || opcaoInstancia == 6) {
        return 261791;
    } else if(opcaoInstancia == 7 || opcaoInstancia == 11 || opcaoInstancia == 15 || opcaoInstancia == 19) {
        return 1000;
    } else if(opcaoInstancia == 8 || opcaoInstancia == 12 || opcaoInstancia == 16 || opcaoInstancia == 20) {
        return 10000;
    } else if(opcaoInstancia == 9 || opcaoInstancia == 13 || opcaoInstancia == 17 || opcaoInstancia == 21) {
        return 100000;
    }
    return 1000000;
}

string definirEndereco(int opcaoInstancia) {
    if(opcaoInstancia < 3) {
        return "DicionarioAleatorio";
    } else if(opcaoInstancia < 5) {
        return "DicionarioInversamenteOrdenado";
    } else if(opcaoInstancia < 7) {
        return "DicionarioOrdenado";
    } else if(opcaoInstancia < 11) {
        return "ListaAleatoria";
    } else if(opcaoInstancia < 15) {
        return "ListaInversamenteOrdenada";
    } else if(opcaoInstancia < 19) {
        return "ListaOrdenada";
    }
    return "ListaQuaseOrdenada";
}

void chamarMetodoEscolhidoString(int metodo, int tamanho, string endereco) {
    string* vetor = new string[tamanho];
    long long int comparacoes = 0, movimentacoes = 0;
    string metodoEscolhido;

    lerArquivo(vetor, endereco, tamanho);

    double inicio = clock();

    // Chama o método escolhido
    switch(metodo) {
        case 1:
            bubbleSort(vetor, tamanho, comparacoes, movimentacoes);
            metodoEscolhido = "BubbleSort";
            break;
        case 2:
            insertionSort(vetor, tamanho, comparacoes, movimentacoes);
            metodoEscolhido = "InsertionSort";
            break;
        case 3:
            selectionSort(vetor, tamanho, comparacoes, movimentacoes);
            metodoEscolhido = "SelectionSort";
            break;
        case 4:
            shellSort(vetor, tamanho, comparacoes, movimentacoes);
            metodoEscolhido = "ShellSort";
            break;
        case 5:
            quickSort(vetor, 0, tamanho-1, comparacoes, movimentacoes);
            metodoEscolhido = "QuickSort";
            break;
        case 6:
            mergeSortString(vetor, 0, tamanho-1, comparacoes, movimentacoes);
            metodoEscolhido = "MergeSort";
            break;
    }
    double tempoSegundos = (clock() - inicio) / CLOCKS_PER_SEC;
    gerarResultado(tempoSegundos, comparacoes, movimentacoes, endereco, tamanho, metodoEscolhido);
}

void chamarMetodoEscolhidoInteiro(int metodo, int tamanho, string endereco) {
    int* vetor = new int[tamanho];
    long long int comparacoes = 0, movimentacoes = 0;
    string metodoEscolhido;

    lerArquivo(vetor, endereco, tamanho);

    double inicio = clock();

    // Chama o método escolhido
    switch(metodo) {
        case 1:
            bubbleSort(vetor, tamanho, comparacoes, movimentacoes);
            metodoEscolhido = "BubbleSort";
            break;
        case 2:
            insertionSort(vetor, tamanho, comparacoes, movimentacoes);
            metodoEscolhido = "InsertionSort";
            break;
        case 3:
            selectionSort(vetor, tamanho, comparacoes, movimentacoes);
            metodoEscolhido = "SelectionSort";
            break;
        case 4:
            shellSort(vetor, tamanho, comparacoes, movimentacoes);
            metodoEscolhido = "ShellSort";
            break;
        case 5:
            quickSort(vetor, 0, tamanho-1, comparacoes, movimentacoes);
            metodoEscolhido = "QuickSort";
            break;
        case 6:
            mergeSort(vetor, 0, tamanho-1, comparacoes, movimentacoes);
            metodoEscolhido = "MergeSort";
            break;
    }
    double tempoSegundos = (clock() - inicio) / CLOCKS_PER_SEC;
    gerarResultado(tempoSegundos, comparacoes, movimentacoes, endereco, tamanho, metodoEscolhido);
}

void imprimirMenuMetodos() {
    cout << "---------------------" << endl;
    cout << "| 1. Bubble Sort    |" << endl;
    cout << "| 2. Insertion Sort |" << endl;
    cout << "| 3. Selection Sort |" << endl;
    cout << "| 4. Shell Sort     |" << endl;
    cout << "| 5. Quick Sort     |" << endl;
    cout << "| 6. Merge Sort     |" << endl;
    cout << "| 7. Sair           |" << endl;
    cout << "---------------------" << endl;
    cout << "Escolha uma opcao: ";
}

void imprimirMenuInstancias() {
    cout << "--------------------------------------------------" << endl;
    cout << "| 1.  DicionarioAleatorio -------------- 29855   |" << endl;
    cout << "| 2.  DicionarioAleatorio -------------- 261791  |" << endl;
    cout << "| 3.  DicionarioInversamenteOrdenado --- 29855   |" << endl;
    cout << "| 4.  DicionarioInversamenteOrdenado --- 261791  |" << endl;
    cout << "| 5.  DicionarioOrdenado --------------- 29855   |" << endl;
    cout << "| 6.  DicionarioOrdenado --------------- 261791  |" << endl;
    cout << "| 7.  ListaAleatoria ------------------- 1000    |" << endl;
    cout << "| 8.  ListaAleatoria ------------------- 10000   |" << endl;
    cout << "| 9.  ListaAleatoria ------------------- 100000  |" << endl;
    cout << "| 10. ListaAleatoria ------------------- 1000000 |" << endl;
    cout << "| 11. ListaInversamenteOrdenada -------- 1000    |" << endl;
    cout << "| 12. ListaInversamenteOrdenada -------- 10000   |" << endl;
    cout << "| 13. ListaInversamenteOrdenada -------- 100000  |" << endl;
    cout << "| 14. ListaInversamenteOrdenada -------- 1000000 |" << endl;
    cout << "| 15. ListaOrdenada -------------------- 1000    |" << endl;
    cout << "| 16. ListaOrdenada -------------------- 10000   |" << endl;
    cout << "| 17. ListaOrdenada -------------------- 100000  |" << endl;
    cout << "| 18. ListaOrdenada -------------------- 1000000 |" << endl;
    cout << "| 19. ListaQuaseOrdenada --------------- 1000    |" << endl;
    cout << "| 20. ListaQuaseOrdenada --------------- 10000   |" << endl;
    cout << "| 21. ListaQuaseOrdenada --------------- 100000  |" << endl;
    cout << "| 22. ListaQuaseOrdenada --------------- 1000000 |" << endl;
    cout << "| 23. Voltar                                     |" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Escolha uma opcao: ";
}