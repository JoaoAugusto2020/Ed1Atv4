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
    	cout<<"Lista:"<<endl;
    	
        No* aux = inicio;
        //printf("%d %d\n", aux, aux->valor);
        while (aux != NULL) {
            printf("%d", aux->valor);
            //printf("%d %d\n", aux->prox, aux->valor);
            aux = aux->prox;
            if(aux != NULL) cout<<" ";
        }
        
        cout<<endl<<endl;
    }
    
    
	//1)
    void removerUltimos(int cont){
    	if (n == 0) return;
    	while(cont--){
    		removerFinal();
		}
	}
	
	//2)
	void removerSegundo(){
		if (n == 0 || n ==1) return;
        //criei um nó
		No* segundo;
		
		//ele recebe agora o próimo nó dps de início
        segundo = inicio->prox;
        
        //o prox dps do início agora é o prox do segundo número
        inicio->prox = segundo->prox;
        
        //excluo o segundo nó dps do inicio
		delete(segundo);
        n--;
	}
	
	//3)
	void tamanhoFinal(){
		inserirFinal(n);
	}
	
	//4)
	void inserirFinalVarios(int x){
		for(int i=1; i<=x; i++){
			inserirFinal(i);
		}
	}
	
	//5)
	void inserirPenultimo(int valor){
		if (n ==1) return;
		No* novo = new No(valor);
        No* aux = inicio;
        
        //procurando o penultimo (aux é o penultimo nó)
        while (aux->prox != fim) {
            aux = aux->prox;
        }
        
        //prox do penultimo agora é o novo nó
        //novo nó aponta para o fim
        aux->prox = novo;
        novo->prox = fim;
        n++;
	}
	
};

int main() {

    Lista l;

    l.inserirInicio(10);
    l.inserirInicio(5);
    l.inserirInicio(1);
    l.inserirInicio(8);
    l.inserirFinal(7);
    l.inserirFinal(3);
    
    l.imprimir();
    
    l.inserirPenultimo(222);
		
	l.imprimir();

    return 0;
}
