#pragma once
#include <string>
#include "C_Birthday.h"
class C_Persona
{
private:
	std::string Nombre;
	static int Cantidad_Personas; //se inicializa o define en fuera de la clase, por cuestiones practicas sera en el .cpp
								// pertenece a la clase, no a los objetos
	int Edad;
	float Altura;
	C_Birthday Birthday;  //Composicion
public:
	C_Persona();
	C_Persona(std::string Nombre, int Edad, C_Birthday &B, float Altura=1.50);
	C_Persona(std::string Nombre, int Edad);
	C_Persona(std::string Nombre);
	C_Persona(const C_Persona &); //constructor de copia
	~C_Persona();

	////Setters

	void setNombre(std::string);
	void setEdad(int);
	void setAltura(float);

	////Getters

	std::string getNombre();
	int getEdad();
	float getAltura();
	C_Birthday& getBirthday();


	//////Management

	void Mostrar_Datos();

	static void Mostrar_Cantidad();

	friend void Saludar_A(const C_Persona &P1); //funcion amiga permite acceder a miembros no publicos, esta definida en otro archivo

};

//La diferencia entre definir una funcion miembro dentro de la definicion de la clase y declarar la funcion dentro de la clase y definirla fuera de la clase
//Es que en la primera la funcion es considerada de manera automatica por el compilador una funcion miembro inline, mientras que en la segunda es una funcion normal(not - inline)
//Esto no causa diferencia en su comportamiento, pero si posibles optimizaciones del compilador
