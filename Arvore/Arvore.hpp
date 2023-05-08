#ifndef ARVORE
#define ARVORE

#include <iostream>

using namespace std;

struct Item {
    int id;
    string nome;
};

struct Arvore
{
    Item item;
    Arvore* esquerda;
    Arvore* direita;
};

typedef Arvore* TipoNo;
TipoNo arvoreID = NULL;
TipoNo arvoreNome = NULL;

bool insereItemID(Item item);
void Antecessor(TipoNo q, TipoNo* r);
void removeItemPorID(TipoNo* atual, int id);
bool insereItemNome(Item item);
void removeItemPorNome(TipoNo* atual, string nome);
void imprimeArvore(TipoNo atual);

#endif