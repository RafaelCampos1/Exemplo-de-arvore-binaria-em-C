#ifndef ArvoreBinaria_h_included
#define ArvoreBinaria_h_included

typedef struct NO* ArvBin;

ArvBin* cria_ArvBin();
void libera_ArvBin(ArvBin *raiz);
int insere_ArvBin(ArvBin* raiz, int valor);
int insere_ArvBin2(ArvBin* raiz, int valor);
int remove_ArvBin(ArvBin *raiz, int valor);
int estaVazia_ArvBin(ArvBin *raiz);
int altura_ArvBin(ArvBin *raiz);
int totalNO_ArvBin(ArvBin *raiz);
int totalNO_ArvBin2(ArvBin *raiz2);
int consulta_ArvBin(ArvBin *raiz, int valor);
void preOrdem_ArvBin(ArvBin *raiz);
void emOrdem_ArvBin(ArvBin *raiz);
void posOrdem_ArvBin(ArvBin *raiz);
int iguais(ArvBin *raiz,ArvBin *raiz2);
int conta_folhas(ArvBin *raiz);
int dados_iguais(ArvBin *raiz,int valor);
void preOrdem_ArvBin2(ArvBin *raiz2);
int imprime_folhas(ArvBin *raiz);
int verif_arvore_de_busca(ArvBin *raiz);
int deleta_numeropar(ArvBin *raiz);
int imprime_valormax(ArvBin *raiz);
void zera_variaveis(void);
int arvore_bin(ArvBin *raiz);
int consulta_rapida(ArvBin *raiz, int valor);
int trasforma_esq_dir(ArvBin *raiz);
#endif
