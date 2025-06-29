#include <iostream>
using namespace std;

char alfabetoMinus[] = "abcdefghijklmnopqrstuvwxyz";
char alfabetoMais[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string cifrar(string texto, int chave) {
    for (int i = 0; texto[i] != '\0'; i++) {
        bool trocou = false;

        // Procurar letra minúscula
        for (int j = 0; j < 26; j++) {
            if (texto[i] == alfabetoMinus[j]) {
                texto[i] = alfabetoMinus[(j + chave) % 26]; //USAR O MOD Q CRIEI
                trocou = true;
                break;
            }
        }

        if (trocou) continue;

        // Procurar letra maiúscula
        for (int j = 0; j < 26; j++) {
            if (texto[i] == alfabetoMais[j]) {
                texto[i] = alfabetoMais[(j + chave) % 26];
                break;
            }
        }
    }
    return texto;
}

int main() {
    string texto;
    int chave;

    cout << "Digite uma frase: ";
    getline(cin, texto);

    cout << "Digite a chave: ";
    cin >> chave;

    cout << "Texto cifrado: " << cifrar(texto, chave) << endl;

    return 0;
}
