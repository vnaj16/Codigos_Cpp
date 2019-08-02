#pragma once
#include <iostream>
#include <conio.h>

using namespace std;
using namespace System;

class paraguas {
private:
	int Posicion_X, Posicion_Y;
	bool Usado = false;
public:
	paraguas(int x, int y) {
		Posicion_X = x;
		Posicion_Y = y;
	}

	~paraguas() {
		cout << "Paraguas destruido" << endl;
	}

	int getPosicion_X() {
		return Posicion_X;
	}

	void setUsado(bool a) {
		Usado = a;
	}

	void setPosicion_X(int x) {
		Posicion_X = x;
	}

	void setPosicion_Y(int y) {
		Posicion_Y = y;
	}

	void Mostrar_Datos() {
		cout << "El paraguas esta en el eje x " << Posicion_X << " y en el eje y " << Posicion_Y << endl;
	} 

	void Mostrar_Uso() {
		cout << "El paraguas " << (Usado==true ? "" : "no") << " esta en uso" << endl;
	}



};