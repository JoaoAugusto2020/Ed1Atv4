#include<iostream>
#include<bits/stdc++.h>

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
        while (aux != NULL) {
            if (aux != inicio) printf(" ");
            printf("%d", aux->valor);
            aux = aux->prox;
        }
        cout<<endl;
    }
    
    int proximoValor(){
    	int primeiro=0, segundo=0;
    	
		No* aux = inicio->prox;
		
		primeiro = inicio->valor;
        segundo = aux->valor;
        
		return primeiro + segundo;
	}

};

int main() {
	
	int qtd=0;
    Lista l;
	
	cin>>qtd;
	
	l.inserirInicio(1);
	l.inserirInicio(1);
	
	if(qtd==1){
		cout<<"1"<<endl;
		return 0;
	}else if(qtd==2){
		cout<<"1 1"<<endl;
		return 0;
	}else{
		qtd-=2;
		int val;
		while(qtd--){
			val = l.proximoValor();
			l.inserirInicio(val);
		}
		
	}
    
	l.imprimir();

    return 0;
}
