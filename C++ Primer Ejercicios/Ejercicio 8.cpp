#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
#include <string.h>

using namespace std;
using namespace System;

int main() {

	/*vector<string> Calificacion = { "C","B","A","AD" };

	float Nota;

	cout << "Ingrese nota: "; 

	while (cin >> Nota && (Nota >= 0 && Nota <= 20)) {
		Console::Clear();

		cout << "Su calificacion es: ";

		if (Nota == 20) {
			cout << Calificacion[3];
		}
		else if (Nota >=16) {
			cout << Calificacion[2];
		}
		else if(Nota>=11) {
			cout << Calificacion[1];
		}
		else {
			cout << Calificacion[0];
		}

		cout << endl << endl << "Ingrese nota: ";
	}*/

	string Palabra;
	vector<int> Vocales(5,0);

	while (getline(cin, Palabra) && !Palabra.empty()) {

		

		for (auto i = 0; i < Palabra.size(); i++) {
			switch (Palabra[i]) {
			case 'a':
				Vocales[0] += 1;
				break;
			case 'e':
				Vocales[1] += 1;
				break;
			case 'i':
				Vocales[2] += 1;
				break;
			case 'o':
				Vocales[3] += 1;
				break;
			case 'u':
				Vocales[4] += 1;
				break;
			}
		}

		cout << endl << "Vocal a: " << Vocales[0] << endl;
		cout << endl << "Vocal e: " << Vocales[1] << endl;
		cout << endl << "Vocal i: " << Vocales[2] << endl;
		cout << endl << "Vocal o: " << Vocales[3] << endl;
		cout << endl << "Vocal u: " << Vocales[4] << endl;
		cout << endl << endl;

		for (auto i = 0; i < Vocales.size(); i++) {
			Vocales[i] = 0;
		}
	}




	_getch();
	return 0;
}