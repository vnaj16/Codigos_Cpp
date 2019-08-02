#include <iostream>
#include <conio.h>

using namespace std;

struct cuadrado {
	float Lado;
	float Perimetro;
	float Area;

	cuadrado(float n) {
		Lado = n;
		Perimetro = Lado * 4;
		Area = Lado * Lado;
	}

	cuadrado operator + (cuadrado &C) {
		this->Lado += C.Lado;
		this->Perimetro = Lado * 4;
		this->Area = Lado * Lado;

		return *this; //Regreso el mismo objeto pero ya modificado
	}

	//Sumar cuadrado + entero
	cuadrado operator + (const int N) {
		this->Lado += N;
		this->Perimetro = Lado * 4;
		this->Area = Lado * Lado;

		return *this; //Regreso el mismo objeto pero ya modificado
	}

	//Sumar entero + cuadrado
	friend cuadrado operator +(const int N, cuadrado &A);

	cuadrado operator += (cuadrado &C) {
		this->Lado += C.Lado;
		this->Perimetro = Lado * 4;
		this->Area = Lado * Lado;

		return *this; //Regreso el mismo objeto pero ya modificado
	} //Recordar que no es lo mismo + que +=

	//Conversion por operador
		//Se puede convertir a la mayoria de tipo definidos y predefinidos
	//Sintaxis
		// <operator> <tipo a convertir ()>  { <declaraciones>}
	operator int() { return this->Lado; }
};

//Definicion de la funcion friend
cuadrado operator +(const int N, cuadrado &A) {
	A.Lado += N;
	A.Area = A.Lado*A.Lado;
	A.Perimetro = A.Lado * 4;

	return A;
}




class C_Cuadrado {
	float Lado;
	float Perimetro;
	float Area;
public:
	C_Cuadrado() {
		Lado = 1;
		Perimetro = Lado * 4;
		Area = Lado * Lado;
	}
	C_Cuadrado(float N) {
		Lado = N;
		Perimetro = Lado * 4;
		Area = Lado * Lado;
	}
	C_Cuadrado(C_Cuadrado &N) {
		Lado = N.getLado();
		Perimetro = Lado * 4;
		Area = Lado * Lado;
	}
	~C_Cuadrado() {

	}

	C_Cuadrado operator + (C_Cuadrado &C) {
		this->Lado += C.Lado;
		this->Perimetro = Lado * 4;
		this->Area = Lado * Lado;

		return *this; //Regreso el mismo objeto pero ya modificado
	}

	float getLado() {
		return Lado;
	}

	void Mostrar_Datos() {
		cout << "Cuadrado de lado: " << Lado << endl;
		cout << "Perimetro: " << Perimetro << endl;
		cout << "Area: " << Area <<endl;
	}
};


////////////////SOBRECARGA DE OPERADORES//////////
	//La sobrecarga de operadores es solamente «azúcar sintáctico», lo que signiﬁca que es simplemente otra manera de invocar funciones.
	//
	//La diferencia es que los argumentos para estas funciones no aparecen entre paréntesis, sino que rodean o 
	//siguen a los caracteres que siempre pensó como operadores inalterables.
	//
	//Sintaxis
		// <tipo> operator <operador> (<argumentos>){
		// <sentencias>
		//	}
	//Recordar: Si el operador está deﬁnido como una función global (un argumento para los unarios, dos para los binarios) 
		//o un método (cero argumentos para los unarios y uno para los binarios. 
		//En este último caso el objeto (this) se convierte en el argumento del lado izquierdo al operador).
	//Nota:  los operadores =, [], ->, (), new, delete solo pueden ser sobrecargados cuando se definen como miembros de una clase//
			//el tipo de dato de los parametros y el valor de retorno pueden ser diferentes

int main() {

	cuadrado C1(2), C2(3);
	C_Cuadrado C3(6),C4(2), C5 = C4;

	/*
	//Comprobacion del operador con la estructura cuadrado
	cout << "Lado de C1: " << C1.Lado << endl;
	cout << "Lado de C2: " << C2.Lado << endl;

	C1 = C1 + C2;
	cout << "Lado de C1: " << C1.Lado << endl;
	cout << "Lado de C2: " << C2.Lado << endl;

	C1 += C2;
	cout << "Lado de C1: " << C1.Lado << endl;
	cout << "Lado de C2: " << C2.Lado << endl;

	C1 = C1 + 5;
	cout << "Lado de C1: " << C1.Lado << endl;
	cout << "Lado de C2: " << C2.Lado << endl;
	C1 = 5 + C1;
	cout << "Lado de C1: " << C1.Lado << endl;
	cout << "Lado de C2: " << C2.Lado << endl;
	//*/
	
	/*
	//Comprobacion del operador con la clase cuadrado
	C3.Mostrar_Datos();
	C3 = C3 + C4;
	C3.Mostrar_Datos();*/

	//cout << "Lado de C1: " << int(C1); //Prueba de conversion

	_getch();
	return 0;
}

