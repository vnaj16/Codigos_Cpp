#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace System;

struct Pelota {
	int Posicion_X, Posicion_Y, Movimiento_X, Movimiento_Y, Color; //variables para controlar movimiento y determinar color
	char Forma;		// variable para determinar la forma

	Pelota(int p_x, int p_y, int m_x, int m_y, int color, int Forma) { //Este es un metodo constructor, me obliga a definir una variable (objeto) ni bien lo declaro
																			//Recuerda que DECLARAR es decirle al compilador que existe una variable de tipo tal con nombre tal
																			// Y que DEFINIR significa darle un valor a esa variable																				
		Posicion_X = p_x; //Inicializo o defino Posicion_X y asi con los demas
		Posicion_Y = p_y;
		Movimiento_X = m_x;
		Movimiento_Y = m_y;
		Color = color;
		this->Forma = Forma; //this-> sirve para hacer referencia a la variable local Forma y que no se confunda con el parametro Forma del constructor
	}

	void Dibujar() {
		Console::SetCursorPosition(Posicion_X, Posicion_Y); //Ubico el cursor en su pos_x y pos_y
		Console::BackgroundColor = ConsoleColor::Black; //Su fondo de la pelota sera negro
		Console::ForegroundColor = ConsoleColor(Color); //Y la pelota con su color respectivo
		cout << Forma; //dibujo la pelota
	}

	void Borrar() {
		Console::SetCursorPosition(Posicion_X, Posicion_Y);
		Console::BackgroundColor = ConsoleColor::Black;
		Console::ForegroundColor = ConsoleColor(0); //En vez de dibujar la pelota con su color, la dibujo con negro para hacer el efecto de borrado	//El cero es el color negro
		cout << Forma;
	}

	void Mover() {

		Borrar();

		if (Posicion_X + Movimiento_X < 0 || Posicion_X + Movimiento_X >= 100) {//lo que hago aqui es verificar si en el movimiento que sigue la pelota excede los limites, de ahi el pos_x + mov_x
			Movimiento_X *= -1; //Si la pelota choca con los limites de la consola le cambio su direccion (su signo)
							//Si va hacia derecha que ahora vaya hacia izquierda y viceversa
		}

		if (Posicion_Y + Movimiento_Y < 0 || Posicion_Y + Movimiento_Y >=30) {
			Movimiento_Y *= -1;
		}


		Posicion_X += Movimiento_X; //Actualizo las nuevas posiciones
		Posicion_Y += Movimiento_Y;


		Dibujar();

		//NOTA
			//Esta funcion primero borra, evalua y modifica posiciones y luego dibuja en posiciones nuevas

	}

};

struct Barra {
	int Posicion_X, Posicion_Y, Movimiento_X, Movimiento_Y, Color, Largo = 3; 
	char Forma;		

	Barra(int p_x, int p_y, int m_x, int m_y, int color, int Forma) { 																			
		Posicion_X = p_x;
		Posicion_Y = p_y;
		Movimiento_X = m_x;
		Movimiento_Y = m_y;
		Color = color;
		this->Forma = Forma; 
	}

	void Dibujar() {
		Console::BackgroundColor = ConsoleColor::Black;
		Console::ForegroundColor = ConsoleColor(Color);

		for (int i = 0; i < Largo; i++) { //Uso este bucle para dibujar la barra de manera vertical, cambio la pos_Y para generar ese efecto
			Console::SetCursorPosition(Posicion_X, Posicion_Y + i);
			cout << char(Forma);
		}
	}

	void Borrar() {
		Console::BackgroundColor = ConsoleColor::Black;
		Console::ForegroundColor = ConsoleColor(0);

		for (int i = 0; i < Largo; i++) { //Uso este bucle para dibujar la barra de manera vertical, cambio la pos_Y para generar ese efecto
			Console::SetCursorPosition(Posicion_X, Posicion_Y + i);
			cout << char(Forma);
		}
	}

	void Mover() {

		Borrar();

		if (Posicion_Y + Movimiento_Y < 0 || Posicion_Y + Movimiento_Y >=30) { //Movimiento solo vertical
			Movimiento_Y *= -1;
		}


		Posicion_X += Movimiento_X; //Actualizo las nuevas posiciones
		Posicion_Y += Movimiento_Y;


		Dibujar();

		//NOTA
			//Esta funcion primero borra, evalua y modifica posiciones y luego dibuja en posiciones nuevas

	}

};

void Detectar_Colision(Pelota &Pelota1, Barra &Barra1, Barra &Barra2) {


	//Primero compruebo que este en el mismo eje X para luego comparar su eje Y
	if (Pelota1.Posicion_X == Barra1.Posicion_X && (Pelota1.Posicion_Y == Barra1.Posicion_Y //Aca verifico si esta en el mismo eje Y		//Para el primer bloque
		|| Pelota1.Posicion_Y == Barra1.Posicion_Y + 1  //Aca si esta en el mismo eje Y pero + 1								//Para el segundo bloque
		|| Pelota1.Posicion_Y == Barra1.Posicion_Y + 2)) { //Aca si esta en el mismo eje Y pero + 2							//Para el 3er bloque	
																								//Recuerda que tiene de largo 3, por eso, hay tres bloques

		Pelota1.Movimiento_X *= -1;
		Pelota1.Movimiento_Y *= -1; //Si hay contacto, cambio de direccion la pelota
	}

	//Este es para la barra 2
	
	if (Pelota1.Posicion_X == Barra2.Posicion_X && (Pelota1.Posicion_Y == Barra2.Posicion_Y 
		|| Pelota1.Posicion_Y == Barra2.Posicion_Y + 1						
		|| Pelota1.Posicion_Y == Barra2.Posicion_Y + 2)) { 
																						
		Pelota1.Movimiento_X *= -1;
		Pelota1.Movimiento_Y *= -1;
	}

	//NOTA
		//Para un mejor efecto de colision, se debe comprobar la posicion + movimiento al igual como el choque con los limites
		//Como solo se compara en la posicion, no es una colision en si, ya que si la pelota esta en el eje x con un valor de 5 y la barra tambien en 5, se ejecuta pero 
		//la pelota ya se dibujo en la posicion x igual a 5
		//En cambio si se hace posicion + movimiento , siguiendo el ejemplo... ahora la pelota en el eje x tiene un valor de 4 y un movimiento en x de 1 y la barra en eje x con
		// valor 5, la pelota se dibujar en eje x igual a 4 pero se evalua si en la posicion 5 (pos_x = 4 + mov_x =1 -> 4 +1) choca con la barra, y si se cumple la igualdad
		//La pelota no entra en la posicion 5, sino mas bien cambio de direccion debido al 'choque'

}


int main() {
	srand(time(0));

	Pelota Pelota1(rand() % 100, rand() % 30, 1, 1, 12, '*');
	Barra Barra1(5, 0, 0, rand() % 2 + 1, 15, 219), Barra2(95, 0, 0, rand() % 2 + 1, 15, 219); //Para que veas mejor la colision, establece una posicion Y diferente de 0 y mov_y =0

	while (true) {

		Detectar_Colision(Pelota1, Barra1, Barra2);

		Pelota1.Mover();
		Barra1.Mover();
		Barra2.Mover();
		_sleep(80);
	}

	cin.get();
	return 0;
}