#include <iostream>
#include <conio.h>

using namespace std;
using namespace System;


int main() {

	//Manejar excepciones si se ingresa negativos o caracteres

	short N;
	do {

		try {
			cout << "Ingrese un numero positivo: "; cin >> N;
			cout << endl << endl;
			if (N < 0) {
				throw 1;
			}
			else if (N == 0) {
				throw 0;
			}
			else {
				throw 2;
			}
		}
		catch (int X) {
			if (X == 1) {
				cout << "NUMERO NEGATIVO";
			}
			else if (X == 0) {
				cout << "EL NUMERO ES 0";
			}
			else {
				cout << "El numero es: " << N;
			}
			cout << endl;

		}
		cout << endl << endl;
	} while (N != 999);

	_getch();
	return 0;
}