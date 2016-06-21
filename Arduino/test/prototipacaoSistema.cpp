//============================================================================
// Name        : prototipacaoSistema.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#ifndef ARDUINO

#include <iostream>
#include "Porta.h"
#include "Lampada.h"
using namespace std;

int main() {
	int aux;
	string acao;
	int i=1;
	Porta porta1(i, i);
	Lampada lamp1(i);
	while(1){
		cout << "Digite a Acao:" << endl; // prints !!!Hello World!!!
		cin >>  acao;
		if(acao == "abrir"){
			if((aux=porta1.abrir())==0){
				cout << "Erro ao abrir a porta" << endl;
			}
			else if(aux == 1){
				cout << "Sucesso ao abrir a porta" << endl;
			}
			else{
				cout << "Erro ao abrir a porta: Ja aberta" << endl;
			}
		}
		else if(acao == "fechar"){
			if((aux=porta1.fechar())==0){
				cout << "Erro ao fechar a porta" << endl;
			}
			else if(aux == 1){
				cout << "Sucesso ao fechar a porta" << endl;
			}
			else{
				cout << "Erro ao fechar a porta : Ja esta fechada" << endl;
			}
		}

		else if(acao == "trancar"){
			if((aux=porta1.trancar())==0){
				cout << "Erro ao trancar a porta" << endl;
			}
			else if(aux == 1){
				cout << "Sucesso ao trancar a porta" << endl;
			}
			else{
				cout << "Erro ao trancar a porta : Ja esta trancada" << endl;
			}
		}

		else if(acao == "destrancar"){
			if((aux=porta1.destrancar())==0){
				cout << "Erro ao destrancar a porta" << endl;
			}
			else if(aux == 1){
				cout << "Sucesso ao destrancar a porta" << endl;
			}
			else{
				cout << "Erro ao destrancar a porta : Ja esta destrancada" << endl;
			}
		}

		else if(acao == "ligar"){
			if((aux=lamp1.acender())==0){
				cout << "Erro ao acender a lampada" << endl;
			}
			else if(aux == 1){
				cout << "Sucesso ao acender a lampada" << endl;
			}
			else{
				cout << "Erro ao acender a lampada: Ja acesa" << endl;
			}
		}

		else if(acao == "desligar"){
			if((aux=lamp1.apagar())==0){
				cout << "Erro ao apagar a lampada" << endl;
			}
			else if(aux == 1){
				cout << "Sucesso ao apagar a lampada" << endl;
			}
			else{
				cout << "Erro ao apagar a lampada: Ja apagada" << endl;
			}
		}
		else if(acao == "parar"){
			break;
		}
		else if(acao == "estado"){
			cout << "Estado Atual" << endl;
			cout << porta1.toString() << endl;
			cout << lamp1.toString() << endl;
		}
		else{
			cout << "Comando nao reconhecido" << endl;
		}
	}
	cout << "Fim do programa" << endl;
	return 0;
}

#endif