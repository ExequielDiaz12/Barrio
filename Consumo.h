/*
 * Consumo.h
 *
 *  Created on: 23 nov. 2023
 *      Author: Usuario
 */

#ifndef CONSUMO_H_
#define CONSUMO_H_
#include <iostream>
using namespace std;
#include "Fecha.h"

class Consumo {
private:
	double importe;
	Fecha fecha;
public:
	Consumo(double importe, const Fecha& fecha);
	virtual ~Consumo();
	double getImporte()const;
	Fecha getFecha()const;
};

#endif /* CONSUMO_H_ */
