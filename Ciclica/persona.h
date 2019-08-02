#pragma once
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;
using namespace System;

class persona {
private:
	string *Nombre = new string;
	int Edad;
	float Altura;
	persona *Hijo;
public:
	persona(string Nombre, int Edad, float Altura) {
		*this->Nombre = Nombre;
		this->Edad = Edad;
		this->Altura = Altura;
	}

	void setPariente(persona *Hijo) {
		this->Hijo = Hijo;
	}
	void setNombre(string N) {
		*Nombre = N;
	}
	void setEdad(int Edad) {
		this->Edad = Edad;
	}

	void setAltura(float F) {
		Altura = F;
	}

	string getNombre() {
		return *Nombre;
	}
	int getEdad() {
		return Edad;
	}

	float getAltura() {
		return Altura;
	}

	persona* getHijo() {
		return Hijo;
	}

	void Mostrar_Datos_Papa() {
		cout << "El senior " << *Nombre << " es papa del ninio " << Hijo->getNombre() << endl;
		cout << *Nombre << " tiene " << Edad << " anios y " << Hijo->getNombre() << " tiene " << Hijo->getEdad() << " anios"<<endl;
		if (Altura > Hijo->getAltura()) {
			cout << *Nombre << " es mas alto que " << Hijo->getNombre()<<endl;
		}
		else {
			cout << Hijo->getNombre() << " es mas alto que " << *Nombre << endl;
		}
	}

	void Mostrar_Datos() {
		cout << "Nombre: " << *Nombre << endl;
		cout << "Edad: " << Edad << endl;
		cout << "Altura: " << Altura << endl;
	}



};