//
// Created by tania on 1/12/2019.
//

#include "Procesos.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>

Procesos::Procesos(){}
Procesos::Procesos(const Vuelo &vueloAsignado, const Operacion &operacion) {
    this -> vueloAsignado = vueloAsignado;
    this ->status = EN_ESPERA;
    this -> operacion = operacion;
}

void Procesos::calcularTiempoAtencion() {
    srand(time(NULL));
    int random;
    switch (this -> operacion){
        case DESPEGUE:
            random = 5 + rand() % (8-1);
            this ->tiempoAtencion = (short)random;
            break;
        case ATERRIZAJE:
            random = 1 + rand() % (4 - 1);
            this->tiempoAtencion = (short) random;
            break;
        case ABORDAJE:
            this ->tiempoAtencion = (short)(this->vueloAsignado.getAvion().getCantidadPasajeros()*.005);
            break;
        case DESEMBARCO:
            this ->tiempoAtencion = (short)(this->vueloAsignado.getAvion().getCantidadPasajeros()*.005);
            break;
    }
}


void Procesos::calcularPrioridad(time_t times){
    switch (this->operacion){
        case DESPEGUE:
        case ABORDAJE:{
            int * horas = this->vueloAsignado.calcularDiferenciaHoras(times);
            if(horas[0]==0 && horas[1]<=59){
                this->prioridad = 0;
            }else if (horas[0]>=1 && horas[0]<=3){
                this->prioridad = 1;
            } else if (horas[0]>3 && horas[0]<=7){
                this->prioridad = 2;
            }else if(horas[0]>7 && horas[0]<=15){
                this->prioridad = 3;
            }else if(horas[0]>15 && horas[0]<=23){
                this->prioridad = 4;
            }else{
                cout << "Solo se tomaran en cuenta las primeras 24 horas" << endl;
            }
            break;
        }
        case ATERRIZAJE:
            if(this->vueloAsignado.getAvion().getPorcentajeCombustible()<=20){
                this->prioridad = 0;
            }else if(this->vueloAsignado.getAvion().getPorcentajeCombustible()>20 &&this->vueloAsignado.getAvion().getPorcentajeCombustible()<=50){
                this->prioridad = 1;
            }else if(this->vueloAsignado.getAvion().getPorcentajeCombustible()>50 &&this->vueloAsignado.getAvion().getPorcentajeCombustible()<=80){
                this->prioridad = 2;
            } else
                this->prioridad = 3;
            break;
        case DESEMBARCO:
            break;
    }
}

const Vuelo &Procesos::getVueloAsignado() const {
    return vueloAsignado;
}

void Procesos::setVueloAsignado(const Vuelo &vueloAsignado) {
    Procesos::vueloAsignado = vueloAsignado;
}

Status Procesos::getStatus() const {
    return status;
}

void Procesos::setStatus(Status status) {
    Procesos::status = status;
}

short Procesos::getTiempoAtencion() const {
    return tiempoAtencion;
}

void Procesos::setTiempoAtencion(short tiempoAtencion) {
    Procesos::tiempoAtencion = tiempoAtencion;
}

Operacion Procesos::getOperacion() const {
    return operacion;
}

void Procesos::setOperacion(Operacion operacion) {
    Procesos::operacion = operacion;
}

short Procesos::getTiempoEspera() const {
    return tiempoEspera;
}

void Procesos::setTiempoEspera(short tiempoEspera) {
    Procesos::tiempoEspera = tiempoEspera;
}

short Procesos::getPrioridad() const {
    return prioridad;
}

void Procesos::setPrioridad(short prioridad) {
    Procesos::prioridad = prioridad;
}
