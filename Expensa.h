/*
 * Expensa.h
 *
 *  Created on: 25 nov. 2023
 *      Author: Usuario
 */

#ifndef EXPENSA_H_
#define EXPENSA_H_
#include <iostream>
using namespace std;
#include "Fecha.h"

class Expensa {
private:
	Fecha fecha;
	Fecha fechaVencimiento;
	bool pagado;
	double costoServicio;
	double consumoElectrico;
	double consumoElectricoComunitario;
	double interesesGenerados;
    double bonificacion;
    double total;
public:
	Expensa(const Fecha& fecha, const Fecha& fechaVencimiento, bool pagado,
            double costoServicio, double consumoElectrico, double consumoElectricoComunitario,
            double interesesGenerados, double bonificacion);
	virtual ~Expensa();
	Fecha getFecha()const;
};

#endif /* EXPENSA_H_ */
