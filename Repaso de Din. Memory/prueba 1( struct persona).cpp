#include <iostream>
#include <conio.h>
#include <string>

using namespace std;
using namespace System;

struct persona {
	int Edad;
	string Nombre;
	~persona() {
		cout << "DESTRUIDO " << endl; system("pause>0");
	};
};

int Menu() {
	int Opcion;
	Console::SetCursorPosition(40, 2);
	cout << "MENU";
	Console::SetCursorPosition(20, 6);
	cout << "1. Agregar Persona";
	Console::SetCursorPosition(20, 8);
	cout << "2. Eliminar Persona";
	Console::SetCursorPosition(20, 10);
	cout << "3. Modificar Persona";
	Console::SetCursorPosition(20, 12);
	cout << "4. Mostrar Personas";
	Console::SetCursorPosition(20, 14);
	cout << "5. Mostrar Menor y Mayor Persona";
	Console::SetCursorPosition(20, 16);
	cout << "6. Mostrar Edad Repetida";
	Console::SetCursorPosition(20, 18);
	cout << "7. Salir";
	do {
		Console::SetCursorPosition(30, 20);
		cout << "Opcion: "; cin >> Opcion;
	} while (Opcion < 0 || Opcion>7);
	Console::Clear();
	return Opcion;

}


persona* Agregar_Persona(persona *Persona, int *Cantidad) {
	persona *Aux = new persona[*Cantidad + 1];
	int Edad;
	string Nombre;

	for (int i = 0; i < *Cantidad; i++) {
		Aux[i] = Persona[i];
	}

	Console::Clear();
	cin.ignore();
	cout << "Ingrese el nombre de la persona: "; getline(cin, Nombre);
	cout << "Ingrese su edad: "; cin >> Edad;
	Aux[*Cantidad].Edad = Edad;
	Aux[*Cantidad].Nombre = Nombre;

	Persona->~persona();

	Console::Clear();

	*Cantidad += 1;

	return Aux;

}

persona* Eliminar_Persona(persona *Persona, int *Cantidad) {
	if (*Cantidad == 0) {
		cout << "NO HAY PERSONA PARA ELIMINAR";
		return Persona;
	}
	else if (*Cantidad == 1) {
		cout << "La persona ha sido eliminada";
		Persona->~persona();
		*Cantidad = 0;
		return NULL;
	}
	else {
		int Posicion;
		do {
			cout << "Ingrese la posicion de la persona que desea eliminar (0 , " << *Cantidad << ">" << endl;
			cout << "Posicion: "; cin >> Posicion;
		} while (Posicion < 0 || Posicion >*Cantidad - 1);
		persona *Aux = new persona[*Cantidad - 1];
		for (int i = 0; i < Posicion; i++) {
			Aux[i] = Persona[i];
		}
		for (int i = Posicion; i < *Cantidad - 1; i++) {
			Aux[i] = Persona[i + 1];
		}

		Persona->~persona();

		*Cantidad -= 1;
		cout << "PERSONA ELIMINADA CON EXITO";
		return Aux;


	}
}


void Modificar_Persona(persona *Persona, int *Cantidad) {
	if (*Cantidad == 0) {
		cout << "NO HAY PERSONA PARA MODIFICAR";
	}
	else if (*Cantidad == 1) {
		int Edad;
		string Nombre;
		cin.ignore();
		cout << "Ingrese el nombre de la persona: "; getline(cin, Nombre);
		cout << "Ingrese la nueva edad de la persona: "; cin >> Edad;
		Persona[0].Edad = Edad;
		Persona[0].Nombre = Nombre;
		cout << "La persona ha sido modificada";

	}
	else {
		int Posicion;
		do {
			cout << "Ingrese la posicion de la persona que desea modificar (0 , " << *Cantidad << ">" << endl;
			cout << "Posicion: "; cin >> Posicion;
		} while (Posicion < 0 || Posicion >*Cantidad - 1);
		int Edad;
		string Nombre;
		Console::Clear();
		cin.ignore();
		cout << "Ingrese el nombre de la persona: "; getline(cin, Nombre);
		cout << "Ingrese la nueva edad de la persona: "; cin >> Edad;
		Persona[0].Edad = Edad;
		Persona[0].Nombre = Nombre;
		cout << "PERSONA MODIFICADA CON EXITO";
	}
}

void Mostrar_Datos(persona *Persona, int *Cantidad) {
	Console::Clear();
	cout << "\tPERSONAS" << endl<<endl;
	for (int i = 0; i < *Cantidad; i++) {
		cout << "Persona " << i + 1 << endl;
		cout << "Nombre: " << Persona[i].Nombre << endl;
		cout << "  Edad: " << Persona[i].Edad<<endl<<endl;
	}
	system("pause>0");
	
}

int main() {

	persona *Persona = new persona;
	int *Cantidad = new int(0);

	bool Salir = false;

	do {
		switch (Menu()) {
		case 1:
			Persona = Agregar_Persona(Persona, Cantidad);
			cout << "PERSONA AGREGADA CON EXITO";
			_sleep(1000);
			Console::Clear();
			break;
		case 2:
			Persona = Eliminar_Persona(Persona, Cantidad);
			_sleep(1000);
			Console::Clear();
			break;
		case 3:
			Modificar_Persona(Persona, Cantidad);
			_sleep(1000);
			Console::Clear();
			break;
		case 4:
			Mostrar_Datos(Persona, Cantidad);
			Console::Clear();
			break;
		case 5:
			//Mayor_Menor_Persona(Persona, Cantidad);
			_sleep(3000);
			Console::Clear();
			break;
		case 6:

			//Mostrar_Edad_Repetida(Persona, Cantidad);
			_sleep(3000);
			Console::Clear();
			break;
		case 7:
			Salir = true;
			break;
		}
	} while (!Salir);




	_getch();
	return 0;
}



