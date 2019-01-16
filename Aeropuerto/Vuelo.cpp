//
// Created by tania on 1/12/2019.
//

#include "Vuelo.h"

#include <ctime>
#include <math.h>

Vuelo::Vuelo(const string& codigoVuelo, const Avion& avionVuelo, const string& horaL, const string& horaS){
    setCodigoVuelo(codigoVuelo);
    this -> avionVuelo = avionVuelo;
    this -> tiempoL = horaL;
    this -> tiempoS = horaS;
}

Vuelo::Vuelo() {}

const string & Vuelo::getCodigoVuelo() const {
    return this -> codigoVuelo;
}

void Vuelo::setCodigoVuelo(const string& codigoVuelo) {
    this -> codigoVuelo = (codigoVuelo == "") ? "Vuelo no Identificado" : codigoVuelo;
}

const Avion & Vuelo::getAvion() const {
    return this -> avionVuelo;
}

void Vuelo::setAvion(const Avion& avionVuelo){
    this -> avionVuelo = avionVuelo;
}

const string &Vuelo::getTiempoL() const {
    return tiempoL;
}

void Vuelo::setTiempoL(const string &tiempoL) {
    Vuelo::tiempoL = tiempoL;
}

const string &Vuelo::getTiempoS() const {
    return tiempoS;
}

void Vuelo::setTiempoS(const string &tiempoS) {
    Vuelo::tiempoS = tiempoS;
}



Vuelo::StringVector Explode(const std::string & str, char separator )
{
    Vuelo::StringVector  result;
    size_t pos1 = 0;
    size_t pos2 = 0;
    while ( pos2 != str.npos )
    {
        pos2 = str.find(separator, pos1);
        if ( pos2 != str.npos )
        {
            if ( pos2 > pos1 )
                result.push_back( str.substr(pos1, pos2-pos1) );
            pos1 = pos2+1;
        }
    }
    result.push_back( str.substr(pos1, str.size()-pos1) );
    return result;
}

int* Vuelo::calcularDiferenciaHoras(time_t times) {
    tm formattedTime = *localtime(&times);
    StringVector horaL = Explode(this->tiempoL,':');

    int hora = atoi(horaL[0].c_str()),

    min = atoi(horaL[1].c_str()),

    minutosCompletos = hora*60 + min,
    minutosCompletosAhora = formattedTime.tm_hour*60+formattedTime.tm_min;

    int diferencia = minutosCompletos-minutosCompletosAhora;

    int result[2];
    result[0] = (int)floor(diferencia/60);
    result[1] = diferencia % 60;

    return result;
}