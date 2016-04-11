/* \par Fichero: donante.hpp
	Monomio representa a la clase Donante
   \author David Martinez Lora
   \date 11-Abril-2016
*/
#ifndef DONANTE_HPP
#define DONANTE_HPP

#include "donanteInterfaz.hpp"
#include <stdio.h>
#include <cstdlib>
#include <string>

using namespace std;
//! \attention Creamos el espacio de nombres ED
namespace ed{
  //! Clase Donante
  class Donante:public DonanteInterfaz{
    //! \name Atributos privados de Donante
    private:
        string _nombre; //!< nombre del donante
        string _apellidos; //!< apellidos del donante
        string _grupoSanguineo;//!< grupo sanguineo del donante
        string _rh;//!< rh del donante

    //! \name Atributos publicos de Monomio
    public:
        //Constructor por defecto.
        //! \name Constructores de Donante

			/*!
					\brief Constructor desde nombre, apellidos, grupo sanguineo y rh
					\attention funcion de sobrecarga
					\note Los parámetros tienen valores por defecto
					\pre Ninguna
					\post Ninguna
				*/
        Donante()
          {
              _nombre='X';
              _apellidos='X';
              _grupoSanguineo='X';
              _rh='X';
          }

        //Constructor de copia
        /*!
				\brief Constructor de copia
				\attention Funcion de sobrecarga
				\param d Donante, Donante pasado por referencia
				\pre Ninguna
				\post Ninguna
				\sa setNombre(), setApellidos(), setGrupoSanguineo(), setRH()
		*/

        Donante(const Donante &d)
        {
          setNombre(_nombre);
          setApellidos(_apellidos);
          setGrupoSanguineo(_grupoSanguineo);
          setRH(_rh);
        }

        //Observadores
        /*!
			\brief Devuelve el nombre de un donante
			\return Nombre de un donante
			\pre El donante debe existir
			\post Ninguna
		*/
          string getNombre()const
            {
              return _nombre;
            }
            /*!
          \brief Devuelve apellidos de un donante
          \return Apellidos de un donante
          \pre El donante debe existir
          \post Ninguna
          */
          string getApellidos()const
            {
              return _apellidos;
            }
            /*!
          \brief Devuelve el grupo sanguineo de un donante
          \return Grupo sanguineo de un donante
          \pre El donante debe existir
          \post Ninguna
          */
          string getGrupoSanguineo()const
            {
              return _grupoSanguineo;
            }
            /*!
          \brief Devuelve el rh de un donante
          \return RH de un donante
          \pre El donante debe existir
          \post Ninguna
          */
          string getRH()const
            {
              return _rh;
            }

        //Modificadores
        /*!
			\brief Asigna un nombre al nombre de un donante
			\param nombre string pasado por referencia constante
			\pre El donante debe existir
			\post Ninguna
		*/
          void setNombre(string nombre)
            {
              _nombre = nombre;
            }

            /*!
          \brief Asigna los apellidos a apellidos de un donante
          \param apellidos string pasado por referencia constante
          \pre El donante debe existir
          \post Ninguna
          */
          void setApellidos(string apellidos)
            {
              _apellidos = apellidos;
            }
            /*!
          \brief Asigna un grupo sanguineo al grupo sanguineo de un donante
          \param grupoSanguineo string pasado por referencia constante
          \pre El donante debe existir
          \post Ninguna
          */
         void setGrupoSanguineo(string grupoSanguineo)
            {
              _grupoSanguineo = grupoSanguineo;
            }
            /*!
          \brief Asigna un rh al rh de un donante
          \param rh string pasado por referencia constante
          \pre El donante debe existir
          \post Ninguna
        */
          void setRH(string rh)
                {
                  _rh = rh;
                }
                /*!
                		\brief Asigna a un Donante el "nombre", "apellidos", "grupo sanguineo" y "rh" leídas desde el teclado
                		\pre El Donante debe existir
                		\post Ninguna
                	*/
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
            /*!
		\brief Imprime por pantalla el nombre, apellidos, grupo sanguineo y rh de un donante.
		\pre El Donante debe existir
		\post Ninguna
	*/
          void escribirDonante()
            {
              cout<<"Nombre: "<<getNombre()<<endl;
              cout<<"Apellidos:"<<getApellidos()<<endl;
              cout<<"Grupo Sanguieno: " << getGrupoSanguineo()<<endl;
              cout<<"Factor RH: " <<getRH()<<endl;
            }

          //Operador de igualdad.
          /*!
					\brief Operador de asignacion de un donante a otro
					\attention Se sobrecarga el operador de asignacion
					\param d Donante, pasado por referencia constante
					\pre ninguna
					\post Ninguna
					\sa setNombre(), getNombre(), setApellidos(), getApellidos(), setRH(), getRH(), setGrupoSanguineo(), setGrupoSanguineo()
				*/
          Donante &operator =(const Donante &d)
            {
              this->setNombre(d.getNombre());
              this->setApellidos(d.getApellidos());
              this->setGrupoSanguineo(d.getGrupoSanguineo());
              this->setRH(d.getRH());

              return *this;
            }
          //Operador para la comparacion
          /*!
				\brief Operador busqueda de donantes
        \attention Se sobrecarga el operador ==
				\param d Donant, pasado por referencia constante
				\pre El donante debe existir
				\post Ninguna
				\sa setNombre(), getNombre(), setApellidos(), getApellidos(), setRH(), getRH(), setGrupoSanguineo(), setGrupoSanguineo()
			*/
          bool operator ==(const Donante &d)
            {
                  return this->getNombre() == d.getNombre() && this->getApellidos() == d.getApellidos();
            }
          //Sobrecarga operador <=
          //Ordenar primero por apellidos y luego por nombres.
          /*!
				\brief Operador busqueda de donantes
        \attention Se sobrecarga el operador <=
				\param d Donant, pasado por referencia constante
				\pre El donante debe existir
				\post Ninguna
				\sa setNombre(), getNombre(), setApellidos(), getApellidos(), setRH(), getRH(), setGrupoSanguineo(), setGrupoSanguineo()
			*/
          bool operator <=(const Donante &d)
            {
                return this->getNombre() == d.getNombre() && this->getApellidos() == d.getApellidos();
            }
          //Funciones friend
          //! \name Funciones amigas para poder acceder a la parte privada de Monomio

		/*!
					\brief Sobrecarga del operador de entrada ">>"
					\attention Funcion amiga de la clase Donante
					\param stream istream, flujo de entrada
					\param d Donante, pasado por referencia constante
					\pre El donante debe existir
					\post Se le asignan los valores nombre, apellidos, grupo sanguineo y rh a un monomio.
					\sa operator <<
				*/
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
            /*!
            			\brief Sobrecarga del operador de salida "<<"
            			\attention Funcion amiga de la clase Donante
            			\param o ostream, flujo de salida
            			\param d Donante, pasado por referencia constante
            			\pre El donante debe existir
            			\post Se escribe por pantalla el nombre, apellidos, grupo sanguineo y rh de un donante.
            			\sa operator >>
            		*/
          friend ostream &operator<<(ostream &o, Donante &d)
            {
              o << d.getNombre() << " " <<d.getApellidos()<< " " << d.getGrupoSanguineo()<< " " << d.getRH()<<endl;
              return o;
            }

  };
}
#endif
