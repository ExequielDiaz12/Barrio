/*
 * Expensa.cpp
 *
 *  Created on: 25 nov. 2023
 *      Author: Usuario
 */

#include "Expensa.h"

Expensa::Expensa(const Fecha& fecha, const Fecha& fechaVencimiento, bool pagado,
                 double costoServicio, double consumoElectrico, double consumoElectricoComunitario,
                 double interesesGenerados, double bonificacion)
    : fecha(fecha), fechaVencimiento(fechaVencimiento), pagado(pagado),
      costoServicio(costoServicio), consumoElectrico(consumoElectrico),
      consumoElectricoComunitario(consumoElectricoComunitario),
      interesesGenerados(interesesGenerados), bonificacion(bonificacion) {
    //aqui deberia calcular el total de cada cosa?
    total = costoServicio + consumoElectrico + consumoElectricoComunitario +
            interesesGenerados - bonificacion;
}

Expensa::~Expensa() {
	// TODO Auto-generated destructor stub
}

Fecha Expensa::getFecha(){return fecha;}

void Expensa::Pagar() {
    pagado = true;
}
