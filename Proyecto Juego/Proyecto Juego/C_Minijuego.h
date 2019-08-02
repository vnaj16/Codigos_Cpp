#pragma once
#include "C_Bomba.h"
using namespace System::Drawing;

class C_Minijuego
{
private:
	C_Bomba *Bomba;
	int Cantidad_Bombas;

public:
	C_Minijuego();
	~C_Minijuego();

	int getCantidad_Bombas();
	C_Bomba *getBomba();

	void Definir(BufferedGraphics ^Buffer);
	void Mover_Elementos(BufferedGraphics ^Buffer, Bitmap ^bmpBomba, int i);


};

