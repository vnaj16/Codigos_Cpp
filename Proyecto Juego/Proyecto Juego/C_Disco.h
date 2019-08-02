#pragma once

using namespace System::Drawing;

class C_Disco
{
protected:
	int Posicion_X, Posicion_Y, Movimiento_X, Movimiento_Y, Movimiento_XL, Movimiento_YL, IndiceX = 0, IndiceY=0, Ancho = 154, Alto = 156, Size = 32;
	bool Modo_Lento = false;

public:
	C_Disco();
	~C_Disco();



	void Definir(int X, int Y, int MX, int MY, int Size);
	void setMovimiento_X(int X);
	void setMovimiento_Y(int Y);
	void setSize(int S);
	void setModo_Lento(bool M);


	int getPosicion_X();
	int getPosicion_Y();
	int getSize();
	bool getModo_Lento();


	void Definir(int x, int y, int mx, int my);
	void Dibujar(BufferedGraphics ^Buffer, Bitmap ^bmpDisco, Bitmap ^bmpDiscoX);
	void Mover(BufferedGraphics ^Buffer, Bitmap ^bmpDisco, Bitmap ^bmpDiscoX);
};

