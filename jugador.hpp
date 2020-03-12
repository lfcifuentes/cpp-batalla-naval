//Guardas
#ifndef JUGADOR_HPP
#define JUGADOR_HPP
// inclucion de librerias 
#include <iostream>
#include <cstdlib>
#include <string>
#include "tableros.cpp"

using namespace std;

using std::string;

// clase jugador
class  jugador{
    public:
		jugador();						//contructor
		//jugador(int aciertos, int tipo, tablero MiTablero);			//contructor con parametros
		~jugador();						//destructor
    	void getDisparo(int x, int y,char contenidoTablaOponente);	//ingresar coordenada
    	void setAcierto();				// ingresar primer acierto
    	void acierto();					// sumar un acierto
		int getAciertos();				// ver los aciertos
		tablero MisTableros;
		
	private:	
		int aciertos;					// cantidad de disparos acertados					
};

#endif


