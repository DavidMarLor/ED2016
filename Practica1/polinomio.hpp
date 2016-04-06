/* \par Fichero: polinomio.hpp
	Polinomio representa a la clase Polinomio
   \author David Martinez Lora
   \date 17-Marzo-2016
*/
#ifndef POLINOMIO_HPP
#define POLINOMIO_HPP

#include <iostream>
#include <vector>//Para poder usar el vector de la stl
#include "polinomioInterfaz.hpp"
#include "monomio.hpp"
#include "monomioInterfaz.hpp"

using namespace std;

namespace ed{
//! Clase Polinomio
class Polinomio:public ed::PolinomioInterfaz
	{
		//! \name Atributos privados de Polinomio
		private:
			vector<Monomio> _polinomio;//!< vector de polinomios
  			int _grado;//!<grado del polinomio
  			int _nterminos;//!numero de terminos
		//! \name Metodos publicos de Polinomio
		public:

  			//Observadores
  			/*!
				\brief Devuelve el grado del polinomio
				\return Grado del polinomio
				\pre El polinomio debe existir
				\post Ninguna
			*/
 		 	int getGrado()const
				{
    					return _grado;
  				}
			/*!
				\brief Devuelve el numero de terminos del polinomio
				\return Numero de terminos del polinomio
				\pre El polinomio debe existir
				\post Ninguna
			*/
			int getTerminos()const
				{
    					return _nterminos;
  				}
			/*!
				\brief Devuelve el polinomio
				\return El polinomio
				\pre El polinomio debe existir
				\post Ninguna
			*/
			vector<Monomio> getPolinomio()const
				{
  					return _polinomio;
  				}
			/*!
				\brief Devuelve si el vector esta vacio
				\return un booleano
				\pre El polinomio debe existir
				\post Ninguna
			*/
			bool estaVacio() const
				{
					return _polinomio.empty();
				}
			
			Monomio getMonomioDelVector(const int i)const
				{
   					return _polinomio[i];
  				}
			
			//Modificadores
			/*!
				\brief Asigna un valor "grado" al polinomio
				\param g int pasado por referencia constante
				\pre El polinomio debe existir
				\post Ninguna
			*/
			void setGrado(const int g)
				{
    					_grado=g;
  				}
  			/*!
				\brief Asigna el numero de termino que compondra polinomio
				\param nt int pasado por referencia constante
				\pre El polinomio debe existir
				\post Ninguna
			*/
			void setTerminos(const int nt)
				{
   					 _nterminos=nt;
  				}
			/*!
				\brief Asigna un monomio al vector de Polinomios
				\param p constante
				\pre El polinomio debe existir
				\post Ninguna
			*/
			void setPolinomio(const vector<Monomio> &p)
				{
   					 Monomio aux;
   					 for (int i = 0; i < p.size(); i++) 
						{
      							aux=p[i];
      							_polinomio.push_back(aux);
    						}
  				}

			//Constructor por Defecto
			/*!
				\brief Constructor desde grado y numero de terminos y polinomio.
				\attention Funcion de sobrecarga
				\param g int,valor por defecto 0
				\param nt int, valor por defecto 0
				\param n int, valor por defecto 0
				\pre Ninguna
				\post Ninguna
			*/
			Polinomio(int g=0, int nt=1, int n=0)
				{
   					setGrado(g);
    					setTerminos(nt);
    					_polinomio.resize(n);
  				}

  			//Constructor de Copia
  			/*!
				\brief Constructor de copia
				\attention Funcion de sobrecarga
				\param p Polinomio, Polinomio pasado por referencia
				\pre Ninguna
				\post Ninguna
			*/
			Polinomio(Polinomio const &p)
				{
    			   		setGrado(p.getGrado());
    				    	setTerminos(p.getTerminos());
    			   		setPolinomio(p.getPolinomio());
				}

			//Funcion para leer el Polinomio
			/*! 
				\brief Lee por pantalla un Polinomio
				\pre Ninguna
				\post Ninguna
			*/	
   			void leerPolinomio()
  				{
  					vector <Monomio> vector;
  					Monomio m;
  					int grado, monomios;
  					

  					cout<<"Numero de terminos"<<endl;
  					cin>>monomios;
  					setTerminos(monomios);
  					for(int i = 0; i < monomios; i++)
						{
  							m.leerMonomio();
    						if (m.getCoeficiente() != 							0){
      						vector.push_back(m);
    							}
  						}
  					for(int j=0; j<monomios;j++)
  						{
  						cout<<"vector: "<< vector[j].getGrado()<<endl;
  						cout<<"vector: "<< vector[j].getCoeficiente()<<endl;
  						}
  				}

    			//Funcion para imprimir un polinomio
    			/*! 
				\brief Escribe por pantalla un Polinomio
				\pre Ninguna
				\post Ninguna
			*/	
    			void escribirPolinomio()
  				{
    					vector<Monomio> v;
    					v=getPolinomio();
    					for (int i = 0; i < getTerminos(); i++)
    						{
    							cout<<v[i].getCoeficiente()<<"x^"<<v[i].getGrado()<<" + "<<std::endl;
    						}
  	
  				}

