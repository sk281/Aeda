#include <queue>
#include <cstdlib>
#include "balcao.h"
#include "exceptions.h"
#include <ctime>
using namespace std;

//a alterar
Cliente::Cliente() {
numPresentes = rand() % 5 + 1; // entre 1 e 5.
}

//a alterar
int Cliente::getNumPresentes() const {
    return numPresentes;
}

//a alterar
Balcao::Balcao(int te): tempo_embrulho(te) {//tempo_embrulho = te...
    tempo_atual = 0;
    prox_chegada = rand() % 20 + 1;
    prox_saida = 0;
    clientes_atendidos = 0;
}

//a alterar
void Balcao:: proximoEvento(){//#a fazer
    //Estados
    int prev;
    if(prox_saida>prox_chegada || prox_saida==0){
        tempo_atual=prox_chegada;
        chegada();
    }
    else {
        saida();
        tempo_atual=prox_saida;
    }
}


//a alterar
void Balcao::chegada(){
    Cliente c1; //cria novo cliente
    if(clientes.empty()){
        prox_saida= tempo_atual + c1.getNumPresentes()*tempo_embrulho;
        //proxima saida (tempo) = tempo_actual + (c1.getNumPresentes()) *(vezes)* (tempo_embrulho)
        //                                                                Multiplicação
    }
    clientes.push(c1);//adiciona cliente

    prox_chegada= tempo_atual + rand() % 20 + 1;// tempo_atual + o tempo de chegar
    printf("tempo= %d\nchegou novo cliente com %d presentes\n", tempo_atual,c1.getNumPresentes());
    //printf() o %d sao os valores a frente ->...
}

//a alterar
void Balcao::saida(){

    getProxCliente();
    clientes.pop();
    prox_saida= tempo_atual + clientes.front().getNumPresentes()*tempo_embrulho;
    clientes_atendidos++;
    printf("tempo= %d\nsaiu um cliente com %d presentes\n", tempo_atual,clientes.front().getNumPresentes());
    //clientes.front().getnunmpresentes = cliente da frente getnumpresentes
}


int Balcao::getTempoAtual() const { return tempo_atual; }

int Balcao::getProxChegada() const { return prox_chegada; }

//a alterar
ostream & operator << (ostream & out, const Balcao & b1)
{
     return out;
}

//a alterar
int Balcao::getTempoEmbrulho() const {
	return tempo_embrulho;
}

//a alterar
int Balcao::getProxSaida() const {
	return prox_saida;
}

//a alterar
int Balcao::getClientesAtendidos() const {
	return clientes_atendidos;
}

//a alterar
Cliente & Balcao::getProxCliente() {

    if(clientes.empty())
        throw FilaVazia();
    return clientes.front(); //.front() função da stack já.
}