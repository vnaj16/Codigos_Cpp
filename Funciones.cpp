#include <iostream>
#include <conio.h>
#include <string>

using namespace std;
using namespace System;

//Funcion sobrecargada 
void Escribir_Datos(string Nombre) {
	cout << "Nombre: " << Nombre;
}

void Escribir_Datos(string Nombre, int Edad) {
	cout << "Nombre: " << Nombre << endl;
	cout << "Edad: " << Edad;
}


//Funcion con parametros por defecto
	//Recordar que los parametros por defecto siempre van a lo ultimo
	//Basta que el primer parametro por defecto sea inicializado para que el resto lo haga
	//No se usan si se debe agregar codigo de validacion
	//Ordenar los argumentos de acuerdo un orden logico(valores tipicos, secuencias, los que menos cambian se ponen al final, etc)
void Mostrar_Datos(int Codigo, string Nombre = "SIN NOMBRE", int Edad = 0) {
	cout << "Codigo: " << Codigo << endl;
	cout << "Nombre: " << Nombre << endl;
	cout << "Edad: " << Edad;
}



//Funcion de plantilla
template <class T> 
	void Mostrar(T var) {
		cout << var << endl;
	}


template <class T>
void Mostrar_Mayor(T n1, T n2, T n3) {
	cout << "El mayor es: ";
	if (n1 > n2 && n1 > n3) {
		cout << n1;
	}
	else {
		if (n2 > n3) {
			cout << n2;
		}
		else {
			cout << n3;
		}
	}
}


//Funcion con paso de referencia
//Por eficiencia, para no crear copias de los parametros, se pasan los parametros por referencia
//Generalmente se usan las referencias para modificar las variables, pero si no se van a modificar y se desea eficiencia con datos no predefinidos
//Se debe usar <const type& name> ejm: const string& Nombre 
void Duplicar_Numeros(int &X, int &Y) {
	X *= 2;
	Y *= 2;
}


//Funciones inline
	//Se usan para optimizar, ya que se evita el proceso de llamar a una funcion normal(apilamientos,saltos,etc) y lo que en vez hace es reemplazar el codigo de la funcion
	//en el lugar donde se llama. Se recomienda cuando el cuerpo de la función es pequeño o su tarea no es tan grande
inline void Saludar() {
	cout << "HOLA, SOY UNA FUNCION INLINE" << endl;
}




//Funcion con array de parametro
void Mostrar_Numero(int Arr[], int Size) {
	for (int i = 0; i < Size; i++) {
		cout << "Elemento " << i + 1 << ": " << Arr[i]<<endl;
	}
}

//Funcion con matriz de parametro
void Mostrar_Numero(int M[][5], int Filas, int Columnas) {
	for (int f = 0; f < Filas; f++) {
		for (int c = 0; c < Columnas; c++) {
			cout << M[f][c] << " ";
			if (M[f][c] < 10) {
				cout << " ";
			}
		}
		cout << endl;
	}
}

//Funcion recursiva
/*
la recursión gana mucho en legibilidad pero pierde igualmente en rendimiento, 
por lo que sólo es recomendable para resolver problemas que no requieran de muchos 
calculos por parte del procesador, mientras que los bucles o ciclos administran de 
forma mucho más eficiente los recursos de la computadora.
*/
void Mostrar_Numero(int n, int f) {

	if (n != f) { //Caso general
		cout << n << " ";
		Mostrar_Numero(n+1 ,f);
	}
	else {//Caso base
		cout << n;
	}
}

void Buscar_Numero(int Indice,int Arr[],int Size, int &Posicion, int Numero) {
	if (Arr[Indice] == Numero) {
		Posicion = Indice;
	}
	else {
		if (Indice < Size) {
			Buscar_Numero(Indice + 1, Arr, Size, Posicion, Numero);
		}
		else {
			Posicion = -1;
		}
	}
}

void Buscar_Numero(int Arr[], int Size, int &Posicion, int Numero) {
	for (int i = 0; i < Size; i++) {
		if (Arr[i] == Numero) {
			Posicion = i;
			break;
		}
	}
}


//Funciones con funciones como parametros

int Duplicar(int N) {
	return N * 2;
}

int Triplicar(int N) {
	return N * 3;
}

void escribir(int *Array, int Size, int (&Funcion)(int)) { //Para poner como parametro una funcion se pone su tipo de retorno, como referencia o puntero y dos parentesis con los parametros corres.
					//SINTAXIS: return type ((& o *)Name Function) (parameter list)
	for (int i = 0; i < Size; i++) {
		cout << Funcion(Array[i]) << " ";
	}
	cout << endl;
}

int main() {

	/*
	//Llamada a funcion sobrecargada
	Escribir_Datos("Arthur");
	Escribir_Datos("Arthur", 19);*/

	/*
	//Llamada a funcion con PD
	Mostrar_Datos(15);*/

	/*
	//Llamada a funcion de plantilla
	string Nombre = "Arthur";

	Mostrar((long)&Nombre);*/

	/*
	//Llamada a funcion con paso de referencia
	int X = 5, Y = 6;
	cout << "ANTES DE LA LLAMADA" << endl;
	cout << "X: " << X << endl;
	cout << "Y: " << Y << endl;

	Duplicar_Numeros(X, Y);

	cout << "DESPUES DE LA LLAMADA" << endl;
	cout << "X: " << X << endl;
	cout << "Y: " << Y << endl;*/

	/*
	//Llamada a funcion con parametro array
	int Arr[5] = { 1,2,3,4,5 };

	Mostrar_Numero(Arr, 5);*/

	/*
	//Llamada a funcion con parametro matriz
	int M[3][5] = { {1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15} };
	Mostrar_Numero(M, 3, 5);*/

	/*
	//Llamada a funcion recursiva
	//Mostrar_Numero(5);
	const int Size = 199999;
	int Arr[Size];

	for (int i = 0; i < Size; i++) {
		Arr[i] = 0;
	}
	Arr[Size-1] = 1;
	int Posicion = -1;

	//Buscar_Numero(0, Arr, Size, Posicion, 1); //Recursividad provoca stack overflow
	Buscar_Numero(Arr, Size, Posicion, 1); //Iteracion se ejecuta normal

	if (Posicion >= 0) {
		cout << "El numero se encontro en la posicion " << Posicion << endl;
	}
	else {
		cout << "El numero no se ha encontrado";
	}*/
	

	//Comprobacion de funcion que recibe funcion como argumento
	int *Array = new int(5);
	Array[0] = 1;
	Array[1] = 2;
	Array[2] = 3;
	Array[3] = 4;
	Array[4] = 5;
	escribir(Array, 5, Duplicar);
	escribir(Array, 5, Triplicar);

	_getch();
	return 0;
}