#pragma once
#include "C_Disco.h"

using namespace System::Drawing;
class C_Disco_Perseguidor: public C_Disco
{
private:
	int Posicion_Final_X,  Posicion_Final_Y;
	bool Persiguiendo = true;
public:
	C_Disco_Perseguidor();
	~C_Disco_Perseguidor();

	void setPosicion_Final_X(int X);
	void setPosicion_Final_Y(int Y);

	void Determinar_Movimiento();
	void Perseguir(BufferedGraphics ^Buffer, Bitmap ^bmpDisco, Bitmap ^bmpDiscoX);
};

