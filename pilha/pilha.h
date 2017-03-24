#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
//associando void pointer a pilha
typedef void* pilha;
//associando void pointer ao conteúdo a ser inserido
typedef void* item;
//funcao para criar uma pilha
pilha create_pilha();
//funcao que insere na pilha
void insere(pilha *topo, item conteudo);
//funcao para desempilhar
item pop(pilha *topo);
//fucnao que verifica se a pilha esta vazia
int vazia(pilha topo);
//funcao que libera a pilha
void libera(pilha *topo);


#endif // PILHA_H_INCLUDED
