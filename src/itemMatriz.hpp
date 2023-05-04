#ifndef ITEM_MATRIZ_HPP
#define ITEM_MATRIZ_HPP

#include <iostream>
#include <string>
#include <utility>
#include <fstream>

using namespace std;

typedef struct itemMatriz{
    string valor, cor;
    //bool visitado;
    pair<int, int> vetorFronteira[3];
}itemMatriz;

#endif