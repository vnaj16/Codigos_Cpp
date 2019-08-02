#include "C_Bateria.h"




C_Bateria::C_Bateria()
{
}


C_Bateria::~C_Bateria()
{
}

// Setter

void C_Bateria::setMarca(string M) {
	Marca = M;
}
void C_Bateria::setMiliamperios(int MH) {
	Miliamperios = MH;
}

//Getter 

string C_Bateria::getMarca() {
	return Marca;
}
int C_Bateria::getMiliamperios() {
	return Miliamperios;
}

//Management

void C_Bateria::Mostrar_Datos() {
	cout << endl << "		Bateria" << endl
		<< "Marca de la bateria: " << Marca << endl 
		<< "Cantidad de miliamperios: " << Miliamperios << endl;
}

void C_Bateria::Pedir_Datos() {
	cin.ignore();
	cout << "		Bateria" << endl
		<< "Ingrese la marca de la bateria: "; getline(cin, Marca);
	cout << "Ingrese la cantidad de miliamperios: "; cin >> Miliamperios;
}