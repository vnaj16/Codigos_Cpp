#include <iostream>
#include <conio.h>
#include "celular.h"

using namespace std;
using namespace System;

int main() {
	celular *Celular = new celular("Nokia", 2012);
	_sleep(1000);
	Celular->getBateria()->setCapacidad(2500);
	_sleep(1000);
	Celular->getBateria()->Mostrar_Datos();
	_sleep(1000);
	Celular->Mostrar_Datos();
	_sleep(1000);
	Celular->~celular();



	_getch();
	return 0;
}