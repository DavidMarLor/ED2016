/* \par Fichero: polinomioInterfaz.hpp
	PolinomioInterfaz representa las funcione virtuales puras de la clase polinomio
   \author David Martinez Lora
   \date 17-Marzo-2016
*/
#ifndef POLINOMIOINTERFAZ_HPP
#define POLINOMIOINTERFAZ_HPP

#include <vector>
#include "monomio.hpp"
#include "monomioInterfaz.hpp"

namespace ed{
//! Clase MonomioInterfaz
class PolinomioInterfaz{
//! \name Atributos publicos de la clase polinomio
	public:

		virtual void setGrado(const int g) = 0;

		virtual void setTerminos(const int nt) = 0;

		virtual void setPolinomio(const vector<Monomio> &p) = 0;

		virtual int getGrado()const = 0;

		virtual int getTerminos() const = 0;

		virtual vector<Monomio> getPolinomio() const = 0;

		virtual bool estaVacio() const = 0;

	};
}

#endif 
