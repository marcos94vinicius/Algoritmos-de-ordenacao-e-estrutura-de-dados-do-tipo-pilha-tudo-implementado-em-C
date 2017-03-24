#include<stdio.h>
#include<stdlib.h>
#include"pilha.h"

//estrutura da pilha
struct NoPilha{

    item elemento;
    struct NoPilha *prox;
};
typedef struct NoPilha NoPilha;
//funcao que cria a pilha
pilha create_pilha(){

    return NULL;
}
//funcao que insere na pilha
void insere(pilha *topo, item conteudo){

    NoPilha *nova=(NoPilha *)malloc(sizeof(NoPilha));
    nova->elemento=conteudo;
    nova->prox=*topo;
    *topo=nova;
}
//funcao que desempilha
item pop(pilha *topo){

    NoPilha *aux=*topo;
    item ele;
    if(*topo==NULL){

        return 0;
    }
    *topo=aux->prox;
    ele=aux->elemento;
    free(aux);
    return ele;
}
//funcao que verifica se a pilha esta vazia
int vazia(pilha topo){

    return (topo==NULL);
}
//funcao que libera a pilha
void libera(pilha *topo){

    NoPilha *aux;
    while(*topo!=NULL){

        aux=*topo;
        *topo=aux->prox;
        free(aux);
    }
}
