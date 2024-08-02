#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct No {

    char idioma[200];
    char mensagem[200];
    No* prox;

    No() {
        prox = NULL;
    }

};

struct Lista {

    No* inicio;
    No* fim;
    int n;

    Lista() {
        inicio = NULL;
        fim = NULL;
        n = 0;
    }

    void inserirInicio(char idioma[], char mensagem[]) {
        No* novo = new No();
        
        strcpy(novo->idioma, idioma);
        strcpy(novo->mensagem, mensagem);
        
		if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            novo->prox = inicio;
            inicio = novo;
        }
        n++;
    }

    void imprimir() {
        No* aux = inicio;
        while (aux != NULL) {
            printf("%s\n", aux->idioma);
            printf("%s\n", aux->mensagem);
            aux = aux->prox;
        }
    }
    
    void buscarIdioma(char idioma[]){
    	No* aux = inicio;
        while (aux != NULL) {
        	if(strcmp(aux->idioma,idioma) == 0){
        		printf("%s\n", aux->mensagem);
			}
            aux = aux->prox;
        }
	}
};

int main() {
	
    Lista l;
	int qtdIdioma=0, qtdCriancas=0;
	char idioma[200], mensagem[200], nome[200];
	
	scanf("%d%*c", &qtdIdioma);
	while(qtdIdioma--){
		scanf("%[^\n]%*c",idioma);
		scanf("%[^\n]%*c",mensagem);
		
		l.inserirInicio(idioma, mensagem);
	}
	
	scanf("%d%*c", &qtdCriancas);
	while(qtdCriancas--){
		scanf("%[^\n]%*c",nome);
		cout<<nome<<endl;
		scanf("%[^\n]%*c",idioma);
		
		l.buscarIdioma(idioma);
		
		cout<<endl;
	}

    return 0;
}
