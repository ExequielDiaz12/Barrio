/*
 * lotePrivado.h
 *
 *  Created on: 25 nov. 2023
 *      Author: Usuario
 */

#ifndef LOTEPRIVADO_H_
#define LOTEPRIVADO_H_
#include <iostream>
using namespace std;
#include "Lote.h"
#include "Fecha.h"
#include "Reserva.h"
#include <vector>
#include "Expensa.h"
#include "Persona.h"

class lotePrivado : public Lote{
private:
	bool vendido;
	Persona* propietario;
	vector<Expensa> expensas;
public:
	lotePrivado(double area, bool vendido, Persona* propietario);
	virtual ~lotePrivado();

	bool estaVendido() const;
	Persona* getPropietario() const;
	void agregarExpensa(const Expensa& expensa);
	const vector<Expensa>& getExpensas()const;
	string getTipo() const override;
	double getImporte(const Fecha& fecha) const override;
};

#endif /* LOTEPRIVADO_H_ */
