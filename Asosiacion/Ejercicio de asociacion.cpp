#include <iostream>
#include <conio.h>
#include "paraguas.h"
#include "persona.h"

using namespace std;
using namespace System;


int main(){
	paraguas *Paraguas = new paraguas(5, 10);
	_sleep(1000);
	persona *Persona;
	_sleep(1000);
	Paraguas->Mostrar_Datos();
	_sleep(1000);
	Paraguas->Mostrar_Uso();
	_sleep(1000);
	Persona = new persona("Arthur",15, 18, Paraguas);
	_sleep(1000);
	Persona->Mostrar_Datos();
	_sleep(1000);
	Paraguas->Mostrar_Uso();
	_sleep(1000);
	Persona->~persona();
	Paraguas->Mostrar_Datos();
	_sleep(1000);
	Paraguas->Mostrar_Uso();
	_sleep(1000);





	_getch();
	return 0;
}