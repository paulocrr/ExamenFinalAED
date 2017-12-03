#pragma once
#include "cNodeList.h"
class cLinkedList
{
public:
	cNodeList *head = nullptr;
	int numNodes = 0;
	int lastId = 1;
	cLinkedList() {
	}
	cLinkedList(int camiseta,string apellido,string posicion,int edad,string seleccion) {
		cNodeList *node = new cNodeList(lastId,camiseta,apellido,posicion,edad,seleccion);
		head = node;
		numNodes++;
		lastId++;
	}
	bool findNode(int x, cNodeList **& n) {
		n = &head;
		while (*n && (*n)->id < x) {
			n = &((*n)->next);
		}
		return *n && (*n)->id == x;
	}
	bool find(int x, cNodeList **& n) {
		n = &head;
		while (*n && (*n)->id < x) {
			n = &((*n)->next);
		}
		return *n && (*n)->id == x;
	}

	cNodeList* insert(int camiseta, string apellido, string posicion, int edad, string seleccion) {
		cNodeList **n;
		cNodeList *temp = new cNodeList(lastId, camiseta, apellido, posicion, edad, seleccion);
		if (find(lastId, n)) {
			return nullptr;
		}
		temp->next = *n;
		*n = temp;
		lastId++;
		return *n;
	}

	bool remove(int id) {
		cNodeList **n;
		if (find(id, n)) {
			cNodeList *temp = *n;
			n = &((*n)->next);
			delete temp;
			return true;
		}
		return false;
	}
	void printList() {
		cNodeList *p = head;
		while (p->next)
		{
			cout << "id: " <<p->id << " - camiseta: " << p->camiseta << " - apellido: " << p->apellido << " - posicion: "<<p->posicion << "- edad: "<<p->edad<<"- seleccion: "<<p->seleccion<< endl;
			p = p->next;
		}
		cout << "id: " << p->id << " - camiseta: " << p->camiseta << " - apellido: " << p->apellido << " - posicion: " << p->posicion << "- edad: " << p->edad << "- seleccion: " << p->seleccion << endl;
	}
	~cLinkedList() {

	}
};

