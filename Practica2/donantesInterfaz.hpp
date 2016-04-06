#ifndef DONANTESINTERFAZ_HPP
#define DONANTESINTERFAZ_HPP

using std::string;

namespace ed{

class DonantesInterfaz{

public:
    virtual bool getDonantes()const = 0;

    virtual list<Donante> getDonante()const = 0;

    virtual void insertarDonante()= 0;

    virtual void borrarDonante() = 0;

};
}
#endif
