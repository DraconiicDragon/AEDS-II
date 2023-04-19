#include "FuncoesMain.cpp"

// Faz o controle dos menus
int main() {

    int opcaoMetodo, opcaoInstancia, tamanhoVetor;
    string endereco;

    // Loop princinpal
    do {

        // Loop do menu de métodos, garante que um número aceito será digitado
        do {
            imprimirMenuMetodos();
            cin >> opcaoMetodo;
            system("cls");
        }while(opcaoMetodo < 1 || opcaoMetodo > 7);

        // Sair do programa
        if(opcaoMetodo == 7) {
            return 0;
        }

        // Loop do menu de instâncias, garante que um número aceito será digitado
        do {
            imprimirMenuInstancias();
            cin >> opcaoInstancia;
            system("cls");
        }while(opcaoInstancia < 1 || opcaoInstancia > 23);

        // Se a opção escolhida não for voltar para o menu de métodos
        if(opcaoInstancia != 23) {
            tamanhoVetor = definirTamanhoVetor(opcaoInstancia);
            endereco = definirEndereco(opcaoInstancia);
            endereco += "-" + to_string(tamanhoVetor) + ".txt";

            cout << "Ordenando Vetor...";

            // Define se é um vetor de números ou palavras
            if(opcaoInstancia < 7) {
                chamarMetodoEscolhidoString(opcaoMetodo, tamanhoVetor, endereco);
            } else {
                chamarMetodoEscolhidoInteiro(opcaoMetodo, tamanhoVetor, endereco);
            }
        }
        system("pause");
        system("cls");
    } while(opcaoMetodo != 7);

    return 0;
}