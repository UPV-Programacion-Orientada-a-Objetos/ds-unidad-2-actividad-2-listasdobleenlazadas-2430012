/**
 * @file TramaMap.h
 * @brief Implementación de la trama de mapeo (M,N).
 */

#ifndef TRAMAMAP_H
#define TRAMAMAP_H
#include "TramaBase.h"
#include "ListaDeCarga.h"
#include "RotorDeMapeo.h"
#include <cstdio>

/**
 * @class TramaMap
 * @brief Representa una trama "M,N" que indica una rotación del rotor.
 */
class TramaMap : public TramaBase {
private:
    int pasos;
public:
    explicit TramaMap(int p): pasos(p) {}

    void procesar(ListaDeCarga* /*carga*/, RotorDeMapeo* rotor) override {
        printf("Procesando Trama MAP -> ROTAR %d\n", pasos);
        rotor->rotar(pasos);
    }

    ~TramaMap() override {}
};

#endif // TRAMAMAP_H
