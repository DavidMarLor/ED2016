#ifndef DONANTEINTERFAZ_HPP
#define DONANTEINTERFAZ_HPP

#include <iostream>
#include <cstring>
#include <cstdlib>

using std::string;

namespace ed{
  class DonanteInterfaz{
  public:
      virtual void setNombre(string nombre) = 0;

      virtual void setApellidos(string apellidos) = 0;

      virtual void setGrupoSanguineo(string grupoSanguineo) = 0;

      virtual void setRH(string rh) = 0;

      virtual string getNombre()const = 0;

      virtual string getApellidos()const = 0;

      virtual string getGrupoSanguineo()const = 0;

      virtual string getRH()const = 0;
  };
}

#endif
      
