#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int ExponenciacaoModular(int b, int n, int m) {
    int x = 1;
    int power = b % m;

    while (n > 0) {
        if (n % 2 == 1)
            x = (x * power) % m;
        power = (power * power) % m;
        n = n / 2;
    }

    return x;
}

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int mdcEstendido(int a, int b, int &s, int &t) {
    if (b == 0) {
        s = 1; t = 0;
        return a;
    }
    int s1, t1;
    int mdc = mdcEstendido(b, a % b, s1, t1);
    s = t1;
    t = s1 - (a / b) * t1;
    return mdc;
}

// Encripta o texto 
string encriptar(const string &texto, int e, int n) {
    string textoCriptografado = "";
    for (char c : texto) {
        int caractere = (int)c;
        if (caractere >= n) {
            cerr << "Erro: caractere '" << c << "' com valor " << caractere << " é maior que n = " << n << endl;
            return "";
        }
        int caractereCriptografado = ExponenciacaoModular(caractere, e, n);
        textoCriptografado += to_string(caractereCriptografado) + " ";
    }
    return textoCriptografado;
}

// Decripta o texto 
string decriptar(const string &textoCriptografado, int d, int n) {
    string textoDescriptografado = "";
    string bloco = "";
    for (char c : textoCriptografado) {
        if (c != ' ') {
            bloco += c;
        } else {
            if (!bloco.empty()) {
                int caractere = stoi(bloco);
                int m = ExponenciacaoModular(caractere, d, n);
                textoDescriptografado += (char)m;
                bloco = "";
            }
        }
    }
    // Para o último bloco, se houver
    if (!bloco.empty()) {
        int caractere = stoi(bloco);
        int m = ExponenciacaoModular(caractere, d, n);
        textoDescriptografado += (char)m;
    }
    return textoDescriptografado;
}

int main() {
    int p, q;
    cout << "Digite dois numeros primos p e q: " << endl;
    cin >> p >> q;

    if (!isPrime(p) || !isPrime(q)) {
        cout << "Erro: ambos os números devem ser primos!" << endl;
        return 1;
    }

    int n = p * q;
    int phi = (p - 1) * (q - 1);

    if (n <= 127) {
        cout << "Erro: n = " << n << " é muito pequeno. Escolha primos maiores." << endl;
        return 1;
    }

    int e;
    for (e = 2; e < phi; e++) {
        int s, t;
        if (mdcEstendido(e, phi, s, t) == 1)
            break;
    }

    int s, t;
    mdcEstendido(e, phi, s, t);
    int d = (s % phi + phi) % phi;

    cout << "Valor de n: " << n << endl;
    cout << "Chave pública (e): " << e << endl;
    cout << "Chave privada (d): " << d << endl;

    cin.ignore();
    string texto;
    cout << endl << "Digite o texto para criptografar: " << endl;
    getline(cin, texto);

    string textoCriptografado = encriptar(texto, e, n);
    if (textoCriptografado == "") return 1;

    cout << endl << "Texto criptografado : " << textoCriptografado << endl;

    string textoDescriptografado = decriptar(textoCriptografado, d, n);
    cout << endl << "Texto descriptografado: " << textoDescriptografado << endl;

    return 0;
}