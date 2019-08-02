#pragma once
#include <iostream>
#include <conio.h>

using namespace std;
using namespace System;

class bateria {
private:
	float Capacidad;
public:
	bateria(float mA) {
		Capacidad = mA;
	}
	bateria() {

	}
	~bateria() {
		cout << "Bateria destruida";
		_sleep(1000);
	}

	void setCapacidad(float mA) {
		Capacidad = mA;
	}

	float getCapacidad() {
		return Capacidad;
	}

	void Mostrar_Datos() {
		cout << "Capacidad de la bateria " << Capacidad << " mAh" << endl;
	}



};