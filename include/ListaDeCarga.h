/**
 * @file ListaDeCarga.h
 * @brief Implementación manual de una lista doblemente enlazada
 *        para almacenar los fragmentos decodificados.
 */

#ifndef LISTADECARGA_H
#define LISTADECARGA_H
#include <cstdio>

/**
 * @struct NodoCarga
 * @brief Nodo de la lista doblemente enlazada que almacena un carácter.
 */
struct NodoCarga {
    char dato;
    NodoCarga* prev;
    NodoCarga* next;
    NodoCarga(char d): dato(d), prev(nullptr), next(nullptr) {}
};

/**
 * @class ListaDeCarga
 * @brief Lista doblemente enlazada para almacenar caracteres decodificados.
 */
class ListaDeCarga {
private:
    NodoCarga* head;
    NodoCarga* tail;

public:
    ListaDeCarga(): head(nullptr), tail(nullptr) {}
    ~ListaDeCarga();

    /**
     * @brief Inserta un carácter al final de la lista.
     */
    void insertarAlFinal(char dato);

    /**
     * @brief Imprime el mensaje completo en formato [H][O][L][A] y luego el texto plano.
     */
    void imprimirMensaje();
};

#endif // LISTADECARGA_H
