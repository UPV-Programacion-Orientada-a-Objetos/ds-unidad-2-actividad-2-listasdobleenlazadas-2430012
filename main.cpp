#include <iostream>
#include <fstream>
#include <cstring>   // strtok, atoi
#include "TramaBase.h"
#include "TramaLoad.h"
#include "TramaMap.h"
#include "ListaDeCarga.h"
#include "RotorDeMapeo.h"

using namespace std;

int main() {
    cout << "=== DECODIFICADOR PRT-7 ===" << endl;
    cout << "Conectando a puerto COM simulado..." << endl;

    // --- Inicialización de estructuras principales ---
    ListaDeCarga lista;
    RotorDeMapeo rotor;

    cout << "Conexión establecida. Esperando tramas...\n" << endl;

    // --- Simulación de lectura desde archivo (o podría ser el puerto serial real) ---
    // Si tu profesor usa Arduino, puedes reemplazar "tramas.txt" por "/dev/ttyUSB0" o "COM3"
    ifstream serialInput("tramas.txt"); 

    if (!serialInput.is_open()) {
        cerr << "Error: no se pudo abrir el flujo de datos (tramas.txt o puerto COM)." << endl;
        return 1;
    }

    char linea[64];
    while (serialInput.getline(linea, sizeof(linea))) {
        if (strlen(linea) == 0) continue; // Línea vacía, saltar

        cout << "Trama recibida: [" << linea << "] -> Procesando... ";

        // Parseo de la trama manualmente (sin std::string)
        char *tipo = strtok(linea, ",");
        char *valor = strtok(nullptr, ",");

        if (!tipo || !valor) {
            cout << "Trama malformada, ignorada." << endl;
            continue;
        }

        TramaBase *trama = nullptr;

        if (tipo[0] == 'L') {
            // Trama de carga (LOAD)
            char dato = valor[0];
            trama = new TramaLoad(dato);
        }
        else if (tipo[0] == 'M') {
            // Trama de mapeo (MAP)
            int desplazamiento = atoi(valor);
            trama = new TramaMap(desplazamiento);
        }
        else {
            cout << "Tipo de trama desconocido, ignorada." << endl;
            continue;
        }

        // Procesar la trama
        trama->procesar(&lista, &rotor);

        // Liberar memoria de la trama
        delete trama;
    }

    serialInput.close();

    cout << "\n---" << endl;
    cout << "Flujo de datos terminado." << endl;
    cout << "MENSAJE OCULTO ENSAMBLADO:" << endl;
    lista.imprimirMensaje();
    cout << "\n---" << endl;
    cout << "Liberando memoria... Sistema apagado." << endl;

    return 0;
}
