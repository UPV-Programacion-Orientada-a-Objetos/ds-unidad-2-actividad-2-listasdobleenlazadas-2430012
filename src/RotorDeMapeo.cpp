#include "RotorDeMapeo.h"

RotorDeMapeo::RotorDeMapeo() : head(nullptr), size(0) {
    inicializarAlfabeto();
}

RotorDeMapeo::~RotorDeMapeo() {
    if (!head) return;
    // Romper el círculo para liberar nodos
    head->prev->next = nullptr;
    NodoRotor* cur = head;
    while (cur) {
        NodoRotor* nxt = cur->next;
        delete cur;
        cur = nxt;
    }
}

void RotorDeMapeo::inicializarAlfabeto() {
    NodoRotor* first = nullptr;
    NodoRotor* last = nullptr;
    for (char c = 'A'; c <= 'Z'; ++c) {
        NodoRotor* nodo = new NodoRotor(c);
        if (!first) first = nodo;
        if (last) {
            last->next = nodo;
            nodo->prev = last;
        }
        last = nodo;
        size++;
    }
    first->prev = last;
    last->next = first;
    head = first;
}

void RotorDeMapeo::rotar(int N) {
    if (!head || size == 0) return;
    int pasos = N % size;
    if (pasos < 0) pasos += size;
    for (int i = 0; i < pasos; ++i) head = head->next;
    printf("-> ROTANDO ROTOR %s%d. (Nueva cabeza = '%c')\n", (N>=0?"+":""), N, head->letra);
}

char RotorDeMapeo::getMapeo(char inChar) {
    if (inChar == ' ') return ' ';
    if (!isalpha((unsigned char)inChar)) return inChar;
    char upper = toupper((unsigned char)inChar);
    int pos = upper - 'A';
    int headPos = head->letra - 'A';
    int mapped = (pos + headPos) % 26;
    return (char)('A' + mapped);
}
