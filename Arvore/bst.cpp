#include <iostream>
#include <windows.h>

using namespace std;

typedef struct No
{
    int valor;
    No *esq;
    No *dir;
};

No *raiz = NULL;

void insere(int valor)
{
    No *novo = new No;
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    if (raiz == NULL)
    {
        raiz = novo;
    }
    else
    {
        No *atual = raiz;
        No *anterior = NULL;
        while (atual != NULL)
        {
            anterior = atual;
            if (valor < atual->valor)
            {
                atual = atual->esq;
            }
            else
            {
                atual = atual->dir;
            }
        }
        if (valor < anterior->valor)
        {
            anterior->esq = novo;
        }
        else
        {
            anterior->dir = novo;
        }
    }
}

void imprime(No *atual)
{
    if (atual != NULL)
    {
        imprime(atual->esq);
        cout << atual->valor << " ";
        imprime(atual->dir);
    }
}

void imprimePosOrdem(No *atual)
{
    if (atual != NULL)
    {
        imprimePosOrdem(atual->esq);
        imprimePosOrdem(atual->dir);
        cout << atual->valor << " ";
    }
}

void imprimePreOrdem(No *atual)
{
    if (atual != NULL)
    {
        cout << atual->valor << " ";
        imprimePreOrdem(atual->esq);
        imprimePreOrdem(atual->dir);
    }
}

int main()
{
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);

    insere(5);
    insere(3);
    insere(7);

    cout << "Imprimindo em ordem: ";
    imprime(raiz);
    cout << "\nImprimindo pré-ordem: ";
    imprimePreOrdem(raiz);
    cout << "\nImprimindo pós-ordem: ";
    imprimePosOrdem(raiz);

    cout << endl;
    return 0;
}