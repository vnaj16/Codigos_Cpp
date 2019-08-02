#include <iostream>
#include <conio.h>
#include <cstdlib>

using namespace std;

//Arreglo dinamico de mas de un millon de elementos para comprobar velocidad de busqueda del Binary Search

//Se comprueba que la busqueda binaria es super efectiva en tiempo
int Time_BS=0, Time_TS=0;

int Binary_Search(int *Array, int Numero, int Limite_Inferior, int Limite_Superior) {
	int Medio;
	if (Limite_Inferior > Limite_Superior) {
		_sleep(1);
		++Time_BS;
		return -1;
	}
	else {
		Medio = (Limite_Inferior + Limite_Superior) / 2;
		if (Numero == *(Array + Medio)) {
			_sleep(1);
			++Time_BS;
			return Medio;
		}
		else if (Numero > *(Array + Medio)) {
			_sleep(1);
			++Time_BS;
			return Binary_Search(Array, Numero, Medio + 1, Limite_Superior);
		}
		else {
			_sleep(1);
			++Time_BS;
			return Binary_Search(Array, Numero, Limite_Inferior, Medio - 1);
		}
	}
}

int Traditional_Search(int *Array, int Numero, int Size) {
	for (int i = 0; i < Size; i++) {
		_sleep(1);
		++Time_TS;
		if (*(Array + i) == Numero) {
			return i;
		}
	}

	return -1;
}

void Generar_Numeros(int *Array, int Size) {
	for (int i = 0; i < Size; i++) {
		Array[i] = i + 1;
	}
}


int main() {

	int Size = 10000;
	int *Array = new int[Size];
	int Posicion = 0;

	Generar_Numeros(Array, Size);

	cout << "		Busqueda binaria: " << endl;
	cout << (((Posicion = Binary_Search(Array, 9999, 0, Size - 1)) == -1)? "No se encontro" : "Si, se encontro en la posicion  ") << Posicion << endl;
	cout << "TIEMPO USADO: " << Time_BS << " milisegundos" << endl << endl;
	cout << "		Busqeda tradicional: " << endl;
	cout << (((Posicion == Traditional_Search(Array, 9999,Size - 1)) == -1) ? "No se encontro" : "Si, se encontro en la posicion  ") << Posicion << endl;
	cout << "TIEMPO USADO: " << Time_TS << " milisegundos" << endl << endl;



	_getch();
	return 0;
}