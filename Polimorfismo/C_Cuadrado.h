#pragma once
#include "C_Cuadrilatero.h"
class C_Cuadrado : public C_Cuadrilatero
{
	int Lado;
public:
	C_Cuadrado();
	C_Cuadrado(int);
	~C_Cuadrado();

	float Hallar_Area();
	float Hallar_Perimetro();
	void Pintar_Cuadrado();
	void Pintar();
};

