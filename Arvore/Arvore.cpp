#include "Arvore.hpp"

bool insereItemID(Item item) {
    TipoNo novo = new Arvore;
    novo->item = item;
    novo->direita = NULL;
    novo->esquerda = NULL;

    if(arvoreID == NULL) {
        arvoreID = novo;
        return true;
    }

    TipoNo anterior;
    TipoNo atual = arvoreID;

    while(atual != NULL) {
        anterior = atual;
        if(item.id < atual->item.id) {
            atual = atual->esquerda;
        } else if(item.id > atual->item.id) {
            atual = atual->direita;
        }
    }

    if(novo->item.id < anterior->item.id) {
        anterior->esquerda = novo;
        return true;
    }
    if(novo->item.id > anterior->item.id) {
        anterior->direita = novo;
        return true;
    }
    return false;
}

void Antecessor(TipoNo q, TipoNo* r) {
    if((*r)->direita != NULL) {
        Antecessor(q, &(*r)->direita);
        return;
    }
    q->item = (*r)->item;
    q = *r;
    *r = (*r)->esquerda;
    delete q;
}

void removeItemPorID(TipoNo* atual, int id) {
    TipoNo aux;
    if(*atual == NULL) {
        return;
    }
    if(id < (*atual)->item.id) {
        removeItemPorID(&(*atual)->esquerda, id);
        return;
    }
    if(id > (*atual)->item.id) {
        removeItemPorID(&(*atual)->direita, id);
        return;
    }
    if((*atual)->direita == NULL) {
        aux = *atual;
        *atual = (*atual)->esquerda;
        delete aux;
        return;
    }
    if((*atual)->esquerda != NULL) {
        Antecessor(*atual, &(*atual)->esquerda);
        return;
    }
    aux = *atual;
    *atual = (*atual)->direita;
    delete atual;
}

bool insereItemNome(Item item) {
    TipoNo novo = new Arvore;
    novo->item = item;
    novo->direita = NULL;
    novo->esquerda = NULL;

    if(arvoreNome == NULL) {
        arvoreNome = novo;
        return true;
    }

    TipoNo anterior;
    TipoNo atual = arvoreNome;

    while(atual != NULL) {
        anterior = atual;
        if(item.nome < atual->item.nome) {
            atual = atual->esquerda;
        } else if(item.nome > atual->item.nome) {
            atual = atual->direita;
        }
    }

    if(novo->item.nome < anterior->item.nome) {
        anterior->esquerda = novo;
        return true;
    }
    if(novo->item.nome > anterior->item.nome) {
        anterior->direita = novo;
        return true;
    }
    return false;
}

void removeItemPorNome(TipoNo* atual, string nome) {
    TipoNo aux;
    if(*atual == NULL) {
        return;
    }
    if(nome < (*atual)->item.nome) {
        removeItemPorNome(&(*atual)->esquerda, nome);
        return;
    }
    if(nome > (*atual)->item.nome) {
        removeItemPorNome(&(*atual)->direita, nome);
        return;
    }
    if((*atual)->direita == NULL) {
        aux = *atual;
        *atual = (*atual)->esquerda;
        delete aux;
        return;
    }
    if((*atual)->esquerda != NULL) {
        Antecessor(*atual, &(*atual)->esquerda);
        return;
    }
    aux = *atual;
    *atual = (*atual)->direita;
    delete atual;
}

void imprimeArvore(TipoNo atual) {
    if(atual != NULL) {
        imprimeArvore(atual->esquerda);
        cout << atual->item.id << " " << atual->item.nome << endl;
        imprimeArvore(atual->direita);
    }
}