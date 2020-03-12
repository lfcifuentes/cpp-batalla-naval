#include "partida.hpp"

// constructor
partida::partida(){};

// destructor
partida::~partida(){}

// iniciar la batalla
void partida::iniciarJuego(){
	
	int res;
	cout 
    << "---------------------- BATALLA NAVAL ----------------------\n";
    cout <<"        |*" << endl; 
	cout <<"        |**" << endl; 
	cout <<"        |****" << endl; 
	cout <<"        |******" << endl; 
	cout <<"        | " << endl; 
	cout <<"  \\***************/" << endl; 
	cout <<"   \\***o*****o***/" << endl; 
	cout <<"    \\***********/" << endl; 
	cout <<"~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "------------menu principal:------------------"<< endl;
	cout << "1) jugar." << endl;
	cout << "2) cargar juego." << endl;
	cin >> res;
	
	if(res == 1){
		turno(1,1);
	}
};

void partida::turno(int Jugador, int Turno){
	system("clear");
	cout << "Turno del Jugador " << Jugador << ":"<< endl; 
	jugador *Actual = new jugador();
	if(Turno == 1){
		int resUbicar;
		Actual->setAcierto();
		Actual->MisTableros.vaciarTableros(); 
		bool errorUB;
		errorUB = true;
		// capturar si se ingresa una opción invalida;
		while(errorUB){
			cout << "Como deceas ubicar los barcos?. \n "<< endl;
			cout << "1) a mano. \n "<< endl;
			cout << "2) aleatoriamente "<< endl;
			cin >> resUbicar;
			//si la opción no es valida retorna el mensaje 
			if((resUbicar < 1) or (resUbicar >2)){
				cout << "Opcion invalida por favor seleccione (1) o (2)" << endl;
			}else{
				// si la opción es valida sigue con la ejecucion
				errorUB = false;
			}
		}
		if(resUbicar == 1){
			Actual->MisTableros.ubicarBarcos(1); 
		}else{
			Actual->MisTableros.ubicarBarcosAleaotio(1);
		}
		Actual->MisTableros.verTableroJugador();
		Actual->MisTableros.verTableroDisparos();
		cout << "has ubicato todos tus barcos. \n "<< endl;
		cout << "Pulsa la tecla '1' Y ENTER para continuar "<< endl;
		if(Jugador == 1){			
			jugador1 = Actual;
			turno(2,Turno);
		}else{
			jugador2 = Actual;
			turno(1,Turno+=1);
		}
	}else{
		if(Jugador == 1){
			jugador1->MisTableros.verTableroJugador();
			jugador1->MisTableros.verTableroDisparos();
		}else{
			jugador2->MisTableros.verTableroJugador();
			jugador2->MisTableros.verTableroDisparos();
		}
		int px, py, continuar;
		cout << "Ingresa la cordanada en x del disparo:"<< endl;
		cin >> py;
		cout << "Ingresa la cordanada en y del disparo:"<< endl;
		cin >> px;
		if(Jugador == 1){
			jugador1->getDisparo(px,py,jugador2->MisTableros.verTableroPosicion(1,px,py));
			jugador1->MisTableros.verTableroJugador();
			jugador1->MisTableros.verTableroDisparos();
			if(jugador2->MisTableros.verTableroPosicion(1,px,py) == 'B'){
				jugador1->acierto();
			}
			if(jugador1->getAciertos() == 21){
				system("clear");
				cout << "FELICIDADES HAS GANADO LA PARTIDA!! \n \n "<< endl;
				cout << "el jugador1 ha ganado la partida. \n "<< endl;
				cout << "Pulsa la tecla '1' Y ENTER para continuar "<< endl;
				cin >> continuar;
				iniciarJuego();
			}
			if(jugador2->MisTableros.verTableroPosicion(1,px,py) == 'B'){
				cout << "FELICIDADES HAS ACERTADO UN TIRO!! \n \n "<< endl;
				turno(1,Turno);
			}else{
				cout << "NO HAS ACERTADO EL TIRO, MEJOR SUERTE TU PROXIMO TURNO.!! \n \n "<< endl;
				cout << "Pulsa la tecla '1' Y ENTER para continuar "<< endl;
				cin >> continuar;
				turno(2,Turno);
			}
		}else{
			jugador2->getDisparo(px,py,jugador1->MisTableros.verTableroPosicion(1,px,py));
			jugador2->MisTableros.verTableroJugador();
			jugador2->MisTableros.verTableroDisparos();
			if(jugador1->MisTableros.verTableroPosicion(1,px,py) == 'B'){
				jugador2->acierto();
			}
			if(jugador2->getAciertos() == 21){
				system("clear");
				cout << "FELICIDADES HAS GANADO LA PARTIDA!! \n \n "<< endl;
				cout << "el jugador2 ha ganado la partida. \n "<< endl;
				cout << "Pulsa la tecla '1' Y ENTER para continuar "<< endl;
				cin >> continuar;
				iniciarJuego();
			}
			if(jugador1->MisTableros.verTableroPosicion(1,px,py) == 'B'){
				cout << "FELICIDADES HAS ACERTADO UN TIRO!! \n \n "<< endl;
				turno(2,Turno);
			}else{
				cout << "NO HAS ACERTADO EL TIRO, MEJOR SUERTE TU PROXIMO TURNO.!! \n \n "<< endl;
				cout << "Pulsa la tecla '1' Y ENTER para continuar "<< endl;
				cin >> continuar;
				turno(1,Turno+=1);
			}
		}
	}
	delete Actual;
}
