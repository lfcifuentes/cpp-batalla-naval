#include "barco.hpp"

// constructor
barco::barco(){};

// detructor
barco::~barco(){};

// referencia del barco
void barco::setReferencia(int ref){
	this->referencia  = ref;
};

//retornar referencia del barco
int  barco::getReferencia(){
	return this->referencia;
};			

//ver coordenada en x
void  barco::setSimbolo(string sim){
	this->simbolo = sim;
};	

//ingresar el simbolo
string  barco::getSimbolo(){
	return this->simbolo;
};			

//ver el simbolo
void barco::setEstado(int est){
	this->estado = est;
};		

// ingrear el estado
int barco::getEstado(){
	return this->estado;
};

// ingresar una coordenada
bool barco::setCoordenada(coordenada &cor, int tipo){
	if(tipo == 1){
		this-> coordenadaInicio = &cor;
		return true;
	}else if(tipo == 2){
		this-> coordenadaFin = &cor;
		return true;
	}else{return false;}
};

// ingrear una coordenada
coordenada barco::getCoordenada(int tipo){
	if(tipo == 1){
		return *coordenadaInicio;
	}else {
		return *coordenadaFin;
	}
};
// ingresar los puetos
void barco::setPuestos(int puesto){
	this->puestos = puesto;
};								

// ingresar el total de puetos
int barco::getPuestos(){
	return this->puestos;
};								

// ver el total e puestos
void barco::acierto(){
	this->aciertos = this->aciertos + 1;
};	

int barco::getAciertos(){
	return this->aciertos;
};
		
