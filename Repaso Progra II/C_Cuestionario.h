#pragma once
class C_Cuestionario
{
private:
	int Edad = 0, Indice; //Para indicar numero de cuestionario
	char Respuesta1 = 'A', Respuesta2 = 'A', Respuesta3 = 'A';

public:
	C_Cuestionario();
	~C_Cuestionario();

	C_Cuestionario(int Indice) {
		this->Indice = Indice;
	}

	//Getters

	int getEdad() { return Edad; }
	int getIndice() { return Indice; }

	char getRespuesta1() { return Respuesta1; }
	char getRespuesta2() { return Respuesta2; }
	char getRespuesta3() { return Respuesta3; }

	//Setters

	bool setEdad(int);
	void setIndice(int);

	bool setRespuesta1(char);
	bool setRespuesta2(char);
	bool setRespuesta3(char);
};

