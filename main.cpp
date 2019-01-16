// wxWidgets "Hello World" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <iostream>
#include <ctime>
#include "ClasesBases/File.h"
#include "Aeropuerto/Vuelo.h"
#include "ClasesBases/Planificacion.h"


int main(){
    /*time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    cout << asctime (timeinfo)<<  endl;
    string cadena = asctime (timeinfo);
    cout << cadena;
    getchar();*/

    Planificacion planificacion;
    planificacion.crearVuelo(DESPEGUE,"Airbus 320",30,288,"LA333N","11:30","12:30");

    planificacion.crearVuelo(DESPEGUE,"Boeing 319",30,288,"LE339N","09:30","20:30");
    for(vector<Procesos, std::allocator<Procesos>>::const_iterator it = planificacion.getProcesosDespegue().begin(); it != planificacion.getProcesosDespegue().end(); ++it){
        cout << it.base()->getVueloAsignado().getCodigoVuelo() << endl;
    }
    planificacion.ejecutandoDespegue();
    for(vector<Procesos, std::allocator<Procesos>>::const_iterator it = planificacion.getProcesosDespegue().begin(); it != planificacion.getProcesosDespegue().end(); ++it){
        cout << it.base()->getVueloAsignado().getCodigoVuelo() << endl;
    }

    return 0;
}

/*void procesos::rnm(){
    auxiden = 0;
    auxfin = 0;
    auxcuenta = 0;
    auxpri = 0;
    auxnivel = 0;
    cambio = 0;

    fprintf(textfile, ”%s\n”, ”************************************************************”);
    fprintf(textfile, ”%s”, ”Simulación RNM con ”);
    fprintf(textfile, ”%i”, cc);
    fprintf(textfile, ”%s\n”, ” ciclos de control.”);

    cout <<”\n”;
    cout <<”Secuencia de selección de procesos para su ejecución según RNM:”;
    cout <<”\n”;
    cout <<”**************************************************************”;
    cout <<”\n”;
    cout <<”Los procesos son atendidos según su nivel en la lista de procesos listos;\n”;
    cout <<”pero disponen de un tiempo limitado (cuantum) del procesador;\n”;
    cout <<”si son interrumpidos por entrada / salida permanecen en la subcola\n”;
    cout <<”del nivel donde están, pero si son interrumpidos por tiempo pasan a\n”;
    cout <<”un nivel superior, que es atendido cuando ya no hay procesos listos\n”;
    cout <<”en los niveles inferiores; de allí el nombre de\n”;
    cout <<”Retroalimentación de Niveles Múltiples:”;
    cout <<”\n” <<”\n”;

    for (register int j=0; j<cc; j++) // ***Realiza ’cc’ ciclos de control***
    {
        auxfin = 0;
        for (register int m=0; m<np; m++)
        {
            if (p[m].fin != 2)
            {
                auxfin = 1;
                m = np;
            }
        }
        if (auxfin == 0)
        {
            cout <<”\n”<< ”Todos los procesos han finalizado en ”<< j << ” ciclos de control.\n”;

            fprintf(textfile, ”%s”, ”Todos los procesos han finalizado en ”);
            fprintf(textfile, ”%i”, j);
            fprintf(textfile, ”%s\n”, ” ciclos de control.”);
            j = cc;
            auxfin = getch();
        }
        if (auxpri == 1)
        {
            for (register int s=0; s<np; s++)
            {
                for (register int t=s; t<(np - 1); t++)
                {
                    if (p[t+1].nivel < p[t].nivel)
                    {
                        auxiden = p[t].identif;
                        auxfin = p[t].fin;
                        auxcuenta = p[t].cuenta;
                        auxpri = p[t].pri;
                        auxnivel = p[t].nivel;
                        p[t].identif = p[t+1].identif;
                        p[t].fin = p[t+1].fin;
                        p[t].cuenta = p[t+1].cuenta;
                        p[t].pri = p[t+1].pri;
                        p[t].nivel = p[t+1].nivel;
                        p[t+1].identif = auxiden;
                        p[t+1].fin = auxfin;
                        p[t+1].cuenta = auxcuenta;
                        p[t+1].pri = auxpri;
                        p[t+1].nivel = auxnivel;
                    }
                }
            }
        }
        for (register int i=0; i<np; i++)
        {
            if (p[i].fin == 0)
            {
                auxpri = 0;
                cout <<”Procesador asignado al proceso: ”<< p[i].identif;
                cout <<”\n”;
                p[i].cuenta = p[i].cuenta + 1;
                p[i].fin = int(random(4)); // Determina próximo estado del proceso.
                // cout <<”\n” <<p[i].identif <<p[i].fin <<p[i].nivel <<”\n”;
                if (p[i].fin == 0) p[i].fin = 3;
                if (p[i].fin == 1)
                    cout <<”Proceso ”’ <<p[i].identif <<”’ interrumpido por entrada / salida. ”<< ”\n”;
                else {
                    if (p[i].fin == 2)
                        cout <<”Proceso ”’ <<p[i].identif <<”’ finalizado. ”<< ”\n”;
                    else {
                        if (p[i].fin == 3)
                            cout <<”Proceso ”’ <<p[i].identif <<”’ interrumpido por tiempo. ”<< ”\n”;
                        p[i].nivel = p[i].nivel + 1;
                    }
                }
                if (p[i].fin > 0)
                { // Intercambio de contexto.
                    cambio = cambio + 1;
                    auxiden = p[i].identif;
                    auxfin = p[i].fin;
                    auxcuenta = p[i].cuenta;
                    auxpri = p[i].pri;
                    auxnivel = p[i].nivel;
                    for (register int k=i; k<(np - 1); k++)
                    {
                        p[k].identif = p[k+1].identif;
                        p[k].fin = p[k+1].fin;
                        p[k].cuenta = p[k+1].cuenta;
                        p[k].pri = p[k+1].pri;
                        p[k].nivel = p[k+1].nivel;
                    }
                    p[(np - 1)].identif = auxiden;
                    p[(np - 1)].fin = auxfin;
                    p[(np - 1)].cuenta = auxcuenta;
                    p[(np - 1)].pri = auxpri;
                    p[(np - 1)].nivel = auxnivel;
                    auxpri = 1; // Indica que hubo intercambio de contexto y debe reordenarse la lista de procesos según prioridades.
                }
                i = np;
                auxfin = getch();
            }
            for (register int k=0; k<np; k++) // Determina si continúa la espera por entrada /salida.
            {
                if (p[k].fin == 1) p[k].fin = int (random (2));
            }
            for (register int l=0; l<np; l++) // Determina si continúa la espera por tiempo.
            {
                if (p[l].fin == 3)
                {
                    auxfin = int (random (4));
                    if (auxfin == 1) auxfin = 0;
                    else {if (auxfin == 2) auxfin = 3;}
                    p[l].fin = auxfin;
                }
            }
        }
    }
    cout <<” n n”<< ”***Se han producido ”<< cambio<< ” cambios de contexto.***”<<
    ”\n”;

    fprintf(textfile, ”%s”, ”Se han simulado ”);
    fprintf(textfile, ”%i”, np);
    fprintf(textfile, ”%s\n”, ” procesos concurrentes.”);
    fprintf(textfile, ”%s”, ”Se han producido ”);
    fprintf(textfile, ”%i”, cambio);
    fprintf(textfile, ”%s\n”, ” cambios de contexto.”);
    auxfin = getch();
}*/