#pragma once
#include "C_Poligono.h"
class C_Triangulo : public C_Poligono
{
	int Numero_Lados,Lado1,Lado2,Lado3;
public:
	C_Triangulo();
	C_Triangulo(int,int,int,int);
	~C_Triangulo();

	float Hallar_Area();
	float Hallar_Perimetro();
	int getNumero_Lados();
	void Pintar();
};

