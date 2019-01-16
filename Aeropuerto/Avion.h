//
// Created by tania on 1/11/2019.
//

#ifndef UNTITLED_AVION_H
#define UNTITLED_AVION_H


#include <string>
using namespace std;

class Avion {
private:
    string modelo;
    short porcentajeCombustible;
    short cantidadPasajeros;

public:
    Avion();
    Avion(const string&, short, short);

    short getPorcentajeCombustible() const;
    void setPorcentajeCombustible(short);

    string getModelo();

    short getCantidadPasajeros() const;
    void setCantidadPasajeros(short);

    void setModelo(const string &);
};


#endif //UNTITLED_AVION_H
