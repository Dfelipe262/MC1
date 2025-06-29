#include <iostream>
using namespace std;

// Função que verifica se um número é primo
bool ehPrimo(int num) {
    if (num <= 1) return false; // números <= 1 não são primos
    for (int i = 2; i < num; i++) {
        if (num % i == 0) return false; // encontrou divisor, não é primo
    }
    return true; // não encontrou divisor, é primo
}

// Função que imprime todos os primos entre inicio e fim
void primosNoIntervalo(int inicio, int fim) {
    for (int i = inicio; i <= fim; i++) {
        if (ehPrimo(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int inicio, fim;

    cout << "Digite o início do intervalo: ";
    cin >> inicio;

    cout << "Digite o fim do intervalo: ";
    cin >> fim;

    cout << "Primos entre " << inicio << " e " << fim << ": ";
    primosNoIntervalo(inicio, fim);

    return 0;
}