//
// Created by tania on 1/12/2019.
//

#ifndef UNTITLED_PROCESOS_H
#define UNTITLED_PROCESOS_H


#include "../Aeropuerto/Vuelo.h"

typedef enum {
    EJECUTANDOSE = 0,
    INTERRUMPIDO = 1,
    EN_ESPERA = 2,
    TERMINADO
} Status;

typedef enum {
    DESPEGUE = 0,
    ATERRIZAJE = 1,
    ABORDAJE = 2,
    DESEMBARCO = 3
} Operacion;


class Procesos {
protected:
    Vuelo vueloAsignado;
    Status status;
    short tiempoAtencion;
    Operacion operacion;
    short tiempoEspera;
    short prioridad;

public:
    void calcularTiempoAtencion();
    void calcularPrioridad(time_t);
    Procesos(const Vuelo &vueloAsignado, const Operacion &operacion);
    Procesos();

    const Vuelo &getVueloAsignado() const;

    void setVueloAsignado(const Vuelo &vueloAsignado);

    Status getStatus() const;

    void setStatus(Status status);

    short getTiempoAtencion() const;

    void setTiempoAtencion(short tiempoAtencion);

    Operacion getOperacion() const;

    void setOperacion(Operacion operacion);

    short getTiempoEspera() const;

    void setTiempoEspera(short tiempoEspera);

    short getPrioridad() const;

    void setPrioridad(short prioridad);

};



#endif //UNTITLED_PROCESOS_H
