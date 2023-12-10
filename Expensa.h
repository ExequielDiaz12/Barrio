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
	void setFechaVencimiento();
	void pagarExpensa();
	double calcularIntereses();
public:
	Expensa(const Fecha& fecha,double costoServicio, double consumoElectrico, double consumoElectricoComunitario,
            double bonificacion);
	Fecha getFecha();
	void emitirFactura();
	virtual ~Expensa();
	bool getPagado();

};

#endif /* EXPENSA_H_ */
