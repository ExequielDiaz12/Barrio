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
/*
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
*/
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


bool LoteComunitario::ComprobarReserva(Fecha& fecha, const int inicio, const int fin, Persona* persona){
	bool seReservo = true;
	Fecha fechaActual;
	if(fecha >= fechaActual){
		vector<Reserva*>::iterator it;
		it = reservas.begin();
		while(it!=reservas.end() && seReservo)
		{
			if((*it)->EstaReservado(fecha,inicio,fin)){
				seReservo = false;
			}
			++it;
		}

		if(seReservo)
		{
			agregarReserva(fecha,inicio,fin,persona);
			return true;
		}else{
			return false;
		}
	}else{
		return true;
	}
}

void LoteComunitario::agregarReserva(Fecha& fecha,  int inicio,  int fin, Persona* persona){
	double precioReserva = (inicio-fin) * precioBase;
	Reserva *nuevaReserva = new Reserva(fecha, inicio, fin, precioReserva, this, persona);
	persona->getLote()->AgregarReserva(nuevaReserva);
	reservas.push_back(nuevaReserva);
}

string LoteComunitario::getTipo() const{return "Comunitario";}

const vector<Reserva*>& LoteComunitario::getReservas() const{return reservas;}
