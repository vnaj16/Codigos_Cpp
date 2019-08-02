#pragma once
#include "C_Cuestionario.h"
class C_Encuesta
{
private:
	int Numero_Cuestionarios=0;
	C_Cuestionario *Encuesta;

	int CE_Tipo1 = 0; //Cantidad de empleados que indican que definitivamente no reciben un salario adecuado por su trabajo. 
	int CE_Tipo2 = 0; //Porcentaje de empleados que señalan que a menudo las tareas asignadas ayudan a desarrollar su aspecto profesional. 
	int CE_Tipo3 = 0; //Cantidad de empleados que si reciben un salario adecuado y si están satisfechos con su empleo. 

public:
	C_Encuesta();
	~C_Encuesta();

	//Setter

	bool setEncuesta(int N);

	//Getters

	int getNumero_Cuestionarios() { return Numero_Cuestionarios; }
	C_Cuestionario *getEncuesta() { return Encuesta; }

	int getCE_Tipo1() { return CE_Tipo1; }
	int getCE_Tipo2() { return CE_Tipo2; }
	int getCE_Tipo3() { return CE_Tipo3; }

	//Analizar Encuesta
	void Analizar_Datos();


	//Ordenar datos
	void Ordenar_Datos();

};

