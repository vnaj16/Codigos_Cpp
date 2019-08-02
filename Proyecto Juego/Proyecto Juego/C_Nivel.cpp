#include "C_Nivel.h"

using namespace System;

C_Nivel::C_Nivel(C_Personaje *Personaje)
{
	this->Personaje = Personaje;
}

C_Nivel::C_Nivel()
{
}

C_Nivel::~C_Nivel()
{
}


////////SETTERS///////////
void C_Nivel::setModo_Lento(bool M) {
	Modo_Lento = M;
}
void C_Nivel::setTiempo_Modo_Lento(int N) {
	Tiempo_Modo_Lento = N;
}
void C_Nivel::setIntentos_Camara_Lenta(int I) {
	Intentos_Camara_Lenta = I;
}
void C_Nivel::setTiempo_Nivel(int T) {
	Tiempo_Nivel = T;
}
void C_Nivel::setDiscos_Activos(int D) {
	Discos_Activos = D;
}
	
void C_Nivel::setCantidad_Discos(int C) {
	Cantidad_Discos = C;
}

////////GETTERS///////////
bool C_Nivel::getModo_Lento() {
	return Modo_Lento;
}
int C_Nivel::getTiempo_Modo_Lento() {
	return Tiempo_Modo_Lento;
}
int C_Nivel::getIntentos_Camara_Lenta() {
	return Intentos_Camara_Lenta;
}
int C_Nivel::getTiempo_Nivel() {
	return Tiempo_Nivel;
}
int C_Nivel::getDiscos_Activos(){
	return Discos_Activos;
}
int C_Nivel::getCantidad_Discos() {
	return Cantidad_Discos;
}
int C_Nivel::getNivel() {
	return Nivel;
}




void C_Nivel::Inicializar(int N, BufferedGraphics ^Buffer) {
	Random r;

	Nivel = N;
	Tiempo_Modo_Lento = r.Next(4,9);
	Tiempo_Nivel = 30 + (Nivel-1) *2 + 5;
	Intentos_Camara_Lenta = 2 * (Nivel) - 1;

	//DiscoP = new C_Disco_Perseguidor[Nivel];
	Cantidad_Discos = Nivel + 2;
	Discos_Activos = 1;
	Disco = new C_Disco[Cantidad_Discos];
	Mapa = new C_Mapa;
	

	for (int i = 0; i < Cantidad_Discos; i++) {
		Disco[i].setSize(r.Next(32, 72));
		Disco[i].Definir(r.Next(Buffer->Graphics->VisibleClipBounds.Width - Disco[i].getSize()), r.Next(Buffer->Graphics->VisibleClipBounds.Height - Disco[i].getSize()-50), r.Next(5, 12), r.Next(5, 12));
	}

	/*for (int i = 0; i < Nivel; i++) {
		DiscoP[i].setSize(r.Next(32, 33));
		DiscoP[i].Definir(Buffer->Graphics->VisibleClipBounds.Width/2, Buffer->Graphics->VisibleClipBounds.Height/2, r.Next(5, 12), r.Next(5, 12));
		DiscoP[i].setPosicion_Final_X(5);
		DiscoP[i].setPosicion_Final_Y(5);
	}*/

	Mapa->setNivel(Nivel);

}

void C_Nivel::Detectar_Colision(Graphics ^g) {
	Random r;
	for (int i = 0; i < Discos_Activos; i++) {
		if (//Esquina superior izquierda
			(Disco[i].getPosicion_X() >= Personaje->getPosicion_X() && Disco[i].getPosicion_X() <= Personaje->getPosicion_X() + Personaje->getAncho() &&
			Disco[i].getPosicion_Y() >= Personaje->getPosicion_Y() && Disco[i].getPosicion_Y() <= Personaje->getPosicion_Y() + Personaje->getAlto()) ||

			//Esquina superior derecha
			(Disco[i].getPosicion_X() + Disco[i].getSize() >= Personaje->getPosicion_X() && Disco[i].getPosicion_X() + Disco[i].getSize() <= Personaje->getPosicion_X() + Personaje->getAncho() &&
			Disco[i].getPosicion_Y() >= Personaje->getPosicion_Y() && Disco[i].getPosicion_Y() <= Personaje->getPosicion_Y() + Personaje->getAlto()) ||

			//Esquina inferior izquierda
			(Disco[i].getPosicion_X() >= Personaje->getPosicion_X() && Disco[i].getPosicion_X() <= Personaje->getPosicion_X() + Personaje->getAncho() &&
			Disco[i].getPosicion_Y() + Disco[i].getSize() >= Personaje->getPosicion_Y() && Disco[i].getPosicion_Y() + Disco[i].getSize() <= Personaje->getPosicion_Y() + Personaje->getAlto()) ||

			//Esquina inferior derecha
			(Disco[i].getPosicion_X() + Disco[i].getSize() >= Personaje->getPosicion_X() && Disco[i].getPosicion_X() + Disco[i].getSize() <= Personaje->getPosicion_X() + Personaje->getAncho() &&
			Disco[i].getPosicion_Y() + Disco[i].getSize() >= Personaje->getPosicion_Y() && Disco[i].getPosicion_Y() + Disco[i].getSize() <= Personaje->getPosicion_Y() + Personaje->getAlto())

			) {
			Personaje->setPosicion_X(r.Next(g->VisibleClipBounds.Width - Personaje->getAncho()));
			Personaje->setVidas(Personaje->getVidas() - 1);
		}
	}
}

void C_Nivel::Activar_Modo_Lento() {
	if (Modo_Lento) {
		for (int i = 0; i < Discos_Activos; i++) {
			Disco[i].setModo_Lento(true);
		}
		Personaje->setModo_Lento(true);
	}
	else {
		for (int i = 0; i < Discos_Activos; i++) {
			Disco[i].setModo_Lento(false);
		}
		Personaje->setModo_Lento(false);
	}
}

void C_Nivel::Mover_Elementos(Graphics ^g, BufferedGraphics ^Buffer, Bitmap ^bmpPersonaje, Bitmap ^bmpPersonajeX, Bitmap ^bmpDisco, Bitmap ^bmpDiscoX, Bitmap ^Map) {
	Activar_Modo_Lento();
	Mapa->Dibujar(Buffer, Map);
	for (int i = 0; i < Discos_Activos; i++) {
		Disco[i].Mover(Buffer, bmpDisco, bmpDiscoX);
	}

	Personaje->Mover(Buffer, bmpPersonaje, bmpPersonajeX);

	

	Detectar_Colision(g);
}

