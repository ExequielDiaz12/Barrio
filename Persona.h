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

class Reserva;
class lotePrivado;

class Persona {
private:
	string dni;
	string nombre;
	//vector<Reserva*> reservas;//esto no va
	vector<lotePrivado*> lotes;//array de lotes que posee
	//falta una referencia al lote que habita
public:
	Persona(string& dni, string& nombre);
	virtual ~Persona();

	const string& getDni() const;
	const string& getNombre() const;
	//void agregarReserva(Reserva* reserva);//no iria
	//const vector<Reserva*>& getReservas() const;//no iria
	void agregarLotePropietario(lotePrivado* lote);
	//const std::vector<lotePrivado*>& getLotesPropietarios() const;//no hace fata
	//get lote que habita
};

#endif /* PERSONA_H_ */
