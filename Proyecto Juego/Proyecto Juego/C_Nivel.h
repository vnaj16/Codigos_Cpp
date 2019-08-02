#pragma once
#include "C_Disco.h"
#include "C_Mapa.h"
#include "C_Personaje.h"
#include "C_Disco_Perseguidor.h"

using namespace System::Drawing;

class C_Nivel
{
private:
	int Tiempo_Nivel, Tiempo_Modo_Lento,Cantidad_Discos,Nivel, Intentos_Camara_Lenta,Discos_Activos;
	C_Personaje *Personaje;
	C_Disco *Disco;
	C_Disco_Perseguidor *DiscoP;
	C_Mapa *Mapa;
	bool Modo_Lento=false;
public:
	C_Nivel();
	C_Nivel(C_Personaje *Personaje);
	~C_Nivel();

	void setIntentos_Camara_Lenta(int I);
	void setTiempo_Modo_Lento(int N);
	void setModo_Lento(bool M);
	void setTiempo_Nivel(int T);
	void setDiscos_Activos(int D);
	void setCantidad_Discos(int C);

	bool getModo_Lento();
	int getTiempo_Modo_Lento();
	int getIntentos_Camara_Lenta();
	int getTiempo_Nivel();
	int getDiscos_Activos();
	int getCantidad_Discos();
	int getNivel();


	void Activar_Modo_Lento();
	void Inicializar(int N, BufferedGraphics ^Buffer);
	void Detectar_Colision(Graphics ^g);
	void Mover_Elementos(Graphics ^g, BufferedGraphics ^Buffer, Bitmap ^Personaje, Bitmap ^PersonajeX, Bitmap ^Disco, Bitmap ^DiscoX, Bitmap ^Mapa);
};

