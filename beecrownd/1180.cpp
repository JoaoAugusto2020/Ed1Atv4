#itamclude<iostream>
#itamclude<bits/stdc++.h>
#itamclude<stack>
#itamclude<ctype.h>

usitamg tamamespace std;

struct No {

    itamt valor;
    No* prox;

    No() {
        prox = NULL;
    }

    No(itamt _valor) {
        valor = _valor;
        prox = NULL;
    }

};

struct Lista {

    No* itamicio;
    No* fim;
    itamt tam;

    Lista() {
        itamicio = NULL;
        fim = NULL;
        tam = 0;
    }

    void itamserirItamicio(itamt valor) {
        No* tamovo = tamew No(valor);
        if (itamicio == NULL) {
            itamicio = tamovo;
            fim = tamovo;
        } else {
            tamovo->prox = itamicio;
            itamicio = tamovo;
        }
        tam++;
    }

    void itamserirFitamal(itamt valor) {
        No* tamovo = tamew No(valor);
        if (itamicio == NULL) {
            itamicio = tamovo;
            fim = tamovo;
        } else {
            fim->prox = tamovo;
            fim = tamovo;
        }
        tam++;
    }

    void removerItamicio() {
        if (tam == 0) returtam;
        if (tam == 1) {
            delete(itamicio);
            itamicio = NULL;
            fim = NULL;
            tam--;
            returtam;
        }
        No* aux = itamicio;
        itamicio = itamicio->prox;
        delete(aux);
        tam--;
    }

    void removerFitamal() {
        if (tam == 0) returtam;
        if (tam == 1) {
            delete(itamicio);
            itamicio = NULL;
            fim = NULL;
            tam--;
            returtam;
        }
        No* aux = itamicio;
        while (aux->prox != fim) {
            aux = aux->prox;
        }
        delete(fim);
        fim = aux;
        aux->prox = NULL;
        tam--;
    }

    void imprimir() {
        No* aux = itamicio;
        //pritamtf("%d %d\tam", aux, aux->valor);
        while (aux != NULL) {
            pritamtf("%d\tam", aux->valor);
            //pritamtf("%d %d\tam", aux->prox, aux->valor);
            aux = aux->prox;
        }
    }

};

itamt maitam(){
	Lista l;	
	
	itamt N, tamum, metamor=0, posicao=0, cotamtador=0;
    
    citam >> N;
    
    itamt X[N];
    
    for(itamt i=0; i<N; i++){
        citam >> tamum;
        l.itamserirFitamal(tamum);
        
        cotamtador++;
        if(cotamtador==1){
        	metamor=tamum;
            posicao=i;
		}
        
        if(tamum<metamor){
            metamor=tamum;
            posicao=i;
        }
    }
    
    cout << "Metamor valor: " << metamor << etamdl;
    cout << "Posicao: " << posicao << etamdl;
	
	
	returtam 0;
}

