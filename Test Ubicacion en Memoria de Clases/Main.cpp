#include <iostream>
#include <conio.h>
#include "C_Punto.h"

using namespace std;

void main() {
	int Numero = 5; //Ubicado en la pila
	C_Punto Punto_Estatico; // Ubicado en la pila
	C_Punto *Punto_Dinamico = new C_Punto(); //el puntero esta ubicado en la pila, lo que apunta esta en el heap

	cout << "Direccion de Numero: " << long(&Numero) << endl << endl; //En la pila

	cout << "Direccion de Punto estatico: " << long(&Punto_Estatico) << endl; // En la pila
	Punto_Estatico.getDirections(); // Las variables y metodos estan en la pila

	cout << endl << endl << "Direccion del puntero Punto dinamico: " << long(&Punto_Dinamico) << endl << endl; //En la pila

	cout << "Direccion de Punto dinamico: " << (long)Punto_Dinamico << endl; // En el heap
	Punto_Dinamico->getDirections(); // Las variables y metodos estan en el heap


	//Conclusion: las variables y metodos de la clase se crean o se colocan donde se instancie el objeto. Es decir, si el objeto se instancia en el heap, en el heap se pondran las variables y metodos

	_getch();
}