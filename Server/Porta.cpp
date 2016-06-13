/*
 * Porta.cpp
 *
 *  Created on: May 20, 2016
 *      Author: ra141876
 */

#include "Porta.h"

Porta::Porta(int pinM, int pinT) {
	pinMotor = pinM;
	pinTranca = pinT;
	aberta = false;
	trancada = false;
}

Porta::~Porta() {
	// TODO Auto-generated destructor stub
}

/*
 * Tenta trancar a porta e retorna o seguinte codigo:
 * Se estiver fechada e destrancada, a tranca e retorna 1
 * Se estiver fechada e trancada, retorna 2 (ja esta trancada)
 * Se estiver aberta, retorna 0 (nao pode trancar).
 */
int Porta::trancar() {
	if(!aberta){
		if(!trancada){
			//codigo do motor
			trancada = true;
			return 1;
		}
		else{
			return 2;
		}
	}
	else{
		return 0;
	}
	return 0;
}
/*
 * Tenta destrancar a porta e retorna o seguinte codigo:
 * Se estiver fechada e trancada, a destranca e retorna 1
 * Se estiver aberta, retorna 0.
 *
 */
int Porta::destrancar() {
	if(!aberta){
		if(trancada){
			//codigo de trancar
			trancada = false;
			return 1;
		}
		else{
			return 2;
		}
	}
	else{
		return 0;
	}
	return 0;
}

/*
 * Tenta abrir a porta seguindo o seguinte padrão:
 * Se estiver fechada e destrancada, a abre e retorna 1(sucesso)
 * Se ja estiver
 * Se estiver fechada e trancada, retorna 0 (nao da pra abrir)
 */
int Porta::abrir() {
	if(!aberta){
		if(!trancada){
			//codigo de abrir a porta
			aberta = true;
			return 1;
		}
		else{
			return 0;
		}
	}
	else{
		return 2;
	}
	return 0;
}

/*
 * Tenta fechar a porta
 * Se ela estiver aberta, a fecha e retorna 1 (sucesso)
 * Se ela estiver fechada, retorna 2 (ja fechada)
 * Se
 */
int Porta::fechar() {
	//se estiver aberta
	if(aberta){
		//codigo de fechar o motor
		aberta = false;
		return 1;
	}
	//se ja estiver fechada
	else{
		return 2;
	}
}

string Porta::toString(){
	string aux="";
	if(aberta){
		aux+="Porta esta aberta.";
	}
	else{
		aux+="Porta esta fechada e";

		if(trancada){
			aux+=" trancada.";
		}

		else{
			aux+=" destrancada.";
		}
	}

	return aux;

}

