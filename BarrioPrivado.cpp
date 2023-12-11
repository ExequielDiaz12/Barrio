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

	    Administracion administracion("Barrio XYZ");


	    LoteComunitario* loteComunitario = new LoteComunitario("Área de recreación", 500.0, 100.0);
	    administracion.agregarLoteComunitario("Área de recreación", 500.0, 100.0);


	    lotePrivado* miLotePrivado = new lotePrivado(300.0, false, nullptr);
	    administracion.agregarLotePrivado(300.0, false, nullptr);


	    Persona persona("123456789", "Juan Perez");


	   administracion.venderLotePrivado(persona, miLotePrivado);


	    Fecha fechaReserva(2023, 12, 15);
	    loteComunitario->agregarReserva(fechaReserva, 14, 16, 50.0,&persona);


	    Fecha fechaExpensa(2023, 12, 1);
	    double expensaPrivada = administracion.calcularExpensaPrivada(fechaExpensa);


	    cout << "Expensa privada para diciembre de 2023: $" << expensaPrivada << endl;


	    delete loteComunitario;
	    delete miLotePrivado;
	return 0;

}
