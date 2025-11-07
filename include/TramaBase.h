/**
 * @file TramaBase.h
 * @brief Clase base abstracta para todas las tramas del protocolo PRT-7.
 */

#ifndef TRAMABASE_H
#define TRAMABASE_H

class ListaDeCarga;
class RotorDeMapeo;

/**
 * @class TramaBase
 * @brief Interfaz común para las tramas PRT-7.
 *
 * Define la operación polimórfica `procesar()`, implementada
 * por las clases derivadas TramaLoad y TramaMap.
 */
class TramaBase {
public:
    /**
     * @brief Método virtual puro para procesar la trama.
     * @param carga Lista de carga (lista doble) donde se almacenan caracteres decodificados.
     * @param rotor Rotor de mapeo (lista circular) para decodificar o rotar caracteres.
     */
    virtual void procesar(ListaDeCarga* carga, RotorDeMapeo* rotor) = 0;

    /**
     * @brief Destructor virtual obligatorio para liberar memoria correctamente.
     */
    virtual ~TramaBase() {}
};

#endif // TRAMABASE_H
