/*
 * Lampada.cpp
 *
 *  Created on: May 20, 2016
 *      Author: ra141876
 */

#include "Lampada.h"

Lampada::Lampada(int pinL) {
	acesa = false;
	pinLampada = pinL;
}

Lampada::~Lampada() {
	// TODO Auto-generated destructor stub
}

/*
 * Tenta acender a lampada
 * Se estiver ligada, retorna 2 (ja acesa)
 * Se estiver desligada, a liga e retorna 1 (sucesso)
 * Se occorrer um erro ao tentar liga-la, retorna 0 (erro)
 */
int Lampada::acender(){
	if(!acesa){
		acesa = true;
		return 1;
	}
	else{
		return 2;
	}

	return 0;
}

/*
 * Tentar apagar a lampada
 * Se ja estiver apagada, retorna 2 (ja apagada)
 * Se estiver ligada, a apaga e retorna 1 (sucesso)
 * Se ocorrer um erro, retorna 0
 */
int Lampada::apagar(){
	if(acesa){
		acesa = false;
		return 1;
	}
	else{
		return 2;
	}
	return 0;
}

string Lampada::toString(){
	string aux="";
	if(acesa){
		aux = "Lampada esta ligada.";
	}
	else{
		aux = "Lampada esta desligada";
	}

	return aux;
}
