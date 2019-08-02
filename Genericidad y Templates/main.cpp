#include <iostream>
#include <conio.h>
#include "Matematica.h"

using namespace std;

struct Punto {
	float X, Y;
	Punto(int X, int Y) {
		this->X = X;
		this->Y = Y;
	}

	Punto(const Punto& point) {
		this->X = point.X;
		this->Y = point.Y;
	}

	Punto operator +(const Punto& point) {
		this->X += point.X;
		this->Y += point.Y;

		return *this;
	}

	Punto operator -(const Punto& point) {
		this->X -= point.X;
		this->Y -= point.Y;

		return *this;
	}

	Punto operator *(const Punto& point) {
		this->X *= point.X;
		this->Y *= point.Y;

		return *this;
	}

	Punto operator /(const Punto& point) {
		this->X /= point.X;
		this->Y /= point.Y;

		return *this;
	}

	//Puede ser void tambien
	//Lo del lado derecho lo asigna al izquierdo, supuestamente, pero en este caso, los valores del lado derecho los asignamos al lado izquierdo
	int operator =(const Punto& point) {
		this->X = point.X;
		this->Y = point.Y;

		return 1;
	}
};

struct Fraccion {
	int Denominador, Numerador;

	Fraccion(int Numerador, int Denominador) {
		this->Numerador = Numerador;
		this->Denominador = Denominador;
	}

	Fraccion(const Fraccion &F) {
		this->Numerador = F.Numerador;
		this->Denominador = F.Denominador;
	}

	//	8/4		4/8

	void Factorizar() {
		int Divisores[] = { 2,3,5,7,11,13 };
		bool Pasar = false;

		//Simulo el proceso de maximo comun divisor
		for (int i = 0; i < 6; i++) {
			Pasar = false;
			while (!Pasar) {
				if ((Numerador % Divisores[i] == 0) && (Denominador % Divisores[i] == 0)) {
					Numerador /= Divisores[i];
					Denominador /= Divisores[i];
				}
				else {
					Pasar = true;
				}
			}
		}
	}

	Fraccion operator + (const Fraccion &F) {
		this->Numerador = this->Numerador*F.Denominador + this->Denominador*F.Numerador;
		this->Denominador *= F.Denominador;

		Factorizar();

		return *this;
	}

	Fraccion operator - (const Fraccion &F) {
		this->Numerador = this->Numerador*F.Denominador - this->Denominador*F.Numerador;
		this->Denominador *= F.Denominador;

		Factorizar();

		return *this;
	}

	Fraccion operator * (const Fraccion &F) {
		this->Numerador *= F.Numerador;
		this->Denominador *= F.Denominador;

		Factorizar();

		return *this;
	}

	Fraccion operator / (const Fraccion &F) {
		this->Numerador *= F.Denominador;
		this->Denominador *= F.Numerador;

		Factorizar();

		return *this;
	}


};

//Plantillas de funcion
	//Se acostumbra a usar typename

//Plantillas de clase
	//Se acostumbra a usar class

template <typename T>
T Sumar(T Element1, T Element2) {
	return Element1 + Element2;
}


int main() {

	/*Punto p1(2, 4), p2(4, 6);
	
	cout << "ANTES DE LA SUMA" << endl;
	cout << "Punto x: " << p1.X << endl;
	cout << "Punto y: " << p1.Y << endl;

	p1 = Sumar(p1, p2);

	cout << "DESPUES DE LA SUMA" << endl;
	cout << "Punto x: " << p1.X << endl;
	cout << "Punto y: " << p1.Y << endl;
	*/
	
	/*
	Fraccion f1(3,2), f2(5,3);

	cout << f1.Numerador << endl;
	cout << f1.Denominador << endl;

	f1 = f1 / f2;

	cout << f1.Numerador << endl;
	cout << f1.Denominador << endl;*/

	Matematica <int> Operaciones(2,5);

	cout << Operaciones.Sumar();

	_getch();
	return 0;
}