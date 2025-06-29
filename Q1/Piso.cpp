#include <iostream>
using namespace std;

int piso(float num) {
    int resultado = 0;

    if (num >= 0) {
        // Para positivos: descer até resultado + 1 > num
        while (resultado + 1 <= num) { // 1 <= 3.7? res = 1
            resultado++;               // 2 <= 3.7? res = 2
                                       // 3 <= 3.7? res = 3
                                       // 4 <= 3.7? para
        }
    } else {
        // Para negativos: descer até resultado <= num
        while (resultado > num) {      // 0 > -3.7? res = -1
            resultado--;               // -1 > -3.7? res = -2
                                       // -2 > -3.7? res = -3
                                       // -3 > -3.7? res = -4
                                       // -4 > -3.7? para
        }                             
    }

    return resultado;
}

int main() {
    float valor;

    cout << "Digite um número para encontrar o piso: ";
    cin >> valor;

    cout << "piso(" << valor << ") = " << piso(valor) << endl;

    return 0;
}
