#include "C_Celular.h"



C_Celular::C_Celular()
{
}

C_Celular::C_Celular(string M, float P, int N, string MB, int MHB, string MC, int MGC, bool FC) {
	Marca = M;
	Precio = P;
	Numero_Serie = N;
	Bateria.setMarca(MB);
	Bateria.setMiliamperios(MHB);
	Camara.setMarca(MC);
	Camara.setMegapixeles(MGC);
	Camara.setTieneFlash(FC);
}

C_Celular::~C_Celular()
{
}


//Setter

void C_Celular::setMarca(string M) {
	Marca = M;
}
void C_Celular::setPrecio(float P) {
	Precio = P;
}
void C_Celular::setNumero_Serie(int N) {
	Numero_Serie = N;
}
void C_Celular::setBateria(C_Bateria Ba) {
	Bateria = Ba;
}
void C_Celular::setCamara(C_Camara C) {
	Camara = C;
}


//Getter

string C_Celular::getMarca() {
	return Marca;
}
float C_Celular::getPrecio() {
	return Precio;
}
int C_Celular::getNumero_Serie() {
	return Numero_Serie;
}
C_Bateria& C_Celular::getBateria() {
	return Bateria;
}
C_Camara& C_Celular::getCamara() {
	return Camara;
}

//Management

void C_Celular::Mostrar_Datos() {
	cout << "		Celular " << Marca << endl
		<< "Numero de serie: " << Numero_Serie << endl
		<< "Precio: " << Precio << endl;
	Bateria.Mostrar_Datos();
	cout << endl;
	Camara.Mostrar_Datos();
}

void C_Celular::Pedir_Datos() {
	cin.ignore();
	cout << "		Celular" << endl
		<< "Ingrese la marca del celular: "; getline(cin, Marca);
	cout << "Ingrese el numero de serie: "; cin >> Numero_Serie;
	cout << "Ingrese el precio: "; cin >> Precio;
	cout << endl;
	
	Bateria.Pedir_Datos();
	cout << endl;

	Camara.Pedir_Datos();
	cout << "CELULAR REGISTRADO";
}