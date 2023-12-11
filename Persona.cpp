/*
 * Persona.cpp
 *
 *  Created on: 24 nov. 2023
 *      Author: Usuario
 */

#include "Persona.h"
#include "Reserva.h"
#include "lotePrivado.h"

Persona::Persona(string dni, string nombre)
	:dni(dni), nombre(nombre){}

Persona::~Persona() {
	for (lotePrivado* lote : lotes) {
	        delete lote;
	    }
}

const string& Persona::getDni() const {return dni;}

const string& Persona::getNombre() const {return nombre;}

const lotePrivado* Persona::getLote() const{return loteHabita;}

void Persona::agregarLotePropietario(lotePrivado* lote) {
    lotes.push_back(lote);
}

void Persona::agregarLoteHabita(lotePrivado* lote) {
    loteHabita = lote;
}

