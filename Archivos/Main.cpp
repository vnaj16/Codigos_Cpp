#include <iostream>
#include <conio.h>
#include <fstream> //Libreria para manejo de archivos (files)
#include <string>


using namespace std;

string Nombre_Archivo;

struct persona {
	char Nombre[20];
	int Edad;
};

void Escribir_Archivo();
void Leer_Archivo();
void Agregar_Archivo();
void Escribir_Archivo_Bin();
void Leer_Archivo_Bin();

int main() {

	//////Para manejar archivos.txt
	/*
	Escribir_Archivo();

	_getch();

	Leer_Archivo();

	_getch();

	Agregar_Archivo();*/




	//////Para manejar archivos binarios.dat
	Escribir_Archivo_Bin();

	_getch();

	Leer_Archivo_Bin();

	_getch();

	_getch();
	return 0;
}


void Escribir_Archivo() {
	ofstream Archivo; //Objeto de tipo output para manejar los archivos en modo escritura
	

	cout << "Nombre: "; getline(cin, Nombre_Archivo);

	Nombre_Archivo += ".txt"; //Agregar extension

			//Abrir archivo en modo ios::out (output)
	//Archivo.open("C://Arthur//Programacion//Texto.txt", ios::out); //Creado en la ubicacion dada
	//Archivo.open("Texto.txt", ios::out); //Creado en la ubicacion del .cpp
	Archivo.open(Nombre_Archivo, ios::out); //Creado en la ubicacion del .cpp

	//Verificar que no haya habido fallos
	if (Archivo.fail()) { 
		cout << "No se pudo abrir el archivo";
		exit(1);
	}
	else {
		cout << "Archivo creado" << endl;
	}

	cout << "Posicion actual: " << Archivo.tellp()<<endl; //Obtener la posicion actual del cursor

	Archivo.seekp(8); //Ubicar el cursor en la posicion 10

	Archivo << "Arthur Valladares" << endl; //Escribiendo (mandando datos) al archivo
	Archivo << "Edad: 19" << endl;


	Archivo.close(); // Cerrar archivo
}

void Leer_Archivo() {
	ifstream Archivo; //Objeto de tipo input para manejar los archivos en modo lectura

	string Texto = "", Aux="";

	Archivo.open(Nombre_Archivo, ios::in);  //Leido en la ubicacion del .cpp

	//Verificar que no haya habido fallos
	if (Archivo.fail()) {
		cout << "No se pudo abrir el archivo";
		exit(1);
	}
	else {
		cout << "Archivo leido";
		_getch();
	}

	cout << "Posicion actual: " << Archivo.tellg() << endl; //Obtener la posicion actual del cursor

	Archivo.seekg(10); //Ubicar el cursor en la posicion 10


	while (!Archivo.eof()) { //Mientras no sea el final del archivo
		getline(Archivo, Aux);
		Texto += Aux;
		Texto += "\n";
	}

	cout << endl << endl <<Texto;

	Archivo.close();
}

void Agregar_Archivo() {

	ofstream Archivo;

	Archivo.open(Nombre_Archivo, ios::app); //Archivo abierto en modo Append

	if (Archivo.fail()) {
		cout << "No se pudo abrir el archivo";
		exit(1);
	}
	else {
		cout << "Archivo abierto";
		_getch();
	}
	

	Archivo << "Telefono: 952539737" << endl;


	Archivo.close();

}

void Escribir_Archivo_Bin() {
	ofstream Archivo; //Objeto de tipo output para manejar los archivos en modo escritura

	persona Persona;

	cout << "Nombre: "; getline(cin, Nombre_Archivo);

	Nombre_Archivo += ".dat"; //Agregar extension

			//Abrir archivo en modo ios::out (output) | ios::binary
	Archivo.open(Nombre_Archivo, ios::out | ios::binary); //Creado en la ubicacion del .cpp

	//Verificar que no haya habido fallos
	if (Archivo.fail()) {
		cout << "No se pudo abrir el archivo";
		exit(1);
	}
	else {
		cout << "Archivo creado" << endl;
	}

	fflush(stdin); //Limpiar buffer
	cout << endl << "Ingrese el nombre: ";
	cin.getline(Persona.Nombre, 20, '\n');
	cout << "Ingrese la edad: "; cin >> Persona.Edad;

	
	Archivo.write((char *)&Persona, sizeof(persona)); //Para escribir al archivo

	Archivo.close(); // Cerrar archivo
}

void Leer_Archivo_Bin() {
	ifstream Archivo; //Objeto de tipo input para manejar los archivos en modo lectura

	persona Persona;

	Archivo.open(Nombre_Archivo, ios::in | ios::binary);  //Leido en la ubicacion del .cpp

	//Verificar que no haya habido fallos
	if (Archivo.fail()) {
		cout << "No se pudo abrir el archivo";
		exit(1);
	}
	else {
		cout << "Archivo leido";
		_getch();
	}

	Archivo.read((char *)&Persona, sizeof(Persona));

	cout << endl << "Nombre: " << Persona.Nombre << endl;
	cout << "Edad: " << Persona.Edad << endl;

	Archivo.close();
}