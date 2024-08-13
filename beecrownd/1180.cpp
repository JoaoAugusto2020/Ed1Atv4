#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<ctype.h>

using namespace std;

struct No {

    int valor;
    No* prox;

    No() {
        prox = NULL;
    }

    No(int _valor) {
        valor = _valor;
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

    void inserirInicio(int valor) {
        No* novo = new No(valor);
        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            novo->prox = inicio;
            inicio = novo;
        }
        n++;
    }

    void inserirFinal(int valor) {
        No* novo = new No(valor);
        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            fim->prox = novo;
            fim = novo;
        }
        n++;
    }

    void removerInicio() {
        if (n == 0) return;
        if (n == 1) {
            delete(inicio);
            inicio = NULL;
            fim = NULL;
            n--;
            return;
        }
        No* aux = inicio;
        inicio = inicio->prox;
        delete(aux);
        n--;
    }

    void removerFinal() {
        if (n == 0) return;
        if (n == 1) {
            delete(inicio);
            inicio = NULL;
            fim = NULL;
            n--;
            return;
        }
        No* aux = inicio;
        while (aux->prox != fim) {
            aux = aux->prox;
        }
        delete(fim);
        fim = aux;
        aux->prox = NULL;
        n--;
    }

    void imprimir() {
        No* aux = inicio;
        //printf("%d %d\n", aux, aux->valor);
        while (aux != NULL) {
            printf("%d\n", aux->valor);
            //printf("%d %d\n", aux->prox, aux->valor);
            aux = aux->prox;
        }
    }

};

int main(){
	Lista l;	
	
	int N, num, menor=0, posicao=0, contador=0;
    
    cin >> N;
    
    int X[N];
    
    for(int i=0; i<N; i++){
        cin >> num;
        l.inserirFinal(num);
        
        contador++;
        if(contador==1){
        	menor=num;
            posicao=i;
		}
        
        if(num<menor){
            menor=num;
            posicao=i;
        }
    }
    
    cout << "Menor valor: " << menor << endl;
    cout << "Posicao: " << posicao << endl;
	
	
	return 0;
}
