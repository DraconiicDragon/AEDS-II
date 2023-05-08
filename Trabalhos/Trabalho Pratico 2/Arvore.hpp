#ifndef ARVORE
#define ARVORE

#include <iostream>

using namespace std;

// Funcionario
struct Item {
    int id;
    string nome;
};

// Nó da árvore
struct Arvore
{
    Item item;
    Arvore* esquerda;
    Arvore* direita;
};

typedef Arvore* TipoNo;

// Árvore organizada com base no cpf
TipoNo arvoreID = NULL;

// Árvore organizada com base no nome
TipoNo arvoreNome = NULL;

// Insere o item na arvoreID
bool insereItemID(Item item);
bool insereItemNome(Item item);

// Pega o antecessor do item removido
void Antecessor(TipoNo q, TipoNo* r);

// Remove o item com base no cpf
void removeItemPorID(TipoNo* atual, int id);

// Remove o item com base no nome
void removeItemPorNome(TipoNo* atual, string nome);

// Imprime a árvore
void imprimeArvore(TipoNo atual);

#endif