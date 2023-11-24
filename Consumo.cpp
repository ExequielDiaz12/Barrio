/*
 * Consumo.cpp
 *
 *  Created on: 23 nov. 2023
 *      Author: Usuario
 */

#include "Consumo.h"

Consumo::Consumo(double importe, const Fecha& fecha): importe(importe),fecha(fecha) {}

Consumo::~Consumo() {}

double Consumo::getImporte()const {return importe;}
Fecha Consumo::getFecha() const {return fecha;}

