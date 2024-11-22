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
	ofstream archivo;
	
	archivo.open("output.txt");
	cout << "RUC: ";
	while(cin >> ruc){
		cin.ignore();
		cout << "Producto: ";
		getline(cin, producto);
		cout << "Unidades: ", cin >> unidades;
		cout << "Precio: ", cin >> precio;
		
		archivo << ruc << " " << unidades << " "
				<< precio << " " << producto << endl;
		cout << "RUC: ";
	}
	archivo.close();
		
	return 0;
}