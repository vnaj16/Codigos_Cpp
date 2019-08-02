#pragma once
#include <iostream>
#include <conio.h>

using namespace std;
using namespace System;

class animal {
protected:
	int Cantidad_Patas;
public:
	animal(int Patas) {
		Cantidad_Patas = Patas;
	}
	animal() {

	}

	int getCantidad_Patas() {
		return Cantidad_Patas;
	}

	void setCantidad_Patas(int Patas) {
		Cantidad_Patas = Patas;
	}

	void Mostrar_Cantidad_Patas() {
		cout << "Tiene " << Cantidad_Patas << " patas" << endl; 
	}

};