#include <iostream>
#include <conio.h>

using namespace std;
using namespace System;

template <class T> 
	int Determinar_Mayor(T Arr[], int Size) {
		T Mayor = 0; int Posicion;
		for (int i = 0; i < Size; i++) {
			if (Arr[i] > Mayor) {
				Mayor = Arr[i];
				Posicion = i;
			}
		}
		return Posicion;
	}

template <class T>
	int Determinar_Menor(T Arr[], int Size) {
		T Menor = Arr[0]; int Posicion;
		for (int i = 0; i < Size; i++) {
			if (Arr[i] < Menor) {
				Menor = Arr[i];
				Posicion = i;
			}
		}
		return Posicion;
	}

template<class T>
T* Determinar_Elementos_Rango(T *Arr, int Rango_Inicio, int Rango_Final, int *Size) {
	if ( Rango_Inicio >  Rango_Final) {
		int aux = Rango_Inicio;
		Rango_Inicio = Rango_Final;
		Rango_Final = aux;
	}
	int Cantidad_Elementos=0,e=0;
	T *Arr2;
	for (int i = 0; i < *Size; i++) {
		if (Arr[i] >= Rango_Inicio && Arr[i] <= Rango_Final) {
			Cantidad_Elementos += 1;
		}
	}
	Arr2 = new T[Cantidad_Elementos];
	
	for (int i = 0; i < *Size; i++) {
		if (Arr[i] >= Rango_Inicio && Arr[i] <= Rango_Final) {
			Arr2[e] = Arr[i];
			e += 1;
		}
	}
	*Size = Cantidad_Elementos;

	return Arr2;

}

template <class T>
T* Eliminar_Repetidos(T *Arr, int *Size) {
	int Cantidad=1,e=0;
	bool repetido = false;
	T* Arr2;
	for (int i = 0; i < *Size; i++) {
		for (int j = i + 1; j < *Size; j++) {
			if (Arr[i] == Arr[j]) {
				repetido = true;
			}
		}
		if (!repetido) {
			Cantidad += 1;
			
		}	
		repetido = false;
	}
	
	Arr2 = new T[Cantidad];
	for (int i = 0; i < *Size; i++) {
		for (int j = i + 1; j < *Size; j++) {
			if (Arr[i] == Arr[j]) {
				repetido = true;
			}
		}
		if (!repetido) {
			Arr2[e] = Arr[i];
			e++;
			
		}
		repetido = false;
	}
*Size = Cantidad-1;
	
	return Arr2;

}

template <class T>
int Elemento_Mayor_Repetido(T Arr[], int Size) {
	int Mayor_Repeticion = 1,Cantidad_Repeticiones=1,Posicion;
	for (int i = 0; i < Size; i++) {
		for (int j = i + 1; j < Size; j++) {
			if (Arr[i] == Arr[j]) {
				Mayor_Repeticion += 1;
				Cantidad_Repeticiones += 1;
			}
		}
		if (Cantidad_Repeticiones >= Mayor_Repeticion) {
			Mayor_Repeticion = Cantidad_Repeticiones;
		}
		Cantidad_Repeticiones = 0;
	}
	for (int i = 0; i < Size; i++) {
		for (int j = i + 1; j < Size; j++) {
			if (Arr[i] == Arr[j]) {
				//Mayor_Repeticion += 1;
				Cantidad_Repeticiones += 1;
			}
		}
		if (Cantidad_Repeticiones == Mayor_Repeticion) {
			//Mayor_Repeticion = Cantidad_Repeticiones;
			Posicion = i;
		}
		Cantidad_Repeticiones = 0;
	}
	return Posicion;

	/*for (int i = 0; i < Size; i++) {
		for (int j = i + 1; j < Size; j++) {
			if (Arr[i] == Arr[j]) {
				//Mayor_Repeticion += 1;
				Cantidad_Repeticiones += 1;
			}
		}
		if (i!=0 && Mayor_Repeticion == Cantidad_Repeticiones) {
			return i;
		}
		Cantidad_Repeticiones = 0;
	}*/



}


/// {2,5,6,7}


int main() {
	int *Size1 = new int(10), *Size3 = new int(10);
	int Arr[10] = {1,8,6,8,3,8,5,8,2,5};
	int *Arr2;
	int *Arr3;
	Arr2 = Determinar_Elementos_Rango(Arr, 3,1, Size1);
	Arr3 = Eliminar_Repetidos(Arr, Size3);
	cout << Arr[Determinar_Mayor(Arr, 5)]<<endl;
	cout << Arr[Determinar_Menor(Arr, 5)] << endl;
	for (int i = 0; i < *Size1; i++) {
		cout << Arr2[i] << " ";
	}
	cout << endl << endl;
	for (int i = 0; i < *Size3; i++) {
		cout << Arr3[i] << " ";
	}
	cout << endl;
	cout << Arr[Elemento_Mayor_Repetido(Arr, 10)]<<endl;

	_getch();
	return 0;
}