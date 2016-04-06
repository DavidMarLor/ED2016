#ifndef LISTADOBLEENLAZADA_HPP
#define LISTADOBLEENLAZADA_HPP

#include <stdlib.h>

using namespace std;

namespace ed{
  template <class T>
    class ListaEnlazada{

    private:
      LinkedNode<T> *_cabeza;
      LinkedNode<T> *_actual;

    public:
      ListaEnlazada()
        {
          _cabeza=NULL;
          _actual=NULL;
        }

      const LinkedNode<T> * cabezaConst() const
        {
          return _cabeza;
        }

      LinkedNode<T> *cabeza()
        {
          return _cabeza;
        }

      void setCabezaP(LinkedNote<T> *newV)
        {
            _cabeza=newV;
        }

      const LinkedNode<T> * actualConst() const
        {
          return _actual;
        }

      LinkedNode<T> *actual()
        {
          return _actual;
        }

      void setActual(LinkedNode<T> *newV)
        {
          _actual = newV;
        }

      bool isEmpty() const
        {
          if(_cabeza==NULL)
                  return 1;
          else
                  return 0;
        }

      void goTO(const unsigned idx)
        {
          setActual(cabeza());

                for(unsigned i=0; i<idx && _actual != 0; i++)
                  {
                    setActual(actual()->next());
                  }
        }

      bool isValid (const int pos) const
        {
              ListaEnlazada<T> * _this = const_cast<ListaEnlazada<T>*>(this);
              LinkedNode<T> * savedActual=_this->actual();
              _this->goTo(pos);
              bool retVal;
              if(_this->actual()!=0)
                    retVal=1;
              else
                    retVal=0;
            _this->setActual(savedActual);
            return retVal;
        }

      bool isLast(const int pos) const
      {
        assert(isValid(pos));

        ListaEnlazada<T> * _this = const_cast<ListaEnlazada<T>*>(this);
        LinkedNode<T> * savedActual=_this->actual();
        _this->goTo(pos);
        bool retVal=0;
        if(_this->actual()->next()==0)
            retVal=1;
        _this->setActual(savedActual);
        return retVal;
      }

      const T& item(const int pos) const
      {
        assert(isValid(pos));
        ListaEnlazada<T> * _this = const_cast<ListaEnlazada<T>*>(this);
        LinkedNode<T> * savedActual=_this->actual();
        _this->goTo(pos);
        const T& retVal=_this->actual()->item();
        _this->setActual(savedActual);
        return retVal;
      }

      void flush()
        {
          LinkedNode<T> *aux;
          setActual(cabeza());
          while(this->actual()!=0)
            {
             setActual(actual()->next());
             aux=actual()->previous();
             actual()->setPrevious(NULL);
             free(aux);
            }
            setCabeza(0);
        }

        void deletePosition(const int pos)
        {
            assert(isValid(pos));
            bool oldIsLast = isLast(pos);
            T oldItemNext = T();
            if(not oldIsLast)
                oldItemNext = item(pos+1);
            goTo(pos);
            LinkedNode<T> * old = actual();
            if(this->actual()->previous()==0){
                setCabeza(actual()->next());
                actual()->next()->setPrevious(0);
            }
            else{
              this->actual()->previous()->setNext(actual()->next());
              this->actual()->next()->setPrevious(actual()->previous());
            }
            assert(old==actual());
            delete old;
            assert(oldIsLast or item(pos)==oldItemNext);
        }

        int findItem(const T& it, const int from=0)const
          {
                assert(isValid(from));
                int retVal=-1;
                ListaEnlazada<T> * _this = const_cast<ListaEnlazada<T>*>(this);
                LinkedNode<T> * savedActual=_this->actual();
                _this->goTo(from);
                for(int i=from; retVal==-1 && _this->actual()!=0; i++)
                    if(_this->actual()->item() == it)
                        retVal = i;
                    else
                        _this->setActual(_this->actual()->next());
                _this->setActual(savedActual);
                assert(not (retVal==-1) || isValid(retVal));
                assert(not (retVal==-1) || item(retVall)==it);
                return retVal;
          }


        void insertar(const T& it)
          {
            int lugar = 0;
            if(this->isEmpty())
              {
                setHead(new ListaEnlazada<T>(it,0,00));
              }
            else
              {
                LinkedNode<T> * ptr=cabeza();
                LinkedNode<T> * aux=NULL;
                    while(lugar==0)
                      {
                        if(if < cabeza()->item())
                          {
                            LinkedNode<T> * p=new LinkedNode<T>(itr,ptr,0);
                            ptr->setPrevious(p);
                            setCabeza(p);
                            lugar=1;
                          }

                          else if(ptr->next()==NULL)
                            {
                              prt->setNext(new LinkedNode<T>(it,0,ptr));
                              lugar=1;
                            }
                          if(ptr->item() < it && it < ptr->()->item())
                            {
                              aux=ptr->next();
                              LinkedNode<T> * p=new LinkedNode<T>(it,aux,ptr);
                              ptr->next()->setPrevious(p);
                              ptr->setNext(p);
                              lugar=1;
                            }
                            else{
                              aux=ptr->next();
                              ptr=aux;
                              }
                            }
                      }
              }
          }
    };
}
#endif
