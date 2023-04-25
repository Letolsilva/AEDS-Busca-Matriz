#ifndef ITEM_LISTA_HPP
#define ITEM_LISTA_HPP

#include "itemMatriz.hpp"

typedef struct itemLista{
    itemMatriz item;
    itemLista * proximo;
}itemLista;

#endif