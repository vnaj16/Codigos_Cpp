#pragma once
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;
using namespace System;

class arreglo {
private:
	int *Numeros, *N = new int(0);
public:
	arreglo(int *Numeros) {
		this->Numeros = Numeros;
	}

	void Agregar_Numero() {
		int *Aux = new int[*N + 1];

		for (int i = 0; i < *N; i++) {
			Aux[i] = Numeros[i];
		}
		cout << "Ingrese un numero: "; int Nu; cin >> Nu;
		Aux[*N] = Nu;

		delete Numeros;


		*N += 1;
		Numeros = Aux;
	}

	void Mostrar_Datos() {
		for (int i = 0; i < *N; i++) {
			cout << Numeros[i] << "// ";
		}
		_getch();
	}

	void Eliminar_Numero() {
		cout << "Ingrese posicion que desea eliminar [0, " << *N << ">";
		int Posicion; cin >> Posicion;

		int *Aux = new int[*N - 1];
		for (int i = 0; i < Posicion; i++) {
			Aux[i] = Numeros[i];
		}

		for (int i = Posicion; i < *N; i++) {
			Aux[Posicion] = Numeros[Posicion + 1];
		}

		*N -= 1;
		delete Numeros;
		Numeros = Aux;
	}



};