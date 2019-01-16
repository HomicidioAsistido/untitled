//
// Created by tania on 1/13/2019.
//

#ifndef UNTITLED_PLANIFICACION_H
#define UNTITLED_PLANIFICACION_H


#include "Procesos.h"
#include <list>

class Planificacion {
private:
    list<Procesos> procesosDespegue;
    list<Procesos> procesosAterrizaje;
    list<Procesos> procesosAbordaje;
    list<Procesos> procesosDesembarco;

public:
    void crearVuelo(Operacion,const string&, short , short, const string&, const string&, const string&);
    bool compare(Procesos procesoA, Procesos procesoB);

    void ejecutandoDespegue();

    void ejecutandoAterrizaje();


};


#endif //UNTITLED_PLANIFICACION_H
