/*
 * Administracion.cpp
 *
 *  Created on: 10 dic. 2023
 *      Author: Usuario
 */

#include "Administracion.h"

Administracion::Administracion(string nombre):nombre(nombre) {}

Administracion::~Administracion() {
	for (LoteComunitario* lote : lotesComunitarios) {
	     delete lote;
	}

	for (lotePrivado* lote : lotesPrivados) {
		 delete lote;
	}
}

