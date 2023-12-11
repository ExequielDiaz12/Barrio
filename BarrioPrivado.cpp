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
#include "lotePrivado.h"
#include "Fecha.h"
#include "Consumo.h"
#include "Persona.h"
#include "Reserva.h"
#include "Administracion.h"

int main() {

		Persona persona1("dni","nombre");

	    Fecha fechaExpensa(1, 1, 2020);
	    Administracion administracion("Barrio XYZ");

	    administracion.agregarContratacion("empresa",fechaExpensa,25.0,"tipoServicio1");
	    administracion.agregarContratacion("empresa",fechaExpensa,50.0,"tipoServicio2");


	    administracion.agregarLotePrivado(300.0, false); // creo lote, id: 1

	    administracion.venderLote(1, &persona1);

	    administracion.agregarConsumo(1,fechaExpensa,99.0); // agrego consumo

	    administracion.agregarLoteComunitario("Área de recreación", 500.0, 100.0); // creo lote Com, id:2

	    administracion.agregarReservaLoteComunitario(2,fechaExpensa,4,6,&persona1); //agrego una reserva a ese loteCom (2)



	    administracion.CalcularExpensa(fechaExpensa);

	    administracion.emitirFactura(1, fechaExpensa);


//	    delete loteComunitario;
//	    delete miLotePrivado;
	return 0;

}
