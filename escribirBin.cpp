#include <iostream>
#include <fstream>

const int MAX=80;

struct tRegistro {
	int codigo;
	char item[MAX];
	double valor;
};
int SIZE = sizeof(tRegistro);

using namespace std;
int main() {
	tRegistro registro;
	fstream archivo;
	archivo.open("bd.dat", ios::out | ios::binary);
	bool seguir=true;
	while (seguir) {
		cout<<"Codigo: ";
		cin.sync();
		cin>>registro.codigo;
		cout<<"Nombre: ";
		cin.sync();
		cin.getline(registro.item,MAX); //MAX=80
		cout<<"Precio: ";
		cin.sync();
		cin>>registro.valor;
		archivo.write((char *) &registro, SIZE);
		cout<<"Otro? [S/N] ";
		char c;
		cin>>c;
		if ((c=='n') || (c=='N')) {
			seguir=false;
		}
	}
	archivo.close();
	return 0;
}