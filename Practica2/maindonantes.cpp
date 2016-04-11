#include "donantes.hpp"
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace ed;
using namespace std;
using std::sting;

int main()
{

  int opc;

  do{
    cout<<"1. Comprobar si hay donantes."<<endl;
    cout<<"2. Cargar una lista de donantes de un fichero."<<endl;
    cout<<"3. Grabar una lista de donantes en un fichero."<<endl;
    cout<<"4. Insertar un nuevo donante en la lista."<<endl;
    cout<<"5. Modificar la informacion de un donante."<<endl;
    cout<<"6. Borrar un donante de la lista."<<endl;
    cout<<"7. Mostrar por pantalla los donantes de sangre."<<endl;
    cout<<"8. Fin del programa."<<endl;
    cin>>opc;

    if(opc<1 || opc>8)
      {
        cout<<"Lo siento pero ha introducido una opcion erronea."<<endl;
      }
    else
      {
        switch(opc)
          {
            case 1:
              break;

            case 2:
              break;

            case 3:
              break;

            case 4:
              break;

            case 5:
              break;

            case 6:
              break;

            case 7:
              break;
          }
      }
  }while(opc!=8)

  return 0;
};
