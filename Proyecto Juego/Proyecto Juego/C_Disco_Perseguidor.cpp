#include "C_Disco_Perseguidor.h"



C_Disco_Perseguidor::C_Disco_Perseguidor()
{
}


C_Disco_Perseguidor::~C_Disco_Perseguidor()
{
}

void C_Disco_Perseguidor::setPosicion_Final_X(int X) {
	Posicion_Final_X = X;
}
void C_Disco_Perseguidor::setPosicion_Final_Y(int Y) {
	Posicion_Final_Y = Y;
}


void C_Disco_Perseguidor::Determinar_Movimiento() {
	if (Posicion_X < Posicion_Final_X) {
		Movimiento_X *= 1;
	}
	else {
		Movimiento_X *= -1;
	}

	if (Posicion_Y < Posicion_Final_Y) {
		Movimiento_Y *= 1;
	}
	else {
		Movimiento_Y *= -1;
	}
}

void C_Disco_Perseguidor::Perseguir(BufferedGraphics ^Buffer, Bitmap ^bmpDisco, Bitmap ^bmpDiscoX) {

	
	if (Posicion_X == Posicion_Final_X && Posicion_Y == Posicion_Final_Y) {
		Persiguiendo = false;
	}

	if (IndiceX < 3) {
		IndiceX += 1;
	}
	else {
		IndiceX = 0;
	}


	Posicion_X += Modo_Lento ? Movimiento_XL : Movimiento_X;
	Posicion_Y += Modo_Lento ? Movimiento_YL : Movimiento_Y;

	Dibujar(Buffer, bmpDisco, bmpDiscoX);

}
