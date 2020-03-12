//Guardas
#ifndef COORDENADAS_HPP
#define COORDENADAS_HPP
// inclucion de librerias 
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

using std::string;

// clase coordenada
class  coordenada{
    public:
		coordenada();						//contructor
		coordenada(int x, int y);   		//contructor
		~coordenada();						//destructor
    	void setCordenada(int x, int y);	//ingresar coordenada
    	int  getCordenadaX();				//ver coordenada en x
    	int  getCordenadaY();				//ver coordenada en y
    	
    private:
        int X;
        int Y;
};

#endif
