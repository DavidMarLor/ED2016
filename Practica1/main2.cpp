#include <stdio.h>
#include "polinomio.hpp"
#include "monomio.hpp"

using namespace std;
using namespace ed;

int main(){
	int opcion = 0;
	double x=0;
	Polinomio p1,p2,p3;
	Monomio m1, m2(1,1), m3(2,2), m4(1,2);
	
	
	
	do
	{
		cout << "1. Valor de un polinomio para un dato concreto de X." << endl;
		cout << "2. Suma de dos polinomios y almacenar el resultado en ele tercero." << endl;
		cout << "3. Multiplicacion de dos polinomios y almacenar el resultado en el tercero." << endl;
		cout << "4. Lectura y escritura de un polinomio haciendo uso de los operadores '>>' y '<<'" << endl;
		cout << " 5. Fin del programa."<< endl;
		cin >> opcion;
		
		switch(opcion)
		{
			case 1:
				p1.leerPolinomio();
				cout << "Introduzca el valor x para el calculo del monomio: "<< endl;
				cin >> x;
				cout <<"HOLA"<<endl;
				p1.escribirPolinomio();
				x=p1.darValorXP(x);
				cout << "El valor es el siguiente: " << x <<endl;
				break;
					
			case 2:
				p1.leerPolinomio();
				p2.leerPolinomio();
				p3 = p1 + p2;
				p3.escribirPolinomio();	
				break;
			
			case 3:
				p1.leerPolinomio();
				p2.leerPolinomio();
				p3 = p1 * p2;
				p3.escribirPolinomio();		
				break;
				
			case 4:
				cin >> p2;
    				cout << p2 << endl;
				break;
				
		}
	}while(opcion!=5);
return 0;
}

