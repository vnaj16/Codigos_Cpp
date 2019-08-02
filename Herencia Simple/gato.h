#pragma once
#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include "animal.h"
#include "mascota.h"

class gato: public animal, public mascota{
private:
	string *Raza = new string;
	int Edad;
public:
	gato(int Cantidad_Patas, string Nombre, bool Vacunado, string Raza, int Edad) : animal(Cantidad_Patas), mascota(Nombre, Vacunado) {
		*this->Raza = Raza;
		this->Edad = Edad;
	}
	gato() {

	}

	string getRaza() {
		return *Raza;
	}
	int getEdad() {
		return Edad;
	}

	void setRaza(string Raza) {
		*this->Raza = Raza;
	}
	void setEdad(int Edad) {
		this->Edad = Edad;
	}

	void Mostrar_Datos_Gato() {
		Mostrar_Datos_Mascota();
		Mostrar_Cantidad_Patas();
		cout << "Raza: " << *Raza << endl;
		cout << "Tiene " << Edad << " meses " << endl;
	}



};