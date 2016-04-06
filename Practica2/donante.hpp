#ifndef DONANTE_HPP
#define DONANTE_HPP

#include "donanteInterfaz.hpp"
#include <stdio.h>
#include <cstdlib>
#include <string>

using namespace std;

namespace ed{
  class Donante:public DonanteInterfaz{
    private:
        string _nombre;
        string _apellidos;
        string _grupoSanguineo;
        string _rh;

    public:
        //Constructor por defecto.
        Donante()
          {
              _nombre='X';
              _apellidos='X';
              _grupoSanguineo='X';
              _rh='X';
          }

        //Constructor de copia
        Donante(const Donante &d)
        {
          setNombre(_nombre);
          setApellidos(_apellidos);
          setGrupoSanguineo(_grupoSanguineo);
          setRH(_rh);
        }

        //Observadores
          string getNombre()const
            {
              return _nombre;
            }

          string getApellidos()const
            {
              return _apellidos;
            }

          string getGrupoSanguineo()const
            {
              return _grupoSanguineo;
            }

          string getRH()const
            {
              return _rh;
            }

        //Modificadores
          void setNombre(string nombre)
            {
              _nombre = nombre;
            }


          void setApellidos(string apellidos)
            {
              _apellidos = apellidos;
            }

         void setGrupoSanguineo(string grupoSanguineo)
            {
              _grupoSanguineo = grupoSanguineo;
            }

          void setRH(string rh)
                {
                  _rh = rh;
                }

          void leerDonante()
            {
                string nombre, apellidos, grupoSanguineo, rh;

                cout<<"Introduce el nombre del donante: "<<endl;
                cin>>nombre;
                cout<<"Introduce los apelldos del donante: "<<endl;
                cin>>apellidos;
                cout<<"Introduce el grupo sanguineo del donante: "<<endl;
                cin>>grupoSanguineo;
                cout<<"Introduce el factor RH del donante: "<<endl;
                cin>>rh;

                setNombre(nombre);
                setApellidos(apellidos);
                setGrupoSanguineo(grupoSanguineo);
                setRH(rh);

            }

          void escribirDonante()
            {
              cout<<"Nombre: "<<getNombre()<<endl;
              cout<<"Apellidos:"<<getApellidos()<<endl;
              cout<<"Grupo Sanguieno: " << getGrupoSanguineo()<<endl;
              cout<<"Factor RH: " <<getRH()<<endl;
            }

          void modificarDonante()
          {
            int opc=0;
            string nombre, apellidos, grupoSanguineo, rh;

            cout<<"Introduce el dato que desea modificar: "<<endl;
            cout<<"1 para nombre, 2 para apellidos, 3 para grupo sanguineo y 4 para RH"<<endl;
            cin>>opc;

            switch(opc)
            {
              case 1:
                cout<<"Introduce el nuevo nombre"<<endl;
                cin>>nombre;
                setNombre(nombre);
                break;
              case 2:
                cout<<"Introducelos nuevos apellidos"<<endl;
                cin>>apellidos;
                setApellidos(apellidos);
                break;
              case 3:
                cout<<"Introduce el nuevo grupo sanguineo"<<endl;
                cin>>grupoSanguineo;
                setGrupoSanguineo(grupoSanguineo);
                break;
              case 4:
                cout<<"Introduce el nuevo factor rh"<<endl;
                cin>>rh;
                setRH(rh);
                break;
            }
          }

          //Operador de igualdad.
          Donante &operator =(const Donante &d)
            {
              this->setNombre(d.getNombre());
              this->setApellidos(d.getApellidos());
              this->setGrupoSanguineo(d.getGrupoSanguineo());
              this->setRH(d.getRH());

              return *this;
            }
          //Operador para la comparacion
          bool operator ==(const Donante &d)
            {
                  return this->getNombre() == d.getNombre() && this->getApellidos() == d.getApellidos();
            }
          //Sobrecarga operador <=
          //Ordenar primero por apellidos y luego por nombres.
          bool operator <=(const Donante &d)
            {
                return this->getNombre() == d.getNombre() && this->getApellidos() == d.getApellidos();
            }
          //Funciones friend
          friend istream &operator>>(istream &stream, Donante &d)
            {
              string nombre, apellidos, grupoSanguineo, rh;
              cout << "Introduzca el nombre del donante" << endl;
              stream >> nombre;
              d.setNombre(nombre);
              cout << "Introduzca los apellidos del donante" << endl;
              stream >> apellidos;
              d.setApellidos(apellidos);
              cout << "Introduzca el grupo sanguineo del donante" << endl;
              stream >> grupoSanguineo;
              d.setGrupoSanguineo(grupoSanguineo);
              cout << "Introduzca el factor RH del donante" << endl;
              stream >> rh;
              d.setRH(rh);

              return stream;
            }

          friend ostream &operator<<(ostream &o, Donante &d)
            {
              o << d.getNombre() << " " <<d.getApellidos()<< " " << d.getGrupoSanguineo()<< " " << d.getRH()<<endl;
              return o;
            }

  };
}
#endif
