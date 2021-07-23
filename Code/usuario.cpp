#include "usuario.h"

Tno* rotacao_simples_esquerda(Tno* a){

   Tno *aux;
   aux = a->dir;
   a->dir = aux->esq;
   aux->esq = a;
   a = aux;   
   
   return a;
   
}

Tno * rotacao_simples_direita(Tno *a){
	
	Tno *aux;
	aux = a->esq;
	a->esq = aux->dir;
	aux->dir = a;
	a = aux;
	
	return a;
	
}

Tno* criar(int elemento, char *nome_completo, char *cpf, char *endereco, char *cartao_credito){
	
	Tno * dado = (Tno *)malloc(sizeof(Tno));
    dado->elemento = elemento;
    
    dado->nome_completo = (char*)malloc(sizeof(strlen(nome_completo)+1));
    strcpy(dado->nome_completo, nome_completo);
    
    dado->cpf = (char*)malloc(sizeof(strlen(cpf)+1));
    strcpy(dado->cpf, cpf);
    
    dado->endereco = (char*)malloc(sizeof(strlen(endereco)+1));
    strcpy(dado->endereco, endereco);
    
    dado->cartao_credito = (char*)malloc(sizeof(strlen(cartao_credito)+1));
    strcpy(dado->cartao_credito, cartao_credito);
    
    dado->cor = vermelho;
    dado->esq = NULL;
    dado->dir = NULL;
    
    return dado;
    
}

Tno* inserir(Tno* a, int valor, char *nome_completo, char *cpf, char *endereco, char *cartao_credito){
	
	Tno* dado = criar(valor, nome_completo, cpf, endereco, cartao_credito);
	a = incluir_no(a, dado);
	
	if(a != NULL){
		a->cor = preto;
	}
	
	return a;
	
}

Tno* incluir_no(Tno* a, Tno* dado){
	
	if (a == NULL){
		return dado;
	}
	else if(dado->elemento == a->elemento);
	else{
		if(a->elemento > dado->elemento){
			a->esq = incluir_no(a->esq, dado);
		}
		else{
			a->dir = incluir_no(a->dir, dado);
		}
		
		if((cor(a->esq)==vermelho) && (cor(a->dir)==vermelho)){
			trocaCor(a);
		}
		if((cor(a->esq)==vermelho) && (cor(a->esq->esq)==vermelho)){
			a->cor = vermelho;
			a->esq->cor = preto;
			a = rotacao_simples_direita(a);	
		}
		if((cor(a->esq)==vermelho) && (cor(a->esq->dir)==vermelho)){
			Tno *aux = rotacao_simples_esquerda(a->esq);
			a->esq = aux;
			a->cor = vermelho;
			a->esq->cor = preto;
			a = rotacao_simples_direita(a);
		}
		if((cor(a->dir)==vermelho) && (cor(a->dir->dir)==vermelho)){
			a->cor = vermelho;
			a->dir->cor = preto;
			a = rotacao_simples_esquerda(a);
		}
		if((cor(a->dir)==vermelho) && (cor(a->dir->esq)==vermelho)){
			Tno *aux = rotacao_simples_direita(a->dir);
			a->dir = aux;
			a->cor = vermelho;
			a->dir->cor = preto;
			a = rotacao_simples_esquerda(a);
		} 	
	}	

	return a; 
		 	
}

int cor(Tno* a){
	
	if(a==NULL)
		return preto;
	else
		return a->cor;
		
}

void trocaCor(Tno* a){
	
	a->cor = !a->cor;
	
	if(a->esq !=NULL){
		a->esq->cor = !a->esq->cor;
	}
	if(a->dir !=NULL){
		a->dir->cor = !a->dir->cor;
	}
		
}

void imprime(Tno* a){
	
    if (a == NULL){
		return;
	}
	printf("\n-----------------------------------------------------\n");
    printf("%d [cor: %d]\n",a->elemento, a->cor);
    printf("Nome Completo: %s\n",a->nome_completo);
    printf("CPF: %s\n",a->cpf);
    printf("Endereco: %s\n",a->endereco);
    printf("Cartao de Credito: %s",a->cartao_credito);
 
    if(a->esq != NULL){
    	printf("\n(E:%d [cor: %d])",a->esq->elemento, a->esq->cor);
	}
    if(a->dir != NULL){
    	printf("\n(D:%d [cor: %d])",a->dir->elemento, a->dir->cor);
	}
    printf("\n-----------------------------------------------------");
 
    imprime(a->esq);
    imprime(a->dir);
    
}

int valida_cpf(char *cpf){
	if(strlen(cpf) == K){
	
		int cont = 0;
	
		for(int i = 0; i < K; i++){
			if(isdigit(cpf[i])){
				cont ++;
			}
		}
		if(cont == K)
			return 1;
	}
	
	return 0;	
		
}

int valida_cpf_pedido(Tno* a, char *cpf){
	
	if(strlen(cpf) == K){
	
		int cont = 0;
	
		for(int i = 0; i < K; i++){
			if(isdigit(cpf[i])){
				cont ++;
			}
		}
		if(cont == K){
			
			int existe = cpf_existe(a, cpf);
			if(existe == 1){
				return 1;
			}
			
		}
	}
	
	return 0;	
		
}

int cpf_existe(Tno* a, char *cpf){
	
	if (a == NULL){
		return 0;
	}
	if(!(strcmp(a->cpf, cpf))){
		return 1;
	}
	else{
		cpf_existe(a->esq, cpf);
    	cpf_existe(a->dir, cpf);
    }
	
}

void busca_user(Tno* a, AVLno* b, char *cpf){
	
	if (a == NULL){
		return;
	}
	
	if(!(strcmp(a->cpf, cpf))){
		
		printf("-----------------------------------------------------\n");
		printf("Informacoes do Usuario:\n");
	    printf("Nome Completo: %s\n",a->nome_completo);
	    printf("CPF: %s\n",a->cpf);
	    printf("Endereco: %s\n",a->endereco);
	    printf("Cartao de Credito: %s\n",a->cartao_credito);
	    printf("\nPedidos Efetuados:\n");
	    busca_pedidos(b, cpf);
	    printf("\n-----------------------------------------------------");
	    
	}
	else{
		
		busca_user(a->esq, b, cpf);
    	busca_user(a->dir, b, cpf);
    	
	}
	
}

void print_all(Tno* a, AVLno* b){
	
	if (a == NULL){
		return;
	}
	
	busca_user(a, b, a->cpf);
		
	print_all(a->esq, b);
    print_all(a->dir, b);
    	
	
}

void modifica_user(Tno* a, char *cpf_busca, char *endereco, char *cartao_credito){
	
	if(!(strcmp(a->cpf, cpf_busca))){
		
    	a->endereco = (char*)malloc(sizeof(strlen(endereco)+1));
    	strcpy(a->endereco, endereco);
    
    	a->cartao_credito = (char*)malloc(sizeof(strlen(cartao_credito)+1));
    	strcpy(a->cartao_credito, cartao_credito);
	    
	}
	else{
		
		modifica_user(a->esq, cpf_busca, endereco, cartao_credito);
    	modifica_user(a->esq, cpf_busca, endereco, cartao_credito);
    	
	}
	
}

