#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

const int MAX = 80;

struct tRegistro {
	int codigo;
	char item[MAX];
	double valor;
};

const int SIZE2 = sizeof(tRegistro);

void mostrar(tRegistro &r){
	cout << r.codigo << " - " << r.item << "\t" << r.valor << " soles";
}

int main() {
	SetConsoleOutputCP(CP_UTF8);
	tRegistro registro;
	fstream archivo;
	archivo.open("bd.dat", ios::in | ios::out | ios::binary);
	archivo.seekg(0, ios::end);
	int pos = archivo.tellg();
	int numReg = pos / SIZE2;
	cout << "Número de registros: " << numReg << endl;
	int num;
	cout << "Registro número?: ";
	cin >> num;
	if ((num > 0) && (num <= numReg)) {
	    archivo.seekg((num - 1) * SIZE2, ios::beg);
	    archivo.read((char *) &registro, SIZE2);
	    mostrar(registro);
	    cout << endl << "Cambiar nombre [S/N]? ";
	    char c;
	    cin.sync();
	    cin >> c;
		if ((c == 's') || (c == 'S')) {
	    	cout << "Nombre: ";
	    	cin.sync();
	    	cin.getline(registro.item, 80);
	    }
	    cout << endl << "Cambiar precio [S/N]? ";
	    cin.sync();
	    cin >> c;
	    if ((c == 's') || (c == 'S')) {
	    	cout << "Precio: ";
	    	cin >> registro.valor;
		}
	    archivo.seekg((num - 1) * SIZE2, ios::beg);
	  	archivo.write((char *) &registro, SIZE2);
	  	cout << "Registro actualizado:" << endl;
	  	mostrar(registro);
    }
    archivo.close();
    return 0;
}