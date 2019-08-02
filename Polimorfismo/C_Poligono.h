#pragma once
#include <string>
class C_Poligono
{
protected:
	float Area, Perimetro;

public:
	C_Poligono();
	C_Poligono(float, float);
	virtual ~C_Poligono(); //Regla: si en una clase existen funciones virtuales, el destructor debe ser virtual para borrar correctamente

	virtual float Hallar_Area() = 0; //Funciones virtuales puras //Basta con una para que la clase sea abstracta
	virtual float Hallar_Perimetro() = 0;
	virtual void Pintar() = 0;
	
	std::string ToString();
};

