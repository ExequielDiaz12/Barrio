/*
 * Reserva.cpp
 *
 *  Created on: 23 nov. 2023
 *      Author: Usuario
 */

#include "Reserva.h"

Reserva::Reserva(Fecha& fecha, int horaInicio, int horaFin, double precio, LoteComunitario* lote, Persona* persona)
: fecha(fecha),horaInicio(horaInicio),horaFin(horaFin),precio(precio), lote(lote), persona(persona){}

Reserva::~Reserva() {}

Fecha Reserva::getFecha() const {return fecha;}

double Reserva::getPrecio() const{return precio;}

LoteComunitario* Reserva::getLoteComunitario() const{
	return lote;
}

Persona* Reserva::getPersona() const{
	return persona;
}
