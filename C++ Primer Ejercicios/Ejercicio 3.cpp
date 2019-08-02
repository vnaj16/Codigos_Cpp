#include <iostream>
#include <conio.h>

using namespace std;

struct persona {
	unsigned int Edad;
	double Estatura;
}

int main() {
/*
	bool V = 65;
	int I = V;
	signed char C = 256;


	if (V) {
		cout << "Es Verdadero";
	}
	else {
		cout << "Es Falso";
	}

	cout << endl << "El valor de I es: " << I;

	cout << endl << "El valor de C es: " << C;
	*/

	/*unsigned u = 10, u2 = 42; 
	std::cout << u2 - u << std::endl; 
	std::cout << u - u2 << std::endl; 
	int i = 10, i2 = 42; 
	std::cout << i2 - i << std::endl; 
	std::cout << i - i2 << std::endl; 
	std::cout << i - u << std::endl; 
	std::cout << u - i << std::endl;

	*/

	/*int Edad = 5;
	int &refEdad = Edad;
	cout << "Edad: " << Edad << endl;
	cout << "refEdad: " << refEdad << endl;
	refEdad += 2;
	cout << "Edad: " << Edad << endl;
	cout << "refEdad: " << refEdad << endl;*/

	persona P1 = { 15,1.86 };

	cout << P1.Edad << endl << P1.Estatura;

	_getch();
	return 0;
}