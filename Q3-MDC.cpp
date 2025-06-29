#include <iostream>
using namespace std;

int calcularMDC(int a, int b) {
    cout << "\nAlgoritmo de Euclides - " << a << " e " << b << ":\n";

    // Troco os valores para garantir que o menor divida o maior
    if (b > a) {
        int temp = a;
        a = b;
        b = temp;
    }

    while (b != 0) {
        int resto = a % b;
        cout << a << " % " << b << " = " << resto << endl;
        a = b;
        b = resto;
    }

    cout << "\nMDC: " << a << endl;
    return a;
}

int main() {
    int num1, num2;

    cout << "Digite dois números inteiros: ";
    cin >> num1 >> num2;

    calcularMDC(num1, num2);

    return 0;
}
