#include "ejercicios.h"
#include "auxiliares.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>

using namespace std;

/******++++**************************** EJERCICIO tiempoTotal ***********+++***********************/
tiempo tiempoTotal(viaje v) {
    tiempo t;

    // codigo
    tiempo tMayor;
    tiempo tMenor = obtenerTiempo(v[0]);
    tiempo tActual;
    for (int i= 0; i < v.size(); i ++){
        tActual = obtenerTiempo(v[i]);
        if (tActual > tMayor){
            tMayor = tActual;
        }
        if (tActual< tMenor){
            tMenor = tActual;
        }
    }
    t = tMayor - tMenor;
    return t;
}

// O(n) recorre todos los elementos para asegurarse de tener el mayor y el menor.
// // n = |v|

/************++*********************** EJERCICIO distanciaTotal ************++*********************/

int tiempoMenor(viaje v, int j) {
    int tMenor = j;
    for (int i = j; i <  v.size() -1 ; i++){
        tiempo tActual = obtenerTiempo(v[i]);
        if (tActual< obtenerTiempo(v[tMenor])){
            tMenor = i;
        }
    }
    return tMenor;
}
// O(n) recorre todo el vector


viaje swap(int i, int j , viaje v){
    tuple<tiempo, gps> x = v[i];
    tuple<tiempo, gps> y = v[j];
    v[i] = y;
    v[j] = x;
    return v;
}

viaje ordenarPorTiempo(viaje v){
    for (int i = 0; i < v.size() -1 ; i++){
        int tMenor =  tiempoMenor(v, i);
        v = swap(i, tMenor,v);
    }
    return v;
}
// es O(n^2) recorre todos los elementos y usa la funcion tiempoMenor que es O(n).
// n = |v|

distancia distanciaTotal(viaje v) {
    distancia d;
    // codigo
    viaje v0 = v;
    v0 = ordenarPorTiempo(v);
    for (int i = 1; i< v0.size(); i++){
        d = d + distEnKM(obtenerPosicion(v0[i]), obtenerPosicion(v0[i-1]));
    }

    return d;
}

// es O(n^2 + n), ordena el vector y despues lo recorre, pertenece a O(n^2).
// n = |v|
/*****************************+***** EJERCICIO excesoDeVelocidad **********************************/
int velocidad(tuple<tiempo, gps> p1, tuple<tiempo, gps> p2){
    int distancia = distEnKM(obtenerPosicion(p2), obtenerPosicion(p1));
    tiempo tmp = (obtenerTiempo(p2)- obtenerTiempo(p1)) / 3600;
    int vel = distancia / tmp;
    return  vel;

}

bool excesoDeVelocidad(viaje v) {
    bool resp = false;


    v = ordenarPorTiempo(v);
    int i = 0;
    while(i < v.size() && velocidad(v[i-1],v[i]) < 80){
        i++;
    }
    return i != v.size();
}


// es O(n^2 + n), ordena el vector y despues lo recorre, pertenece a O(n^2).


/************************************ EJERCICIO recorridoCubierto *******************************/
bool puntoCubiertoViaje(gps v, recorrido r, distancia u){
    bool estacubierto = false;
    for (int i = 0; i< r.size() && !estacubierto; i++){
        distancia dist =distEnKM(v, r[i]);
        if (distEnKM(v, r[i]) < u){
            estacubierto = true;
                }
    }
    return estacubierto;
}
vector<gps> recorridoNoCubierto(viaje v, recorrido r, distancia u) {
    vector<gps> resp;
    // codigo

    for (int i = 0; i < v.size(); i++){
        if (puntoCubiertoViaje(obtenerPosicion(v[i]),r,u))
        {
            resp.push_back(obtenerPosicion(v[i]));
        }
    }
    return resp;
}

/***************************************** EJERCICIO flota ***************************************/


bool viajeEnFranja(viaje v,tiempo t0, tiempo tf){
    int i = 0;
    while(i < v.size() && !(obtenerTiempo(v[i]) > t0 && obtenerTiempo(v[i]) < tf)){
        i++;
    }
    return i != v.size();
}
// es O(n) en el peor caso recorre todo el vector

int flota(vector<viaje> f, tiempo t0, tiempo tf) {
    int resp  = 0;
    // codigo
    for(int i = 0; i<f.size(); i++){
        viaje v = f[i];
        if (viajeEnFranja(v, t0, tf)){
            resp = resp +1;
        }


    }
    return resp;
}

// Sea n = |f| y m = elementos de un vector cualquiera dentro de f.
// En el peor caso la complejidad es O(n * m) recorre todos los elementos de f y los elementos dentro de ellos.
/************************************** EJERCICIO construirGrilla *******************************/
grilla construirGrilla(gps esq1, gps esq2, int n, int m) {
    grilla resp = {};
    // codigo

    return resp;
}

/************************************* EJERCICIO cantidadDeSaltos ******************************/
int cantidadDeSaltos(grilla g, viaje v) {
    int resp;
    // codigo

    return resp;
}


/************************************* EJERCICIO corregirViaje ******************************/
void corregirViaje(viaje& v, vector<tiempo> errores){
    // codig

    return;
}

