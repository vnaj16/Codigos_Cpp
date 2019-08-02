#include "C_Cuadrado.h"
#include <iostream>

using namespace std;

C_Cuadrado::C_Cuadrado()
{
}

C_Cuadrado::C_Cuadrado(int L) : C_Cuadrilatero()
{
	Lado = L;
	Perimetro = Lado * 4;
	Area = Lado * Lado;
	cout << endl << "CUADRADO CREADO" << endl << endl;
}


C_Cuadrado::~C_Cuadrado()
{
	cout << endl << "CUADRADO DESTRUIDO" << endl;
}

float C_Cuadrado::Hallar_Area()
{
	return Area = Lado*Lado;
}

float C_Cuadrado::Hallar_Perimetro()
{
	return Perimetro = Lado * 4;
}

void C_Cuadrado::Pintar_Cuadrado()
{
	cout << "PINTADO";
}

void C_Cuadrado::Pintar()
{
	cout << endl << endl << "Cuadrado pintado" << endl << endl;
}
