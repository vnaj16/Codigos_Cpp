#include "C_Encuesta.h"



C_Encuesta::C_Encuesta()
{
}


C_Encuesta::~C_Encuesta()
{
}

bool C_Encuesta::setEncuesta(int N)
{
	if (N > 0 && N <=100) {
		Numero_Cuestionarios = N;
		Encuesta = new C_Cuestionario[N];
		return true;
	}
	return false;
}

void C_Encuesta::Analizar_Datos()
{
	for (int i = 0; i < Numero_Cuestionarios; i++) {
		if (Encuesta[i].getRespuesta1() == 'D') {
			CE_Tipo1 += 1;
		}

		if (Encuesta[i].getRespuesta2() == 'B') {
			CE_Tipo2 += 1;
		}

		if ((Encuesta[i].getRespuesta1() == 'A' || Encuesta[i].getRespuesta1() == 'B') &&
			(Encuesta[i].getRespuesta3() == 'A' || Encuesta[i].getRespuesta3() == 'B')
			)
		{
			CE_Tipo3 += 1;
		}
	}
}

void C_Encuesta::Ordenar_Datos()
{

	for (int i = 0; i < Numero_Cuestionarios - 1; i++) {
		for (int j = i + 1; j < Numero_Cuestionarios; j++) {
			if (Encuesta[i].getEdad() > Encuesta[j].getEdad()) {
				C_Cuestionario Aux = Encuesta[i];

				Encuesta[i] = Encuesta[j];
				Encuesta[j] = Aux;
			}
		}
	}

}
