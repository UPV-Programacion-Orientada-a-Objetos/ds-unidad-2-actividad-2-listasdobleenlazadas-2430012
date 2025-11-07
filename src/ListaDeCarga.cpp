#include "ListaDeCarga.h"

ListaDeCarga::~ListaDeCarga() {
    NodoCarga* cur = head;
    while (cur) {
        NodoCarga* next = cur->next;
        delete cur;
        cur = next;
    }
}

void ListaDeCarga::insertarAlFinal(char dato) {
    NodoCarga* nodo = new NodoCarga(dato);
    if (!head) {
        head = tail = nodo;
    } else {
        tail->next = nodo;
        nodo->prev = tail;
        tail = nodo;
    }
}

void ListaDeCarga::imprimirMensaje() {
    printf("\nMENSAJE OCULTO ENSAMBLADO:\n");
    NodoCarga* cur = head;
    while (cur) {
        printf("[%c]", cur->dato);
        cur = cur->next;
    }
    printf("\n");
    cur = head;
    while (cur) {
        putchar(cur->dato);
        cur = cur->next;
    }
    printf("\n");
}
