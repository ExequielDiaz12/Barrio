/*
 * LoteComunitario.cpp
 *
 *  Created on: 23 nov. 2023
 *      Author: Usuario
 */
#include "Lote.h"
#include "LoteComunitario.h"
#include "Fecha.h"
#include "Reserva.h"

LoteComunitario::LoteComunitario(string nombreLote,double area, double precioBase) :Lote(area){
	this->precioBase = precioBase;
	this->nombreLote = nombreLote;
}

LoteComunitario::~LoteComunitario() {
	for(Reserva* reserva : reservas){
		delete reserva;
	}
}

string LoteComunitario::getNombreLote(){return nombreLote;}

double LoteComunitario::getImporte (const Fecha& fecha) const {
	double totalImporte = 0.0;
	for(const Consumo* consumo: consumos){
		if(
				(consumo->getFecha().getMes() == fecha.getMes()) &&
				(consumo->getFecha().getAnio() == fecha.getAnio())
		){
			totalImporte += consumo->getImporte();
		}
	}
	return totalImporte;
}

double LoteComunitario::getPrecioBase(){return precioBase;}

void LoteComunitario::agregarReserva(Fecha& fecha, const int inicio, const int fin, double precioReserva){
	Reserva* nuevaReserva = new Reserva(fecha, inicio, fin, precioReserva, this);
	reservas.push_back(nuevaReserva);
}

const vector<Reserva*>& LoteComunitario::getReservas() const{return reservas;}
