#include <iostream>
#include <conio.h>
#include <vector>
#include <deque>
#include <fstream> //para ofstream o ifstream
#include <iterator> //para ostream_iterator
#include <numeric>	//para accumulate
#include <algorithm>
using namespace std;
using namespace System;

//Funcion template con estructura similar a las de algorithm
		//Se apoyan de los iteradores para trabajar con cualquier contenedor
template<typename iterador> // puede ser class en ves de typename
iterador Maximo(iterador Inicio, iterador Final) { //devuelve un iterador  //recibe dos iteradores para trabajar con cualquier rango
	//Creamos una variable para guardar el maximo y otra para recorrer con los iteradores sin alterar los originales
	iterador Maximo = Inicio;
	iterador Aux = Inicio;

	while (Aux != Final) {
		if (*Aux > *Maximo) {//Comparamos para ver si el actual es mayor al maximo
			Maximo = Aux;
		}
		Aux++; //Recorremos en ++
	}

	return Maximo; //devolvemos el iterador
}

template<typename iterador>
void Show(iterador Inicio, iterador Fin, char Fill = '|') {
	for (iterador i = Inicio; i != Fin; ++i) {
		cout << *i ;
		if (i != Fin - 1 ) {
			cout << Fill;
		}
	}
	cout << endl;
}

template<typename iterador>
int getPosition(iterador Inicio, iterador Posicion) {
	int P = 0;

	while (Posicion != Inicio) {
		Posicion--;
		P++;
	}

	return P;
}


int Generar() {
	return rand() % 6 + 10;
}

template<typename type>
bool esPar(type Objeto) {
	return (Objeto % 2 == 0);
}

void Duplicar(int &N) { // recibe el parametro por referencia
	N *= 2;
}

int Convertir_Par(int N) {
	return (N % 2 == 0) ? N : N + 1;
}

