//
// Created by dario on 9/11/22.
//

#ifndef INFO_LISTA_HPP
#define INFO_LISTA_HPP

#include <memory>
#include <iostream>
#include <algorithm>

#include "Nodo.hpp"

template<class T>
class Lista
{
    const uint64_t _largo_max;
    uint64_t  _largo;
    std::shared_ptr<Nodo<T>> _inicio;

    std::shared_ptr<Nodo<T>> buscar_nodo (uint64_t n);
    std::shared_ptr<Nodo<T>> buscar_nodo (std::shared_ptr<Nodo<T>> ptr, uint64_t n);

public:
    std::shared_ptr<Nodo<T>> borrar_hasta(std::shared_ptr<Nodo<T>> ptr, uint64_t n);
    explicit Lista(uint64_t largo_max = UINT_LEAST64_MAX):
    _largo_max(largo_max), _inicio(new Nodo<T>)
    {
        _largo = 0;
        _inicio->set_ant(nullptr);
        _inicio->set_sig(nullptr);
    }
    ~Lista();

    void insertar(const T &item , int64_t n = -1);
    T    eliminar(int64_t n);
    uint64_t size();

    T&  operator[](int64_t n);
    Lista<T>& operator=(const Lista<T> &lista_2);
};

template<class T>
std::shared_ptr<Nodo<T>> Lista<T>::buscar_nodo(const uint64_t n)
{
    if(_inicio == nullptr || n >= _largo) return nullptr;
    else return buscar_nodo(_inicio->get_sig(), n);
}

template<class T>
std::shared_ptr<Nodo<T>> Lista<T>::buscar_nodo(std::shared_ptr<Nodo<T>> ptr, const uint64_t n)
{
    if(ptr == nullptr) return nullptr;
    if(n == 0) return ptr;
    else return buscar_nodo(ptr->get_sig(), n-1);
}

template<class T>
std::shared_ptr<Nodo<T>> Lista<T>::borrar_hasta(std::shared_ptr<Nodo<T>> ptr, const uint64_t n)
{
    if(ptr == nullptr) return nullptr;
    if(n == 0) return ptr->get_sig();
    else
    {
        auto aux = ptr->get_sig();
        ptr->set_sig(nullptr);
        return borrar_hasta(aux, n-1);
    }
}

template<class T>
Lista<T>::~Lista()
{
    borrar_hasta(_inicio, _largo);
    _largo = 0;
}

template<class T>
void Lista<T>::insertar(const T &item, int64_t n)
{
    if(_largo_max != -1 && _largo >= _largo_max) return;
    if(n < 0) n += _largo + 1;

    if(n >= 0 && n <= _largo)
    {
        std::cout << "Agregando nodo en: " << n << " Valor: " << item << "\n";
        auto ant = n!=0 ? buscar_nodo(n-1) : _inicio;
        std::shared_ptr<Nodo<T>> nuevo(new Nodo<T>(item));
        auto sig = buscar_nodo(n);
        if(ant != nullptr)
        {
            nuevo->set_ant(ant);
            ant->set_sig(nuevo);
        }
        else nuevo->set_ant(nullptr);
        if(sig != nullptr)
        {
            nuevo->set_sig(sig);
            sig->set_ant(nuevo);
        }
        else nuevo->set_sig(nullptr);

        _largo ++;
    }
}

template<class T>
T Lista<T>::eliminar(int64_t n)
{
    if(_largo == 0) return _inicio->get();
    if(n < 0) n += _largo;

    if(n >= 0 && n < _largo)
    {
        std::cout << "Removiendo nodo en: " << n << "\n";
        auto ant  = n!=0 ? buscar_nodo(n-1) : _inicio;
        auto nodo = buscar_nodo(n);
        auto sig  = buscar_nodo(n+1);
        if(ant != nullptr) ant->set_sig(sig);
        if(sig != nullptr) sig->set_ant(ant);

        _largo--;
        return nodo->get();
    }

    return _inicio->get();
}
template<class T>
uint64_t Lista<T>::size()
{
    return _largo;
}

template<class T>
T& Lista<T>::operator[](int64_t n)
{
    if(n < 0) n += _largo;

    if(0 <= n && n < _largo)
    {
        auto nodo = buscar_nodo(n);
        if(nodo == nullptr)
        {
            std::cout << "null\n";
            return _inicio->get();
        }

        return nodo->get();
    }

    return _inicio->get();
}

template<class T>
Lista<T>& Lista<T>::operator=(const Lista<T> &lista_2)
{
    std::cout << "xd\n";
}

#endif //INFO_LISTA_HPP
