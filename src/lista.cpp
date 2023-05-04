#include "lista.hpp"

void init(Lista * l){
    /*l->primeiro = (itemLista*)malloc(sizeof(itemLista));
    l->ultimo = l->primeiro;
    l->primeiro->proximo = NULL;*/
    l->primeiro = NULL;
    l->ultimo = NULL;
    l->nItens = 0;
}

void insertEnd(/*Lista * l, itemMatriz item*/Lista * l, itemLista*& primeiro, itemMatriz item){
    /* itemLista * novo = (itemLista*)malloc(sizeof(itemLista));
    novo->item = item; */
    /*if(listaVazia(l)){
        itemLista * novo = (itemLista*)malloc(sizeof(itemLista));
        novo->item = item;
        l->primeiro = novo;
        l->ultimo = novo;
        l->nItens = 1;
        l->ultimo->proximo = NULL;
    }
    else{
        l->ultimo->proximo = (itemLista*) malloc (sizeof(itemLista));
        l->ultimo = l->ultimo->proximo;
        l->ultimo->proximo = NULL;
        l->ultimo->item = item;
    }*/
    /* if(listaVazia(l)){
        l->primeiro = novo;
        l->ultimo = novo;
        l->nItens = 1;
        l->ultimo->proximo = NULL;
    }
    else{
        l->ultimo->proximo = novo;
        l->ultimo = novo;
        l->ultimo->proximo = NULL;
        l->nItens++;
    } */
    itemLista * novo = new itemLista;
    novo->item = item;
    novo->proximo = NULL;
    if(listaVazia(l)){
        primeiro = novo;
        l->nItens = 1;
    }
    else{
        itemLista * aux = primeiro;
        while(aux->proximo != NULL){
            aux = aux->proximo;
        }
        aux->proximo = novo;
        l->nItens++;
    }
}

void LImprime(Lista *l){
	itemLista *aux;
	aux = l->primeiro;
	while(aux != NULL){
		printf("%d - %d\n", aux->item.posicaoLinha, aux->item.posicaoColuna);
		aux = aux->proximo;
	}
}

bool listaVazia(Lista * l){
    if(l->nItens == 0){
        return true;
    }
    else{
        return false;
    }
}

void removerItemInicio(Lista * l){
    itemLista * removido;
    if(listaVazia(l)){
        cout << "A lista está vazia.\n";
        return;
    }

    removido = l->primeiro;
    l->primeiro = removido->proximo;
    free(removido);
    l->nItens--;
}

void excluirLista(Lista * l){
    while(!listaVazia(l)){
        removerItemInicio(l);
    }
    free(l);
}