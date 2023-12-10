/*
 * lotePrivado.cpp
 *
 *  Created on: 25 nov. 2023
 *      Author: Usuario
 */

#include "lotePrivado.h"

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
    // Implementa el cálculo del importe según tus necesidades
    return 0.0;
}
