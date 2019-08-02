#include <iostream>
#include <conio.h>
#include <vector>
#include <string.h>
#include <string>

using namespace std;
using namespace System;

struct persona {

	string Nombre;
	int Edad;

};

int main() {

	int *p1=0, *p2=0;
	int p3=6, p4 = 5;

	vector<int*> P1 = { p1,p2};
	vector<int> P2 = { p3,p4 };
	vector<int> *P3 = new vector<int>;

	vector<persona> *Persona = new vector<persona>;

	vector<string> Cadena(10, "Hi");
	vector<string> Cadena1{ 10, "Hi" };

	vector<vector<int>> H;

	/*cout << "Tamanio de vector<int*> : " << sizeof(vector<int*>)<<endl;
	cout << "Tamanio de vector<int> * : " << sizeof(vector<int> *) << endl;
	
	for (int i = 0; i < 10; i++) {
		P3->push_back(i);
	}
	cout << endl << endl;
	
	for (auto i : *P3) {
		cout << i << endl;
	}

	P2.push_back(5);*/

	persona J = { "Hola",5 };

	Persona->push_back(J);

	for (auto i = Persona->begin(); i != Persona->end(); i++) {
		cout << (*i).Edad << endl << (*i).Nombre;
	}



	_getch();
	return 0;
}