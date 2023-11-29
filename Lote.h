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
	Lote(double area);//aqui creo el array de consumo
	//Lote(double area, const vector<Consumo*>& consumos);//borro
	virtual ~Lote();

	int getNumero()const;
	double getArea()const;
	virtual double getImporte(const Fecha& fecha) const = 0;// no la hago abstracta y la implementacion la hago aca
	//agregar getipo abstracto // esto consideraciones del informe
	void agregarConsumo(double importe, const Fecha& fecha);
};

#endif /* LOTE_H_ */
