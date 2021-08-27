#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h" //inclui os Protótipos
int x=0,i=0,x1=0,x2=0,x3=0,x4=0,valor=0,total=0,count=0;
void zera_variaveis(void){
	if(x2>0||x1>0||x>0||i>0||x3>0||x4>0||total>0){
	x1=0;
	x2=0;
	x=0;
	i=0;
	x3=0;
	x4=0;
	total=0;
	}
}
struct NO{
    int info;
    struct NO *esq;
    struct NO *dir;
};

ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NO(struct NO* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//libera cada nó
    free(raiz);//libera a raiz
}

int insere_ArvBin(ArvBin* raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL)
        return 0;
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL)
        *raiz = novo;
    else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(valor == atual->info){
                free(novo);
                return 0;//elemento já existe
            }
            
            if(valor > atual->info){ 
                atual = atual->dir;
              
            }else{
                atual = atual->esq;
                }
        }
        if(valor > ant->info){
		
            ant->dir = novo;
        }else{
		
            ant->esq = novo;}
    }
    return 1;
}


int insere_ArvBin2(ArvBin* raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL)
        return 0;
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL)
        *raiz = novo;
    else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(valor > atual->info){ 
                atual = atual->dir;
              
                
            }else{
                atual = atual->esq;
                
                }
        }
        if(valor > ant->info){
		
            ant->dir = novo;
        }else{
		
            ant->esq = novo;}
    }
    return 1;
}


struct NO* remove_atual(struct NO* atual) {
    struct NO *no1, *no2;
    if(atual->esq == NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    // no2 é o nó anterior a r na ordem e-r-d
    // no1 é o pai de no2
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}
// http://www.ime.usp.br/~pf/algoritmos/aulas/binst.html
int remove_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* ant = NULL;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            if(atual == *raiz)
                *raiz = remove_atual(atual);
            else{
                if(ant->dir == atual)
                    ant->dir = remove_atual(atual);
                else
                    ant->esq = remove_atual(atual);
            }
            return 1;
        }
        ant = atual;
        if(valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

int consulta_rapida(ArvBin *raiz, int valor){
   if(raiz == NULL)
        return 0;
   if(*raiz == NULL)
        return 0;
		     
        int retorno_valor=0;
    struct NO* atual = *raiz;
	if(valor==atual->info){
		printf("valor igual a raiz.");
		return 1;
	}

    while(atual != NULL){
        if(valor == atual->info){
            return retorno_valor++;
        }
        if(valor > atual->info){
			retorno_valor++;
            atual = atual->dir;
        }else{
			retorno_valor++;
            atual = atual->esq;
            }
    }
    return 0;
}

int deleta_numeropar(ArvBin *raiz){
    if(raiz == NULL)
        return 0;
	if(*raiz == NULL)
        return 0;
  	struct NO* atual = *raiz;
  	
	deleta_numeropar(&(*raiz)->esq);
	deleta_numeropar(&(*raiz)->dir);
  
    	if((*raiz)->info%2==0){
    		*raiz = remove_atual(atual);
		}
		return 1;

}
int arvore_bin(ArvBin *raiz){
    if(raiz == NULL)
        return 0;
	if(*raiz == NULL)
        return 0;
        struct NO* r = *raiz;
        struct NO* e = (*raiz)->esq;
  	  	struct NO* d = (*raiz)->dir;

  			
  		if(d->info > e->info && d->info>r->info && e->info < r->info)
		  return 1;
  			else
  		return 0;
  

}

int trasforma_esq_dir(ArvBin *raiz){
  if(raiz == NULL)
        return 0;
   if(*raiz == NULL)
        return 0;
    	
    trasforma_esq_dir(&((*raiz)->esq));
	trasforma_esq_dir(&((*raiz)->dir));
    	

     total += (*raiz)->info;
    
	
    return total;
    
	

}


int arvore_estritamentebin(ArvBin *raiz){
    if(raiz == NULL)
        return 0;
	if(*raiz == NULL)
        return 0;
    			arvore_estritamentebin(&((*raiz)->esq));
    			arvore_estritamentebin(&((*raiz)->dir));
    			
    if ((*raiz) != NULL){
		if((*raiz)->esq == NULL && (*raiz)->dir != NULL || (*raiz)->dir == NULL && (*raiz)->esq != NULL ){
			x2=1;
		}
	}
	
	if(x2==1){
		return 0;
	}else
		return 1;
		
}


int imprime_valormax(ArvBin *raiz){
    if(raiz == NULL)
        return 0;
	if(*raiz == NULL)
        return 0;
	int aux;
  	imprime_valormax(&(*raiz)->dir);	
  
  	if ((*raiz)->dir ==NULL){
  		printf("O valor maximo e: %d\n",(*raiz)->info);
  		
	}
		return 1;

}

   
int iguais(ArvBin *raiz,ArvBin *raiz2){// funcao que usa recursividade, duas variaveis globais e comparacao de nos para saber se ambas as arvores sao ou nao iguais
	if(raiz == NULL || raiz2 == NULL)
		return 0;
	if(*raiz == NULL || *raiz2 == NULL)
		return 0;
		if(*raiz!=NULL && *raiz2!=NULL ){			
			iguais(&((*raiz)->esq),&((*raiz2)->esq));
			iguais(&((*raiz)->dir),&((*raiz2)->dir));
			
			if((*raiz)->info!=(*raiz2)->info){
				x++;
				}
				
			}
			if(totalNO_ArvBin(raiz)<totalNO_ArvBin2(raiz2)){
				i=1;
			}
				
			else if(totalNO_ArvBin(raiz)>totalNO_ArvBin2(raiz2)){
				i=1;
			}
		
		if(x>0 || i==1){
			return 0;
		}else{
			return 1;
		}	
}

int dados_iguais(ArvBin *raiz, int valor){
	if(raiz == NULL )
		return 0;
	if(*raiz == NULL )
		return 0;
		if(*raiz!=NULL){	
			dados_iguais(&((*raiz)->dir),valor);		
			dados_iguais(&((*raiz)->esq),valor);
			
			if(valor==(*raiz)->info){
				x1++;				
			}
		
		}
			return x1;
}

int imprime_folhas(ArvBin *raiz){
	if(raiz == NULL )
		return 0;
	if(*raiz == NULL )
		return 0;

	imprime_folhas(&(*raiz)->dir);
	imprime_folhas(&(*raiz)->esq);



	if ((*raiz)->dir ==NULL && (*raiz)->esq == NULL ){
		printf("%d\n",(*raiz)->info);
	}
}


int conta_folhas(ArvBin *raiz){
	if(raiz == NULL )
		return 0;
	if(*raiz == NULL )
		return 0;
		
  	if (((*raiz)->esq == NULL) && ((*raiz)->dir == NULL))
    return 1;
    else
  	return conta_folhas(&(*raiz)->esq) + conta_folhas(&(*raiz)->dir);
  	
}
	


int estaVazia_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}

