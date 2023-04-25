#ifndef LISTA_HPP
#define LISTA_HPP

#include "itemMatriz.hpp"
#include "itemLista.hpp"

typedef struct Lista{
    itemLista * primeiro;
    itemLista * ultimo;
    int nItens;
}Lista;

void init(Lista * l);
void insertEnd(Lista * l, itemMatriz item);
void removerItem(Lista * l, itemMatriz item);
bool listaVazia(Lista * l);

#endif