#include<stdio.h>
#include<stdlib.h>
#include"pilha.h"

main(){

	pilha topo=create_pilha();
	
	int i, x;

	for(i=0;i<10;i++){

		insere(&topo,(int)i);
	}

	for(i=0;i<10;i++){

		x=(int)pop(&topo);
		printf("Elemento: %d\n", x);
	}
		

	return 0;
}
