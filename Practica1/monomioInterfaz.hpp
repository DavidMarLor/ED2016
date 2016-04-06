/* \par Fichero: monomioInterfaz.hpp
	monomioInterfaz representa las funcione virtuales puras de la clase monomio
   \author David Martinez Lora
   \date 17-Marzo-2016
*/
#ifndef MONOMIOINTERFAZ_HPP
#define MONOMIOINTERFAZ_HPP
namespace ed{
//! Clase MonomioInterfaz
	class MonomioInterfaz {
	//! \name Atributos publicos de la clase monomio
	public:
		virtual int getGrado() const = 0;
	
		virtual double getCoeficiente() const = 0;
		
		virtual void setGrado(int g) = 0;
		
		virtual void setCoeficiente(double c) = 0;
		
	};
}
#endif
