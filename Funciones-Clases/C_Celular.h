#pragma once
#include <iostream>
#include <string>
#include "C_Bateria.h"
#include "C_Camara.h"

using namespace std;

class C_Celular
{
private:
	string Marca = "Nokia";
	float Precio = 100;
	int Numero_Serie = 0001;
	C_Bateria Bateria;
	C_Camara Camara;


public:
	C_Celular();
	C_Celular(string, float, int, string, int, string, int, bool);
	~C_Celular();

	//Setter

	void setMarca(string);
	void setPrecio(float);
	void setNumero_Serie(int);
	void setBateria(C_Bateria);
	void setCamara(C_Camara);


	//Getter

	string getMarca();
	float getPrecio();
	int getNumero_Serie();
	C_Bateria& getBateria();
	C_Camara& getCamara();
	
	//Management

	void Mostrar_Datos();
	void Pedir_Datos();
};

