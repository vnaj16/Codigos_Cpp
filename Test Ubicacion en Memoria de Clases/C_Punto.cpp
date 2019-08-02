#include "C_Punto.h"
#include <iostream>



C_Punto::C_Punto()
{
	X = 5;
	Y = 5;
}


C_Punto::~C_Punto()
{
}

void C_Punto::getDirections()
{
	std::cout << "Direccion de X: " << long(&X) <<std::endl;
	std::cout << "Direccion de Y: " << long(&Y) << std::endl;
}
