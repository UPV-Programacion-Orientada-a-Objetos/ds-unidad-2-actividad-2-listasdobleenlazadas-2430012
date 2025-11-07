/**
 * @file RotorDeMapeo.h
 * @brief Lista circular doblemente enlazada para mapeo de caracteres A-Z.
 */

#ifndef ROTORDEMAPEO_H
#define ROTORDEMAPEO_H
#include <cstdio>
#include <cctype>

/**
 * @struct NodoRotor
 * @brief Nodo de la lista circular que contiene una letra del alfabeto.
 */
struct NodoRotor {
    char letra;
    NodoRotor* prev;
    NodoRotor* next;
    NodoRotor(char c): letra(c), prev(nullptr), next(nullptr) {}
};

/**
 * @class RotorDeMapeo
 * @brief Representa el “disco de cifrado” tipo César.
 *
 * Implementado como lista circular doblemente enlazada con 26 letras.
 * El puntero `head` indica la posición cero actual.
 */
class RotorDeMapeo {
private:
    NodoRotor* head;
    int size;
    void inicializarAlfabeto();

public:
    RotorDeMapeo();
    ~RotorDeMapeo();

    /**
     * @brief Rota el rotor N posiciones (positivo = derecha, negativo = izquierda).
     */
    void rotar(int N);

    /**
     * @brief Mapea un carácter de entrada según la rotación actual del rotor.
     */
    char getMapeo(char inChar);
};

#endif // ROTORDEMAPEO_H
