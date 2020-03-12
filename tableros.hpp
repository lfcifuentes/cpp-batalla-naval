//Guardas
#ifndef TABLEROS_HPP
#define TABLEROS_HPP
// inclucion de librerias 
#include <iostream>
#include <cstdlib>
#include <string>
#include "barco.cpp"

using namespace std;

using std::string;

// clase tablero
class tablero{
    public:
		tablero();						//contructor
		~tablero();						//destructor
    	void vaciarTableros();			//vaciar los tableros
    	void verTableroJugador();		// ver tablero del jugador
    	void verTableroDisparos();		// ver tablero con disparos
    	char verTableroPosicion(int tabla, int x, int y); // ver que hay en un tablero en la posicion dada 
		void disparar(char Tablero, int x, int y); //disparar a una posicion
    	void ubicarBarcos(int iteracion);			//  ubicar los barcos
    	void ubicarBarcosAleaotio(int iteracion);	//ubicar los barcos de forma aleatoria 
    	 
     private:
		char *tableroJugador[10][10] ;		// tablero con los barcos del jugador
		char *tableroDisparos[10][10] ;	// tablero con los disparos del jugador
        
        // barcos del jugador:
        barco *Barco1; // porta aviones 	
        barco *Barco2; // acorazado o submarino 
        barco *Barco3; // acorazado o submarino
        barco *Barco4; // acorazado o submarino
        barco *Barco5; // destructor
        barco *Barco6; // destructor
        barco *Barco7; // destructor
        barco *Barco8; // fragata
        barco *Barco9; // fragata
};

#endif

