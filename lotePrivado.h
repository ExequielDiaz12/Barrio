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

class lotePrivado : public Lote{
private:
	bool vendido;
	vector<Persona*> propietarios;
	vector<Persona*> habitantes;
	vector<Expensa*> expensas;
	vector<Reserva*> reservas;
public:
	lotePrivado(double area, bool vendido);
	virtual ~lotePrivado();

	string getTipo() const override;
	bool getVendido() const;

	void AgregarReserva(Reserva *reserva);
	double CalcularBonificacion(Fecha &fecha);
	void CrearExpensa(Fecha &fecha, double areaTotal, double servicios, double consumoComunitario);
	void EmitirFacturaExpensa(Fecha &fecha);
	void PagarExpensa(Fecha &fecha);
	void VenderLote( Persona *persona); // agrega una persona al propietarios
	void AgregarHabitante (Persona * persona);
	//Persona* getPropietario() const;
//	void agregarExpensa(const Expensa& expensa);
	//const vector<Expensa>& getExpensas()const;
};

#endif /* LOTEPRIVADO_H_ */
