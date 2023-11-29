/*
 * Lote.h
 *
 *  Created on: 23 nov. 2023
 *      Author: Usuario
 */

#ifndef LOTE_H_
#define LOTE_H_
#include <iostream>
using namespace std;
#include "Consumo.h"
#include "Fecha.h"
#include <vector>

class Lote {
protected:
	static int lotesCreados;
	int numero;
	double area;
	vector<Consumo*> consumos;
public:
	Lote(double area);
	virtual ~Lote();

	void agregarConsumo(double importe, const Fecha& fecha);
	int getNumero()const;
	double getArea()const;
	virtual double getImporte(const Fecha& fecha) const = 0;
	virtual string getTipo() const = 0;

};

#endif /* LOTE_H_ */
