#include "C_Triangulo.h"
#include <iostream>
#include <cmath>

using namespace std;


C_Triangulo::C_Triangulo()
{
	cout << endl << "TRIANGULO CREADO" << endl << endl;
}

C_Triangulo::C_Triangulo(int Lados,int Lado1, int Lado2, int Lado3) : C_Poligono()
{
	Numero_Lados = Lados;
	this->Lado1 = Lado1;
	this->Lado2 = Lado2;
	this->Lado3 = Lado3;
	Perimetro = Lado1 + Lado2 + Lado3;
	Area = sqrt(Perimetro*(Perimetro - Lado1)*(Perimetro - Lado2)*(Perimetro - Lado2));
	cout << endl << "TRIANGULO CREADO" << endl;
}


C_Triangulo::~C_Triangulo()
{
	cout << endl << "TRIANGULO DESTRUIDO" << endl;
}

float C_Triangulo::Hallar_Area()
{
	return Area = sqrt(Perimetro*(Perimetro - Lado1)*(Perimetro - Lado2)*(Perimetro - Lado2));
}

float C_Triangulo::Hallar_Perimetro()
{
	return Perimetro = Lado1 + Lado2 + Lado3;
}

int C_Triangulo::getNumero_Lados()
{
	return Numero_Lados;
}

void C_Triangulo::Pintar()
{
	cout << endl << endl << "Triangulo pintado" << endl << endl;
}
