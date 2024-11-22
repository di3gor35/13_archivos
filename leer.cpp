#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main(){
	const int IGV = 18;
	string ruc, producto;
	int unidades;
	double precio, neto, total, igv;
	char aux;
	
	int contador = 0;
	
	ifstream archivo;
	
	archivo.open("compras.txt");
	
	if(archivo.is_open()){
		while(archivo >> ruc){
			contador++;
			archivo >> unidades >> precio;
			archivo.get(aux);
			
			getline(archivo, producto);
			neto = unidades * precio;
			igv = IGV * neto / 100;
			total = neto + igv;
			
			cout << "Compra " << contador << ".-" << endl;
			cout << "\t" << producto << ": " << unidades
				 << " x " << fixed << setprecision(2)	
				 << precio << " = " << neto << " - I.G.V.: "
				 << igv << " - Total: " << total << endl;
		}
		archivo.close();
	} else {
		cout << "ERROR: no se pudo abrir el archivo";
	}
	
	return 0;
}