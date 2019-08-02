#pragma once
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;
using namespace System;

class regla {
private:
	int *Color = new int(12);
	string *Marca = new string("Artesco");
	float *Tamanio = new float;

public:
	regla(float T) {
		*Tamanio = T;
		cout << "regla creada"<< endl; _getch();
		Console::Clear();
	}
	~regla() {
		cout << "regla destruida" << endl; _getch();
		delete Marca, Color, Tamanio;
		Console::Clear();
	}

	string getMarca() {
		return *Marca;
	}

	float Medir() {
		Random r;
		return r.Next(0, *Tamanio + 1);
	}

	void Mostrar_Datos() {
		cout << "Regla " << *Marca << " de color rojo y con " << *Tamanio << " cm de tamanio"<<endl;
	}



};