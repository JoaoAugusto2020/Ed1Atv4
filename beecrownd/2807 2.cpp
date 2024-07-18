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
        	//o inicio e o fim é no mesmo ponteiro
            ponteiroInicio = ponteiroNovo;
            ponteiroFim = ponteiroNovo;
        } else {
        	//Próximo ponteiro do novo No recebe o ponteiro do inicio
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
        	//o inicio e o fim é no mesmo ponteiro
            ponteiroInicio = ponteiroNovo;
            ponteiroFim = ponteiroNovo;
        } else {
        	//O próximo ponteiro do último No recebe o ponteiro do novo No
            ponteiroFim->proximo = ponteiroNovo;
            //Atualiza o endereço do último No para o endereço do novo No
            ponteiroFim = ponteiroNovo;
        }
        n++;
    }

    void removerInicio() {
    	//se vazio
        if (n == 0) return;
        //se tiver só 1 No, limpar a lista
        if (n == 1) {
            delete(ponteiroInicio);
            ponteiroInicio = NULL;
            ponteiroFim = NULL;
            n--;
            return;
        }
        //cria um ponteiro AUX que aponta para o No do início
        //No* aux = ponteiroInicio;
		//delete(aux);
        
        //Ponteiro de inicio recebe o próximo ponteiro dele mesmo
        ponteiroInicio = ponteiroInicio->proximo;
        n--;
    }

    void removerFinal() {
    	//se vazio
        if (n == 0) return;
        //se tiver só 1 No, limpar a lista
        if (n == 1) {
            delete(ponteiroInicio);
            ponteiroInicio = NULL;
            ponteiroFim = NULL;
            n--;
            return;
        }
        //cria um ponteiro AUX que aponta para o No do início
        No* aux = ponteiroInicio;
        
        //enquanto não for o penultimo
        while(aux->proximo != ponteiroFim) {
            //atualize o endereço o próximo
			aux = aux->proximo;
        }
        //delete(ponteiroFim);
        //o penultimo vira o ultimo
		ponteiroFim = aux;
        aux->proximo = NULL;
        n--;
    }

    void imprimir() {
    	//cria um ponteiro AUX que aponta para o No do início
        No* aux = ponteiroInicio;
        
        //enquanto o ponteiro do próximo No não for NULL
        while(aux != NULL){
            printf("%d\n", aux->valor);
            aux = aux->proximo;
        }
    }
    
    void fibo(int tam){
    	int i=1;
    	
    	while(i!=tam){
	        //se estiver vazia
	        if (ponteiroInicio == NULL) {
	        	//o inicio e o fim é no mesmo ponteiro
	            ponteiroInicio = ponteiroNovo;
	            ponteiroFim = ponteiroNovo;
	        } else {
	        	//O próximo ponteiro do último No recebe o ponteiro do novo No
	            ponteiroFim->proximo = ponteiroNovo;
	            //Atualiza o endereço do último No para o endereço do novo No
	            ponteiroFim = ponteiroNovo;
	        }
	        
	        //cria um ponteiro que aponta para um novo No
    		No* ponteiroNovo = new No(valor);
	        
    		i++;
		}
	}
};

int main(){
	Lista l;	
	
	int tam, i;
    //long long int f[40];

    cin>>tam;
	
	l.inserirFinal(1);
	l.inserirFinal(1);
	
    for(i=2; i<tam; i++){
        f[i]=f[i-1]+f[i-2];
    }
	
    for(i=tam-1; i>=0; i--){
        cout<<f[i];
        if(i!=0) cout<<" ";
    }
    cout<<endl;
	
	return 0;
}

