#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include "bateria.h"

using namespace std;
using namespace System;

class celular {
private:
	string *Marca = new string;
	int Anio;
	bateria *Bateria = new bateria;
public:
	celular(string Marca, int Anio) {
		*this->Marca = Marca;
		this->Anio = Anio;
	}
	~celular() {
		delete Bateria;
		delete Marca;
		Bateria = NULL;
		cout << "Celular Destruido";
	}

	bateria* getBateria() {

		return Bateria;
	}

	void Mostrar_Datos() {
		cout << "El celular de marca " << *Marca << " del anio " << Anio << " tiene una bateria de " << Bateria->getCapacidad() << " mAh"<<endl;
	}



};