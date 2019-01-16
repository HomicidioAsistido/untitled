//
// Created by tania on 1/13/2019.
//

#include "Planificacion.h"
#include "../Aeropuerto/Vuelo.h"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cmath>

using namespace std;
/*
 * for (i=1; i<TAM; i++)
    2.      for j=0 ; j<TAM - 1; j++)
    3.           if (lista[j] > lista[j+1])
    4.                temp = lista[j];
    5.                lista[j] = lista[j+1];
    6.                lista[j+1] = temp;
 */

void Planificacion::crearVuelo(Operacion operacion, const string &nombreAvion, short porcentaje, short cantidadPasajeros,
        const string &nombreVuelo, const string &horaL, const string &horaS) {

    Procesos proceso;
    proceso.setVueloAsignado(Vuelo(nombreVuelo,Avion(nombreAvion,porcentaje,cantidadPasajeros),horaL,horaS));
    proceso.setOperacion(operacion);
    switch (operacion){
        case DESPEGUE:
            this->procesosDespegue.push_back(proceso);
            break;
        case ATERRIZAJE:
            this->procesosAterrizaje.push_back(proceso);
            break;
        case ABORDAJE:
            this->procesosAbordaje.push_back(proceso);
            break;
        case DESEMBARCO:
            this->procesosDesembarco.push_back(proceso);
            break;
    }
}

bool Planificacion::compare(Procesos procesoA, Procesos procesoB) {
    Operacion op = procesoA.getOperacion();
    if(procesoA.getPrioridad() < procesoB.getPrioridad()){
        return true;
    }else if(procesoB.getPrioridad() < procesoA.getPrioridad()){
        return false;
    } else{

    }

    if(op==DESPEGUE){
        Vuelo::StringVector str1 = Vuelo::Explode(procesoA.getVueloAsignado().getTiempoL(),':');
        Vuelo::StringVector str2 = Vuelo::Explode(procesoB.getVueloAsignado().getTiempoL(),':');
        time_t now;
        now = time(NULL);
        tm formatted = *localtime(&now);
        int horaA = atoi(str1[0].c_str()), minA = atoi(str1[1].c_str()), horaB = atoi(str2[0].c_str()), minB = atoi(str2[1].c_str());
        int horaCompA = horaA*60+minA, horaCompB = horaB*60+minB;
        if((formatted.tm_hour==horaA && formatted.tm_min==minA) && ())

    }
    return false;
}


