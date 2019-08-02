#pragma once
#include <iostream>
#include <string>

using namespace std;

class C_Bateria
{
private:
	string Marca = "Generica";
	int Miliamperios = 3000;

public:
	C_Bateria();
	~C_Bateria();

	//Setter
	
	void setMarca(string);
	void setMiliamperios(int);

	//Getter 

	string getMarca();
	int getMiliamperios();

	//Management

	void Mostrar_Datos();
	void Pedir_Datos();
};

