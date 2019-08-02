#include <iostream>
#include <conio.h>
#include <string>
#include "C_Celular.h"
#include <vector>

using namespace std;
using namespace System;

void Menu(int &Opcion) {
	int y = 2, dy=2;
	Console::SetCursorPosition(15, y);
	cout << "		MENU";
	Console::SetCursorPosition(5, y + dy); dy += 2;
	cout << "1. Agregar celular";
	Console::SetCursorPosition(5, y + dy); dy += 2;
	cout << "2. Mostrar celulares";
	Console::SetCursorPosition(5, y + dy); dy += 2;
	cout << "3. Modificar celular";
	Console::SetCursorPosition(5, y + dy); dy += 2;
	cout << "4. Eliminar celular";
	Console::SetCursorPosition(5, y + dy); dy += 2;
	cout << "5. Salir";
	Console::SetCursorPosition(5, y + dy); dy += 2;
	cout << "Opcion: "; cin >> Opcion;
}

/////////////////Funcion Agregar celular//////////////////

void Agregar_Celular(vector<C_Celular> &Deposito) {
	C_Celular Celular;
	Celular.Pedir_Datos();

	Deposito.push_back(Celular);
	Console::Clear();
	cout << endl<<"Agregado con exito";
	_getch();
}

/////////////////Funcion Mostrar celulares////////////////////

void Mostrar_Celulares(vector<C_Celular> &Deposito) {
	//Forma 1 para recorrer el vector
	/*for (C_Celular i : Deposito) {
		i.Mostrar_Datos();
		cout << endl <<endl;
		for (int i = 0; i < 20; i++) {
			cout << "__";
		}
	}*/
	
	//Forma 2 para recorrer el vector
	for (vector<C_Celular>::iterator i = Deposito.begin(); i < Deposito.end(); i++) {
		i->Mostrar_Datos();
		cout << endl << endl;
		for (int i = 0; i < 20; i++) {
			cout << "__";
		}
		cout << endl;
	}

	_getch();
}

/////////////////////Funcion Modificar celular/////////////////

void Modificar_Celular(vector<C_Celular> &Deposito) {
	//Modificar todo, celular, camara, bateria

	int Posicion,Opcion=0;
	string Marca; float Precio; int N;
	string Respuesta;
	do {
		Console::Clear();
		cout << "Que celular desea modificar (0, " << Deposito.size() - 1 << "): "; cin >> Posicion;
	} while (Posicion<0 || Posicion>Deposito.size() - 1);

	cout << "Celular seleccionado correcto" << endl;

	while (Opcion == 0) {
		cout << endl << "	Elija una opcion de modificacion"<<endl;
		cout << "1. Modificar todo el celular" << endl;
		cout << "2. Modificar solo el celular" << endl;
		cout << "3. Modificar solo la camara" << endl;
		cout << "4. Modificar solo la bateria" << endl;
		cout << "Opcion: "; cin >> Opcion;
		switch (Opcion) {
		case 1:
			Deposito[Posicion].Pedir_Datos();
			break;
		case 2:
			
			cin.ignore();
			cout << "	CELULAR" << endl;
			cout << "Ingrese la marca: "; getline(cin, Marca);
			cout << "Ingrese el precio: "; cin >> Precio;
			cout << "Ingrese el numero de serie: "; cin >> N;
			Deposito[Posicion].setMarca(Marca);
			Deposito[Posicion].setNumero_Serie(N);
			Deposito[Posicion].setPrecio(Precio);
			break;
		case 3:
			Deposito[Posicion].getCamara().Pedir_Datos();
			break;
		case 4:
			Deposito[Posicion].getBateria().Pedir_Datos();
			break;
		}
		cout << "Modificacion hecha"<<endl <<endl;

		cout << "Desea hacer otra modificacion(si/no): "; cin >> Respuesta;
		if (Respuesta == "si") {
			Opcion = 0;
			
		}
		Console::Clear();
	}

}

///////////////////Funcion Eliminar celular///////////////////

//Func Elim Marca de celular

void Eliminar_Marca_Celular(vector<C_Celular> &Deposito, string Marca) {
	int Eliminados = 0;
	//Error de logica ya que el end cambia cada vez que se elimina //Arreglado con el --i
	for (vector<C_Celular>::iterator i = Deposito.begin(); i != Deposito.end(); i++) {
		if (i->getMarca() == Marca) {
			Deposito.erase(i);
			++Eliminados;
			if (!Deposito.empty()) {
				--i;
			}
			else {
				break;
			}
			
		}
	}

	cout << "Se eliminaron " << Eliminados << " celular con marca " << Marca << endl;
	_getch();
}

void Eliminar_Celular(vector<C_Celular> &Deposito) {
	//Crear eliminar por posicion, marca, rango de precios, marca de camara, rango de cantidad de megapix
	int Opcion;
	int Posicion=0, Rango_Menor_Precio=0, Rango_Mayor_Precio=0, Rango_Menor_Mpx=0, Rango_Mayor_Mpx=0;
	string Marca_Celular, Marca_Camara;
	cin.ignore();
	cout << "	Que opcion de eliminacion desea" << endl;
	cout << "1. Por posicion" << endl;
	cout << "2. Por marca de celular" << endl;
	cout << "3. Por rango de precio" << endl;
	cout << "4.Por marca de camara" << endl;
	cout << "5.Por rango de megapixeles" << endl;
	cout << "Opcion: "; cin >> Opcion;

	switch (Opcion) {
	case 1:
		Deposito.erase(Deposito.begin() + Posicion);
		break;
	case 2:
		Console::Clear();
		cin.ignore();
		cout << "Ingrese la marca: "; getline(cin, Marca_Celular);
		Eliminar_Marca_Celular(Deposito, Marca_Celular);
		break;
	}

	cout << "ELIMINADO";
	_getch();

}

int main() {
	int Opcion = 0; //Opcion para el menu
	vector<C_Celular> *Deposito = new vector<C_Celular>; //Deposito donde estan guardados los celulares

	while (Opcion != 5) {
		Menu(Opcion);
		Console::Clear();

		switch (Opcion)
		{
		case 1:
			Agregar_Celular((*Deposito));
			break;
		case 2:
			Mostrar_Celulares((*Deposito));
			break;
		case 3:
			Modificar_Celular((*Deposito));
			break;
		case 4:
			Eliminar_Celular((*Deposito));
			break;

		}

		Console::Clear();
	}

	_getch();
	return 0;
}