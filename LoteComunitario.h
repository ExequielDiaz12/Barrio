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

class lotePrivado;

class LoteComunitario : public Lote {
private:
	string nombreLote;
	double precioBase;
	vector<Reserva*> reservas;
	bool estaReservado( Fecha& fecha);//comprobar reserva
public:
	LoteComunitario(string nombreLote,double area, double precioBase);
	virtual ~LoteComunitario();
	string getTipo() const override;
	string getNombreLote();
	double getPrecioBase();
	bool ComprobarReserva(Fecha& fecha, const int inicio, const int fin, Persona* persona);
	void agregarReserva( Fecha& fecha, const int inicio, const int fin, Persona* persona);//realizar reserva
	const vector<Reserva*>& getReservas() const;
	double calcularRecaudacion(Fecha& fecha);


};

#endif /* LOTECOMUNITARIO_H_ */
