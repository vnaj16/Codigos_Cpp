#include <iostream>
#include <conio.h>
#include <set>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {

	set<int> Conjunto;
	//multiset<int> MultiConjunto; // puedo insertar valores repetidos
		//MultiConjunto.count(element) //Sirve para contar cuantas veces hay cierto elemento, en el set es inservible porque siempre habra solo una vez cierto elemento

	Conjunto.insert(8);
	Conjunto.insert(5);
	Conjunto.insert(7);
	Conjunto.insert(6); //A medida que voy ingresando un elemento, este se va ordenando (comprobar con la salida por consola)
	Conjunto.insert(5); //Agregar valores repetidos no se puede, solamente lo ignora
		//Esto se debe a que el set no acepta valores repetidos, en cambio el multiset si permite tener elementos iguales

	copy(Conjunto.begin(), Conjunto.end(), ostream_iterator<int>(cout, " | "));
	cout << endl;

	set<int>::iterator i = find(Conjunto.begin(), Conjunto.end(), 5);//Busqueda de un elemento
	//set<int>::iterator i = Conjunto.find(5); //Metodo de busqueda perteneciente a set
	if (i != Conjunto.end()) {
		cout << "SI SE ENCONTRO " << *i;
	}
	else {
		cout << "NO SE ENCONTRO";
	}

	cout << endl << endl;

	//Conjunto.erase(7); //para borrar un elemento(parametro)
	Conjunto.erase(i); // para borrar el elemento apuntado por el iterador
		//En multiset te borra todos los elementos repetidos
	copy(Conjunto.begin(), Conjunto.end(), ostream_iterator<int>(cout, " | "));
	cout << endl;

	_getch();
	return 0;
}