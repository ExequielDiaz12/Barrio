/*
 * Persona.h
 *
 *  Created on: 24 nov. 2023
 *      Author: Usuario
 */

#ifndef PERSONA_H_
#define PERSONA_H_
#include <iostream>
using namespace std;
#include <vector>


class lotePrivado;

class Persona {
private:
	string dni;
	string nombre;
	vector<lotePrivado*> lotes;
public:
	Persona(string dni, string nombre);
	virtual ~Persona();
	const string& getDni() const;
	const string& getNombre() const;
	void agregarLotePropietario(lotePrivado* lote);
};

#endif /* PERSONA_H_ */
