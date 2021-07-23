#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

typedef struct noAVL{	
	float valor;
	int fator_b;
	char *num_id;
	char *descricao_item;
	int quantidade;
	char *id_cliente;
	char *status;
	
	struct noAVL* esq;
	struct noAVL* dir;
}AVLno;

AVLno* rotacao_simples_esquerda_AVL(AVLno *a);
AVLno* rotacao_simples_diretira_AVL(AVLno *a);
AVLno* balanceamento_AVL(AVLno* a);
AVLno* inserir_AVL(AVLno* a, float valor, char *num_id, char *descricao_item, int quantidade, char *id_cliente, char *status);

int altura_AVL(AVLno *a);
int calcula_FB(AVLno *a);
void imprime_AVL(AVLno* a);
void busca_pedidos(AVLno* a, char *cpf);
int id_existe(AVLno* a, char *num_id);
int modifica_pedido(AVLno* a, char *num_id, int quantidade, char *status);

