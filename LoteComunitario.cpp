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

double LoteComunitario::calcularRecaudacion(Fecha& fecha){
	double totalRecaudacion = 0.0;
	for(const Reserva* reserva: reservas){
			if(
					(reserva->getFecha().getMes() == fecha.getMes()) &&
					(reserva->getFecha().getAnio() == fecha.getAnio())
			){
				totalRecaudacion += reserva->getPrecio();
			}
		}

	return totalRecaudacion;
}

double LoteComunitario::getPrecioBase(){return precioBase;}

bool LoteComunitario::estaReservado( Fecha& fecha){
	for(const Reserva* reserva: reservas){
				if(
						(reserva->getFecha().getMes() == fecha.getMes()) &&
						(reserva->getFecha().getAnio() == fecha.getAnio()) &&
						(reserva->getFecha().getDia() == fecha.getDia())
				){
					return false;
				}
			}
	return true;
}

void LoteComunitario::agregarReserva(Fecha& fecha, const int inicio, const int fin, double precioReserva, Persona* persona){
	if(estaReservado(fecha))
	{
		Reserva* nuevaReserva = new Reserva(fecha, inicio, fin, precioReserva, this, persona);
		reservas.push_back(nuevaReserva);
	}else{
		cout<<"No se pudo hacer reverda"<<endl;
	}

}

string LoteComunitario::getTipo() const{return "Comunitario";}

const vector<Reserva*>& LoteComunitario::getReservas() const{return reservas;}
