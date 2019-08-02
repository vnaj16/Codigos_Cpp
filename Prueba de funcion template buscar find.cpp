#include <iostream>
#include <conio.h>
#include <vector>

using namespace std;

bool esPar(int N) {
	return (N % 2 == 0) ? true : false;
}

template<typename ite>
ite Buscar(ite Inicio, ite Final, bool(&funcion) (int)) {
	ite i;
	for (i = Inicio; i != Final; i++) {
		if (funcion(*i)) {
			return i;
		}
	}
	return i;
}

int main() {

	vector<int> Arreglo;

	Arreglo.push_back(1);
	Arreglo.push_back(5);
	Arreglo.push_back(3);
	Arreglo.push_back(8);

	vector<int>::iterator i;

	i = Buscar(Arreglo.begin(), Arreglo.end(), esPar);

	if (i != Arreglo.end()) {
		cout << "elemento par encontrado: " << *i << endl;
	}
	else {
		cout << "elemento no encontrado" << endl;
	}

	_getch();
	return 0;
}