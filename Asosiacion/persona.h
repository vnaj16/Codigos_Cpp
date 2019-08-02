#pragma once
#include <iostream>
#include <conio.h>
#include "paraguas.h"
#include <string>

using namespace std;
using namespace System;

class persona {
private:
	int Posicion_X, Posicion_Y;
	string *Nombre = new string;
	paraguas *Paraguas;
public:
	persona(string _Nombre, int X, int Y, paraguas *Paraguas){
		*Nombre = _Nombre;
		Posicion_X = X;
		Posicion_Y = Y;
		this->Paraguas = Paraguas;
		Paraguas->setPosicion_X(Posicion_X);
		Paraguas->setPosicion_Y(Posicion_Y);
		Paraguas->setUsado(true);
	}

	~persona() {
		cout << "Persona destruida" << endl;
		Paraguas->setUsado(false);
	}

	void Mostrar_Datos() {
		cout << *Nombre << " esta usando el paraguas en el eje x " << Posicion_X << " y eje y " << Posicion_Y << "." << endl;
		
	}


};