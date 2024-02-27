#include <iostream>
#include <sstream>
using namespace std;

class MetodoInsercion {
private:
    int numeros[50];
    int numDatos;
    string preguntaIteracion;

    void intercambiar(int& a, int& b);
    void mostrarIteracion() const;

public:
    MetodoInsercion();
    void ingresoDeDatos();
    void Insercion();
    void imprimirArreglo() const;
};

void MetodoInsercion::intercambiar(int& a, int& b) {
    int i = a;
    a = b;
    b = i;
}

void MetodoInsercion::mostrarIteracion() const {
    for (int i = 0; i < numDatos; ++i) {
        cout << numeros[i];
        if (i != numDatos - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

MetodoInsercion::MetodoInsercion() {}

void MetodoInsercion::ingresoDeDatos() {
    cout << "METODO DE ORDENACION POR SELECCION" << endl;
    cout << "Ingresa cuantos datos quieres ordenar: ";
    cin >> numDatos;
    cin.ignore(); // limpiar el buffer del salto de línea

    cout << "Ingresa los datos separados por espacios: ";
    string entrada;
    getline(cin, entrada);

    istringstream stream(entrada); // convierte este string a un stream
    int numero;
    int numNumeros = 0; // para ver la cantidad de datos que se ingresaron y poder compararlos

    while (stream >> numero && numNumeros < numDatos) {
        numeros[numNumeros] = numero;
        numNumeros++;
    }

    // Si no hay los datos que el usuario dijo
    if (numNumeros < numDatos) {
        cout << "Faltan datos" << endl;
        numDatos = numNumeros;
    }

    cout << "Quieres ver cada iteracion?";
    cin >> preguntaIteracion;

    // Convertir a minúsculas
    for (char& c : preguntaIteracion) {
        c = tolower(c);
    }
}

void MetodoInsercion::Insercion() {
    int indiceActual, valorActual;
    for (int i = 1; i < numDatos; i++) {
        valorActual = numeros[i];
        indiceActual = i;

        // Mover los elementos del arreglo que son mayores que el valor actual
        // una posición adelante de su posición actual
        while (indiceActual > 0 && numeros[indiceActual - 1] > valorActual) {
            numeros[indiceActual] = numeros[indiceActual - 1];
            indiceActual--;
        }

        // Insertar el valor actual en su posición correcta
        numeros[indiceActual] = valorActual;

        if (preguntaIteracion == "si") {
            mostrarIteracion();
        }
    }
}

void MetodoInsercion::imprimirArreglo() const {
    for (int i = 0; i < numDatos; ++i) {
        cout << numeros[i] << " ";
    }
}

int main() {
    MetodoInsercion ordenamiento;
    ordenamiento.ingresoDeDatos();
    ordenamiento.Insercion();

    cout << endl;
    ordenamiento.imprimirArreglo();
}