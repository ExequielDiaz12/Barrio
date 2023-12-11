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
	void agregarLotePrivado(double area, bool vendido);
	void agregarContratacion(string empresa,Fecha &fecha,float costo,string tipoServicio);
	virtual ~Administracion();

	double calcularAreaTotalPrivado();
	int cantidadLotesPrivadosOcupados();
	float calcularCostoContratacionesPorMes(Fecha& fecha);
	double calcularConsumoComunitario(Fecha& fecha);
	//double recaudacion(Fecha& fecha);//ver
	//double calcularTotalReservas(Fecha& fecha);//ver
	double calcularExpensaPrivada( Fecha& fecha);//calcular diferencia
	bool venderLote(int numLote, Persona *comprador);
	double calculaRecaudacion( Fecha& fecha);//calcular recaudacion comunitario
	bool agregarReservaLoteComunitario(int numLoteCom, Fecha& fecha, int horaInicio, int horaFin, Persona* persona);
	void PagarExpensaLotePrivado(int numLote, Fecha& fechaExpensa);
	void CalcularExpensa(Fecha& fecha);
	void emitirFactura(int numLote, Fecha& fechaExpensa);
	void agregarConsumo(int numLote, Fecha& fecha, double importe);
};

#endif /* ADMINISTRACION_H_ */
