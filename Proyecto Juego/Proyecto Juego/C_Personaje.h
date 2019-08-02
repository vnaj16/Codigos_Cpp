#pragma once

enum Direcciones { Izquierda, Derecha, Arriba, Abajo, Ninguna };

using namespace System::Drawing;

class C_Personaje
{
private:
	int Vidas,Posicion_X, Posicion_Y, Movimiento_Y, Movimiento_X, Velocidad,Indice_X = 0, Indice_Y = 0, Ancho = 36, Alto = 72;
	bool Modo_Lento = false;
public:

	Direcciones Tecla_Presionada = Ninguna;
	Direcciones Tecla_Ultima = Abajo;

	void Definir(int X, int Y, int MY, int MX, int Vidas, int V);
	void setVidas(int Vidas);
	void setMovimiento_X(int X);
	void setMovimiento_Y(int Y);
	void setVelocidad(int V);
	void setPosicion_X(int X);
	void setPosicion_Y(int Y);
	void setModo_Lento(bool C);

	int getVidas();
	int getPosicion_X();
	int getPosicion_Y();
	int getVelocidad();
	int getAncho();
	int getAlto();
	bool getModo_Lento();



	C_Personaje();
	~C_Personaje();

	void Dibujar(BufferedGraphics ^Buffer, Bitmap ^bmpPersonaje, Bitmap ^bmpPersonajeX);
	void Mover(BufferedGraphics ^Buffer, Bitmap ^bmpPersonaje, Bitmap ^bmpPersonajeX);
	void Modo_CLenta();
};

