#include <iostream>
#include "FuncoesMain.cpp"

using namespace std;

int main() {
    int opcao;

    do {
        do {
            imprimeMenu();
            cin >> opcao;
            system("cls");
        }while(opcao < 1 || opcao > 5);

        switch(opcao) {
            case 1:
                cadastrarFuncionario();
            break;

            case 2:
                buscarFuncionario();
            break;

            case 3:
                removerFuncionario();
            break;

            case 4:
                imprimeArvore(arvoreID);
            break;
        }
        if(opcao != 5) {
            cout << endl << "Voltando ao menu principal..." << endl << endl;
            system("pause");
            system("cls");
        }
    }while(opcao != 5);
    return 0;
}