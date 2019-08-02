#include <iostream>
#include <conio.h>

using namespace std;

int main() {

	int N;
	int Suma = 0;
	int C = 0;
	while (cin >> N && N!=0) {
		Suma += N;
		C++;
	}

	cout << endl << "Ingresaste " << C << " numeros" <<endl;
	cout << "La suma de los numeros es: " << Suma;

	_getch();
	return 0;
}