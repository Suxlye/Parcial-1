#include <iostream>
#include <vector>
#include <list>
#include <algorithm> // std::sort, std::find
using namespace std;

int main() {
    // -------------------- DATOS PERSONALES --------------------
    // Nombre: Elmer Estanley García Amaya
    // Autoevaluación: 8

    // -------------------- PARTE 1: VECTOR DE TEMPERATURAS --------------------
    int dias;
    cout << "¿Cuantos dias desea registrar temperaturas? ";
    cin >> dias;

    vector<float> temperaturas(dias);

    for (int i = 0; i < dias; i++) {
        cout << "Ingrese la temperatura del dia " << i + 1 << ": ";
        cin >> temperaturas[i];
    }

    // -------------------- PARTE 2: MOSTRAR CON PUNTEROS --------------------
    float suma = 0;
    float *ptr = &temperaturas[0]; // puntero al inicio del vector

    cout << "\n--- Temperaturas registradas ---\n";
    for (int i = 0; i < dias; i++) {
        cout << "Dia " << i + 1 << ": " << *(ptr + i) << "°C\n";
        suma += *(ptr + i);
    }

    float promedio = suma / dias;
    cout << "Temperatura promedio: " << promedio << "°C\n";

    // -------------------- PARTE 3: BUSQUEDA SECUENCIAL --------------------
    float buscada;
    bool encontrada = false;
    cout << "\nIngrese una temperatura a buscar: ";
    cin >> buscada;

    for (int i = 0; i < dias; i++) {
        if (temperaturas[i] == buscada) {
            cout << "Temperatura encontrada en la posicion " << i << " (Dia " << i + 1 << ")\n";
            encontrada = true;
            break;
        }
    }
    if (!encontrada) {
        cout << "La temperatura " << buscada << " no se encuentra en el registro.\n";
    }

    // -------------------- PARTE 4: ORDENAR TEMPERATURAS --------------------
    sort(temperaturas.begin(), temperaturas.end());

    cout << "\n--- Temperaturas ordenadas (menor a mayor) ---\n";
    for (float t : temperaturas) {
        cout << t << "°C ";
    }
    cout << "\n";

    // -------------------- PARTE 5: LISTA DE EQUIPOS --------------------
    list<string> equipos;
    int n;
    cout << "\n¿Cuantos equipos desea registrar? ";
    cin >> n;

    cin.ignore(); // limpiar buffer
    for (int i = 0; i < n; i++) {
        string equipo;
        cout << "Ingrese el nombre del equipo " << i + 1 << ": ";
        getline(cin, equipo);
        equipos.push_back(equipo);
    }

    // Mostrar lista de equipos con iterador
    cout << "\n--- Lista de equipos ---\n";
    for (auto it = equipos.begin(); it != equipos.end(); it++) {
        cout << *it << "\n";
    }

    // Buscar un equipo
    string buscarEquipo;
    cout << "\nIngrese el nombre de un equipo a buscar: ";
    getline(cin, buscarEquipo);

    auto it = find(equipos.begin(), equipos.end(), buscarEquipo);
    if (it != equipos.end()) {
        cout << "Equipo encontrado: " << *it << "\n";
    } else {
        cout << "El equipo no se encuentra en la lista.\n";
    }

    // Ordenar equipos
    equipos.sort();
    cout << "\n--- Equipos ordenados ---\n";
    for (const string &e : equipos) {
        cout << e << "\n";
    }

    // Eliminar un equipo
    string eliminar;
    cout << "\nIngrese el nombre de un equipo a eliminar: ";
    getline(cin, eliminar);

    equipos.remove(eliminar);

    cout << "\n--- Lista final de equipos ---\n";
    for (const string &e : equipos) {
        cout << e << "\n";
    }

    return 0;
}
