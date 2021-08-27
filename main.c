#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"
int main(){
	int x,e;
	zera_variaveis();
    int N =6, M =3 , dados[6] = {4,2,1,3,6,5},dados2[3] = {4,3,5};
	
	
    ArvBin* raiz = cria_ArvBin();
    ArvBin* raiz2 = cria_ArvBin();
            		
	int valor=0,valoor;

    int i;
    	
    for(i=0; i < N; i++){
        insere_ArvBin(raiz,dados[i]);
        }
		int k;

		
        printf("Menu -- Digite o numero que voce deseja testar\n\n"
		"1--Conta folhas\n"
		"2--Arvores iguais ou nao\n"
		"3--Ocorrencia de numero\n"
		"4--Imprimir folhas\n"
		"5--arvore binaria ou nao\n"
		"6--arvore estritamente binaria ou nao\n"
		"7--Valor maximo\n"
		"8--Exclui todos os nos com valor par\n"
		"9--Numero de folhas\n"
		"10--Menor caminho\n"
		"11--[--QUESTAO EXTRA--]\n");							
        scanf("%d",&e);
        switch(e){
        	
        	case 1:
        		for(i=0; i < M; i++){
        			insere_ArvBin2(raiz2,dados2[i]);
        		}
        		printf("\nFOLHAS DA SEGUNDA ARVORE\n\n");	
        		printf("[%d] Folhas\n",conta_folhas(raiz2));	
        	break;
        		
        	case 2:
        		for(i=0; i < M; i++){
        			insere_ArvBin(raiz2,dados2[i]);
        		}
        		printf("\nAs arvores nao receberam valores repetidos!\n\n");
        		if(iguais(raiz,raiz2))
					printf("arvores iguais");
				else
					printf("arvores diferentes");
        	break;
        	
        	case 3:
        		for(i=0; i < M; i++){
        			insere_ArvBin2(raiz2,dados2[i]);
        		}
        		
        		printf("Digite um valor para a SEGUNDA ARVORE: ");
        		scanf("%d",&valor);
        		printf("[%d] se repete [%d] vezes\n",valor,dados_iguais(raiz2,valor));
        	break;
        		
           	case 4:
           		for(i=0; i < M; i++){
        			insere_ArvBin2(raiz2,dados2[i]);
        		}
        		printf("\nFOLHAS DA SEGUNDA ARVORE\n\n");
        		x= imprime_folhas(raiz2);
        	break;
        		
        	case 5:
        			if(arvore_bin(raiz))
					printf("Arvore binaria com o retorno 1");
				else
					printf("Arvore nao binaria com o retorno 0");
        	break;
				
			case 6:
        		if(arvore_estritamentebin(raiz))
					printf("Arvore estritamente binaria. retorno: 1");
				else
					printf("Arvore nao estritamente binaria. retorn: 0");
        	break;	
        	
			case 7:
        		x=imprime_valormax(raiz);
        	break;	
        	
       		case 8:
       			printf("Valores em pre ordem antes da eliminacao\n");
       			preOrdem_ArvBin(raiz);
        		x=deleta_numeropar(raiz);
        		printf("Valores em pre ordem apos a eliminacao\n");
       			preOrdem_ArvBin(raiz);
        	break;	
        	
       		case 9:
       			
       			printf("[%d] Folhas na PRIMEIRA ARVORE\n",conta_folhas(raiz));
        	break;
        	
        	case 10:
        		printf("Digite um valor: ");
        		scanf("%d",&valor);
        		if(consulta_rapida(raiz,valor)){
       				x = consulta_rapida(raiz,valor);
       				printf("O numero [%d] percorreu [%d] nos ate ser encontrado (sem contas a raiz)\n",valor,x);
       			}else
       				printf("\nValor nao encontrado encontrado abaixo da raiz");
        	break;
        	
        	case 11:
        		k = trasforma_esq_dir(raiz);

        
       			for(i=0; i < N; i++){
        			remove_ArvBin(raiz,dados[i]);
        		}
        	    for(i=0; i < N; i++){
       			 insere_ArvBin2(raiz,k);
       			 }
        		printf("SOMA DE TODOS OS VALORES = %d\n TODOS OS VALORES DA ARVORE (AROVRE UM (SEM REPETICOES)) FORAM TRANSFORMADO NO TOTAL DA SOMA! (AGORA COM REPETICOES)\n\n",k);
        		preOrdem_ArvBin(raiz);
        		break;
				
		}
		        
	
    libera_ArvBin(raiz);

    return 0;
}
