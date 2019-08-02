#include <iostream>
#include <conio.h>
#include <deque>
#include <string>

using namespace std;
using namespace System;

void Menu(int &Opcion);

void Agregar_Numeros(deque<int> &Cola);

void Modificar_Numeros(deque<int> &Cola);

void Eliminar_Numeros(deque <int> &Cola);

void Mostrar_Numeros(deque<int> &Cola);

void Confirmar_Salida(int &Opcion);

int main() {

	//Deque (doble cola o final)
	//Similar al vector (ubicacion en memoria), solo que su caracteristica principal radica 
	//en que al tener doble final se pueden insertar elementos por ambos lados del contenedor

	deque<int> Cola;
	int Opcion;

	while (Opcion != 5) {

		Console::Clear();

		Menu(Opcion);

		switch (Opcion) {
		case 1:
			Agregar_Numeros(Cola);
			break;
		case 2:
			Modificar_Numeros(Cola);
			break;
		case 3:
			Eliminar_Numeros(Cola);
			break;
		case 4:
			Mostrar_Numeros(Cola);
			break;
		case 5:
			Confirmar_Salida(Opcion);
			break;
		}
	}

	_getch();
	return 0;
}

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

void Agregar_Numeros(deque<int> &Cola) {
	int N; char R;

	do{
		cout << "Desea agregar por el inicio(I) o el final (F): "; cin >> R;
	} while (R !='i' && R!= 'f' && R != 'I' && R != 'F');
	cout << "Ingrese el numero: "; cin >> N;
	if (R == 'i' || R == 'I') {
		Cola.push_front(N);
	}
	else {
		Cola.push_back(N);
	}
	
	//El metodo pop_back y pop_front regresa el ultimo o primer elemento del deque
	cout << "NUMERO INGRESADO";
	_sleep(500);
}

void Modificar_Numeros(deque<int> &Cola) {
	if (!Cola.empty()) {
		int N, Num;
		cout << "Que numero desea modificar (0 , " << Cola.size() - 1 << "): "; cin >> N;
		cout << endl;
		cout << "Numero: " << *(Cola.begin() + N) << endl;
		cout << "Ingrese el nuevo numero: "; cin >> *(Cola.begin() + N);
		cout << endl << "NUMERO MODIFICADO";
		_sleep(500);
	}
	else {
		cout << "NO HAY ELEMENTOS";
	}
}

void Eliminar_Numeros(deque<int> &Cola) {
	if (!Cola.empty()) {
		int N;
		cout << "Que numero desea eliminar (0 , " << Cola.size() - 1 << "): "; cin >> N;
		cout << endl;
		Cola.erase(Cola.begin() + N);
		//, Cola.begin() + N + 1
		//Cola.erase(Cola.begin() + N, Cola.begin() + N + 1); borra desde a, hasta b - 1
		cout << endl << "NUMERO ELIMINADO";
		_sleep(500);
	}
	else {
		cout << "NO HAY ELEMENTOS";
	}
}

void Mostrar_Numeros(deque<int> &Cola) {
	if (!Cola.empty()) {
		for (deque<int>::iterator i = Cola.begin(); i != Cola.end(); ++i) {
			cout << *i; //Mostramos el valor al que apunta el iterador i
			if (!(i == Cola.end() - 1))
			{
				cout << "|";
			}
			//los metodos rbegin y rend nos sirven para avanzar desde el final hasta el inicio
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