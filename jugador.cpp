#include "jugador.hpp"

using namespace std;

using std::string;

// constructor  de la clase tablero
jugador::jugador(){};						

//destructor de la clase tablero
jugador::~jugador(){};	
					
// inicializar aciertos en 0					
void jugador::setAcierto(){
	this->aciertos = 0;
} 

//sumar un acierto
void jugador::acierto(){
	this->aciertos += 1 ;
};	

// retornar los acierto del juegor
int jugador::getAciertos(){
	return aciertos;
}


void jugador::getDisparo(int x, int y,char contenidoTablaOponente){
	this->MisTableros.disparar(contenidoTablaOponente, x,y);
};
