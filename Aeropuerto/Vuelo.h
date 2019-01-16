//
// Created by tania on 1/12/2019.
//

#ifndef UNTITLED_VUELO_H
#define UNTITLED_VUELO_H


#include "Avion.h"
#include <vector>

class Vuelo {
protected:
    string codigoVuelo;
    Avion avionVuelo;
    string tiempoL;
    string tiempoS;

public:
    typedef std::vector<std::string>  StringVector;
    Vuelo();
    Vuelo(const string&, const Avion&, const string&, const string&);

    const string & getCodigoVuelo() const;
    void setCodigoVuelo(const string&);

    const Avion & getAvion() const;
    void setAvion(const Avion&);

    const string &getTiempoL() const;

    void setTiempoL(const string&);

    const string &getTiempoS() const;

    void setTiempoS(const string &);

    int* calcularDiferenciaHoras(time_t);

    static StringVector Explode(const std::string & str, char separator);
};


#endif //UNTITLED_VUELO_H
