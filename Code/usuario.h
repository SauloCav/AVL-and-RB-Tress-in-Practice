#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<windows.h>
#include "pedidos.h"

#define K 11

typedef enum {vermelho, preto} Tcor;

typedef struct no{
	int elemento;
	char *nome_completo;
	char *cpf;
	char *endereco;
	char *cartao_credito;
	int cor;
	
	struct no* esq;
	struct no* dir;
}Tno;

Tno* rotacao_simples_esquerda(Tno *a);
Tno* rotacao_simples_direita(Tno *a);
Tno* criar(int elemento, char *nome_completo, char *cpf, char *endereco, char *cartao_credito);
Tno* incluir_no(Tno* a, Tno* dado);
Tno* inserir(Tno* a, int valor, char *nome_completo, char *cpf, char *endereco, char *cartao_credito);

int cor(Tno* a);
void trocaCor(Tno* a);
void imprime(Tno* a);
void busca_user(Tno* a, AVLno* b, char *cpf);
void print_all(Tno* a, AVLno* b);

int valida_cpf(char *cpf);
int valida_cpf_pedido(Tno* a, char *cpf);
int cpf_existe(Tno* a, char *cpf);
void modifica_user(Tno* a, char *cpf_busca, char *endereco, char *cartao_credito);

