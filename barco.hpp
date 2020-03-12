//Guardas
#ifndef BARCO_HPP
#define BARCO_HPP
// inclucion de librerias 
#include <iostream>
#include <cstdlib>
#include <string>
#include "coordenadas.cpp"

using namespace std;

using std::string;

// clase barco
class  barco{
    public:
		barco();										//contructor
		~barco();										//destructor
    	void setReferencia(int ref);					//ingresar referebcia del barco
    	int  getReferencia();							//ver coordenada en x
    	void  setSimbolo(string sim);					//ingresar el simbolo
    	string  getSimbolo();							//ver el simbolo
    	void setEstado(int est);						// ingrear el estado
    	int getEstado();								// ver el estado
		bool setCoordenada(coordenada &cor, int tipo);	// ingrear una coordenada
    	coordenada getCoordenada(int tipo);				// ver una coordenada
		void setPuestos(int puesto);								// ingresar el total de puetos
		int getPuestos();								// ver el total e puestos
		void acierto();									// sumar un acierto
		int getAciertos();								// ver los aciertos
    
    private:
        int referencia;
        string simbolo;
        int estado;
        int puestos;
        int aciertos;
        coordenada *coordenadaInicio;
        coordenada *coordenadaFin;
};

#endif
