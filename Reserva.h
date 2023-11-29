/*
 * Reserva.h
 *
 *  Created on: 23 nov. 2023
 *      Author: Usuario
 */

#ifndef RESERVA_H_
#define RESERVA_H_
#include "Fecha.h"

class LoteComunitario;
class Persona;

class Reserva {
private:
	Fecha fecha;
	int horaInicio;
	int horaFin;
	double precio;
	LoteComunitario* lote;
	Persona* persona; // aqui solo va la referencia de la persona pero la persona no tiene informacion de ella
public:
	Reserva(Fecha& fecha, int horaInicio, int horaFin, double precio, LoteComunitario* lote, Persona* persona);
	virtual ~Reserva();

	double getPrecio() const;
	Fecha getFecha() const;
	LoteComunitario* getLoteComunitario() const;
	Persona* getPersona() const;
};

#endif /* RESERVA_H_ */
