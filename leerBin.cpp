#include <iostream>
#include <fstream>

using namespace std;

const int MAX = 80;

struct tRegistro {
	int codigo;
	char item[MAX];
	double valor;
};

const int SIZE = sizeof(tRegistro);

void mostrarRegistro(tRegistro &r){
	cout << r.codigo << " - " << r.item << "\t" << r.valor << " euros" << endl;
}

int main(){
	tRegistro registro;
	fstream archivo;
	
	archivo.open("bd.dat", ios::in | ios::binary);
		
	while(archivo.read( (char *) &registro, SIZE)){
		mostrarRegistro(registro);

	}
	archivo.close();
	
	return 0;	
}