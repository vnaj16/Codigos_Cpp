#pragma once

//Cuando es una plantilla de clases se declara y se define en el mismo archivo de cabecera para evitar inconvenientes con el linker

template <class T>
class Matematica
{
private:
	T E1, E2;
public:
	Matematica() {

	}

	Matematica(T Elemento,T Elemento1) {
		E1 = Elemento;
		E2 = Elemento1;
	}

	~Matematica() {

	}

	T& getElemento() {
		return E1;
	}


	T Sumar() {
		return E1 + E2;
	}
};



