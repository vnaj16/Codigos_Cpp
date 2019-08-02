#include<iostream>
#include <conio.h>
#include <string>

using namespace std;
using namespace System;

void Menu(int *Opcion) {
	Console::Clear();

	Console::SetCursorPosition(20, 2);
	cout << "1. Agregar cadena";
	Console::SetCursorPosition(20, 4);
	cout << "2. Modificar cadena";
	Console::SetCursorPosition(20, 6);
	cout << "3. Modificar caracter";
	Console::SetCursorPosition(20, 8);
	cout << "4. Modificar a mayuscula";
	Console::SetCursorPosition(20, 10);
	cout << "5. Modificar a minuscula";
	Console::SetCursorPosition(20, 12);
	cout << "6. Mostrar cadenas";
	Console::SetCursorPosition(20, 14);
	cout << "7. Eliminar cadena";
	Console::SetCursorPosition(20, 16);
	cout << "8. Salir";

	Console::SetCursorPosition(30, 18);
	cout << "Opcion: "; cin >> *Opcion;

	Console::Clear();
}

void Agregar_Cadena(string *&Cadena, int *Cantidad_Cadenas) {
	string *Aux = new string[*Cantidad_Cadenas + 1];

	for (int i = 0; i < *Cantidad_Cadenas; i++) {
		Aux[i] = Cadena[i];
	}

	
	cout << "Ingrese la nueva cadena: "; cin.ignore(); getline(cin, Aux[*Cantidad_Cadenas]);


	//delete Cadena;
	Cadena->erase();


	Cadena = Aux;
	*Cantidad_Cadenas+=1;

	
}

void Modificar_Cadena(string *&Cadena, int *Cantidad_Cadenas) {
	int N;
	do {
		cout << "Que cadena desea modificar (0, " << *Cantidad_Cadenas - 1 << "): "; cin >> N; cout << endl;
	} while (N < 0 || N >= *Cantidad_Cadenas);

	cout << endl << "Ingrese la nueva cadena: "; cin.ignore(); getline(cin, Cadena[N]);
	cout << endl << endl << "CADENA MODIFICADA ";
	_getch();

}

void Modificar_Caracter(string *&Cadena, int *Cantidad_Cadenas) {

	int N;
	do {
		cout << "Que cadena desea modificar (0, " << *Cantidad_Cadenas - 1 << "): "; cin >> N; cout << endl;
	} while (N < 0 || N >= *Cantidad_Cadenas);

	int n;
	do {
		cout << "Que caracter desea modificar (0, " << Cadena->size() - 1 << "): "; cin >> n; cout << endl;
	} while (n < 0 || n >= Cadena->size());

	char C;

	cout << "Ingrese caracter: "; cin >> C;

	Cadena[N][n] = C;

}

void Modificar_Mayusculas(string *&Cadena, int *Cantidad_Cadenas) {
	int N;
	do {
		cout << "Que cadena desea modificar (0, " << *Cantidad_Cadenas - 1 << "): "; cin >> N; cout << endl;
	} while (N < 0 || N >= *Cantidad_Cadenas);

	for (auto &C : Cadena[N]) {
		C = toupper(C);
	}
}

void Modificar_Minusculas(string *&Cadena, int *Cantidad_Cadenas) {
	int N;
	do {
		cout << "Que cadena desea modificar (0, " << *Cantidad_Cadenas - 1 << "): "; cin >> N; cout << endl;
	} while (N < 0 || N >= *Cantidad_Cadenas);

	for (auto &C : Cadena[N]) {
		C = tolower(C);
	}
}


void Mostrar_Cadenas(string *Cadena, int *Cantidad_Cadenas) {
	for (int i = 0; i < *Cantidad_Cadenas; i++) {
		cout << "Cadena " << i + 1 << endl << "  " << Cadena[i] << endl << endl;
	}

	_getch();
}

void Eliminar_Cadena(string *&Cadena, int *Cantidad_Cadenas) {

	string *Aux = new string[*Cantidad_Cadenas - 1];

	int N;
	do {
		cout << "Que cadena desea eliminar (0, " << *Cantidad_Cadenas - 1 << "): "; cin >> N; cout << endl;
	} while (N < 0 || N >= *Cantidad_Cadenas);

	for (int i = 0; i < N; i++) {
		Aux[i] = Cadena[i];
	}

	for (int i = N; i < *Cantidad_Cadenas - 1; i++) {
		Aux[i] = Cadena[i + 1];
	}

	Cadena->erase();

	Cadena = Aux;
	*Cantidad_Cadenas -= 1;
}

void Comprobar_Salida(int *Opcion) {
	Console::Clear(); 
	
	cout << "Desea salir? (0: No, 1: Si): "; cin >> *Opcion;

	if (*Opcion != 0) {
		*Opcion = 8;
	}
	
	Console::Clear();
}

int main() {
	/*
	string Nombre;

	
	getline(cin, Nombre);

	Console::Clear();

	cout << "Ingrese Nombre: ";
	while (getline(cin, Nombre) && Nombre.size()!=0) {

		if (Nombre == "Arthur")
		{
			cout << "Eres Arthur";
		}
		else {
			cout << "No eres Arthur, eres " << Nombre;
		}

		cout << endl<< endl << "Ingrese Nombre: " << endl;
	}

	

	string Linea1, Linea2;

	cin >> Linea1 >> Linea2;

	if(Linea1 >= Linea2){
		if (Linea1 == Linea2) {
			cout << "SON IGUALES";
		}
		else {
			cout << "Linea 1: " << Linea1 << " es mayor que Linea 2: " << Linea2 << endl;
		}
	}
	else {
		cout << "Linea 2: " << Linea2 << " es mayor que Linea 1: " << Linea1 << endl;
	}

	string Linea1 = "ABC";
	int Edad[5] = { 1,2,3,4,5 };


	for (auto C : Linea1) {
		cout << C << endl;
	}

	for (int i : Edad) {
		cout << i << endl;
	}
*/

	int *Opcion = new int(0);

	string *Cadena = new string;
	int *Cantidad_Cadenas = new int(0);

	while (*Opcion != 8) {
		Menu(Opcion);

		switch (*Opcion) {
		case 1: 
			Agregar_Cadena(Cadena, Cantidad_Cadenas);
			break;

		case 2:
			Modificar_Cadena(Cadena, Cantidad_Cadenas); 
			break;

		case 3:
			Modificar_Caracter(Cadena, Cantidad_Cadenas);
			break;

		case 4:
			Modificar_Mayusculas(Cadena, Cantidad_Cadenas);
			break;

		case 5:
			Modificar_Minusculas(Cadena, Cantidad_Cadenas);
			break;

		case 6: 
			Mostrar_Cadenas(Cadena, Cantidad_Cadenas);
			break;

		case 7:
			Eliminar_Cadena(Cadena, Cantidad_Cadenas);
			break;

		case 8:
			Comprobar_Salida(Opcion);
			break;
		}
	}


	return 0;
}