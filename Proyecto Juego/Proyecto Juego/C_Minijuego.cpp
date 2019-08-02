#include "C_Minijuego.h"

using namespace System;

C_Minijuego::C_Minijuego()
{
	Random r;
	Cantidad_Bombas = r.Next(5, 50);
	Bomba = new C_Bomba[Cantidad_Bombas];

}


C_Minijuego::~C_Minijuego()
{
}



int C_Minijuego::getCantidad_Bombas(){
	return Cantidad_Bombas;
}

C_Bomba* C_Minijuego::getBomba() {
	return Bomba;
}


void C_Minijuego::Definir(BufferedGraphics ^Buffer) {
	Random r;
	for (int i = 0; i < Cantidad_Bombas; i++) {
		Bomba[i].Definir(r.Next(Buffer->Graphics->VisibleClipBounds.Width-32), 0, r.Next(Buffer->Graphics->VisibleClipBounds.Height - 64), r.Next(8, 14));
	}
}

void C_Minijuego::Mover_Elementos(BufferedGraphics ^Buffer, Bitmap ^bmpBomba, int i) {

		Bomba[i].Mover(Buffer, bmpBomba);
}