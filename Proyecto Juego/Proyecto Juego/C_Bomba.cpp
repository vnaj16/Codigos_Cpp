#include "C_Bomba.h"



C_Bomba::C_Bomba()
{
}


C_Bomba::~C_Bomba()
{
}

void C_Bomba::Definir(int x, int y, int fy, int my) {
	Posicion_X = x;
	Posicion_Y = y;
	Posicion_Final_Y = fy;
	Movimiento_Y = my;
}

void C_Bomba::setPosicion_X(int X)
{
	Posicion_X = X;
}
void C_Bomba::setPosicion_Y(int Y) {
	Posicion_Y = Y;
}
void C_Bomba::setPosicion_Final_Y(int Y) {
	Posicion_Final_Y = Y;
}
void C_Bomba::setMovimiento_Y(int MY) {
	Movimiento_Y = MY;
}
void C_Bomba::setExploto(bool E) {
	Exploto = E;
}

int C_Bomba::getPosicion_X() {
	return Posicion_X;
}
int C_Bomba::getPosicion_Y() {
	return Posicion_Y;
}
int C_Bomba::getPosicion_Final_Y() {
	return Posicion_Final_Y;
}
int C_Bomba::getMovimiento_Y() {
	return Movimiento_Y;
}
bool C_Bomba::getExploto() {
	return Exploto;
}

void C_Bomba::Dibujar(BufferedGraphics ^Buffer, Bitmap ^bmpBomba) {
	Rectangle Area_Usar = Rectangle(Indice*Ancho, 0, Ancho, Alto);
	Rectangle Area_Dibujar =  Rectangle(Posicion_X, Posicion_Y, Ancho, Alto);

	Buffer->Graphics->DrawImage(bmpBomba, Area_Dibujar, Area_Usar, GraphicsUnit::Pixel);
}
void C_Bomba::Mover(BufferedGraphics ^Buffer, Bitmap ^bmpBomba) {

	if (Posicion_Y <= Posicion_Final_Y) {
		if (Indice < 2) {
			Indice += 1;
		}
		else {
			Indice = 0;
		}

		Posicion_Y += Movimiento_Y;
	}
	else {
		if (Indice < 13) {
			Indice += 1;
		}
		else {
			Exploto = true;
		}

	}

	Dibujar(Buffer, bmpBomba);

}
