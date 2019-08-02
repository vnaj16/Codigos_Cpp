#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

int main() {

	Application::EnableVisualStyles();
	Application::Run(gcnew(PruebadeEntrada::MyForm));


}

