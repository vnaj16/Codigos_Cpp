/*


#include <iostream>
#include <conio.h>

using namespace std;
using namespace System;

int Menu() {
	int Opcion;
	Console::SetCursorPosition(40, 2);
	cout << "MENU";
	Console::SetCursorPosition(20, 6);
	cout << "1. Agregar Persona";
	Console::SetCursorPosition(20, 8);
	cout << "2. Eliminar Persona";
	Console::SetCursorPosition(20, 10);
	cout << "3. Modificar Persona";
	Console::SetCursorPosition(20, 12);
	cout << "4. Mostrar Personas";
	Console::SetCursorPosition(20, 14);
	cout << "5. Mostrar Menor y Mayor Persona";
	Console::SetCursorPosition(20, 16);
	cout << "6. Mostrar Edad Repetida";
	Console::SetCursorPosition(20, 18);
	cout << "7. Salir";
	do {
		Console::SetCursorPosition(30, 20);
		cout << "Opcion: "; cin >> Opcion;
	} while (Opcion < 0 || Opcion>7);
	Console::Clear();
	return Opcion;

}

int* Agregar_Persona(int *Edad, int *Persona) {
	int *Aux = new int[*Persona + 1];
	for (int i = 0; i < *Persona; i++) {
		Aux[i] = Edad[i];
	}
	int edad;
	cout << "Ingrese la edad de la nueva persona: "; cin >> edad;
	Aux[*Persona] = edad;

	delete Edad;

	*Persona += 1;

	return Aux;

}

int* Eliminar_Persona(int *Edad, int *Persona) {
	if (*Persona == 0) {
		cout << "NO HAY PERSONA PARA ELIMINAR";
		return Edad;
	}
	else if (*Persona == 1) {
		cout << "La persona ha sido eliminada";
		delete Edad;
		*Persona = 0;
		return NULL;
	}
	else {
		int Posicion;
		do {
			cout << "Ingrese la posicion de la persona que desea eliminar (0 , " << *Persona << ">" << endl;
			cout << "Posicion: "; cin >> Posicion;
		} while (Posicion < 0 || Posicion >*Persona - 1);
		int *Aux = new int[*Persona - 1];
		for (int i = 0; i < Posicion; i++) {
			Aux[i] = Edad[i];
		}
		for (int i = Posicion; i < *Persona - 1; i++) {
			Aux[i] = Edad[i + 1];
		}
		*Persona -= 1;
		cout << "PERSONA ELIMINADA CON EXITO";
		return Aux;
		
		
	}
}

void Modificar_Persona(int *Edad, int *Persona) {
	if (*Persona == 0) {
		cout << "NO HAY PERSONA PARA MODIFICAR";
	}
	else if (*Persona == 1) {
		int Age;
		cout << "Ingrese la nueva edad de la persona: "; cin >> Age;
		Edad[0] = Age;
		cout << "La persona ha sido modificada";
		
	}
	else {
		int Posicion;
		do {
			cout << "Ingrese la posicion de la persona que desea modificar (0 , " << *Persona << ">" << endl;
			cout << "Posicion: "; cin >> Posicion;
		} while (Posicion < 0 || Posicion >*Persona - 1);
		int Age;
		Console::Clear();
		cout << "Ingrese la nueva edad de la persona: "; cin >> Age;
		Edad[Posicion] = Age;
		cout << "PERSONA MODIFICADA CON EXITO";
	}
}

void Mostrar_Datos(int *Edad, int *Persona) {
	Console::Clear();
	cout << "\PERSONAS" << endl<<endl;
	for (int i = 0; i < *Persona; i++) {
		cout << "Persona " << i + 1 << endl;
		cout << "  Edad: " << Edad[i]<<endl<<endl;
	}
	system("pause");
	
}


void Mayor_Menor_Persona(int *Edad, int *Persona) {
	if (*Persona != 0) {
		int Mayor = 0, Menor = Edad[0];

		for (int i = 0; i < *Persona; i++) {
			if (Edad[i] > Mayor) {
				Mayor = Edad[i];
			}
			if (Edad[i] < Menor) {
				Menor = Edad[i];
			}
		}
		cout << "MAYOR EDAD: " << Mayor << endl;
		cout << "MENOR EDAD: " << Menor << endl;
	}
}

void Mostrar_Edad_Repetida(int *Edad, int *Persona) {
	int *Aux = Edad;
	for (int i = 0; i < *Persona; i++) {
		for (int j = i + 1; j < *Persona; j++) {
			if (Aux[i] > Aux[j]) {
				int aux = Aux[i];
				Aux[i] = Aux[j];
				Aux[j] = aux;
			}
		}

	}
	


	int Mayor_Cantidad=1, Cantidad=1;
	for (int i = 0; i < *Persona; i++) {
		for (int j = i + 1; j < *Persona; j++) {
			if (Aux[i] == Aux[j]) {
				Cantidad += 1;
			}
			else {
				break;
			}
		}
		if (Cantidad > Mayor_Cantidad) {
			Mayor_Cantidad = Cantidad;
		}
		Cantidad = 1;
	}

	Cantidad = 1;

	cout << "EDAD REPETIDA"<<endl;

	for (int i = 0; i < *Persona; i++) {
		for (int j = i + 1; j < *Persona; j++) {
			if (Aux[i] == Aux[j]) {
				Cantidad += 1;
			}
			else {
				break;
			}
		}
		if (Cantidad == Mayor_Cantidad) {
			cout << endl << " Edad: " << Aux[i] << endl;
		}
		Cantidad = 1;
	}


}

int main() {

	//new (nothrow) type
			//esto devuelve NULL

	int *Edad;
	int *Personas=new int(0);
	bool Salir = false;

	do {
		switch (Menu()) {
		case 1: 
			Edad= Agregar_Persona(Edad, Personas);
			cout << "PERSONA AGREGADA CON EXITO";
			_sleep(1000);
			Console::Clear();
			break;
		case 2: 
			Edad= Eliminar_Persona(Edad, Personas);
			_sleep(1000);
			Console::Clear();
			break;
		case 3: 
			Modificar_Persona(Edad, Personas);
			_sleep(1000);
			Console::Clear();
			break;
		case 4:
			Mostrar_Datos(Edad, Personas);
			Console::Clear();
			break;
		case 5: 
			Mayor_Menor_Persona(Edad, Personas);
			_sleep(3000);
			Console::Clear();
			break;
		case 6: 
			
			Mostrar_Edad_Repetida(Edad, Personas);
			_sleep(3000);
			Console::Clear();
			break;
		case 7: 
			Salir = true;
			break;
		}
	} while (!Salir);
	

	_getch();
	return 0;
}


*/