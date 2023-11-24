/*
 * LoteComunitario.h
 *
 *  Created on: 23 nov. 2023
 *      Author: Usuario
 */

#ifndef LOTECOMUNITARIO_H_
#define LOTECOMUNITARIO_H_
#include <iostream>
using namespace std;
#include "Lote.h"
#include "Consumo.h"
#include "Fecha.h"
#include "Reserva.h"
#include <vector>

class LoteComunitario : public Lote {
private:
	string nombreLote;
	double precioBase;
	vector<Reserva*> reservas;
public:
	LoteComunitario(string nombreLote,double area, double precioBase);
	virtual ~LoteComunitario();
	double getImporte(const Fecha& fecha) const override;

	string getNombreLote();
	double getPrecioBase();
	void agregarReserva( Fecha& fecha, const int inicio, const int fin, double precioReserva);
	const vector<Reserva*>& getReservas() const;
};

#endif /* LOTECOMUNITARIO_H_ */
