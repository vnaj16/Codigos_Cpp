#include "C_Cuestionario.h"
#include <cctype>


C_Cuestionario::C_Cuestionario()
{
}


C_Cuestionario::~C_Cuestionario()
{
}

bool C_Cuestionario::setEdad(int Edad)
{
	if (Edad < 18 || Edad > 60) {
		return false;
	}
	
	this->Edad = Edad;
	return true;
}

void C_Cuestionario::setIndice(int N)
{
	Indice = N;
}

bool C_Cuestionario::setRespuesta1(char R1)
{
	R1 = char(toupper(R1));

	if (R1 == 'A' || R1 == 'B' || R1 == 'C' || R1 == 'D') {
		Respuesta1 = R1;
		return true;
	}

	return false;
}

bool C_Cuestionario::setRespuesta2(char R2)
{
	R2 = char(toupper(R2));

	if (R2 == 'A' || R2 == 'B' || R2 == 'C' || R2 == 'D') {
		Respuesta2 = R2;
		return true;
	}

	return false;
}

bool C_Cuestionario::setRespuesta3(char R3)
{
	R3 = char(toupper(R3));

	if (R3 == 'A' || R3 == 'B' || R3 == 'C' || R3 == 'D') {
		Respuesta3 = R3;
		return true;
	}

	return false;
}
