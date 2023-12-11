/*
 * lotePrivado.cpp
 *
 *  Created on: 25 nov. 2023
 *      Author: Usuario
 */

#include "lotePrivado.h"
#include "Persona.h"

lotePrivado::lotePrivado(double area, bool vendido, Persona* propietario)
: Lote(area), vendido(vendido), propietario(propietario) {
	// TODO Auto-generated constructor stub

}

lotePrivado::~lotePrivado() {
	// TODO Auto-generated destructor stub
}

bool lotePrivado::estaVendido() const {
    return vendido;
}

Persona* lotePrivado::getPropietario() const {
    return propietario;
}

void lotePrivado::agregarExpensa(const Expensa& expensa) {
    expensas.push_back(expensa);
}

const std::vector<Expensa>& lotePrivado::getExpensas() const {
    return expensas;
}

string lotePrivado::getTipo() const{return "Privado";}

double lotePrivado::getImporte(const Fecha& fecha) const {
    return 0.0;
}

void lotePrivado::setVendido(bool vendido) {
    this->vendido = vendido;
}

void lotePrivado::setPropietario(Persona* propietario) {
    this->propietario = propietario;
}

void lotePrivado::PagarExpensa( Fecha& fechaExpensa) {
    // Encuentra la expensa correspondiente a la fecha especificada
    for (Expensa& expensa : expensas) {
        if (
        		(expensa.getFecha().getAnio() == fechaExpensa.getAnio())&&
        		(expensa.getFecha().getMes() == fechaExpensa.getMes())&&
				(expensa.getFecha().getDia() == fechaExpensa.getDia())
				) {
            // Realiza el pago de la expensa
            expensa.Pagar();
            return;  // Termina el bucle después de pagar la expensa
        }
    }

    // Si llegamos aquí, no se encontró una expensa para esa fecha
    cout << "Error: No se encontró una expensa para la fecha especificada." << endl;
}
