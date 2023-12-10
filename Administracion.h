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
#include "Contratacion.h"

class Administracion {
private:
	string nombre;
	vector<LoteComunitario*> lotesComunitarios;
	vector<lotePrivado*> lotesPrivados;
	vector<Contratacion*> contrataciones;
public:
	Administracion(string nombre);
	void agregarLoteComunitario(string nombreLote,double area, double precioBase);
	void agregarLotePrivado(double area, bool vendido, Persona* propietario);
	void agregarContratacion(string empresa,Fecha &fecha,float costo,string tipoServicio);
	virtual ~Administracion();

	double calcularAreaTotalPrivado();
	int cantidadLotesPrivadosOcupados();
	float calcularCostoContratacionesPorMes(int mes);
	double calcularConsumoComunitario(Fecha& fecha);
	double recaudacion(Fecha& fecha);
	double calcularTotalReservas(Fecha& fecha);
	double calcularExpensaPrivada( Fecha& fecha);
};

#endif /* ADMINISTRACION_H_ */