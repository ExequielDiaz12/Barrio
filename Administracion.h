/*
 * Administracion.h
 *
 *  Created on: 10 dic. 2023
 *      Author: Usuario
 */

#ifndef ADMINISTRACION_H_
#define ADMINISTRACION_H_
#include <iostream>
using namespace std;
#include<vector>
#include "LoteComunitario.h"
#include "lotePrivado.h"
#include "Fecha.h"

class Administracion {
private:
	string nombre;
	vector<LoteComunitario*> lotesComunitarios;
	vector<lotePrivado*> lotesPrivados;
public:
	Administracion(string nombre);
	void agregarLoteComunitario(string nombreLote,double area, double precioBase);
	void agregarLotePrivado();
	virtual ~Administracion();
};

#endif /* ADMINISTRACION_H_ */
