#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definir tamaño del tablero
const int FILAS = 10;
const int COLUMNAS = 10;

// Función para imprimir el tablero
void imprimirTablero() {
    for (int i = 0; i < FILAS; ++i) {
        for (int j = 0; j < COLUMNAS; ++j) {
            cout << ((i == 0 && j == 0) ? "E" :
                     (i == FILAS - 1 && j == COLUMNAS - 1) ? "S" : ".") << " ";
        }
        cout << endl;
    }
}

// Función para convertir coordenadas en un índice del grafo
int obtenerIndice(int fila, int columna) {
    return fila * COLUMNAS + columna;
}

// Función BFS para recorrer el tablero
void bfs(int fila_inicio, int columna_inicio) {
    vector<bool> visitado(FILAS * COLUMNAS, false);
    queue<int> cola;

    int inicio = obtenerIndice(fila_inicio, columna_inicio);
    visitado[inicio] = true;
    cola.push(inicio);

    while (!cola.empty()) {
        int nodo_actual = cola.front();
        cola.pop();

        // Convertir índice a coordenadas
        int fila_actual = nodo_actual / COLUMNAS;
        int columna_actual = nodo_actual % COLUMNAS;

        cout << "(" << fila_actual << ", " << columna_actual << ") "; // Mostrar posición explorada

        // Explorar vecinos (arriba, abajo, izquierda, derecha)
        vector<pair<int, int>> vecinos = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (const auto& vecino : vecinos) {
            int dx = vecino.first;
            int dy = vecino.second;

            int nueva_fila = fila_actual + dx;
            int nueva_columna = columna_actual + dy;

            if (nueva_fila >= 0 && nueva_fila < FILAS &&
                nueva_columna >= 0 && nueva_columna < COLUMNAS) {
                int vecinoIdx = obtenerIndice(nueva_fila, nueva_columna);
                if (!visitado[vecinoIdx]) {
                    visitado[vecinoIdx] = true;
                    cola.push(vecinoIdx);
                }
            }
        }
    }
}

int main() {
    // Imprimir el tablero
    cout << "Tablero:" << endl;
    imprimirTablero();

    // Realizar BFS desde la posición (0,0)
    cout << "\nRecorrido BFS desde (0,0): ";
    bfs(0, 0);
    cout << endl;

    return 0;
}

