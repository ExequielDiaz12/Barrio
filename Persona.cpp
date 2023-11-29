/*
 * Persona.cpp
 *
 *  Created on: 24 nov. 2023
 *      Author: Usuario
 */

#include "Persona.h"
#include "Reserva.h"
#include "lotePrivado.h"

Persona::Persona(string& dni, string& nombre)
	:dni(dni), nombre(nombre){}

Persona::~Persona() {
	/*
	for(Reserva* reserva: reservas){
		delete reserva;
	}
*/
	for (lotePrivado* lote : lotes) {
	        delete lote;
	    }
}

const string& Persona::getDni() const {return dni;}

const string& Persona::getNombre() const {return nombre;}

/*
void Persona::agregarReserva(Reserva* reserva){
	reservas.push_back(reserva);
}

const vector<Reserva*>& Persona::getReservas() const{
	return reservas;
}
*/
void Persona::agregarLotePropietario(lotePrivado* lote) {
    lotes.push_back(lote);
}
/*
const std::vector<lotePrivado*>& Persona::getLotesPropietarios() const {
    return lotes;
}
*/
