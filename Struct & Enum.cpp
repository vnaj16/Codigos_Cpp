#include <iostream>
#include <conio.h>
#include <cctype>
#include <string>


using namespace std;

enum dia {Lunes =1, Martes, Miercoles, Jueves, Viernes,Sabado,Domingo};

//Union sirve para ahorrar memoria y usar variables que no requieran almacenamiento, simplemente para usar una vez y mostrar, etc.
	//Ocupa el espacio de la variable mas grande y se va sobreescribiendo



//struct y class son iguales en mayoria, lo que las diferencia es que struct por defecto deja todo public, mientras que class deja por defecto todo en private


struct persona {
	unsigned short Edad;
	string Nombre;
	dia Dia_Favorito;

	persona(unsigned short E, string N, dia F) {
		Edad = E;
		Nombre = N;
		Dia_Favorito = F;
	}
	persona() {

	}
	~persona() {
		cout << "STRUCT DELETED";
	}

	void Mostrar_Datos() {
		cout << "		" << Nombre << endl
			<< "Edad: " << Edad << endl
			<< "Dia favorito: ";
			switch (Dia_Favorito) {
			case 1: cout << "Lunes"; break;
			case 2: cout << "Martes"; break;
			case 3: cout << "Miercoles"; break;
			case 4: cout << "Jueves"; break;
			case 5:cout << "Viernes"; break;
			case 6: cout << "Sabado"; break;
			case 7: cout << "Dominogo"; break;
			} cout << endl;
	}
};

void Pedir_Datos(persona &Individuo) {
	int i=0;
	cout << "Ingrese el nombre: "; getline(cin, Individuo.Nombre);
	cout << "Ingrese la edad: "; cin >> Individuo.Edad;
	cout << "Ingrese dia favorito: "; cin >> i;
	switch (i) {
	case 1: Individuo.Dia_Favorito = dia::Lunes; break;
	case 2: Individuo.Dia_Favorito = dia::Martes; break;
	case 3:Individuo.Dia_Favorito = dia::Miercoles; break;
	case 4: Individuo.Dia_Favorito = dia::Jueves; break;
	case 5:Individuo.Dia_Favorito = dia::Viernes; break;
	case 6: Individuo.Dia_Favorito = dia::Sabado; break;
	case 7:Individuo.Dia_Favorito = dia::Domingo; break;
	}
}

int main() {

	//persona *Individuo = new persona(19, "Arthur Valladares", dia::Sabado);
	persona *Individuo = new persona();

	Pedir_Datos(*Individuo);
	Individuo->Mostrar_Datos();

	_getch();
	return 0;
}