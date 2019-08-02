#include "C_Camara.h"



C_Camara::C_Camara()
{
}


C_Camara::~C_Camara()
{
}


//setter

void C_Camara::setMegapixeles(int MP) {
	Megapixeles = MP;
}
void C_Camara::setMarca(string M) {
	Marca = M;
}
void C_Camara::setTieneFlash(bool F) {
	tieneFlash = F;
}

//Getter

int C_Camara::getMegapixeles() {
	return Megapixeles;
}
string C_Camara::getMarca() {
	return Marca;
}
bool C_Camara::getTieneFlash() {
	return tieneFlash;
}

//Management

void C_Camara::Mostrar_Datos() {
	cout << "		Camara" <<
		endl << "Marca de la camara: " << Marca << endl
		<< "Numero de megapixeles: " << Megapixeles << endl
		<< (tieneFlash ? "Si " : "No ") << "tiene flash" << endl;
}

void C_Camara::Pedir_Datos() {
	cin.ignore();
	string respuesta;
	cout << "		Camara" << endl
		<< "Ingrese la marca de la camara: "; getline(cin, Marca);
	cout << "Ingrese el numero de megapixeles: "; cin >> Megapixeles;
	cout << "Tiene flash(si/no)?: "; cin >> respuesta;
	if (respuesta == "si") {
		tieneFlash = true;
	}
	else {
		tieneFlash = false;
	}
}