#include <iostream>
#include <string>
#include <sstream>
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
        s = 1;
        t = 0;
        return a;
    }
    int s1, t1;
    int mdc = mdcEstendido(b, a % b, s1, t1);
    s = t1;
    t = s1 - (a / b) * t1;
    return mdc;
}

// encriptar texto
string encriptar(const string &texto, int e, int n) {
    ostringstream oss;
    for (char c : texto) {
        int ascii = static_cast<unsigned char>(c); // Garante que não fique negativo
        if (ascii >= n) {
            cerr << "Erro: caractere '" << c << "' com valor ASCII " << ascii
                 << " é maior ou igual a n = " << n << endl;
            return "";
        }
        int criptografado = ExponenciacaoModular(ascii, e, n);
        oss << criptografado << " ";
    }
    return oss.str();
}

// decriptar texto
string decriptar(const string &textoCriptografado, int d, int n) {
    istringstream iss(textoCriptografado);
    int num;
    string resultado = "";

    while (iss >> num) {
        char c = static_cast<char>(ExponenciacaoModular(num, d, n));
        resultado += c;
    }

    return resultado;
}

int main() {
    int p, q;
    cout << "Digite dois primos (p e q): ";
    cin >> p >> q;

    if (!isPrime(p) || !isPrime(q)) {
        cout << "Erro: ambos os números devem ser primos.\n";
        return 1;
    }

    int n = p * q;
    int phi = (p - 1) * (q - 1);

    if (n <= 255) {
        cout << "Erro: n = " << n << " é muito pequeno. Escolha primos maiores que resultem em n > 255.\n";
        return 1;
    }

    int e = 3, s, t;
    while (e < phi) {
        if (mdcEstendido(e, phi, s, t) == 1)
            break;
        e++;
    }

    mdcEstendido(e, phi, s, t);
    int d = (s % phi + phi) % phi;

    cout << "\nn = " << n << "\n";
    cout << "Chave pública (e): " << e << endl ;
    cout << "Chave privada (d): " << d << endl;

    cin.ignore();
    string texto;
    cout << "\nDigite o texto para criptografar: ";
    getline(cin, texto);

    string textoCriptografado = encriptar(texto, e, n);
    if (textoCriptografado.empty()) return 1;

    cout << "\nTexto criptografado: " << textoCriptografado << endl;

    string textoDecriptado = decriptar(textoCriptografado, d, n);
    cout << "Texto decriptado: " << textoDecriptado << endl;

    return 0;
}

