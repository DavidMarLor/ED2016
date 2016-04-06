#include "monomioInterfaz.hpp"
#include "monomio.hpp"
#include <iostream>

using namespace std;
using namespace ed;

int main(void)
{
	int opcion = 0;
	double x = 0.0;
	Monomio m1(1,1), m2(1,1), m3(1,1);
	
	do
	{
		cout << "0. Conocer el valor del monominio para un valor determinado." << endl;
		cout << "1. Multiplicar dos monomios en un tercero." << endl;
		cout << "2. Salir." << endl;
		cin >> opcion;

	
	

	switch(opcion)
	{
	
		case 0:
			m1.leerMonomio();
			cout << "Intrdouce el valor de x: "<<endl;
			cin >> x;
			x=m1.devolverValor(x);
			cout << "El valor es el siguiente: " << x << endl;
			break;
		case 1:
			m2.leerMonomio();
			m3=m1*m2;
			m3.escribirMonomio();
			break;
	}
	}while(opcion!=2);

return 0;
}


