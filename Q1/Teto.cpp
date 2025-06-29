#include <iostream>
using namespace std;

int teto(float num) {
    int resultado = 0;

    if (num >= 0) {
        // Para positivos: subir até resultado >= num
        while (resultado < num) { // 0 < 3.7? res = 1
            resultado++;          // 1 < 3.7? res = 2
                                  // 2 < 3.7? res = 3
                                  // 3 < 3.7? res = 4
                                  // 4 < 3.7? para
        }
    } else {
        // Para negativos: descer até resultado - 1 < num
        while (resultado - 1 >= num) { // -1 >= -3.7? res = -1
            resultado--;               // -2 >= -3.7? res = -2
                                       // -3 >= -3.7? res = -3
                                       // -4 >= -3.7? para
        }                             
    }

    return resultado;
}

int main() {
    float valor;

    cout << "Digite um número para encontrar o teto: ";
    cin >> valor;

    cout << "teto(" << valor << ") = " << teto(valor) << endl;

    return 0;
}
