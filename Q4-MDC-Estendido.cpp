#include <iostream>
using namespace std;

int mdcEstendido(int a, int b, int &s, int &t) {
    int r1 = a;
    int r2 = b;
    int s1 = 1;
    int s2 = 0;
    int t1 = 0;
    int t2 = 1;

    cout << "R  Q  S  T\n";

    while (r2 != 0) {
        int quociente = r1 / r2;
        int r = r1 - quociente * r2;
        int novoS = s1 - quociente * s2;
        int novoT = t1 - quociente * t2;

        cout << r1 << "  " << quociente << "  " << s1 << "  " << t1 << endl;

        r1 = r2;
        r2 = r;
        s1 = s2;
        s2 = novoS;
        t1 = t2;
        t2 = novoT;
    }

    cout << r1 << "  -  " << s1 << "  " << t1 << endl;

    s = s1;
    t = t1;
    return r1;
}

int main() {
    int a, b;
    cout << "Digite dois numeros: ";
    cin >> a >> b;

    int s, t;
    int resultado = mdcEstendido(a, b, s, t);

    cout << "\nMDC = " << resultado << endl;
    cout << "s = " << s << ", t = " << t << endl;
    cout << resultado << " = " << s << " * " << a << " + " << t << " * " << b << endl;

    return 0;
}
