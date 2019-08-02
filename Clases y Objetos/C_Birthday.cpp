#include "C_Birthday.h"
#include <iostream>

using namespace System;

C_Birthday::C_Birthday()
{
	std::cout << std::endl << "CUMPLE CREADO" << std::endl << std::endl;
}

C_Birthday::C_Birthday(int D, int M, int Y)
{
	Day = D;
	Month = M;
	Year = Y;
	std::cout << std::endl << "CUMPLE CREADO" << std::endl << std::endl;
}

C_Birthday::C_Birthday(const C_Birthday &C)
{
	Day = C.Day;
	Month = C.Month;
	Year = C.Year;
	std::cout << std::endl << "CUMPLE CREADO  cc" << std::endl << std::endl;
}


C_Birthday::~C_Birthday()
{
	std::cout << std::endl << "CUMPLE DESTRUIDO" << std::endl << std::endl;
}

std::string C_Birthday::ToString()
{
	/*std::string N="";
	N += std::to_string(Day); //metodo del estandar C++	11 para pasar a string
	N += " / ";
	N += std::to_string(Month);
	N += " / ";
	N += std::to_string(Year);
	return N;*/
	
	//Por cuestiones de efectividad (evitar crear objeto string)
	return std::to_string(Day) + " / " + std::to_string(Month) + " / " + std::to_string(Year);
}
