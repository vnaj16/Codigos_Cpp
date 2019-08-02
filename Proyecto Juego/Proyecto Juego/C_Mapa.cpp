#include "C_Mapa.h"



C_Mapa::C_Mapa()
{
}


C_Mapa::~C_Mapa()
{
}

void C_Mapa::setNivel(int N) {
	Nivel += N;
	if (Nivel == 6) {
	Nivel = 1;
	}

}
void C_Mapa::setAncho(int W) {Ancho = W;}
void C_Mapa::setAlto(int H) { Alto = H; }

int C_Mapa::getNivel() { return Nivel; }
int C_Mapa::getAncho() { return Ancho; }
int C_Mapa::getAlto() { return Alto; }

void C_Mapa::Dibujar(BufferedGraphics ^Buffer, Bitmap ^bmpMapa) {
	Rectangle Area_Usar = Rectangle(0, Alto*(Nivel - 1),Ancho,Alto);
	Rectangle Area_Dibujar = Rectangle(0, 0, Buffer->Graphics->VisibleClipBounds.Width, Buffer->Graphics->VisibleClipBounds.Height);
	Buffer->Graphics->DrawImage(bmpMapa, Area_Dibujar, Area_Usar, GraphicsUnit::Pixel);
}
