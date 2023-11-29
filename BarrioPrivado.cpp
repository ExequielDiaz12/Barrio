//============================================================================
// Name        : BarrioPrivado.cpp
// Author      : Exequiel Diaz
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "Lote.h"
#include "LoteComunitario.h"
#include "Fecha.h"
#include "Consumo.h"
#include "Persona.h"
#include "Reserva.h"

int main() {
	/*Genero fechas*/
	Fecha f1(1,11,2023);
	Fecha f2(1,10,2023);
	Fecha f3(1,12,2023);
	Fecha fechaHoy;

	/***Creo lotes comunitarios***/
	LoteComunitario LoteCom1("piscina",1500.00, 3000);
	LoteComunitario LoteCom2("Teatro",2000.00, 5000);


	LoteCom1.agregarConsumo(500.50, f1);
	LoteCom1.agregarConsumo(300, f1);
	cout<< "importe de consumo de loteCom1: $"<<LoteCom1.getImporte(f1)<<endl;

	LoteCom2.agregarConsumo(1500.50, f2);
	LoteCom2.agregarConsumo(300.50, f2);
	cout<< "importe de consumo de loteCom2: $"<<LoteCom2.getImporte(f2)<<endl;

	/** Creo las Personas**/
	Persona p1("123","William Blake");
	Persona p2("456","Emmy Noether");
	Persona p3("789","Edmond Kirsch");

	/**creo las reservas**/
	LoteCom1.agregarReserva(f2, 12, 20, 2000, &p1);
	LoteCom1.agregarReserva(f2, 12, 20, 2000, &p3);//esta resrva no se hace
	LoteCom1.agregarReserva(f3, 12, 20, 2000, &p2);
	LoteCom2.agregarReserva(f2, 12, 20, 2000, &p3);

	cout<<"Recaudacion de LoteCom1 en la fecha dada es de $"<<LoteCom1.calcularRecaudacion(f2)<<endl;


	/* Lotes Privados */

	return 0;
}
