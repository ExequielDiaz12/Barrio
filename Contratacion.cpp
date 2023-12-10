/*
 * Contratacion.cpp
 *
 *  Created on: 10 dic. 2023
 *      Author: Usuario
 */

#include "Contratacion.h"

Contratacion::Contratacion(string empresa,Fecha &fecha,float costo,string tipoServicio)
	:empresa(empresa),fecha(fecha),costo(costo),tipoServicio(tipoServicio){}

Contratacion::~Contratacion() {
	// TODO Auto-generated destructor stub
}

float Contratacion::getCosto(){return costo;}
Fecha Contratacion::getFecha(){return fecha;}

