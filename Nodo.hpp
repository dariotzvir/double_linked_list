//
// Created by dario on 9/10/22.
//

#ifndef INFO_NODO_HPP
#define INFO_NODO_HPP

#include <memory>
#include <iostream>

template <class T>
class Nodo
{
    std::shared_ptr<Nodo<T>> _ant;
    T _var;
    std::shared_ptr<Nodo<T>> _sig;
public:
    Nodo();
    Nodo(const T &var);
    ~Nodo(){std::cout << "Desctructor: " << _var << "\n";};

    void set(const T &var);
    void set_ant(std::shared_ptr<Nodo<T>> ant);
    void set_sig(std::shared_ptr<Nodo<T>> sig);

    T &get();
    std::shared_ptr<Nodo<T>> get_ant();
    std::shared_ptr<Nodo<T>> get_sig();
};

template<class T>
Nodo<T>::Nodo()
{
    _ant = nullptr;
    _sig = nullptr;
}

template<class T>
Nodo<T>::Nodo(const T &var)
{
    _ant = nullptr;
    _var = var;
    _sig = nullptr;
}

template<class T>
void Nodo<T>::set(const T &var)
{
    _var = var;
}

template<class T>
void Nodo<T>::set_ant(std::shared_ptr<Nodo<T>> ant)
{
    _ant = ant;
}

template<class T>
void Nodo<T>::set_sig(std::shared_ptr<Nodo<T>> sig)
{
    _sig = sig;
}

template<class T>
T &Nodo<T>::get()
{
    return _var;
}

template<class T>
std::shared_ptr<Nodo<T>> Nodo<T>::get_ant()
{
    return _ant;
}

template<class T>
std::shared_ptr<Nodo<T>> Nodo<T>::get_sig()
{
    return _sig;
}
#endif //INFO_NODO_HPP
