#include "Juego.h"

using namespace ProyectoJuego;

int main() {

	Application::EnableVisualStyles();
	Application::Run(gcnew(Juego));


	return 0;
}
