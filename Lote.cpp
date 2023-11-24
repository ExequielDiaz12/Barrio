/*
 * Lote.cpp
 *
 *  Created on: 23 nov. 2023
 *      Author: Usuario
 */

#include "Lote.h"

int Lote::lotesCreados = 0;

Lote::Lote(double area) : numero(lotesCreados++), area(area) {}

Lote::Lote(double area, const vector<Consumo*>& consumos):
	numero(++lotesCreados),area(area),consumos(consumos){}

Lote::~Lote() {
	for(Consumo* consumo : consumos){
		delete consumo;
	}
}

int Lote::getNumero() const{return numero;}
double Lote::getArea() const{return area;}
void Lote::agregarConsumo(double importe, const Fecha& fecha){
	Consumo* nuevoConsumo = new Consumo(importe, fecha);
	consumos.push_back(nuevoConsumo);
}
