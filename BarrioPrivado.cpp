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
	// Crear una instancia de Administracion
	    Administracion administracion("Barrio XYZ");

	    // Crear un lote comunitario
	    LoteComunitario* loteComunitario = new LoteComunitario("Área de recreación", 500.0, 100.0);
	    administracion.agregarLoteComunitario("Área de recreación", 500.0, 100.0);

	    // Crear un lote privado
	    lotePrivado* lotePrivado = new lotePrivado(300.0, false, nullptr);
	    administracion.agregarLotePrivado(300.0, false, nullptr);

	    // Crear una persona
	    Persona persona("123456789", "Juan Perez");

	    // Vender el lote privado a la persona
	   // administracion.venderLotePrivado(persona, lotePrivado);

	    // Agregar una reserva al lote comunitario
	    Fecha fechaReserva(2023, 12, 15);
	    //loteComunitario->agregarReserva(fechaReserva, 14, 16, 50.0);

	    // Calcular la expensa privada para un mes
	    Fecha fechaExpensa(2023, 12, 1);
	    double expensaPrivada = administracion.calcularExpensaPrivada(fechaExpensa);

	    // Mostrar el resultado
	    cout << "Expensa privada para diciembre de 2023: $" << expensaPrivada << endl;

	    // Liberar la memoria (puedes hacerlo al final del programa)
	    delete loteComunitario;
	    delete lotePrivado;
	return 0;
}
