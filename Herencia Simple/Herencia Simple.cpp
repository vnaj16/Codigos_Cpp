#include <iostream>
#include <conio.h>
#include "gato.h"
 
using namespace std;
using namespace System;


int main() {
	gato *Gato = new gato(4, "Shabio", true, "Angora", 25);
	gato *Gata = new gato(4, "Samantha", false, "Normal", 20);
	Gato->Mostrar_Datos_Gato();
	Gata->Mostrar_Datos_Gato();


	_getch();
	return 0;
}