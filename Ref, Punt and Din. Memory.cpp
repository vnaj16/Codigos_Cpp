#include <iostream>
#include <conio.h>
#include <new.h>

using namespace std;

/////////////////////////Memoria dinamica/////////////////

//Estructura de la memoria
	//Zona estatica
		//Variables globales
	//Zona dinamica
		//Variables dinamicas
	//Pila (stack)
		//Variables locales del main y funciones


//Operador new: primero obtiene espacio de la DM y segundo llama a su constructor del objeto
//Operador delete: primero llama al destructor del objeto y luego libera el espacio de la DM
			//Estos operadores se pueden sobrecargar(cambiar la forma en que se realiza la asignacion o liberacion del espacio, las llamadas a Ds y Cs se mantienen)
			//para una clase especifica por cuestiones de eficiencia y para evitar la fragmentacion del monticulo 
							//(la sobrecarga se encuentra en pags 392-396  399(fijar localizacion))
//los parametros de new y delete son void*


//Manejador new-handler para manejo de excepciones, se le debe pasar la direccion de la funcion

void Falta_Memoria() {
	cout << "ERROR" << endl << "Ya no hay memoria disponible para reservar"; _getch();  exit(1);
} //sirve para mostrar o llamar esta funcion cuando ya no hay memoria 
  // siempre debe ser de tipo void y sin parametros







/////////////////////////Referencias/////////////////////

//Devolucion de referencias

	//Respecto a parametros por referencia, son mejores ya que solo requieren copiar un puntero(direccion de la variable) en lugar de copiar un objeto entero
		// es decir, no se llamara a un constructor para una referencia
int& getMayor(int& x, int& y) {
	return x > y ? x : y;
}

void Mostrar_Datos(int x, int y) {
	cout << endl;
	cout << "Valor de x: " << x << endl;
	cout << "Valor de y: " << y << endl;
}

//Recordar siempre crear un constructor de copia para evitar que el compilador cree uno y no pase los datos bit a bit
	//Forma de constructor de copia name_class(const name_class& name_object){}
		//Formas de usar el CC
			//name_class object = copied_object;
			// name_class object(copied_object);
	//Si no se desea que el objeto se pase o retorne por valor, se debe crear un constructor de copia privado








/////////////////////////Punteros/////////////////

//Sintaxis de un puntero
	// (tipo al que apunta) *(Nombre del puntero) = (direccion que guardara)
		//EJM
			// persona *Persona2 = &Persona1;
			// persona *Persona = new persona;

int main() {

	
	/*int x = 16, &a = x;

	cout << "Valor de x: " << x << endl;
	cout << "Valor de a: " << a << endl;
	++a;

	cout << "Valor de x: " << x << endl;
	cout << "Valor de a: " << a;

	int Y = 5;
	a = Y;

	cout << "Valor de a: " << a;*/
 
	/*
	//Prueba de devolucion de referencias
	int x, y;
	cout << "Ingrese x: "; cin >> x;
	cout << "Ingrese y: "; cin >> y;
	Mostrar_Datos(x, y);

	getMayor(x, y) = 1;

	Mostrar_Datos(x, y);
	*/

	/*
	//Tipos de punteros
	int variable = 1;
	const int constante = 2;
	const int (*puntero_a_constante) = &constante;
	int *const puntero_constante_a_variable = &variable;
	const int *const puntero_constante_a_constante = &constante;  // leer asi: primero desde el * seguido de derecha y luego de * a la izquierda
	*/

	/*
	//Tipos de referencias
	int variable = 1;
	const int constante = 2;
	const int &referencia_a_constante = constante;

	// &const es permitido pero innecesario. Por eso nunca se usa.
	// & es igual a &const ya que las referencias apuntan al mismo objeto toda su vida
	int &const referencia_constante_a_variable = variable;
	const int &const referencia_constante_a_constante = constante;*/

	/*
	//Uso de memoria dinamica
	int *Numero_Dinamico = new int;
	//...USO DE LA VARIABLE DINAMICA
	delete(Numero_Dinamico); //Despues de haber hecho todo lo que tenia que hacer
	Numero_Dinamico = 0; // recomendado hacer esto para asegurar que el puntero queda libre y asi evitar que se pase como argumento a delete
	*/

	/*
	//Llamada a new handler
	set_new_handler(Falta_Memoria); //asignacion de nuevo new handler

	int contador = 0;

	while (1) {
		++contador;
		new int[100000000];
		cout << contador << endl;
	}*/

	/*
	//Prueba de referencia con objeto ostream
	ostream &Consola = cout;

	Consola << "Hola";
	*/


	_getch();
	return 0;
}