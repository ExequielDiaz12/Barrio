/*
 * lotePrivado.cpp
 *
 *  Created on: 25 nov. 2023
 *      Author: Usuario
 */

#include "lotePrivado.h"

lotePrivado::lotePrivado(double area, bool vendido) : Lote(area), vendido(vendido) {
	// TODO Auto-generated constructor stub

}

lotePrivado::~lotePrivado() {
	// TODO Auto-generated destructor stub
}

//bool lotePrivado::estaVendido() const {
//    return vendido;
//}

//Persona* lotePrivado::getPropietario() const {
//    return propietario;
//}

//void lotePrivado::agregarExpensa(const Expensa& expensa) {
//    expensas.push_back(expensa);
//}

//const std::vector<Expensa>& lotePrivado::getExpensas() const {
//    return expensas;
//}

string lotePrivado::getTipo() const{return "Privado";}

bool lotePrivado::getVendido() const{return vendido;}

void lotePrivado::AgregarReserva(Reserva *reserva){
	reservas.push_back(reserva);
}

double lotePrivado::CalcularBonificacion(Fecha &fecha){
	double total = 0;
	for(const Reserva* reserva: reservas){
		if(
			(reserva->getFecha().getMes() == fecha.getMes()) &&
			(reserva->getFecha().getAnio() == fecha.getAnio())
		){
			total += reserva->getPrecio();
		}
	}
	return total * 0.05;
}
void lotePrivado::CrearExpensa(Fecha &fecha, double areaTotal, double servicios, double consumoComunitario){
	double costoServicios = servicios * (area / areaTotal);
	double consumoE = getImporte(fecha);
	double bonificacion = CalcularBonificacion(fecha);
	Expensa *nuevaExpensa = new Expensa(fecha,costoServicios,consumoE,consumoComunitario,bonificacion);
	expensas.push_back(nuevaExpensa);
}

void lotePrivado::EmitirFacturaExpensa(Fecha &fecha){
	for(Expensa* expensa: expensas){
		if(
			(expensa->getFecha().getMes() == fecha.getMes()) &&
			(expensa->getFecha().getAnio() == fecha.getAnio())
		){
			expensa->emitirFactura();
			break;
		}
	}
}

void lotePrivado::PagarExpensa(Fecha &fecha){
	for( Expensa* expensa: expensas){
		if(
			(expensa->getFecha().getMes() == fecha.getMes()) &&
			(expensa->getFecha().getAnio() == fecha.getAnio() && expensa->getPagado() == false)
		){
			expensa->pagarExpensa();
			break;
		}
	}
}

void lotePrivado::VenderLote(Persona *persona){
	vendido = true;
	propietarios.push_back(persona);
	persona->agregarLotePropietario( this );
}

void lotePrivado::AgregarHabitante (Persona * persona){
	habitantes.push_back(persona);
}
