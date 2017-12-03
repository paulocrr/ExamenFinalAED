#pragma once
#include<iostream>
#include "string.h"
#include <algorithm> 
#include<stack>
#include<queue>
#include "cAvlTree.h"
#include "cLinkedList.h"
using namespace std;
class miniSistema
{
public:
	int edad_max = 40;
	cAvlTrees<string> posiciones;
	cAvlTrees<string> paises;
	cAvlTrees<int> edades;
	cLinkedList jugadores;
	miniSistema() {
		posiciones.Insert("portero");
		posiciones.Insert("delantero");
		posiciones.Insert("defensa");
		posiciones.Insert("mediocampista");
		//posiciones.imprimir();
		paises.Insert("rusia");
		paises.Insert("brasil");
		paises.Insert("iran");
		paises.Insert("japon");
		paises.Insert("mexico");
		paises.Insert("belgica");
		paises.Insert("coreadelsur");
		paises.Insert("arabiasaudi");
		paises.Insert("alemania");
		paises.Insert("inglaterra");
		paises.Insert("espania");
		paises.Insert("nigeria");
		paises.Insert("costarica");
		paises.Insert("polonia");
		paises.Insert("egipto");
		paises.Insert("islandia");
		paises.Insert("serbia");
		paises.Insert("portugal");
		paises.Insert("francia");
		paises.Insert("uruguay");
		paises.Insert("argentina");
		paises.Insert("colombia");
		paises.Insert("panama");
		paises.Insert("senegal");
		paises.Insert("marruecos");
		paises.Insert("tunez");
		paises.Insert("suiza");
		paises.Insert("croacia");
		paises.Insert("suecia");
		paises.Insert("dinamarca");
		paises.Insert("australia");
		paises.Insert("peru");
		//paises.imprimir();
		for (int i = 18; i < 40; i++) {
			edades.Insert(i);
		}
		//edades.imprimir();
	}
	struct less_than_key
	{
		inline bool operator() (const cNodeList* struct1, const cNodeList* struct2)
		{
			return (struct1->camiseta < struct2->camiseta);
		}
	};
	bool insertarJugador(int camiseta, string apellido, string posicion, int edad, string seleccion) {
		cNodeList *jugador = jugadores.insert(camiseta, apellido, posicion, edad, seleccion);
		edades.Insert(edad);
		cNode<string> **p;
		cNode<int> **e;
		cNode<string> *country = paises.FindNode(seleccion, p);
		cNode<string> *pos = posiciones.FindNode(posicion, p);
		cNode<int> *age = edades.FindNode(edad, e);
		if (pos != nullptr && age != nullptr &&country != nullptr) {
			country->jugadores.push_back(jugador);
			pos->jugadores.push_back(jugador);
			age->jugadores.push_back(jugador);
			return 1;
		}
		jugadores.remove(jugadores.lastId - 1);
		jugadores.lastId--;
		return 0;
		
	}
	bool deleteJugador(int id) {
		cNodeList **j;
		if (jugadores.findNode(id, j)) {
			cNode<string> **p;
			cNode<int> **e;
			cNode<string> *country = paises.FindNode((*j)->seleccion, p);
			cNode<string> *pos = posiciones.FindNode((*j)->posicion, p);
			cNode<int> *age = edades.FindNode((*j)->edad, e);
			findAndDeleteElement(id, country->jugadores);
			findAndDeleteElement(id, pos->jugadores);
			findAndDeleteElement(id, age->jugadores);
			jugadores.remove(id);
			return 1;
		}
		return 0;
	}
	void listByOrder(){
		cout << "Listado de Jugadores total: " << endl;
		jugadores.printList();
	}
	void listByCountry(string pais) {
		cNode<string> **p;
		cNode<string> *country = paises.FindNode(pais, p);
		if (country != nullptr) {
		sort(country->jugadores.begin(), country->jugadores.end(), less_than_key());
			cout << "Jugadores de la Seleccion de: " << pais << endl;
			for (unsigned int i = 0; i < (country->jugadores).size(); i++) {
				cout << "id: " << country->jugadores[i]->id << " - Caminseta: " << country->jugadores[i]->camiseta << " - Apellido: " << country->jugadores[i]->apellido << " - Posicion: " << country->jugadores[i]->posicion << " - Edad: " << country->jugadores[i]->edad << " - Seleccion: " << country->jugadores[i]->seleccion << endl;
			}
		}
		else {
			cout << "El pais no se encuentra en nuestra base de datos" << endl;
		}
		
	}
	void listByPosition(string posicion) {
		cNode<string> **p;
		cNode<string> *pos = posiciones.FindNode(posicion, p);
		if (pos != nullptr) {
			sort(pos->jugadores.begin(), pos->jugadores.end(), less_than_key());
			for (unsigned int i = 0; i < pos->jugadores.size(); i++) {
				cout << "id: " << pos->jugadores[i]->id << " - Caminseta: " << pos->jugadores[i]->camiseta << " - Apellido: " << pos->jugadores[i]->apellido << " - Posicion: " << pos->jugadores[i]->posicion << " - Edad: " << pos->jugadores[i]->edad << " - Seleccion: " << pos->jugadores[i]->seleccion << endl;
			}
		}
		else {
			cout << "La posicion no se encuentra en nuestra base de datos" << endl;
		}
	}
	void listByAges(int min, int max) {
		cNode<int> **e;
		cNode<int> *age = edades.FindNode(min, e);
		vector<cNodeList *> res;
		
		res = edades.selectRange(min, max);
		if (res.size() == 0) {
			cout << "No hay resultados" << endl;
			cout << endl;
		}
		else {
			sort(res.begin(), res.end(), less_than_key());
			for (unsigned int i = 0; i < res.size(); i++) {
				cout << "id: " << res[i]->id << " - Caminseta: " << res[i]->camiseta << " - Apellido: " << res[i]->apellido << " - Posicion: " << res[i]->posicion << " - Edad: " << res[i]->edad << " - Seleccion: " << res[i]->seleccion << endl;
			}
		}
		
	}
	~miniSistema(){
	}
private:
	void findAndDeleteElement(int id, vector<cNodeList*> &v) {
		int i = 0;
		while (id != v[i]->id) {
			i++;
		}
		v.erase(v.begin() + i);
	}

};
