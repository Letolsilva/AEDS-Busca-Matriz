#include "lista.hpp"

void init(Lista * l){
    l->primeiro = (itemLista*)malloc(sizeof(itemLista));
    l->ultimo = l->primeiro;
    l->primeiro->proximo = NULL;
}

void insertEnd(Lista * l, itemMatriz item){
    l->ultimo->proximo = (itemLista*)malloc(sizeof(itemLista));
    l->ultimo = l->ultimo->proximo;
    l->ultimo->item = item;
    l->ultimo->proximo = NULL;
}

bool listaVazia(Lista * l){
    if((l->primeiro == l->ultimo) || (l == NULL)){
        return true;
    }
    else{
        return false;
    }
}

void removerItem(Lista * l, itemMatriz item){
    itemLista * aux, *tmp;
    bool ok = false;

    if(listaVazia(l)){
        printf("A lista está vazia.\n");
        return;
    }
    
    aux = l->primeiro;
    while(aux->proximo != NULL){
        if(aux->proximo->item.valor == item.valor){//encontrei o item a ser removido
            tmp = aux;
            aux = aux->proximo;
            tmp->proximo = aux->proximo;
            ok = true;
        }
        if(ok){//encontrei
            if(aux == l->ultimo){
                l->ultimo = tmp;
            }
            free(aux);
            aux = l->ultimo;
        }
        else{
            aux = aux->proximo;
        }
    }
    if(!ok){
        cout << "O item procurado não está na lista.\n";
    }
}