#include <iostream>
#include <ctime>

using namespace std;
bool is_sorted(int *vector, int n)
{
    while (--n >= 1)
    {
        if (vector[n] < vector[n - 1])
            return false;
    }
    return true;
}

void shuffle(int *vector, int n)
{
    int position, random;
    for (int i = 0; i < n; i++)
    {
        position = vector[i];
        random = rand() % n;
        vector[i] = vector[random];
        vector[random] = position;
    }
}

void bogosort(int *vector, int n)
{
    while (!is_sorted(vector, n))
        shuffle(vector, n);
}

void print_vector(int *vector, int n) {
    for(int i = 0; i < n; i++) {
        cout << vector[i] << " ";
    }
}

void create_vector(int* vector, int n) {
    srand(time(NULL));
    for(int i = 0; i < n; i++) {
        vector[i] = rand() % n;
    }
}

void menu() {
    cout << "1. vetor tamanho 10" << endl;
    cout << "2. vetor tamanho 11" << endl;
    cout << "3. vetor tamanho 12" << endl;
    cout << "4. vetor tamanho 15" << endl;
    cout << "5. sair" << endl;
    cout << "escolha: ";
}

int main() {
    int num;
    int* vector;
    int tamanho;
    menu();
    cin >> num;
    system("cls");
    switch(num) {
        case 1:
            vector = new int[10];
            tamanho =10;
            break;
        case 2:
            vector = new int[11];
            tamanho =11;
            break;
        case 3:
            vector = new int[12];
            tamanho =12;
            break;
        case 4:
            vector = new int[15];
            tamanho =15;
            break;
    }
    cout << "Organizando Vetor" << endl;
    create_vector(vector, tamanho);
    double before = clock();
    bogosort(vector, tamanho);
    system("cls");
    cout << "Vetor ordenado: " << endl;
    print_vector(vector, tamanho);
    cout << endl << "tempo: " << (clock() - before) / CLOCKS_PER_SEC << "s";
    delete[] vector;

    return 0;
}