#pragma once

using namespace System::Drawing;
class C_Bomba
{
private:
	int Posicion_X=80, Posicion_Y=0, Posicion_Final_Y=100, Movimiento_Y=5, Ancho=32, Alto=64, Indice=0;
	bool Exploto = false;
public:
	C_Bomba();
	~C_Bomba();

	void Definir(int x, int y, int fy, int my);

	void setPosicion_X(int X);
	void setPosicion_Y(int Y);
	void setPosicion_Final_Y(int Y);
	void setMovimiento_Y(int MY);
	void setExploto(bool E);

	int getPosicion_X();
	int getPosicion_Y();
	int getPosicion_Final_Y();
	int getMovimiento_Y();
	bool getExploto();

	void Dibujar(BufferedGraphics ^Buffer, Bitmap ^bmpBomba);
	void Mover(BufferedGraphics ^Buffer, Bitmap ^bmpBomba);
};

