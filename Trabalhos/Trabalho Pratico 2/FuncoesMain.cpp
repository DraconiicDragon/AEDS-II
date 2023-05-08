#include "FuncoesMain.hpp"
#include "Arvore.cpp"

void imprimeMenu() {
    cout << "---------------------------" << endl;
    cout << " 1 - Cadastrar Funcionario" << endl;
    cout << " 2 - Buscar Funcionario" << endl;
    cout << " 3 - Remover Funcionario" << endl;
    cout << " 4 - Imprimir" << endl;
    cout << " 5 - Sair" << endl;
    cout << "---------------------------" << endl;
    cout << "Escolha uma opcao: ";
}

void cadastrarFuncionario() {
    Item funcionario;

    system("cls");
    cout << "Digite o cpf do funcionario: ";
    cin >> funcionario.id;
    cout << "Digite o nome do funcionario: ";
    cin >> funcionario.nome;

    system("cls");
    if(insereItemID(funcionario) && insereItemNome(funcionario)) {
        cout << "Funcionario inserido com sucesso!" << endl;
    } else {
        cout << "Erro ao inserir funcionario ou funcionario ja esta cadastrado no sistema" << endl;
    }
}

void buscarFuncionario() {
    int id;
    string nome;

    int opcao;

    do {
        system("cls");
        cout << "---------------------" << endl;
        cout << " 1 - Buscar por CPF" << endl;
        cout << " 2 - Buscar por Nome" << endl;
        cout << "---------------------" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;
    } while(opcao != 1 && opcao != 2);

    TipoNo aux;

    if(opcao == 1) {
        cout << "Digite o CPF do funcionario: ";
        cin >> id;
        aux = pesquisaPorID(arvoreID, id);
    } else {
        cout << "Digite o nome do funcionario: ";
        cin >> nome;
        aux = pesquisaPorNome(arvoreNome, nome);
    }
    system("cls");
    if(aux == NULL) {
        cout << "Funcionario nao encontrado!" << endl;
    } else {
        imprimeItem(aux->item);
    }
}

void removerFuncionario() {
    int id;
    string nome;

    int opcao;

    do {
        system("cls");
        cout << "---------------------" << endl;
        cout << " 1 - Remover por CPF" << endl;
        cout << " 2 - Remover por Nome" << endl;
        cout << "---------------------" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;
    } while(opcao != 1 && opcao != 2);

    TipoNo aux;

    system("cls");
    if(opcao == 1) {
        cout << "Digite o CPF do funcionario: ";
        cin >> id;
        aux = pesquisaPorID(arvoreID, id);
    } else {
        cout << "Digite o nome do funcionario: ";
        cin >> nome;
        aux = pesquisaPorNome(arvoreNome, nome);
    }
    
    system("cls");
    if(aux == NULL) {
        cout << "Funcionario nao encontrado!" << endl;
    } else {
        removeItemPorID(&arvoreID, aux->item.id);
        removeItemPorNome(&arvoreID, aux->item.nome);
        cout << "Funcionario removido com sucesso!" << endl;
    }
}