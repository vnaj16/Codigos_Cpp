#include <iostream>
#include <conio.h>
#include "persona.h"

using namespace std;
using namespace System;

int main() {
	persona *Hijo = new persona("Arthur", 9, 1.20);
	persona *Papa = new persona("Pablo", 25, 1.70);
	Papa->setPariente(Hijo);
	Papa->Mostrar_Datos_Papa();




	_getch();
	Hijo->Mostrar_Datos();
	_sleep(2000);
	Papa->Mostrar_Datos();
	_sleep(2000);
	_getch();
	return 0;
}