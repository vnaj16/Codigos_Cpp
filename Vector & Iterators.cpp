#include <iostream>
#include <conio.h>
#include <vector>
#include <string>

using namespace std;
using namespace System;


void Menu(int &Opcion) {
	Console::SetCursorPosition(5, 2);
	cout << "MENU";
	Console::SetCursorPosition(0, 4);
	cout << "1. Agregar Numero";

	Console::SetCursorPosition(0, 6);
	cout << "2. Modificar Numero";

	Console::SetCursorPosition(0, 8);
	cout << "3. Eliminar Numero";

	Console::SetCursorPosition(0, 10);
	cout << "4. Mostrar Numeros";

	Console::SetCursorPosition(0, 12);
	cout << "5. Salir";

	Console::SetCursorPosition(8, 14);
	cout << "Opcion: "; cin >> Opcion;

	Console::Clear();

}

void Agregar_Numeros(vector<int> &Numeros) {
	int N;
	cout << "Ingrese el numero: "; cin >> N;
	Numeros.push_back(N);
	//El metodo pop_back regresa el ultimo elemento del vector
	cout << "NUMERO INGRESADO";
	_sleep(500);
}

void Modificar_Numeros(vector<int> &Numeros) {
	if (!Numeros.empty()) {
		int N, Num;
		cout << "Que numero desea modificar (0 , " << Numeros.size() - 1 << "): "; cin >> N;
		cout << endl;
		cout << "Numero: " << *(Numeros.begin() + N) <<endl;
		cout << "Ingrese el nuevo numero: "; cin >> *(Numeros.begin() + N);
		cout << endl << "NUMERO MODIFICADO";
		_sleep(500);
	}
	else {
		cout << "NO HAY ELEMENTOS";
	}
}

void Eliminar_Numeros(vector<int> &Numeros) {
	if (!Numeros.empty()) {
		int N;
		cout << "Que numero desea eliminar (0 , " << Numeros.size() - 1 << "): "; cin >> N;
		cout << endl;
		Numeros.erase(Numeros.begin() + N);
		//, Numeros.begin() + N + 1
		//Numeros.erase(Numeros.begin() + N, Numeros.begin() + N + 1); borra desde a, hasta b - 1
		cout << endl << "NUMERO ELIMINADO";
		_sleep(500);
	}
	else {
		cout << "NO HAY ELEMENTOS";
	}
}

void Mostrar_Numeros(vector<int> Numeros) {
	if (!Numeros.empty()) {
		for (vector<int>::iterator i = Numeros.begin(); i != Numeros.end(); ++i) {
			cout << *i; //Mostramos el valor al que apunta el iterador i
			if (!(i == Numeros.end() - 1)) 
			{
				cout << "|";
			}
		}
	}
	else {
		cout << "NO HAY ELEMENTOS";
	}
	_getch();
}

void Confirmar_Salida(int &Opcion) {
	string Confirmacion;

	do {
		Console::Clear();
		Console::SetCursorPosition(0, 0);

		cout << "De verdad desea salir? (si/no): ";
		cin >> Confirmacion;
	} while (Confirmacion != "si" && Confirmacion != "no");

	if (Confirmacion == "no") {
		Opcion = 0;
	}
	else {

	}

}

int main() {

	//Manejar vector and iteratos// vector de numeros
	//Vector tiene elementos contiguos en memoria y debido a eso son mas rapidos de acceder
	vector<int> Numeros;
	int Opcion = 0;


	while (Opcion != 5) {

		Console::Clear();

		Menu(Opcion);

		switch (Opcion) {
		case 1: 
			Agregar_Numeros(Numeros);
			break;
		case 2:
			Modificar_Numeros(Numeros);
			break;
		case 3:
			Eliminar_Numeros(Numeros);
			break;
		case 4: 
			Mostrar_Numeros(Numeros);
			break;
		case 5:
			Confirmar_Salida(Opcion);
			break;
		}

		

	}


	_getch();
	return 0;
}