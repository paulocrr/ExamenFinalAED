#pragma once
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
class cNodeList
{
public:
	int id;
	int camiseta;
	string apellido;
	string posicion;
	int edad;
	string seleccion;
	cNodeList *next;
	cNodeList() {
		id = NULL;
		camiseta = NULL;
		apellido = "";
		posicion = "";
		edad = NULL;
		seleccion = "";
		next = nullptr;
	}
	cNodeList(int id,int camiseta,string apellido,string posicion, int edad, string seleccion) {
		this->id = id;
		this->camiseta = camiseta;
		this->apellido = apellido;
		this->posicion = posicion;
		this->edad = edad;
		this->seleccion = seleccion;
		next = nullptr;
	}
	~cNodeList() {
	}
};

