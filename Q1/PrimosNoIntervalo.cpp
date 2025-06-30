#include <iostream>
using namespace std;

// Função que verifica se um número é primo
bool isPrime(int num) {
    if (num <= 1) return false; // números <= 1 não são primos
    for (int i = 2; i < num; i++) {
        if (num % i == 0) return false; // encontrou divisor, não é primo
    }
    return true; // não encontrou divisor, é primo
}

// Função que imprime todos os primos no intervalo dado
void Range(int start, int end) {
    for (int i = start; i <= end; i++) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int start, end;

    cout << "Digite o início do intervalo: ";
    cin >> start;

    cout << "Digite o end do intervalo: ";
    cin >> end;

    cout << "Primos entre " << start << " e " << end << ": ";
    Range(start, end);

    return 0;
}