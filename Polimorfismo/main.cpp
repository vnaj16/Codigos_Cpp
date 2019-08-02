#include <iostream>
#include <conio.h>
#include "C_Triangulo.h"
#include "C_Cuadrado.h"

using namespace std;

//Clase poligono (Perimetro,Area) //Clase cuadrilatero //Clase triangulo



//Esta funcion pinta cualquier tipo de poligono, gracias a la herencia y polimorfismo me evito de estar 
// creando una funcion para cada tipo de poligono, con plantillas es imposible (creo hasta el momento 24/01/19)
void Pintar(C_Poligono *Poligono){
	Poligono->Pintar();
}

int main() {

	C_Triangulo *Triangulo1 = new C_Triangulo(3, 3, 4, 5);
	C_Cuadrado *Cuadrado1 = new C_Cuadrado(4);
	C_Poligono *Poligono = Cuadrado1; //Se hace esto por eficiencia

	/*
	Pintar(Poligono);

	delete Poligono;
	Poligono = Triangulo1;
	Pintar(Poligono);
	//*/





	///*
	cout << Poligono->ToString();
	_getch();

	cout << endl << endl;
	
	//delete Cuadrado1; //Con esto borro todo el cuadrado a que apuntaba poligono, por lo cual ya no es necesario borra poligono, solo hacerle otra asignacion

	delete Poligono; //No apunta a cuadrado, apunta a la seccion poligono del cuadrado, no a todo el cuadrado
					//Por lo cual libera el puntero poligono pero no elimina al 100% el cuadrado, solo su parte poligono
					//Haciendo el destructor virtual nos aseguramos de que se borre totalmente el objeto al que apunta
					//(Verificar cuando se llaman a los constructores)
	

	//cout <<Cuadrado1->Hallar_Perimetro(); //No se puede acceder ya que ya se borro la parte poligono del cuadrado

	//Poligono = Triangulo1;


	//cout << Poligono->ToString();
	//*/
	delete Poligono;

	_getch();
	_getch();
	return 0;
}