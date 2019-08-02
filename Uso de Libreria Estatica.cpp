#include <iostream>
#include <conio.h>
#include <C_Movil.h>

using namespace std;

		////Pasos para agregar una static lib////
//1ro modificamos los directorios de inclusiones adicionales en C++/ General y ponemos la direccion donde estan nuestros .h
//2do modificamos los directorios de bibliotecas adicionales en Vinculador/General y ponemos la direccion donde esta el .lib
//3ro modificamos las dependencias adicionales en Vinculador/Entrada y ponemos el nombre de nuesta libreria EJM: Arthur.lib
//Con la DLL es igual, solo que el ultimo paso es incluir el archivo .dll en el directorio del proyecto actual, donde esta el .cpp

int main() {

/*	C_Movil Movil(15,10,1,1,80,25,'6',11);

	while (true)
	{
		Movil.Mover();
		_sleep(70);
	}*/

	int x;
	int *y = new int;
	char a;

	cout << "Valor de x: " <<x << "\nValor de *y: " << *y << "\nValor de a: " << a;



	_getch();
	return 0;
}