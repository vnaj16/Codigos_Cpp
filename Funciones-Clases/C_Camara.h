#pragma once
#include <iostream>
#include <string>

using namespace std;

class C_Camara
{
private:
	int Megapixeles = 13;
	string Marca = "Generica";
	bool tieneFlash = true;

public:
	C_Camara();
	~C_Camara();


	//setter

	void setMegapixeles(int);
	void setMarca(string);
	void setTieneFlash(bool);

	//Getter

	int getMegapixeles();
	string getMarca();
	bool getTieneFlash();

	//Management

	void Mostrar_Datos();
	void Pedir_Datos();

};

