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

int main() {
	Fecha f1;

	LoteComunitario LC1("piscina",123.5, 3000);

	LC1.agregarConsumo(500.50, f1);

	cout<< "nro lote:"<<LC1.getNumero()<<endl;
	cout<< "Area: "<<LC1.getArea()<<endl;
	cout<< "Precio base del lote Comuitario: "<<LC1.getPrecioBase()<<endl;

	cout<< "Primer Importe" << LC1.getImporte(f1)<<endl;

	LC1.agregarConsumo(200, f1);

	cout<< "con el segundo Importe" << LC1.getImporte(f1)<<endl;





	return 0;
}
