#include "usuario.h"

int main(){
	
	int esc, codigo, qtd, v, valida, val, id_valida, new_qtd;
	float valor_compra;	
	char nome[20] = "", cpf[20] = "", endereco[20] = "", cartao_credito[20] = "", new_endereco[20] = "", new_cartao_credito[20] = "";
	char num_id[20] = "", descricao_item[30] = "", id_cliente[20] = "", status[20] = "", cpf_busca[20] = "", num_id_busca[20] = "", new_status[20];
	
    Tno *usuarios = NULL;
    AVLno *pedidos = NULL;
	
	do{
		
	fflush(stdin);
	
	printf("\n              -------------------------------- MENU --------------------------------");
	printf("\n              |  |1| Adicionar Usuario                                             |");
	printf("\n              |  |2| Atualizar Usuario                                             |");
	printf("\n              |  |3| Adicionar Pedido                                              |");
	printf("\n              |  |4| Atualizar Pedido                                              |");
	printf("\n              |  |5| Consultar Usuario                                             |");
	printf("\n              |  |6| Logar como Funcionario                                        |");
	printf("\n              |  |7| Logar como Desenvolvedor                                      |");
	printf("\n              |  |0| Sair                                                          |");
	printf("\n              ----------------------------------------------------------------------\n\n");
	
	printf("                                   Escolha uma das opcoes: ");
	scanf("%d", &esc);
	
	if(esc==0){
		system("cls");
	}
	
	switch(esc){
		
		case (0):{
			break;
		}
		
		case (1):{
			
			printf("Informe o Nome: ");
    		scanf("%s", nome);
    		printf("Informe o CPF: ");
    		scanf("%s", cpf);
    		
    		v = valida_cpf(cpf);
    		if(v == 1){
    			printf("CPF Validado!\n");
			}
			else{
				printf("CPF Invalido!");
				break;
			}
			
    		printf("Informe o Endereco: ");
    		scanf("%s", endereco);
    		printf("Informe o Cartao de Credito: ");
    		scanf("%s", cartao_credito);
			printf("Informe o Codigo do Cliente: ");
    		scanf("%d", &codigo);
    		
    		usuarios = inserir(usuarios, codigo, nome, cpf, endereco, cartao_credito);
			
			printf("\n\n");
			Sleep(500);
			printf(".");
			Sleep(500);
			printf(".");
			Sleep(500);
			printf(".");
			break;
			
		}
		
		case (2):{
			
    		printf("Informe o CPF do Cliente: ");
    		scanf("%s", cpf_busca);
    		
    		valida = cpf_existe(usuarios, cpf_busca);
    		
    		if(valida == 1){
				
	    		printf("Informe o Novo Endereco: ");
	    		scanf("%s", new_endereco);
	    		printf("Informe o Novo Cartao de Credito: ");
	    		scanf("%s", new_cartao_credito);
	    		
    			modifica_user(usuarios, cpf_busca, new_endereco, new_cartao_credito);
    			
			}
			else{
				printf("CPF Nao Encontrado!");
				break;
			}
			
			printf("\n\n");
			Sleep(500);
			printf(".");
			Sleep(500);
			printf(".");
			Sleep(500);
			printf(".");	
			break;
			
		}
		
		case (3):{
			
			printf("Informe o CPF do Cliente que Realizou o Pedido: ");
    		scanf("%s", id_cliente);
    		
    		val = cpf_existe(usuarios, id_cliente);
    		if(val == 1){
    			
    			printf("Descricao do Item: ");
	    		scanf("%s", descricao_item);
	    		printf("Quantidade: ");
	    		scanf("%i", &qtd);
	    		printf("Valor: ");
	    		scanf("%f", &valor_compra);
	    		printf("Informe o Numero de ID do Pedido: ");
	    		scanf("%s", num_id);
	    		printf("Status da Compra (Cancelado | Entregue | Finalizado | Processando): ");
	    		scanf("%s", status);
	    		
	    		pedidos = inserir_AVL(pedidos, valor_compra, num_id, descricao_item, qtd, id_cliente, status);
    			
			}
			else{
				
				printf("CPF Nao Encontrado!");
				break;
				
			}
			
			printf("\n\n");
			Sleep(500);
			printf(".");
			Sleep(500);
			printf(".");
			Sleep(500);
			printf(".");	
			break;
			
		}
		
		case (4):{
			
    		printf("Informe o Numero de ID do Pedido: ");
    		scanf("%s", num_id_busca);
    		
    		id_valida = id_existe(pedidos, num_id_busca);
    		
    		if(id_valida == 1){
				
	    		printf("Informe a Nova Quantidade: ");
	    		scanf("%i", &new_qtd);
	    		printf("Novo Status da Compra (Cancelado | Entregue | Finalizado | Processando): ");
	    		scanf("%s", new_status);
	    		
    			modifica_pedido(pedidos, num_id_busca, new_qtd, new_status);
    			
			}
			else{
				printf("ID Nao Encontrado!");
				break;
			}
			
			printf("\n\n");
			Sleep(500);
			printf(".");
			Sleep(500);
			printf(".");
			Sleep(500);
			printf(".");	
			break;
			
		}
		
		case (5):{
			
    		printf("Informe o CPF do Cliente: ");
    		scanf("%s", cpf_busca);
    		
    		valida = valida_cpf(cpf_busca);
    		if(valida == 1){
    			busca_user(usuarios, pedidos, cpf_busca);
			}
			else{
				printf("CPF Nao Encontrado!");
				break;
			}
			
			printf("\n\n");
			Sleep(500);
			printf(".");
			Sleep(500);
			printf(".");
			Sleep(500);
			printf(".");	
			break;
			
		}
		
		case (6):{
			
			system("cls");
			
			int opc;
	
			do{
					
				fflush(stdin);
				
				printf("\n              -------------------------------- MENU --------------------------------");
				printf("\n              |  |1| Visualizar Arranjo de Pedidos e Usuarios                      |");
				printf("\n              |  |0| Sair                                                          |");
				printf("\n              ----------------------------------------------------------------------\n\n");
				
				printf("                                   Escolha uma das opcoes: ");
				scanf("%d", &opc);
				
				if(esc==0){
					system("cls");
				}
				
				switch(opc){
					
					case (0):{
						break;
					}
					
					case (1):{
						
						print_all(usuarios, pedidos);
						
						printf("\n\n");
						Sleep(500);
						printf(".");
						Sleep(500);
						printf(".");
						Sleep(500);
						printf(".");
						
						break;
					}
				
					default:{
						system("cls");
						break;
					}
					
				}
			getch();
			system("cls");	
			}while(opc!=0);
			
			printf("\n\n");
			system("cls");
			break;
		}
	
		default:{
			system("cls");
			break;
		}
		
		case (7):{
			
			system("cls");
			
			int opc;
	
			do{
					
				fflush(stdin);
				
				printf("\n              -------------------------------- MENU --------------------------------");
				printf("\n              |  |1| Visualizar Arvore Rubro Negra (Arranjo de Usuarios)           |");
				printf("\n              |  |2| Visualizar Arvore AVL (Arranjo de Pedidos)                    |");
				printf("\n              |  |0| Sair                                                          |");
				printf("\n              ----------------------------------------------------------------------\n\n");
				
				printf("                                   Escolha uma das opcoes: ");
				scanf("%d", &opc);
				
				if(esc==0){
					system("cls");
				}
				
				switch(opc){
					
					case (0):{
						break;
					}
					
					case (1):{
						
						imprime(usuarios);
						
						printf("\n\n");
						Sleep(500);
						printf(".");
						Sleep(500);
						printf(".");
						Sleep(500);
						printf(".");
						
						break;
					}
					
					case (2):{
						
						imprime_AVL(pedidos);
						
						printf("\n\n");
						Sleep(500);
						printf(".");
						Sleep(500);
						printf(".");
						Sleep(500);
						printf(".");
						
						break;
					}
				
					default:{
						system("cls");
						break;
					}
					
				}
			getch();
			system("cls");	
			}while(opc!=0);
			
			printf("\n\n");
			system("cls");
			break;
		}
		
	}
	getch();
	system("cls");
	}while(esc!=0);	
	
}

