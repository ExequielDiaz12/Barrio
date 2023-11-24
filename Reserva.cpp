/*
 * Reserva.cpp
 *
 *  Created on: 23 nov. 2023
 *      Author: Usuario
 */

#include "Reserva.h"

Reserva::Reserva(Fecha& fecha, int horaInicio, int horaFin, double precio, LoteComunitario* lote)
: fecha(fecha),horaInicio(horaInicio),horaFin(horaFin),precio(precio), lote(lote){}

Reserva::~Reserva() {
	// TODO Auto-generated destructor stub
}

Fecha Reserva::getFecha() const {return fecha;}

double Reserva::getPrecio() const{return precio;}

LoteComunitario* Reserva::getLoteComunitario() const{
	return lote;
}
