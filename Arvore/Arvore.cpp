#include <iostream>

using namespace std;
     
struct Item {

    int num;
};

struct Arvore
{
    Item item;
    Arvore* esquerda;
    Arvore* direita;
};

typedef Arvore* TipoNo;

bool insereItem(TipoNo raiz, Item item) {

    if(raiz == NULL) {
        TipoNo novo = new Arvore;
        novo->item = item;
        novo->direita = NULL;
        novo->esquerda = NULL;
        raiz = novo;
        return true;
    }

    if(item.num < raiz->item.num) {
        insereItem(raiz->esquerda, item);
    }
    if(item.num > raiz->item.num) {
        insereItem(raiz->direita, item);
    }

    return false;
}