int totalNO_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = totalNO_ArvBin(&((*raiz)->esq));
    int alt_dir = totalNO_ArvBin(&((*raiz)->dir));
    return(alt_esq + alt_dir + 1);
}
int totalNO_ArvBin2(ArvBin *raiz2){
    if (raiz2 == NULL)
        return 0;
    if (*raiz2 == NULL)
        return 0;
    int alt_esq = totalNO_ArvBin2(&((*raiz2)->esq));
    int alt_dir = totalNO_ArvBin2(&((*raiz2)->dir));
    return(alt_esq + alt_dir + 1);
}

int altura_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvBin(&((*raiz)->esq));
    int alt_dir = altura_ArvBin(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}

int consulta_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
        	
            return 1;
        }
        if(valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}



void preOrdem_ArvBin2(ArvBin *raiz2){
      if(raiz2 == NULL)
        return;
	if(*raiz2 != NULL){
	printf("%d\n", (*raiz2)->info);

	preOrdem_ArvBin(&((*raiz2)->esq));
	preOrdem_ArvBin(&((*raiz2)->dir));
	}

}


void preOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    

	if(*raiz != NULL){
	printf("%d\n", (*raiz)->info);

	preOrdem_ArvBin(&((*raiz)->esq));
	preOrdem_ArvBin(&((*raiz)->dir));
	}

	}



void emOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        emOrdem_ArvBin(&((*raiz)->esq));
        printf("%d\n",(*raiz)->info);
        emOrdem_ArvBin(&((*raiz)->dir));
    }
}

void posOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        posOrdem_ArvBin(&((*raiz)->esq));
        posOrdem_ArvBin(&((*raiz)->dir));
        printf("%d\n",(*raiz)->info);
    }
}
