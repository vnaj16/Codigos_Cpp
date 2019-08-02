#pragma once
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;
using namespace System;

class mascota {
protected:
	string *Nombre = new string;
	bool Vacunado = false;
public:
	mascota(string _Nombre, bool Vacunado) {
		*Nombre = _Nombre;
		this->Vacunado = Vacunado;
	}
	mascota() {

	}

	string getNombre() {
		return *Nombre;
	}
	bool getVacunado() {
		return Vacunado;
	}

	void setNombre(string Name) {
		*Nombre = Name;
	}

	void setVacunado(bool a) {
		Vacunado = a;
	}

	void Mostrar_Datos_Mascota() {
		cout << "Nombre: " << *Nombre << endl;
		cout << (Vacunado? "si": "no")<<" esta vacunado " << endl;
	}


};