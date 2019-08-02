#include <iostream>
#include <conio.h>
#include "C_Persona.h"
#include "C_Birthday.h"

using namespace std;

void Saludar_A(const C_Persona &P1){
	//Pasandolo por referencia, paso el objeto en si, mas no una copia. Con eso me evito llamar al constructor de copia
	// y destruir el objeto copia cuando sale de la funcion
	//Solo se destruye el objeto cuando acaba el programa o llamo al destructor
				//

	cout << "Hola " << P1.Nombre << ", mucho gusto en conocerte" << endl;
	//P1.Edad = 16; //Con el const me aseguro que no haya modificaciones accidentales
	_getch();
}

int main() {

	C_Birthday Birthday(16, 10, 1999);

	//C_Persona *P1 = new C_Persona[2];
	//C_Persona P2[2];
	C_Persona Persona("Arthur", 19, Birthday, 1.86); //Forma de funcion
	C_Persona Persona1 = "Arthur"; //Asignacion de inicio
	C_Persona Persona1 {"Graciela"}; //inicializacion uniforme
	C_Persona Persona1 = { "Graciela" }; //POD - like

	Persona.Mostrar_Datos();

	

	/*(P1 + 1)->setNombre("Arthur"); //Aritmetica de punteros
	P1[1].setEdad(19); //Correspondencia entre punteros y arreglos
	(*(P1 + 1)).setAltura(1.86); //desreferencia 

	(P1 + 1)->Mostrar_Datos();
	//*/


	/*
	P2[0].setNombre("Javier"); //Arreglos
	P2->setAltura(1.86); //Correspondencia entre punteros y arreglos, PUNTERO AL PRIMER MIEMBRO
	(*P2).setEdad(19); //Correspondencia entre punteros y arreglos, PUNTERO AL PRIMER MIEMBRO

	P2->Mostrar_Datos();
	//*/



	//Saludar_A(Persona);  //Comprobacion de llamada a funcion amiga

	/*
	//Comprobacion a llamada de funcion estatica

	C_Persona::Mostrar_Cantidad(); 
	//Persona.Mostrar_Cantidad();
	//*/

	//delete[] P1;
	//P1 = 0; 

	_getch();
	return 0;
}