int main() {

	vector<int> Lista_Numeros = { 51,22,43,84,25,46,71,84,49,100,511,128 };
	deque<int> Lista_Numeros2 = { 10,2,30,45,5,6, };


	//////////////Probamos nuestra funcion template que trabaja con cualquier contenedor gracias a los iteradores/////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//cout << "El maximo de vector: " << *(Maximo(Lista_Numeros.begin(), Lista_Numeros.end())) << endl;
	//cout << "El maximo de deque: " << *(Maximo(Lista_Numeros2.begin(), Lista_Numeros2.end())) << endl << endl << endl;

	//generate(Lista_Numeros.begin(), Lista_Numeros.end(), Generar); //Genero numeros aleatorios //parametros(iterador de inicio, iterador de fin,funcion generadora)

	/////////////////////Muestro elementos///////////////
	/////////////////////////////////////////////////////
	/*
	Show(Lista_Numeros.begin(), Lista_Numeros.end(), ' '); 

	cout << endl << endl;*/



	/////////////////Copio elementos a un puntero/////////////
	//////////////////////////////////////////////////////////
	/*
		//1ra forma
	vector<int> Vector_Copia(7); //Aca reservo 7 espacios para copiar el array
	int Array[] = { 0,1,2,3,4,5,6 }; //array que copio
	copy(Array, Array + 7, Vector_Copia.begin());////paso elementos del inicio hasta el final al puntero del 3er parametros

	for (vector<int>::iterator i = Vector_Copia.begin(); i != Vector_Copia.end(); ++i) {
		cout << *i << " ";
	}
	

		//2da forma
	//ostream_iterator<int> Salida(cout, "|"); //iterador de salida que se escribe secuencialmente en un flujo de salida(primer parametro)
											// y tiene un delimitador opcional(2do parametro) que se pone luego de agregar un elemento

	copy(Lista_Numeros.begin(), Lista_Numeros.end(), ostream_iterator<int>(cout, "/")); //copio desde begin hasta end y lo paso al flujo de salida(out stream) Salida;
	cout << endl << endl;
	//*/




	//////////////////Busco un elemento////////////////
	//////////////////////////////////////////////////
	/*
	vector<int>::iterator i = find(Lista_Numeros.begin(), Lista_Numeros.end(), 6); //La funcion find busca un elemento y devuelve un puntero a la primer aparicion
																					//Parametros(iterador de inicio, iterador de fin, elemento a buscar)

	cout << endl;

	if (i != Lista_Numeros.end()) { //verifico que si haya encontrado el elemento, ya que el iterador no ha llegado hasta el fin
		cout << "Se encontro el elemento " << *i << " en la posicion " << getPosition(Lista_Numeros.begin(), i);
	}
	else {
		cout << "No se encontro";
	}
	//*/



	//////////////////Busco elementos que cumplan cierta condicion////////////
	/////////////////////////////////////////////////////////////////////////
	/*
	vector<int>::iterator i = Lista_Numeros.begin(); //iterador para recorrer y encontrar elementos que cumplan

	while ((i = find_if(++i, Lista_Numeros.end(), esPar<int>)) != Lista_Numeros.end()) {//find_if devuelve un puntero al elemento encontrado
																					//el primer parametro es el punto de inicio, se le pasa ++i para que continue donde se quedo pero al siguiente (+1) 
																					//el ultimo parametro es una funcion booleana que recibe el objeto apuntado por el iterador 
																							//este debe cumplir la condicion para ser seleccionado
		cout << *i << " | ";
	}

	cout << endl << endl;
	//*/


	//////////////////Ordeno los elementos de menor a mayor//////////////
	////////////////////////////////////////////////////////////////////
	/*
	sort(Lista_Numeros.begin(), Lista_Numeros.end() ); //recibe el punto de inicio y el punto de final para ordenar ese rango de menor a mayor

	Show(Lista_Numeros.begin(), Lista_Numeros.end());

	cout << endl << endl;
	//
*/



	///////////////Copio elementos de un txt al vector y luego realizar operaciones con el/////////
	//////////////////////////////////////////////////////////////////////////////////////////////
	ifstream archivo("listanumeros.txt", ios::in); //abrimos un archivo en modo lectura (input)
	vector<int> Lista_Numeros3; //creamos un vector donde guardaremos los elementos

	copy(istream_iterator<int>(archivo), istream_iterator<int>(), back_inserter(Lista_Numeros3));//copiamos desde el inicio del archivo 
		//hasta el final(cuando el iterador ya apunta a NULL), el back_inserter lo que hace es que agrega todo desde atras (back) al parametro(contenedor) que se le pasa 
		//un back-insert iterator es un tipo especial de output iterator(designado para algoritmos que sobreescriben elementos, copy)

	Show(Lista_Numeros3.begin(), Lista_Numeros3.end());
	cout << endl;
	cout << "Maximo: " << *(max_element(Lista_Numeros3.begin(), Lista_Numeros3.end())) << endl;
	cout << "Minimo: " << *(min_element(Lista_Numeros3.begin(), Lista_Numeros3.end())) << endl;
	cout << "Suma: " << accumulate(Lista_Numeros3.begin(), Lista_Numeros3.end(), 0) << endl;
	cout << "Cantidad de elementos pares: " << count_if(Lista_Numeros3.begin(), Lista_Numeros3.end(), esPar<int>) << endl;

	cout << endl << "APLICADA FUNCION TRANSFORM" << endl;
	transform(Lista_Numeros3.begin(), Lista_Numeros3.end(), ostream_iterator<int>(cout, " | "), Convertir_Par); //transforma los elementos y los guarda en un contenedor
					//La funcion unaria Convertir_Par recibe la copia del valor, lo evalua y regresa un elemento nuevo para guardarlo en el 3er parametro(contenedor)
					//Similar a la funcion copy, solo que esta usa una funcion y transforma los valores
	random_shuffle(Lista_Numeros3.begin(), Lista_Numeros3.end()); //Desordena elementos de un rango dado

	for_each(Lista_Numeros3.begin(), Lista_Numeros3.end(), Duplicar); //aplica la funcion(3er parametro) a los elementos del rango dado

	cout << endl << endl;

	Show(Lista_Numeros3.begin(), Lista_Numeros3.end());

	

	cout << endl << endl;

	_getch();
	return 0;
}