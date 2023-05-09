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
void insertEnd(Lista * l, itemLista*& primeiro, itemMatriz item);
void removerItemInicio(Lista * l);
void excluirLista(Lista * l);
bool listaVazia(Lista * l);
bool existeNaLista(Lista * l, itemLista * item);
void LImprime(Lista *l);
void insertInicio(Lista * l, itemLista*& primeiro, itemMatriz item);

#endif