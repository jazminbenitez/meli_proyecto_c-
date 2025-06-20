#include <iostream>
using namespace std;

int main() {
    int edadGato;
    cout << "¿Cuántos años tiene el gato?: ";
    cin >> edadGato;

    if (edadGato >= 3) {
        cout << "🐾 El gato puede entrar al laberinto. ¡Suerte, minino!" << endl;
    } else {
        cout << "🚫 Muy pequeño para entrar. ¡A seguir practicando!" << endl;
    }

    return 0;
}
