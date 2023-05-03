#include <iostream>
#include "Arvore.cpp"

using namespace std;

int main() {
    TipoNo raiz = NULL;

    Item item;
    item.num = 10;
    insereItem(raiz, item);

    // item.num = 5;
    // insereItem(raiz, item);

    // item.num = 15;
    // insereItem(raiz, item);

    cout << raiz->item.num << endl;
    // cout << raiz->esquerda->item.num << " " << raiz->direita->item.num;

    return 0;
}