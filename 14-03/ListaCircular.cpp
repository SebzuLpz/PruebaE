#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};
class ListaEnlazadaCircular {
private:
    Nodo* cabeza;
public:
    ListaEnlazadaCircular() {
        cabeza = nullptr;
    }
    ~ListaEnlazadaCircular() {
        if (cabeza != nullptr) {
            Nodo* actual = cabeza;
            Nodo* siguiente = cabeza->siguiente;
            while (siguiente != cabeza) {
                delete actual;
                actual = siguiente;
                siguiente = siguiente->siguiente;
            }
            delete actual;
        }
    }
    void agregarElemento(int valor) {
        Nodo* NodoNuevo = new Nodo;
        NodoNuevo->dato = valor;
        if (cabeza == nullptr) {
            cabeza = NodoNuevo;
            cabeza->siguiente = cabeza;
        } else {
            Nodo* ultimo = cabeza;
            while (ultimo->siguiente != cabeza) {
                ultimo = ultimo->siguiente;
            }
            NodoNuevo->siguiente = cabeza;
            ultimo->siguiente = NodoNuevo;
        }
    }
    void imprimirLista() {
        if (cabeza != nullptr) {
            Nodo* actual = cabeza;
            do {
                cout << actual->dato << " ";
                actual = actual->siguiente;
            } while (actual != cabeza);
            cout << endl;
        }
    }
};
int main() {
    ListaEnlazadaCircular lista;
    int valor;
    cout << "Ingrese valores enteros para agregar a la lista (-1 para terminar):\n";
    cin >> valor;
    while (valor != -1) {
        lista.agregarElemento(valor);
        cin >> valor;
    }
    cout << "Lista enlazada circular:\n" << endl;
    lista.imprimirLista();
    return 0;
}
