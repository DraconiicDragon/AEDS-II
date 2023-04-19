#include <iostream>

using namespace std;

void funcao_a(int v[], int n)
{
    int i, j, x;
    for (i = 1; i < n; i++)
    {
        x = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > x)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = x;
        for (int k = 0; k < n; k++)
        {
            cout << v[k] << " ";
        }
        cout << endl;
    }
}

void funcao_b(int v[], int n)
{
    int i, j, aux, min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (v[j] < v[min])
            {
                min = j;
            }
        }
        aux = v[i];
        v[i] = v[min];
        v[min] = aux;
        for (int k = 0; k < n; k++)
        {
            cout << v[k] << " ";
        }
        cout << endl;
    }
}

void funcao_c(string v)
{
    int i, j, aux;
    int n = v.size();
    for (i = n - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (v[j] > v[j + 1])
            {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }   
}

int main()
{
    string nome = "amogus";
    funcao_c(nome);

    return 0;
}