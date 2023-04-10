#include "FuncoesMain.cpp"

// 29855
// 261791

#define TAMANHO_INICIAL 1000
#define INSTANCIAS 4
#define QUANTIDADE_TESTES 1

double testarFuncao(int tamanho, long long int& comparacoes, long long int& movimentacoes, string endereco) {
    int* vetor = new int[tamanho];
    comparacoes = 0;
    movimentacoes = 0;
    
    cout << "Organizando: " << tamanho << endl;
    lerArquivo(vetor, endereco, tamanho);
    double inicio = clock();
    quickSort(vetor, 0, tamanho-1, comparacoes, movimentacoes);
    double fim = (clock() - inicio) / CLOCKS_PER_SEC;

    delete[] vetor;
    return fim;
}

void gerarResultados(double tempos[], long long int comparacoes[], long long int movimentacoes[], string tipoArquivo, int instancias, int tamanho, string nomeMetodo) {
    string endereco = "./" + nomeMetodo + tipoArquivo + ".csv";
    ofstream arqSaida(endereco);
    
    arqSaida << ";Tempo;Comparacoes;Movimentacoes" << endl << ";";
    arqSaida << nomeMetodo; arqSaida << ";"; arqSaida << nomeMetodo; arqSaida << ";"; arqSaida << nomeMetodo; arqSaida << endl;

    for(int i = 0; i < instancias; i++) {
        arqSaida << tamanho << ";"; arqSaida << tempos[i]; arqSaida << ";"; arqSaida << comparacoes[i]; arqSaida << ";"; arqSaida << movimentacoes[i]; arqSaida << endl;
        tamanho *= 10;
    }
}

int main() {
    
    int tamanho = TAMANHO_INICIAL;

    long long int movimentacoes = 0, comparacoes = 0;

    // ListaAleatoria
    // ListaInversamenteOrdenada
    // ListaOrdenada
    // ListaQuaseOrdenada

    // DicionarioAleatorio
    // DicionarioInversamenteOrdenado
    // DicionarioOrdenado

    string tipoArquivo = "ListaInversamenteOrdenada";
    string endereco;
    
    double tempos[INSTANCIAS];
    long long int vComparacoes[INSTANCIAS];
    long long int vMovimentacoes[INSTANCIAS];

    for(int j = 0; j < INSTANCIAS; j++) {
        endereco = tipoArquivo + "-" + to_string(tamanho) + ".txt";
        tempos[j] = 0;

        for(int i = 0; i < QUANTIDADE_TESTES; i++) {
            tempos[j] += testarFuncao(tamanho, comparacoes, movimentacoes, endereco);
        }

        tempos[j] /= QUANTIDADE_TESTES;
        vComparacoes[j] = comparacoes;
        vMovimentacoes[j] = movimentacoes;

        tamanho *= 10;
    }

    gerarResultados(tempos, vComparacoes, vMovimentacoes, tipoArquivo, INSTANCIAS, TAMANHO_INICIAL, "QuickSort");
    
    return 0;
}