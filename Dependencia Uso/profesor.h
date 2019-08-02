#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include "regla.h"

using namespace std;
using namespace System;

class profesor {
private:
	string *Nombre = new string,*Curso = new string;
	regla *Regla;
public:
	profesor(string N, string C, regla *Regla) {
		*Nombre = N;
		*Curso = C;
		this->Regla = Regla;
		cout << "Profesor creado";
		_getch();
		Console::Clear();
	}
	~profesor() {
		cout << "Profesor destruido";
		_getch();
		_getch();
		delete Nombre, Curso;
		Console::Clear();
	}

	void Medir() {
		cout << "El profesor " << *Nombre << " del curso de " << *Curso << " midio la pizarra y media " << Regla->Medir() << " cm" << endl;
		_getch();
	}




};