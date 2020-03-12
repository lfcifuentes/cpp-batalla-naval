#include "tableros.hpp"
#include <stdlib.h>
#include <time.h>

using namespace std;

using std::string;

// constructor  de la clase tablero
tablero::tablero(){};						

//destructor de la clase tablero
tablero::~tablero(){};						

//vaciar los tableros y llenarlos con agua
void tablero::vaciarTableros(){
	for(int i = 0; i <= 9; i++){ 
		for(int e = 0; e <= 9; e++){ 
			this->tableroJugador[i][e] = new char('~'); 
			this->tableroDisparos[i][e] = new char('~'); 
		}
	} 
};			


void tablero::verTableroDisparos(){
	// pintar el tablero de disparos en consola
	cout << " Tus disparos" << endl; 
	for(int i = 0; i < 10; i++){
		if(i == 0){
				cout << "    ";
		}
		for(int e = 0; e < 10; e++){
			if(i == 0){
				cout << " | "  << e ;		 
			}  
		}
		if(i == 0){
				cout << "\n";
		}
		cout << " | " << i;
			
		for(int e = 0; e < 10; e++){ 
			cout << " | " << *tableroDisparos[i][e];
				 
		}	cout << "\n";
	}
}
void tablero::verTableroJugador(){ 
	// pintar el tablero del jugador en consola
	cout << "Tus barcos"  << endl;
	for(int i = 0; i < 10; i++){
		if(i == 0){
				cout << "  ";
		}
		for(int e = 0; e < 10; e++){
			if(i == 0){
				cout << "|"  << e ;		 
			}  
		}
		if(i == 0){
				cout << "\n";
		}
		cout << "|" << i;
			
		for(int e = 0; e < 10; e++){ 
			cout << "|" << *tableroJugador[i][e];
				 
		}	cout << "\n";
	}
}

// ver una posicion de un tablero
char tablero::verTableroPosicion(int tabla, int x, int y){
	if(tabla == 1){
		return *tableroJugador[x][y];
	}else{
		return *tableroDisparos[x][y];
	}
};
void tablero::disparar(char Tablero, int x, int y){
	
	if(Tablero == 'B'){
		tableroDisparos[x][y] = new char('X');
	}else{
		tableroDisparos[x][y] = new char('0');
	}
};
void tablero::ubicarBarcos(int iteracion){
	system("clear");
	verTableroJugador();
	int x , y , pos ,tam; 
	cout << "Ubicar el barco ";
	switch(iteracion){
	case 1: 
		cout << " Porta aviones de 4 posicione";
		tam = 4;
		break;
	case 2: case 3: case 4 :
		cout << " Acorazado o Submarino de 3 posiciones";
		tam = 3;
		break;
	case 5: case 6: case 7:
		cout << " Destructor de 2 posiciones" ;
		tam = 2;
		break;
	case 8: case 9:
		cout << " Fragata de 1 posicion";
		tam = 1;
		break;
	default :
		cout << "" << endl;
		break;
	}	
	bool errorPos;
	errorPos = true;
	// capturar si se ingresa una opción invalida;
	while(errorPos){
		cout << "\n como decea ingresar el barco: " << endl;
		cout << "1) vertical " << endl;
		cout << "2) horizontal" << endl; 
		cin >> pos;
		//si la opción no es valida retorna el mensaje 
		if((pos < 1) or (pos >2)){
			cout << "Opcion invalida por favor seleccione (1) o (2)" << endl;
		}else{
			// si la opción es valida sigue con la ejecucion
			errorPos = false;
		}
	} 
	coordenada *newC = new coordenada();
	bool errorX;
	errorX = true;
	// capturar si se ingresa una posicion invalida para el barco;
	while(errorX){		
		cout << "Ingrese las coordenadas del barco \n posicion en x =";
		cin >> x;
		// si la poicion es invalida retorno un mensaje 
		if((x > 9) or (x < 0)){
			cout << "La posicion ingresada es invalida!! " << endl;
		}else{
		// si la posicion es valida continuo con la ejecucion
			errorX = false;
		}
	}
	bool errorY;
	errorY = true;
	// capturar si se ingresa una posicion invalida para el barco;
	while(errorY){
		cout << "Posicion en y =";
		cin >> y; 
		// si la poicion es invalida retorno un mensaje 
		if((y > 9) or (y < 0)){
			cout << "La posicion ingresada es invalida!! "<< endl;
		}else{
		// si la posicion es valida continuo con la ejecucion
			errorY = false;
		}
	}
	newC->setCordenada(x,y);
	coordenada *newC2 = new coordenada();
	// calcular la posicion maxima del barco;
	int max = 9 - (tam - 1);
	int e , i;
	// verificar si la posicion en vertical 
	if(pos == 1){ 
		// verificar si la posicion en y es menor que el maximo permitido 
		if(y < max){
		// si no lo es pinto en el tablero un barco desde la posicion dada hasta el tamaño
		// del mismo hacia la derecha 
			e = y;
			y = y - tam; 
			for(i = 0 ; i< tam; i++){
				tableroJugador[e][x] = new char('B');
				e +=1; 
			}
		}else{
		// si es mayor pinto en el tablero un barco desde la posicion dada hasta el tamaño
		// del mismo hacia la izquierda 
			e = y;
			y = y + tam; 
			for(i = 0; i < tam; i++){
				tableroJugador[e][x] = new char('B');
				e = e - 1; 
			}
		} 
	}else{
		// si la poicion es hacia la derecha:
		// verifico i la posicion en x es menor que el maximo permitido
		if(x < max){
		// si  lo es pinto en el tablero un barco desde la posicion dada hasta el tamaño
		// del mismo hacia la abajo 
			e = x;
			x = x - tam; 
			for(i = 0 ; i< tam; i++){
				tableroJugador[y][e] = new char('B');
				e +=1; 
			}
		}else{
		// si no lo es pinto en el tablero un barco desde la posicion dada hasta el tamaño
		// del mismo hacia arriba 
			e = x;
			x = x + tam; 
			for(i = 0; i < tam; i++){
				tableroJugador[y][e] = new char('B');
				e = e - 1; 
			}
		} 
	}
	newC2->setCordenada(x,y);
	barco *Barco = new barco();
	Barco->setCoordenada( *newC , 1);
	Barco->setCoordenada( *newC2 , 1);
	Barco->setReferencia(iteracion);	
	Barco->setSimbolo("B");
	Barco->setEstado(1);
	Barco->setPuestos(tam);
	switch(iteracion){
		case 1:
			this->Barco1 = Barco;
			break;
		case 2: 
			this->Barco2 = Barco;
			break;
		case 3:
			this->Barco3 = Barco;
			break;
		case 4 :
			this->Barco4 = Barco;
			break;
		case 5:
			this->Barco5 = Barco;
			break;
		case 6: 
			this->Barco6 = Barco;
			break;
		case 7:
			this->Barco7 = Barco;
			break;
		case 8:
			this->Barco8 = Barco;
			break;
		case 9:
			this->Barco9 = Barco;
			break;
		default:
			cout << ""<< endl;
		break;
	}
	
	if(iteracion < 9){
		iteracion += 1;
		ubicarBarcos(iteracion);
	} 
	
} 


