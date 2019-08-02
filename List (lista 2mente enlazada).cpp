#include <iostream>
#include <conio.h>
#include <list>
#include <string>

using namespace std;
using namespace System;

void Menu(int &Opcion);

void Agregar_Numeros(list<int> &Lista);

void Modificar_Numeros(list<int> &Lista);

void Eliminar_Numeros(list <int> &Lista);

void Mostrar_Numeros(list<int> &Lista);

void Confirmar_Salida(int &Opcion);

int main() {

	//Sirven para insertar o eliminar en cualquier parte de la lista
	//Son listas doblemente enlazadas, significa que cada elemento(nodo) contiene las direcciones del nodo siguiente y del anterior, ademas el valor de ahi

	int Opcion;
	list<int> Lista;

	while (Opcion != 6) {

		Console::Clear();

		Menu(Opcion);

		switch (Opcion) {
		case 1:
			Agregar_Numeros(Lista);
			break;
		case 2:
			Modificar_Numeros(Lista);
			break;
		case 3:
			Eliminar_Numeros(Lista);
			break;
		case 4:
			Mostrar_Numeros(Lista);
			break;
		case 5:
			Lista.sort();
			cout << "ORDENADO";
			_sleep(500);
			break;
			
		case 6:
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
	cout << "5. Ordenar";

	Console::SetCursorPosition(0, 14);
	cout << "6. Salir";

	Console::SetCursorPosition(8, 16);
	cout << "Opcion: "; cin >> Opcion;

	Console::Clear();

}

void Agregar_Numeros(list<int> &Lista) {
	int N; char R;
	int P;

	do {
		cout << "Desea agregar por el inicio(I), el final (F) o en posicion N(N): "; cin >> R;
	} while (R != 'i' && R != 'f' && R != 'I' && R != 'F' && R!='N' && R != 'n');
	cout << "Ingrese el numero: "; cin >> N;

	if (!Lista.empty()) {
		if (R == 'i' || R == 'I') {
			Lista.push_front(N);
		}
		else if (R == 'F' || R == 'f') {
			Lista.push_back(N);
		}
		else {
			cout << "En que posicion desea ponerlo: (0 , " << Lista.size() - 1 << "): "; cin >> P;
			list<int>::iterator i = Lista.begin(); //Este es un bidirectional iterator, solo pueder moverse ++ o --
													//Los vectores o deque son random access iterator

			while (P > 0) {
				++i;
				--P;
			}

			Lista.insert(i, N);

		}
	}
	else {
		Lista.push_front(N);
	}

	//El metodo pop_back y pop_front regresa el ultimo o primer elemento del deque
	cout << "NUMERO INGRESADO";
	_sleep(500);
}

void Modificar_Numeros(list<int> &Lista) {
	if (!Lista.empty()) {
		int N, Num;
		cout << "Que numero desea modificar (0 , " << Lista.size() - 1 << "): "; cin >> N;
		cout << endl;
		list<int>::iterator i = Lista.begin();
		while (N > 0) {
			++i;
			--N;
		}
		cout << "Numero: " << *i << endl;
		cout << "Ingrese el nuevo numero: "; cin >> *i;
		cout << endl << "NUMERO MODIFICADO";
		_sleep(500);
	}
	else {
		cout << "NO HAY ELEMENTOS";
	}
}

void Eliminar_Numeros(list<int> &Lista) {
	if (!Lista.empty()) {
		int N;
		cout << "Que numero desea eliminar (0 , " << Lista.size() - 1 << "): "; cin >> N;
		cout << endl;
		list<int>::iterator i = Lista.begin();
		while (N > 0) {
			++i;
			--N;
		}
		Lista.erase(i);
		cout << endl << "NUMERO ELIMINADO";
		_sleep(500);
	}
	else {
		cout << "NO HAY ELEMENTOS";
	}
}

void Mostrar_Numeros(list<int> &Lista) {
	if (!Lista.empty()) {
		for (list<int>::iterator i = Lista.begin(); i != Lista.end(); ++i) {
			cout << *i; //Mostramos el valor al que apunta el iterador i
			if (!(i == Lista.end()))
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
