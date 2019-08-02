#include "C_Persona.h"
#include <iostream>

int C_Persona::Cantidad_Personas = 0;

C_Persona::C_Persona()
{
	this->Nombre = "Unnamed";
	this->Edad = 0;
	this->Altura = 0;
	std::cout << std::endl << "PERSONA CREADA" << std::endl << std::endl;
	Cantidad_Personas++;
}

C_Persona::C_Persona(std::string Nombre, int Edad, C_Birthday &B, float Altura) : Birthday(B)
{
	this->Nombre = Nombre;
	this->Edad = Edad;
	this->Altura = Altura;
	std::cout << std::endl << "PERSONA CREADA" << std::endl << std::endl;
	Cantidad_Personas++;
}


C_Persona::C_Persona(std::string Nombre, int Edad)
{
	this->Nombre = Nombre;
	this->Edad = Edad;
	this->Altura = 1.50;
	std::cout << std::endl << "PERSONA CREADA" << std::endl << std::endl;
	Cantidad_Personas++;
}

C_Persona::C_Persona(std::string Nombre)
{
	this->Nombre = Nombre;
	this->Edad = 19;
	this->Altura = 1.86;
	std::cout << std::endl << "PERSONA CREADA" << std::endl << std::endl;
	Cantidad_Personas++;
}

C_Persona::C_Persona(const C_Persona &P)
{
	this->Nombre = P.Nombre;
	this->Altura = P.Altura;
	this->Edad = P.Edad;
	std::cout << std::endl << "PERSONA CREADA  cc" << std::endl << std::endl;
	Cantidad_Personas++;
}


C_Persona::~C_Persona()
{
	std::cout << std::endl << "PERSONA DESTRUIDA" << std::endl << std::endl;
}

void C_Persona::setNombre(std::string Nombre)
{
	this->Nombre = Nombre;
}

void C_Persona::setEdad(int Edad)
{
	this->Edad = Edad;
}

void C_Persona::setAltura(float Altura)
{
	this->Altura = Altura;
}

std::string C_Persona::getNombre()
{
	return this->Nombre;
}

int C_Persona::getEdad()
{
	return this->Edad;
}

float C_Persona::getAltura()
{
	return this->Altura;
}

C_Birthday & C_Persona::getBirthday()
{
	return Birthday;
}

void C_Persona::Mostrar_Datos()
{
	std::cout << std::endl << std::endl << "		" << this->Nombre << std::endl;
	std::cout << "Edad: " << this->Edad << std::endl;
	std::cout << "Altura: " << this->Altura << std::endl;
	std::cout << "Birthday: " << Birthday.ToString() << std::endl << std::endl;
}

void C_Persona::Mostrar_Cantidad()
{
	std::cout << "La cantidad de personas creadas son: " << Cantidad_Personas << std::endl;
}
