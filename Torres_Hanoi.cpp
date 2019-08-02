#include <iostream>
#include <conio.h>

using namespace std;

void Hanoi(int Numero_Discos, char Torre_Inicial, char Torre_Final, char Torre_Auxiliar) {
	if (Numero_Discos == 1) {
		cout << "Mover el disco de la torre " << Torre_Inicial << " a la torre " << Torre_Final << endl;
		_getch();
	}
	else {
		Hanoi(Numero_Discos - 1, Torre_Inicial, Torre_Auxiliar, Torre_Final);
		_getch();
		cout << "Mover el disco de la torre " << Torre_Inicial << " a la torre " << Torre_Final << endl;
		_getch();
		Hanoi(Numero_Discos - 1, Torre_Auxiliar, Torre_Final, Torre_Inicial);
		_getch();
	}
}

int main() {

	Hanoi(3, 'A', 'C', 'B');


	_getch();
	return 0;
}