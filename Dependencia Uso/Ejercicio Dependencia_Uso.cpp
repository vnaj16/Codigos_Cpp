#include <iostream>
#include <conio.h>
#include "regla.h"
#include "profesor.h"

using namespace std;
using namespace System;

int main() {
	regla *Regla = new regla(30);
	_getch();
	profesor *Profesor = new profesor("Arthur", "Programacion", Regla);

	Profesor->Medir();
	_getch();
	Profesor->~profesor();
	cout << endl;
	_getch();
	Regla->Mostrar_Datos();
	_getch();
	
	_getch();
	return 0;
}