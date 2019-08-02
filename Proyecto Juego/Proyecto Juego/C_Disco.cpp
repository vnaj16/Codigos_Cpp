#include "C_Disco.h"



C_Disco::C_Disco()
{
}


C_Disco::~C_Disco()
{
}


void C_Disco::Definir(int X, int Y, int MX, int MY, int Size) {
	Posicion_X = X;
	Posicion_Y = Y;
	Movimiento_X = MX;
	Movimiento_Y = MY;
	this->Size = Size;
}

////////SETTERS///////////
void C_Disco::setMovimiento_X(int X) {
	Movimiento_X = X;
}

void C_Disco::setMovimiento_Y(int Y) {
	Movimiento_Y = Y;
}

void C_Disco::setSize(int S) {
	Size = S;
}
void C_Disco::setModo_Lento(bool M) {
	Modo_Lento = M;
}


////////GETTERS///////////
int C_Disco::getPosicion_X() {
	return Posicion_X;
}

int C_Disco::getPosicion_Y() {
	return Posicion_Y;
}

int C_Disco::getSize() {
	return Size;
}
bool C_Disco::getModo_Lento() {
	return Modo_Lento;
}







void C_Disco::Definir(int x, int y, int mx, int my) {
	Posicion_X = x;
	Posicion_Y = y;
	Movimiento_X = mx;
	Movimiento_Y = my;
	Movimiento_XL = Movimiento_X / 2;
	Movimiento_YL = Movimiento_Y / 2;
}


void C_Disco::Dibujar(BufferedGraphics ^Buffer, Bitmap ^bmpDisco, Bitmap ^bmpDiscoX){
	Rectangle Area_Usar = Rectangle(Ancho*IndiceX, Alto*IndiceY, Ancho, Alto);
	Rectangle Area_Dibujar = Rectangle(Posicion_X, Posicion_Y, Size, Size);

	if(Modo_Lento){ Buffer->Graphics->DrawImage(bmpDiscoX, Area_Dibujar, Area_Usar, GraphicsUnit::Pixel); }
	else { Buffer->Graphics->DrawImage(bmpDisco, Area_Dibujar, Area_Usar, GraphicsUnit::Pixel); }
}


void C_Disco::Mover(BufferedGraphics ^Buffer, Bitmap ^bmpDisco, Bitmap ^bmpDiscoX) {
	

	if (Posicion_X<0 || Posicion_X + Size>Buffer->Graphics->VisibleClipBounds.Width) {
		Movimiento_XL *= -1;
		Movimiento_X *= -1;
	}
	if (Posicion_Y<0 || Posicion_Y + Size>Buffer->Graphics->VisibleClipBounds.Height-50) {
		Movimiento_YL *= -1;
		Movimiento_Y *= -1;
	}

	if (IndiceX < 3) {
			IndiceX += 1;
		}
	else{
		 IndiceX = 0;
		}


	Posicion_X += Modo_Lento? Movimiento_XL:Movimiento_X;
	Posicion_Y += Modo_Lento ? Movimiento_YL : Movimiento_Y;

	Dibujar(Buffer, bmpDisco, bmpDiscoX);

}
