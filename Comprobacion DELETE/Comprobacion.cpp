#include <iostream>
#include <conio.h>
#include <string>
#include "arreglo.h"
using namespace std;
using namespace System;

int main() {
	int Opcion;
	int *N;
	arreglo *Arreglo = new arreglo(N);

	while (Opcion != 9) {
		cin >> Opcion;
		Console::Clear();
		switch (Opcion) {
		case 1: Arreglo->Agregar_Numero();
			break;
		case 2: Arreglo->Mostrar_Datos();
			break;
		case 3: Arreglo->Eliminar_Numero();
		}
		Console::Clear();
	}

	_getch();
	return 0;
}