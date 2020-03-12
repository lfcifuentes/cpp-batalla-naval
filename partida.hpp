//Guardas
#ifndef PARTIDA_HPP
#define PARTIDA_HPP
// inclucion de librerias 
#include <iostream>
#include <cstdlib>
#include <string>
#include "jugador.cpp"

using namespace std;

using std::string;

// clase partida
class  partida{
    public:
		partida();						//contructor
		~partida();						//destructor
    	void iniciarJuego();
    	void turno(int Jugador, int turno); 
		jugador *jugador1;					// jugador 1
		jugador *jugador2;					// jugador 2
	private:
		bool ganador;						
};

#endif



