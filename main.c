#include <stdio.h>
#include <stdlib.h>

int main(){
    struct no{
        int dado;
        struct no *prox;
    };

    struct no *lista, *p, *q;
    int sn, cont, pos, i;
    lista = NULL;
    cont = 0;

    do{
        //contador-inicio
        if(lista == NULL){
            cont = 0;
        }
        else{
            q = lista;
            cont = 1;
            while(q->prox != NULL){
                q = q->prox;
                cont++;
            }
        }//contador-fim

        printf("O novo no deve ser inserido em qual posicao? ");
        scanf("%d", &pos);

        if(pos > cont+1){
            printf("Posicao invalida\n");
        }
        else{
            p = malloc(sizeof(struct no));
            scanf("%d", &p->dado);
            
            if(pos == cont+1){
                //insercao a direita
                p->prox = NULL;
                q = lista;
                while(q->prox != NULL){
                    q = q->prox;
                }
                q->prox = p;
            }
            else{
                if(pos == 1){
                    //insercao a esquerda
                    p->prox = lista;
                    lista = p;
                }
                else{
                    //insercao intermediaria
                    q = lista;
                    for(i = 0; i <pos-2; i++){
                        q = q->prox;
                    }
                    p->prox = q->prox;
                    q->prox = p;
                }
            }
        }

        printf("Deseja inserir outro no a direita? 0-nao 1-sim ");
        scanf("%d", &sn);
    }while(sn == 1);

    //imprime lista
    printf("\n\n");
    p = lista;
    while(p != NULL){
        printf("%d  ", p->dado);
        p = p->prox;
    }

    return 0;
}