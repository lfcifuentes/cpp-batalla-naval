//Guardas
#ifndef COORDENADAS_CPP
#define COORDENADAS_CPP
// inclucion de librerias 
#include <iostream>
#include <cstdlib>
#include <string>
#include "coordenadas.hpp"

using namespace std;

using std::string;
// conntructor
coordenada::coordenada(){};

// conntructor con para metros
coordenada::coordenada(int x, int y){
		this->X = x;
		this->Y = y;
};

// destructor
coordenada::~coordenada(){};

// guardar coordenada
void coordenada::setCordenada(int x, int y){
		this->X = x;
		this->Y = y;
	}
	
// saber coordenada en x
int coordenada::getCordenadaX(){
		return this->X;
	}
// saber coordenada en y
int coordenada::getCordenadaY(){
		return this->Y;	
	}
#endif


