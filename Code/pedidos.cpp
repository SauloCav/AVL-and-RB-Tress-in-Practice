#include "pedidos.h"

int altura_AVL(AVLno *a){
	
    int alt_esq=0, alt_dir=0;
    
    if (a == NULL){
    	return 0;
	}
    else{
    	
        alt_esq = altura_AVL(a->esq);
        alt_dir = altura_AVL(a->dir);
        
        if (alt_esq > alt_dir)
            return (1 + alt_esq);
        else
            return (1 + alt_dir);
            
    }
    
}

int calcula_FB(AVLno *a){
	
    return (altura_AVL(a->esq) - altura_AVL(a->dir));
    
}

AVLno* rotacao_simples_esquerda_AVL(AVLno* a){
	
	AVLno *aux;
	aux = a->dir;
	a->dir = aux->esq;
	aux->esq = a;
	a = aux;
	
	return a;
  
}

AVLno * rotacao_simples_diretira_AVL(AVLno *a){
	
	AVLno *aux;
	aux = a->esq;
	a->esq = aux->dir;
	aux->dir = a;
	a = aux;
	
	return a;
  
}

AVLno * balanceio_esquerda(AVLno *a){

	int fator = calcula_FB(a->esq );
	
	if(fator > 0){
		return rotacao_simples_diretira_AVL(a);
	}
	else if(fator < 0){ 
		a->esq = rotacao_simples_esquerda_AVL(a->esq);
		a = rotacao_simples_diretira_AVL(a); 
		return a;	
	}
	else{
		return a;
	}	
  	
}

AVLno * balanceio_direita(AVLno *a){

	int fator = calcula_FB(a->dir);

	if (fator < 0){
		return rotacao_simples_esquerda_AVL(a);
	}
	else if (fator > 0){ 
		a->dir = rotacao_simples_diretira_AVL(a->dir);
		a = rotacao_simples_esquerda_AVL(a); 
		return a;
	}
	else{
		return a;
	}
	
}

AVLno* balanceamento(AVLno* a){
	
	int fator = calcula_FB(a);
	
	if (fator > 1)
		return balanceio_esquerda(a);
	else if (fator < -1)
		return balanceio_direita(a);
		
	return a;
	
}

AVLno* inserir_AVL(AVLno* a, float valor, char *num_id, char *descricao_item, int quantidade, char *id_cliente, char *status){
	
	if (a == NULL){
		a = (AVLno *)malloc(sizeof(AVLno));
		a->valor = valor;
		
		a->num_id = (char*)malloc(sizeof(strlen(num_id)+1));
    	strcpy(a->num_id, num_id);
    	
    	a->descricao_item = (char*)malloc(sizeof(strlen(descricao_item)+1));
    	strcpy(a->descricao_item, descricao_item);
    	
    	a->id_cliente = (char*)malloc(sizeof(strlen(id_cliente)+1));
    	strcpy(a->id_cliente, id_cliente);
    	
    	a->status = (char*)malloc(sizeof(strlen(status)+1));
    	strcpy(a->status, status);
		
		a->quantidade = quantidade;
		a->esq = NULL;
		a->dir = NULL;
	
		return a;
	}
	else{
		if (a->valor > valor){
			a->esq = inserir_AVL(a->esq, valor, num_id, descricao_item, quantidade, id_cliente, status);
			a = balanceamento(a);
		}
		else{
			a->dir = inserir_AVL(a->dir, valor, num_id, descricao_item, quantidade, id_cliente, status);
			a = balanceamento(a);
		}	
	} 
	
}

void imprime_AVL(AVLno* a){
	
    if (a == NULL){
		return;
	}
	
	printf("\n-----------------------------------------------------\n");
    printf("ID do Pedido: %s\n",a->num_id);
    printf("ID do Cliente: %s\n",a->id_cliente);
    printf("Descricao do Item: %s\n",a->descricao_item);
    printf("Status: %s\n",a->status);
    printf("Quantidade: %d\n",a->quantidade);
    printf("Valor: %f",a->valor);
 
    if(a->esq != NULL)
        printf("\n(E:%f)",a->esq->valor);
    if(a->dir != NULL)
        printf("\n(D:%f)",a->dir->valor);
	
	printf("\n-----------------------------------------------------"); 
 
    imprime_AVL(a->esq);
    imprime_AVL(a->dir);
    
}

void busca_pedidos(AVLno* a, char *cpf){
	
	if (a == NULL){
		return;
	}
	
	if(!(strcmp(a->id_cliente, cpf))){
		
		printf("---------------------------------------------\n");
	    printf("ID do Pedido: %s\n",a->num_id);
	    printf("ID do Cliente: %s\n",a->id_cliente);
	    printf("Descricao do Item: %s\n",a->descricao_item);
	    printf("Status: %s\n",a->status);
	    printf("Quantidade: %d\n",a->quantidade);
	    printf("Valor: %f\n",a->valor);
		printf("---------------------------------------------\n");
		
	}
		
	busca_pedidos(a->esq, cpf);
	busca_pedidos(a->dir, cpf);
	
}

int id_existe(AVLno* a, char *num_id){
	
	if (a == NULL){
		return 0;
	}
	if(!(strcmp(a->num_id, num_id))){
		return 1;
	}
	else{
		id_existe(a->esq, num_id);
    	id_existe(a->dir, num_id);
    }
	
}

int modifica_pedido(AVLno* a, char *num_id, int quantidade, char *status){
	
	if(!(strcmp(a->num_id, num_id))){
		
    	a->quantidade = quantidade;
    
    	a->status = (char*)malloc(sizeof(strlen(status)+1));
    	strcpy(a->status, status);
	    
	}
	else{
		
		modifica_pedido(a->esq, num_id, quantidade, status);
    	modifica_pedido(a->esq, num_id, quantidade, status);
    	
	}
	
}

