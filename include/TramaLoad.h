/**
 * @file TramaLoad.h
 * @brief Implementación de la trama de carga (L,X).
 */

#ifndef TRAMALOAD_H
#define TRAMALOAD_H
#include "TramaBase.h"
#include "ListaDeCarga.h"
#include "RotorDeMapeo.h"
#include <cstdio>

/**
 * @class TramaLoad
 * @brief Representa una trama "L,X" que contiene un carácter a decodificar.
 */
class TramaLoad : public TramaBase {
private:
    char dato;
public:
    explicit TramaLoad(char d): dato(d) {}

    void procesar(ListaDeCarga* carga, RotorDeMapeo* rotor) override {
        char dec = rotor->getMapeo(dato);
        printf("Procesando Trama LOAD -> Fragmento '%c' decodificado como '%c'.\n", dato, dec);
        carga->insertarAlFinal(dec);
    }

    ~TramaLoad() override {}
};

#endif // TRAMALOAD_H
