/*
 * Contratacion.h
 *
 *  Created on: 10 dic. 2023
 *      Author: Usuario
 */

#ifndef CONTRATACION_H_
#define CONTRATACION_H_
#include "Fecha.h"


class Contratacion {
private:
	string empresa;
	Fecha fecha;
	float costo;
	string tipoServicio;
public:
	Contratacion(string empresa,Fecha &fecha,float costo,string tipoServicio);
	virtual ~Contratacion();

	float getCosto();
	Fecha getFecha();
};

#endif /* CONTRATACION_H_ */