			//Funciones Friend
			/*! 
				\brief Recopila la información necesaria de un Polinomio
				\param stream de tipo istream
				\param p de tipo Polinomio
				\attention Función sobrecargada 
				\attention Función friend      
				\return stream
				\pre Ninguna
				\post Ninguna
			*/	
			  friend istream & operator >>(istream &stream, Polinomio &p)
				{
					int t;
					double c;
					int g;
					vector <Monomio> m;
					
					cout<<"Numero de terminos:"<<endl;
  					stream >> t;
  					for (int i = 0; i < t; i++)
						{
  							cout <<"Grado del polinomio "<<endl;
  							stream >> g;
  							m[i].setGrado(g);
							cout <<"Coeficiente del polinomio "<<endl;
  							stream >> c;
  							m[i].setCoeficiente(c);
  						}
  					
	
					p.setTerminos(m.size());
					p.setPolinomio(m);

	
					return stream;	
					
					
				}
			/*! 
				\brief Devuelve y muestra por pantalla la información de un Polinomio
				\param o de tipo ostream
				\param p de tipo Polinomio
				\attention Función sobrecargada 
				\attention Función friend      
				\return o
				\pre Ninguna
				\post Ninguna
			*/	
  			friend ostream & operator <<(ostream &o, Polinomio &p)
				{

					Monomio m;
					int c,g;
					int i;
					vector <Monomio> v;
					v=p.getPolinomio();
					int tam=p.getTerminos();
	
					cout << "El polinomio es: ";
	
					for(i=0;i<tam;i++)
					{
		
					c=v[i].getCoeficiente();
					g=v[i].getGrado();
		
					m.setCoeficiente(c);
					m.setGrado(g);
		
					if(tam==1)
						o << m;
					else{	
						tam--;
						o << m << " + ";
						}
		
					}
					o << endl;

					return o;
				}
			
		//Operadores
			/*! 
				\brief Iguala un Polinomio a otro, teniendo los dos las mismos valores 
				\param p de tipo Polinomio pasado como referencia constante
				\attention Función sobrecargada        
				\return Un Polinomio
				\pre El Polinomio debe existir
				\post Ninguna
			*/	
			Polinomio& operator=(Polinomio const &p)
				{
     					this->setGrado(p.getGrado());
      					this->setTerminos(p.getTerminos());
      					this->setPolinomio(p.getPolinomio());
      				return *this;
  				}
		/*! 
			\brief Se suman dos polinomios y se devuelve un Polinomio resultado 
			\param p de tipo Polinomio pasado como referencia constante
			\attention Función sobrecargada        
			\return Un Polinomio resultado de la suma
			\pre El Polinomio debe existir
			\post Ninguna
		*/
		Polinomio operator+(Polinomio const &p)
				{

					int i;	
					Polinomio s;
					vector<Monomio> suma;
      					vector<Monomio> aux;				

					for (i= 0; i<getTerminos(); i++)
						{
       					 		aux.push_back(getMonomioDelVector(i));
     						}

     					 for (i= 0; i<getTerminos(); i++)
						{
        						aux.push_back(p.getMonomioDelVector(i));
      						}

					suma = sumaAuxiliar(aux);
      					s.setPolinomio(suma);
      					s.setTerminos(suma.size());
      					return s;
					
				}
			/*! 
				\brief Se suma un elemento del polinomio con aquellos elementos que tengan el mismo grado dentro del polinomio
				\param p de tipo Monomio pasado como referencia constante     
				\return Un Polinomio resultado de la suma
				\pre El Polinomio y el Monomio debe existir
				\post Ninguna
			*/
			vector<Monomio> sumaAuxiliar(vector<Monomio> &p)
				{
					vector <Monomio> suma;
       					Monomio msuma;
        				double aux;
        				int i = 0;
       					
					do{
          					aux = p[i].getCoeficiente();
          					for (int j = i+1; j < p.size(); j++)
							{
           							if (p[i].getGrado() == p[j].getGrado())
									{
              									aux = aux + p[j].getCoeficiente();
              									p[j].setGrado(0);
              									p[j].setCoeficiente(0);
            								}
          						}

          					msuma.setGrado(p[i].getGrado());
          					msuma.setCoeficiente(aux);
          					suma.push_back(msuma);

          					i++;
        					}while (i < p.size());

        				for (i = 0; i < suma.size(); i++)
        					{
          						if (suma[i].getCoeficiente()==0)
          							{
           								suma.erase(suma.begin()+i);
            								i--;
          							}
        					}
        				return suma;
				}

			
 			/*! 
				\brief Se multiplican dos polinomios y se devuelve un Polinomio resultado 
				\param p de tipo Polinomio pasado como referencia constante
				\attention Función sobrecargada        
				\return Un Polinomio resultado de la multiplicación
				\pre El Polinomio debe existir
				\post Ninguna
			*/	
			Polinomio operator * (Polinomio const &p)
			{
       				Polinomio p2;
        			Monomio aux;
				vector<Monomio> auxV;
				vector<Monomio> resultado;

       					 for (int i = 0; i < getTerminos(); i++)
        					{
          						for (int j=0; j< p.getTerminos(); j++)
          							{
            							aux=getMonomioDelVector(i) * p.getMonomioDelVector(j);
            							auxV.push_back(aux);
          							}
        					}
        				resultado=sumaAuxiliar(auxV);
        				p2.setPolinomio(resultado);
        				p2.setTerminos(resultado.size());
        				return p2;
      					}
      					
      			/*! 
				\brief Calcula el valor númerico de un Polinomio
				\param x de tipo double
				\return El valor double del Polinomio
				\pre El Polinomio debe existir
				\post Ninguna
			*/			
			double darValorXP(double &x)
   				 {
					double aux=0;
      					Monomio monomio;
      						for (int i=0; i< getTerminos(); i++)
							{
        							monomio = getMonomioDelVector(i);
        							aux += monomio.devolverValor(x);
      							}

      					return aux;
    				}


};
}
#endif
