/*
 * Expensa.cpp
 *
 *  Created on: 25 nov. 2023
 *      Author: Usuario
 */

#include "Expensa.h"

Expensa::Expensa(const Fecha& fecha, double costoServicio, double consumoElectrico, double consumoElectricoComunitario,
                  double bonificacion)
						: fecha(fecha), costoServicio(costoServicio), consumoElectrico(consumoElectrico),
						  consumoElectricoComunitario(consumoElectricoComunitario), bonificacion(bonificacion){
	this->setFechaVencimiento();
	this->pagado = false;
    this->total = costoServicio + consumoElectrico + consumoElectricoComunitario - bonificacion;
}


void Expensa::pagarExpensa(){

		this->pagado= true;
		this->interesesGenerados= this->calcularIntereses();

}



void Expensa::setFechaVencimiento(){
	short dia = this->fecha.getDia(); //Faltaria Controlar cuando se pasa los dias del mes?
	short mes = this->fecha.getMes()+1;
	short anio= this->fecha.getAnio();
	if(mes > 12){
		mes =1;
		anio++;
	}
	this->fechaVencimiento.setFecha(dia, mes, anio);

}

double Expensa::calcularIntereses(){
	Fecha fechaActual;


	if(fechaActual>=this->fechaVencimiento){//funciona?
		int cantAnios=fechaActual.getAnio() - this->fechaVencimiento.getAnio();
		int cantMeses=fechaActual.getMes()- this->fechaVencimiento.getMes();
		int cantDias= fechaActual.getDia() - this->fechaVencimiento.getDia();
		int totalMeses = cantAnios*12 - cantMeses;

		if(totalMeses>0 || (totalMeses==0 && cantDias > 0)){
			return (totalMeses* 0.5) + this->total;
		}
	}
	return 0;
}

void Expensa::emitirFactura(){
	cout << "Fecha de Vencimiento: " << fechaVencimiento << endl;
	cout << "Costo de servicios: " << costoServicio << endl;
	cout << "Consumo Electrico: " << consumoElectrico << endl;
	cout << "Intereses Generados: " << interesesGenerados << endl;
	cout << "Bonificacion: " << bonificacion << endl;
}

Fecha Expensa::getFecha(){return fecha;}

Expensa::~Expensa() {
	// TODO Auto-generated destructor stub
}

bool Expensa::getPagado(){return pagado;}




