#include "C_Personaje.h"



C_Personaje::C_Personaje()
{
}


C_Personaje::~C_Personaje()
{
}

void C_Personaje::Definir(int X, int Y, int MY, int MX, int Vidas, int V) {
	Posicion_X = X;
	Posicion_Y = Y;
	Movimiento_X = X;
	Movimiento_Y = Y;
	this->Vidas = Vidas;
	Velocidad = V;
}


////////SETTERS///////////
void C_Personaje::setVidas(int Vidas) {
	this->Vidas = Vidas;
}
void C_Personaje::setMovimiento_X(int X) {
	Movimiento_X = X;
}
void C_Personaje::setMovimiento_Y(int Y) {
	Movimiento_Y = Y;
}
void C_Personaje::setVelocidad(int V) {
	Velocidad = V;
}
void C_Personaje::setPosicion_X(int X) {
	Posicion_X = X;
}
void C_Personaje::setPosicion_Y(int Y) {
	Posicion_Y = Y;
}
void C_Personaje::setModo_Lento(bool C) {
	Modo_Lento = C;
}


////////GETTERS///////////
int C_Personaje::getVidas() {
	return Vidas;
}
int C_Personaje::getPosicion_X(){
	return Posicion_X;
}
int C_Personaje::getPosicion_Y() {
	return Posicion_Y;
}
int C_Personaje::getVelocidad() {
	return Velocidad;
}
int  C_Personaje::getAncho() {
	return Ancho;
}
int  C_Personaje::getAlto() {
	return Alto;
}
bool C_Personaje::getModo_Lento() {
	return Modo_Lento;
}




void C_Personaje::Modo_CLenta() {
	if (Modo_Lento) {
		Velocidad += 5;
	}
	else {
		Velocidad -= 5;
	}

}


void C_Personaje::Dibujar(BufferedGraphics ^Buffer, Bitmap ^bmpPersonaje, Bitmap ^bmpPersonajeX) {
	Rectangle Area_Usar = Rectangle(Ancho*Indice_X, Alto*Indice_Y, Ancho, Alto);
	Rectangle Area_Dibujar = Rectangle(Posicion_X, Posicion_Y, Ancho, Alto);
	if(Modo_Lento){Buffer->Graphics->DrawImage(bmpPersonajeX, Area_Dibujar, Area_Usar, GraphicsUnit::Pixel);}
	else { Buffer->Graphics->DrawImage(bmpPersonaje, Area_Dibujar, Area_Usar, GraphicsUnit::Pixel); }

}
void C_Personaje::Mover(BufferedGraphics ^Buffer, Bitmap ^bmpPersonaje, Bitmap ^bmpPersonajeX) {
	switch (Tecla_Presionada)
	{
	case Arriba:
		Indice_Y = 3;
		if (Indice_X < 3) {
			Indice_X += 1;
		}
		else {
			Indice_X = 0;
		}
		Movimiento_Y = Modo_Lento ? -Velocidad - 8 : -Velocidad;
		Movimiento_X = 0;
		break;
	case Izquierda:
		Indice_Y = 1;
		if (Indice_X < 3) {
			Indice_X += 1;
		}
		else {
			Indice_X = 0;
		}
		Movimiento_Y = 0;
		Movimiento_X = Modo_Lento ? -Velocidad - 8 : - Velocidad ;
		break;
	case Abajo:
		Indice_Y = 0;
		if (Indice_X < 3) {
			Indice_X += 1;
		}
		else {
			Indice_X = 0;
		}
		Movimiento_Y = Modo_Lento ? Velocidad + 8 : Velocidad;
		Movimiento_X = 0;
		break;
	case Derecha:
		Indice_Y = 2;
		if (Indice_X < 3) {
			Indice_X += 1;
		}
		else {
			Indice_X = 0;
		}
		Movimiento_Y = 0;
		Movimiento_X = Modo_Lento ? Velocidad + 8: Velocidad;
		break;
	case Ninguna:
		switch (Tecla_Ultima)
		{
		case Arriba:
			Indice_Y = 3;
			Indice_X = 0;
			Movimiento_Y = 0;
			Movimiento_X = 0;
			break;
		case Izquierda:
			Indice_Y = 1;
			Indice_X = 0;
			Movimiento_Y = 0;
			Movimiento_X = 0;
			break;
		case Abajo:
			Indice_Y = 0;
			Indice_X = 0;
			Movimiento_Y = 0;
			Movimiento_X = 0;
			break;
		case Derecha:
			Indice_Y = 2;
			Indice_X = 0;
			Movimiento_Y = 0;
			Movimiento_X = 0;
			break;

		}
		break;
	}


	if (Posicion_X + Movimiento_X<0 || Posicion_X + Ancho + Movimiento_X>Buffer->Graphics->VisibleClipBounds.Width) {
		Movimiento_X = 0;
	}
	if (Posicion_Y + Movimiento_Y<0 || Posicion_Y + Alto + Movimiento_Y>Buffer->Graphics->VisibleClipBounds.Height-50) {
		Movimiento_Y = 0;
	}

	Posicion_X += Movimiento_X;
	Posicion_Y += Movimiento_Y;


	Dibujar(Buffer, bmpPersonaje, bmpPersonajeX);
}