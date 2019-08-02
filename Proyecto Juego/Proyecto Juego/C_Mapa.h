#pragma once

using namespace System::Drawing;

class C_Mapa
{
private:
	int Nivel=0, Ancho=274, Alto=222;
public:
	C_Mapa();
	~C_Mapa();

	void setNivel(int N);
	void setAncho(int W);
	void setAlto(int H);

	int getNivel();
	int getAncho();
	int getAlto();

	void Dibujar(BufferedGraphics ^Buffer, Bitmap ^bmpMapa);
};

