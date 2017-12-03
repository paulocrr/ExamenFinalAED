// ExamenFinal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "cLinkedList.h"
#include "miniSistema.h"

using namespace std;
void Menu() {
	int opcion = 0;
	int camiseta;
	string apellido;
	string posicion;
	int edad;
	string seleccion;
	miniSistema sys;
	cout << "Base de Datos Jugadores" << endl;
	while (true) {
		cout << "1) Ingresar Jugador" << endl;
		cout << "2) Borrar Jugador" << endl;
		cout << "3) Listar jugadores por orden ingresado" << endl;
		cout << "4) Listar jugadores por seleccion" << endl;
		cout << "5) Listar jugadores por posicion" << endl;
		cout << "6) Listar jugadores por rango de edades" << endl;
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		cout << endl;
		switch (opcion){
		case 1:
			cout << "Ingrese el numero de camiseta: ";
			cin >> camiseta;
			cout << endl;
			cout << "Ingrese apellido: ";
			cin >> apellido;
			cout << endl;
			cout << "Ingrese posicion: ";
			cin >> posicion;
			cout << endl;
			cout << "Ingrese edad: ";
			cin >> edad;
			cout << endl;
			cout << "Ingrese seleccion: ";
			cin >> seleccion;
			cout << endl;
			if (sys.insertarJugador(camiseta, apellido, posicion, edad, seleccion)) {
				cout << "Se inserto el Jugador" << endl;
			}
			else {
				cout << "Hubo un error, la posisicion o la seleccion no estan en nuestra base de datos" << endl;
			}
			break;
		case 2:
			int id;
			cout << "Ingrese el id del jugador que quiere borrar: ";
			cin >> id;
			if (sys.deleteJugador(id)) {
				cout << "Se borro el jugador" << endl;
				break;
			}
			cout << "El id que quiere borrar no existe" << endl;
			break;
		case 3:
			sys.listByOrder();
			break;
		case 4:
			cout << "Ingrese la seleccion que quiere filtrar: ";
			cin >> seleccion;
			sys.listByCountry(seleccion);
			break;
		case 5:
			cout << "Ingrese la posicion que quiere filtrar: ";
			cin >> posicion;
			sys.listByPosition(posicion);
			break;
		case 6:
			int mini, maxi;
			cout << "Ingrese Edad Minima: ";
			cin >> mini;
			cout << endl;
			cout << "Ingrese Edad Maxima: ";
			cin >> maxi;
			cout << endl;
			sys.listByAges(mini,maxi);
			break;
		default:
			cout << "Ingrese una opcion valida" << endl;
			break;
		}
	}
}


int main()
{
	Menu();

}

