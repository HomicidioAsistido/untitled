//
// Created by tania on 1/11/2019.
//

#include "Avion.h"
Avion::Avion(){}

Avion::Avion(const string& modelo, short porcentajeCombustible, short cantidadPasajeros) {
    this -> modelo = modelo;
    this -> porcentajeCombustible = porcentajeCombustible;
    this -> cantidadPasajeros = cantidadPasajeros;
}

void Avion::setModelo(const string &modelo) {
    Avion::modelo = modelo;
}

string Avion::getModelo() {
    return this ->modelo = modelo;
}

short Avion::getCantidadPasajeros() const {
    return this -> cantidadPasajeros;
}

void Avion::setCantidadPasajeros(short cantidadPasajeros) {
    this -> cantidadPasajeros = cantidadPasajeros;
}

short Avion::getPorcentajeCombustible() const {
    return this -> porcentajeCombustible;
}

void Avion::setPorcentajeCombustible(short porcentajeCombustible) {
    this -> porcentajeCombustible = porcentajeCombustible;
}


