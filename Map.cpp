#include <iostream>
#include <conio.h>
#include <map>
#include <string>

using namespace std;
using namespace System;

typedef pair<int, string> par; // con esto le ponemos un alias a pair..... para usarlo

int main() {

	//////MAP/////
	/*
	map<int, string> Diccionario; //Los map permiten almacenar valores en pares, uno es la clave y el otro el elemento al que representa esa clave
			//Los va ordenando de acuerdo a la clave(primer parametro)
			//EJM
			// 1	Arthur
			// 2	Javier
			//Los datos pueden ser de cualquier tipo
	//Los map permiten solo la existencia de un elemento, en cambio los multimap permiten elementos repetidos 


	//Para insertar se debe agregar de a pares, para ello usamos la template class pair
	Diccionario.insert(pair<int, string>(1, "Arthur"));
	Diccionario.insert(par(2, "Javier")); //aca usamos el alias de pair que es par
	 
	map<int, string>::iterator i = Diccionario.begin();

	cout << "Clave: " << i->first << " | Elemento: " << i->second << endl;
	i++;
	cout << "Clave: " << i->first << " | Elemento: " << i->second << endl;

	cout << Diccionario.at(2) << endl; //Accedemos al elemento que tiene clave dos

	//Diccionario.erase(2);//Se puede pasar borrando por clave
	Diccionario.erase(i);//O pasandole un iterador

	i = Diccionario.find(2); //Devuelve un iterador que apunta al elemento que se busca, en caso no lo encuentre apunta a end

	if (i != Diccionario.end()) {
		cout << "ENCONTRADO";
	}
	else {
		cout << "NO ENCONTRADO";
	}

	//Diccionario[1] = "Valladares";	//Se puede modificar el valor de una clave mediante los corchetes, como en los arreglos
	Diccionario.insert_or_assign(1, "VNAJ");	//o mediante este metodo, que recibe la clave que se quiere modificar(1er P.) y el nuevo valor que tendra(2do P.)

	cout << endl<< Diccionario.at(1) << endl;
	//*/


	/////MULTIMAP/////
	multimap<int, string> Diccionario;

	Diccionario.insert(par(1, "Arthur"));
	Diccionario.insert(par(1, "Javier"));
	Diccionario.insert(par(2, "Valladares"));
	Diccionario.insert(par(2, "Nole"));

	multimap<int, string>::iterator i;

	int Clave = 1;

	cout << "Hay " << Diccionario.count(Clave) << " claves " << Clave << endl << endl;

	for (i = Diccionario.lower_bound(Clave); i != Diccionario.upper_bound(Clave); ++i) { //el iterador solo recorre los elementos que contenga la clave puesta como parametro en los bound
						//Upper_bound devuelve un iterador a la siguiente posicion del ultimo elementon encontrado con esa clave, funciona igual que el end()
		cout << i->second << endl;
	}

	_getch();
	return 0;
}