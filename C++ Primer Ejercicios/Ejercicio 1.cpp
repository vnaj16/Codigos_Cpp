#include <iostream>
#include <conio.h>
#include <vector>

using namespace std;
using namespace System;

void Ingresar_Notas(vector<int> *Notas, int C) {
	int N=0;
	for (int i = 0; i < C; ++i) {
		cout << endl << "Ingrese la nota " << i + 1 << ": "; cin >> N;
		(*Notas).push_back(N);
	}
}

void Mostrar_Notas(vector<int> *Notas, int C) {
	for (int i = 0; i < Notas->size(); ++i) {
		cout << "Nota " << i + 1 << ": " << (*Notas)[i] <<endl;
	}
}

void Determinar_Nota(vector<int> *Notas, int C, int *M, float *P) {
	int Indice = 0;
	for (int i = 0; i < C; i++) {
		if ((*Notas)[i] < *M) {
			*M = (*Notas)[i];
			Indice = i;
		}
	}

	Notas->erase(Notas->begin() + Indice, Notas->begin() + Indice + 1);

	for (int i = 0; i < Notas->size(); i++) {
		*P += (*Notas)[i];
	}

	*P /= Notas->size();

}

int main() {

	vector<int> *Notas = new vector<int>;
	int *Cantidad_Notas = new int, *Menor_Nota=new int(20);
	float *Promedio = new float(0);

	cout << "Ingrese la cantidad de notas: "; cin >> *Cantidad_Notas;

	Ingresar_Notas(Notas, *Cantidad_Notas);
	cout << endl << endl;
	Mostrar_Notas(Notas, *Cantidad_Notas);

	cout << endl << endl;

	Determinar_Nota(Notas, *Cantidad_Notas, Menor_Nota, Promedio);

	cout << "La menor nota es: " << *Menor_Nota;

	cout << endl << endl;
	Mostrar_Notas(Notas, *Cantidad_Notas);

	cout << endl << endl;
	cout << "El promedio es: " << *Promedio;

	_getch();
	return 0;
}