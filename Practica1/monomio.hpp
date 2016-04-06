/* \par Fichero: monomio.hpp
	Monomio representa a la clase Monomio
   \author David Martinez Lora
   \date 17-Marzo-2016
*/

#ifndef MONOMIO_HPP
#define MONOMIO_HPP

#include <iostream>
#include <cmath>// para usar la funcion pow.
#include "monomioInterfaz.hpp"

using namespace std;
//! \attention Creamos el espacio de nombres ED
namespace ed{

//! Clase Monomio
class Monomio:public ed::MonomioInterfaz
{
	//! \name Atributos privados de Monomio
	private:
		double _coeficiente;//!< coeficiente del monomio
		int _grado;//!< grado del monomio
	
	//! \name Atributos publicos de Monomio
	public:
		//! \name Constructores de Monomio
		
			/*!
					\brief Constructor desde grado y coeficiente
					\attention funcion de sobrecarga
					\note Los parámetros tienen valores por defecto
					\param c double, valor por defecto 1.0
					\param g int, valor por defecto 1
					\pre Ninguna
					\post Ninguna
					\sa setCoeficiente(), setGrado()
				*/
		
		//Constructor por defecto
		Monomio(double c=1, int g=1)
			{
				setGrado(g);
				setCoeficiente(c);
			}
			/*!
				\brief Constructor de copia
				\attention Funcion de sobrecarga
				\param m Monomio, Monomio pasado por referencia
				\pre Ninguna
				\post Ninguna
				\sa setCoeficiente(), setGrado(), getGrado(), getCoeficiente()
		*/


		//Constructor de copia
		Monomio(const Monomio &m)
			{
				setGrado(m._grado);
				setCoeficiente(m._coeficiente);
			}
		//Observadores
		/*!
			\brief Devuelve el grado de un monomio
			\return Grado de un monomio
			\pre El monomio debe existir
			\post Ninguna
			\sa getCoeficiente()
		*/
		int getGrado() const
			{
				return _grado;
			}
		/*!
			\brief Devuelve el coeficiente de un monomio
			\return Coeficiente de un monomio
			\pre El monomio debe existir anteriormente
			\post Ninguna
			\sa getGrado()
		*/
		double getCoeficiente() const
			{
				return _coeficiente;
			}
		
		//Modificadores
		/*!
			\brief Asigna un valor "grado" al grado de un monomio
			\param g int pasado por referencia constante
			\pre El monomio debe existir
			\post Ninguna
			\sa setCoeficiente()
		*/
		void setGrado(int g)
			{
				_grado=g;
			}
		/*!
			\brief Asigna un valor "coeficiente" al coeficiente de un monomio
			\param c double pasado por referencia constante
			\pre El monomio debe existir
			\post Ninguna
			\sa setGrado()
		*/
		void setCoeficiente(double c)
			{
				_coeficiente=c;
			}

		//Operadores
		/*!
					\brief Operador de asignacion de un monomio a otro
					\attention Se sobrecarga el operador de asignacion
					\param m Monomio pasado por referencia constante
					\pre ninguna
					\post Ninguna
					\sa getGrado(), getCoeficiente(), setGrado(), setCoeficiente()
				*/
		Monomio &operator = (const Monomio &m)
		{
			this->setGrado(m.getGrado());
			this->setCoeficiente(m.getCoeficiente());
			
			return *this;
		}

		/*!
				\brief Operador producto de monomios
				\attention Se sobrecarga el operador producto
				\param m Monomio pasado por referencia constante
				\pre El monomio debe existir
				\post Ninguna
				\sa getGrado(), getCoeficiente(), setGrado(), setCoeficiente()
			*/
		Monomio operator *(const ed::Monomio &m)
		{
			Monomio aux(1,0);
			
			
			aux.setGrado(this->getGrado() + m.getGrado());
			aux.setCoeficiente(this->getCoeficiente() * m.getCoeficiente());

			return aux;
		}	

		//Operadores >> <<
		//! \name Funciones amigas para poder acceder a la parte privada de Monomio

		/*!
					\brief Sobrecarga del operador de entrada ">>"
					\attention Funcion amiga de la clase Monomio
					\param stream istream, flujo de entrada
					\param m Monomio, pasado por referencia constante
					\pre El monomio debe existir
					\post Se le asignan los valores coeficiente y grado a un monomio
					\sa operator <<
				*/
		friend istream &operator>> (istream &stream,  Monomio &m)
		{
			cout << "Introduzca el coeficiente: " << endl;
			stream >> m._coeficiente;
			cout << "Introduzca el grado: " << endl;
			stream >> m._grado;
			return stream;
		}
		/*!
			\brief Sobrecarga del operador de salida "<<"
			\attention Funcion amiga de la clase Monomio
			\param stream ostream, flujo de salida
			\param m Monomio, pasado por referencia constante
			\pre El monomio debe existir
			\post Se escribe por pantalla el coeficiente y el grado de un monomio
			\sa operator >>
		*/
		friend ostream &operator<< (ostream &stream, Monomio const &m)
		{
			stream<<m.getGrado()<<" "<<m.getCoeficiente()<<endl;
			return stream;	
		}
			
		//Lectura y Escritura
		/*! 
		\brief Imprime por pantalla el coeficiente y el grado de un Monomio.
		\pre El Monomio debe existir
		\post Ninguna
		\sa setGrado()
	*/
		void escribirMonomio()
		{
			cout << getCoeficiente() << "x^" << getGrado() << endl;
		}
		/*! 
		\brief Asigna a un Monomio el "coeficiente" y "grado" leídas desde el teclado
		\pre El Monomio debe existir
		\post Ninguna
		\warning Se deben teclear números flotante/coeficiente y entero/grado
		\sa setGrado(), setCoeficiente()
	*/
		void leerMonomio()
		{
			int g;
			double c;
		
			cout << "Introduzca el coeficiente: " << endl;
			cin >> c;
			cout << "Introduzca el grado: " << endl;
			cin >> g;

			setGrado(g);
			setCoeficiente(c);
			
		}

		//Devolver un valor de x
		/*! 
		\brief Resuelve un Monomio con el valor pasado
		\pre Los Monomio deben existir
		\post Ninguna
		\param x
		\sa getGrado(), getCoeficiente(), setGrado(), setCoeficiente()
	*/
		double devolverValor(double x)
		{
			double aux=1;
			
			aux = pow( getCoeficiente() * x, getGrado());
		
			return aux;
		}
};
}
#endif