void tablero::ubicarBarcosAleaotio(int iteracion){
	
	for(int in=0; in < 9; in++){
		iteracion += in;
		cout<< "ite" << in << endl;
		int x , y , pos ,tam;  
		// saber cual barco voy a generar
		switch(iteracion){
		case 1: 
			tam = 4;
			break;
		case 2: case 3: case 4 :
			tam = 3;
			break;
		case 5: case 6: case 7:
			tam = 2;
			break;
		case 8: case 9:
			tam = 1;
			break;
		default :
			break;
		}
		// posicion del barco horizontal o vertical 
		srand(time(NULL));
		pos = 1 + rand() % (3 - 1); 
		coordenada *newC = new coordenada();
		// cordenadas del barco 
		x = 1 + rand() % (11 - 1);
		y = 1 + rand() % (11 - 1);
		
		y -=1;
		x -=1;		 
		newC->setCordenada(x,y);
		coordenada *newC2 = new coordenada();
		int max = 9 - (tam - 1);
		int e , i;
		if(pos == 1){ 
			if(y < max){
				e = y;
				y = y - tam; 
				for(i = 0 ; i< tam; i++){
					tableroJugador[e][x] = new char('B');
					e +=1; 
				}
			}else{
				e = y;
				y = y + tam; 
				for(i = 0; i < tam; i++){
					tableroJugador[e][x] = new char('B');
					e = e - 1; 
				}
			} 
		}else{
			if(x < max){
				e = x;
				x = x - tam; 
				for(i = 0 ; i< tam; i++){
					tableroJugador[y][e] = new char('B');
					e +=1; 
				}
			}else{
				e = x;
				x = x + tam; 
				for(i = 0; i < tam; i++){
					tableroJugador[y][e] = new char('B');
					e = e - 1; 
				}
			} 
		}
		newC2->setCordenada(x,y);
		barco *Barco = new barco();
		Barco->setCoordenada( *newC , 1);
		Barco->setCoordenada( *newC2 , 1);
		Barco->setReferencia(iteracion);	
		Barco->setSimbolo("B");
		Barco->setEstado(1);
		Barco->setPuestos(tam);
		switch(iteracion){
			case 1:
				this->Barco1 = Barco;
				break;
			case 2: 
				this->Barco2 = Barco;
				break;
			case 3:
				this->Barco3 = Barco;
				break;
			case 4 :
				this->Barco4 = Barco;
				break;
			case 5:
				this->Barco5 = Barco;
				break;
			case 6: 
				this->Barco6 = Barco;
				break;
			case 7:
				this->Barco7 = Barco;
				break;
			case 8:
				this->Barco8 = Barco;
				break;
			case 9:
				this->Barco9 = Barco;
				break;
			default:
				cout << ""<< endl;
			break;
		}
	}	
} 
