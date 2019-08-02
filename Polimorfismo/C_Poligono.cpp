#include "C_Poligono.h"
#include <iostream>

using namespace std; //No agregar muchos de estos en los .h ya que a la hora de agregarlos en otros archivos, se sobreagregan y tal

C_Poligono::C_Poligono()
{
	Area = Perimetro = 0;
	cout << endl << "POLIGONO CREADO" << endl;
}

C_Poligono::C_Poligono(float Area, float Perimetro)
{
	this->Area = Area;
	this->Perimetro = Perimetro;
	cout << endl << "POLIGONO CREADO" << endl <<endl;
}


C_Poligono::~C_Poligono()
{
	cout << endl << "POLIGONO DESTRUIDO" << endl;
}

std::string C_Poligono::ToString()
{
	return "Area: " + std::to_string(Area) + "\nPerimetro: " + std::to_string(Perimetro) + '\n';
}
