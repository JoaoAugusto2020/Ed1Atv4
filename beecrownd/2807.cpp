#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<ctype.h>

using namespace std;

struct No {

    int valor;
    No* proximo;

    No() {
        proximo = NULL;
    }

    No(int _valor) {
        valor = _valor;
        proximo = NULL;
    }

};

struct Lista {
    No* ponteiroInicio;
    No* ponteiroFim;
    int n;
	
	//Lista vazia
    Lista() {
        ponteiroInicio = NULL;
        ponteiroFim = NULL;
        n = 0;
    }

    void inserirInicio(int valor) {
    	//cria um ponteiro que aponta para um novo No
        No* ponteiroNovo = new No(valor);
        
        //se estiver vazia
        if (ponteiroInicio == NULL) {
        	//o inicio e o fim � no mesmo ponteiro
            ponteiroInicio = ponteiroNovo;
            ponteiroFim = ponteiroNovo;
        } else {
        	//Pr�ximo ponteiro do novo No recebe o ponteiro do inicio
            ponteiroNovo->proximo = ponteiroInicio;
            //atualiza o ponteiro do inicio para o pornteiro do novo No
            ponteiroInicio = ponteiroNovo;
        }
        n++;
    }

    void inserirFinal(int valor) {
    	//cria um ponteiro que aponta para um novo No
        No* ponteiroNovo = new No(valor);
        
        //se estiver vazia
        if (ponteiroInicio == NULL) {
        	//o inicio e o fim � no mesmo ponteiro
            ponteiroInicio = ponteiroNovo;
            ponteiroFim = ponteiroNovo;
        } else {
        	//O pr�ximo ponteiro do �ltimo No recebe o ponteiro do novo No
            ponteiroFim->proximo = ponteiroNovo;
            //Atualiza o endere�o do �ltimo No para o endere�o do novo No
            ponteiroFim = ponteiroNovo;
        }
        n++;
    }

    void removerInicio() {
    	//se vazio
        if (n == 0) return;
        //se tiver s� 1 No, limpar a lista
        if (n == 1) {
            delete(ponteiroInicio);
            ponteiroInicio = NULL;
            ponteiroFim = NULL;
            n--;
            return;
        }
        //cria um ponteiro AUX que aponta para o No do in�cio
        //No* aux = ponteiroInicio;
		//delete(aux);
        
        //Ponteiro de inicio recebe o pr�ximo ponteiro dele mesmo
        ponteiroInicio = ponteiroInicio->proximo;
        n--;
    }

    void removerFinal() {
    	//se vazio
        if (n == 0) return;
        //se tiver s� 1 No, limpar a lista
        if (n == 1) {
            delete(ponteiroInicio);
            ponteiroInicio = NULL;
            ponteiroFim = NULL;
            n--;
            return;
        }
        //cria um ponteiro AUX que aponta para o No do in�cio
        No* aux = ponteiroInicio;
        
        //enquanto n�o for o penultimo
        while(aux->proximo != ponteiroFim) {
            //atualize o endere�o o pr�ximo
			aux = aux->proximo;
        }
        //delete(ponteiroFim);
        //o penultimo vira o ultimo
		ponteiroFim = aux;
        aux->proximo = NULL;
        n--;
    }

    void imprimir() {
    	//cria um ponteiro AUX que aponta para o No do in�cio
        No* aux = ponteiroInicio;
        
        //enquanto o ponteiro do pr�ximo No n�o for NULL
        while(aux != NULL){
            printf("%d\n", aux->valor);
            aux = aux->proximo;
        }
    }
    
    void rimprimir() {
        int nlocal = n;
        
        //cria um ponteiro AUX que aponta para o No do in�cio
        No* auxI = ponteiroInicio;
        No* auxF = ponteiroFim;
        
        while(nlocal!=0){
	        //enquanto n�o for o penultimo
	        while(auxI->proximo != auxF) {
	            //atualize o endere�o o pr�ximo
				auxI = auxI->proximo;
	        }
	        auxI = auxI->proximo;
	        printf("%d\n", auxI->valor);
	        //delete(ponteiroFim);
	        //o penultimo vira o ultimo
			auxF = auxI;
			nlocal--;
		}
        
        
    }

};

int main(){
	Lista l;	
	
//	int n, i;
    //long long int f[40];

//    cin>>n;
	
	l.inserirFinal(1);
    l.inserirFinal(2);
    l.inserirFinal(3);
    l.inserirFinal(4);
    l.inserirFinal(5);
    l.inserirFinal(6);
    l.inserirFinal(7);

//    for(i=2; i<n; i++){
//        f[i]=f[i-1]+f[i-2];
//    }
	
	l.imprimir();
	cout<<endl;
	
	l.rimprimir();
	cout<<endl;
	
	l.imprimir();
	cout<<endl;
	
//	l.imprimir();
//    for(i=n-1; i>=0; i--){
//        cout<<f[i];
//        if(i!=0) cout<<" ";
//    }
    cout<<endl;
	
	return 0;
}

