#include <stdio.h>
#include "donante.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;
using namespace ed;


int main()
{
  int opcion = 0;
  Donante donante1,donante2;
  string nombre, apellidos;

  do{
  cout<<"---------------Menu-------------"<<endl;
  cout<<"1.Leer un donante desde teclado."<<endl;
  cout<<"2.Escribir un donante por pantalla."<<endl;
  cout<<"3.Modificar los datos de un donante."<<endl;
  cout<<"4.Comparar lexicograficamente dos donantes."<<endl;
  cout<<"5.Fin del programa."<<endl;
  cin>>opcion;

  switch(opcion){
    case 1:
        donante1.leerDonante();
        break;
    case 2:
        donante1.escribirDonante();
        break;
    case 3:
        cout<<"Introduce el nombre y apellido del donante que desea modificar"<<endl;
        cout<<"Nombre"<<endl;
        cin>>nombre;
        cout<<"Apellidos"<<endl;
        cin>>apellidos;
        if(donante1.getNombre() == nombre && donante1.getApellidos() == apellidos)
          {
            donante1.leerDonante();
          }
        else
          cout<<"No existe ese donante"<<endl;
        break;
    case 4:
        cout<<"Introduce un nuevo donante: "<<endl;
        donante2.leerDonante();
        if(donante1 == donante2)
          {
            cout<<"Los donantes son iguales."<<endl;
          }
        else
          cout<<"No hay otro donante igual."<<endl;
        break;

  }

}while(opcion!=5);


};
