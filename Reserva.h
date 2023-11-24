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

class Reserva {
private:
	Fecha fecha;
	int horaInicio;
	int horaFin;
	double precio;
	LoteComunitario* lote;
public:
	Reserva(Fecha& fecha, int horaInicio, int horaFin, double precio, LoteComunitario* lote);
	virtual ~Reserva();

	double getPrecio() const;
	Fecha getFecha() const;
	LoteComunitario* getLoteComunitario() const;
};

#endif /* RESERVA_H_ */
