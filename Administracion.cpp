/*
 * Administracion.cpp
 *
 *  Created on: 10 dic. 2023
 *      Author: Usuario
 */

#include "Administracion.h"

Administracion::Administracion(string nombre):nombre(nombre) {}

Administracion::~Administracion() {
	for (LoteComunitario* lote : lotesComunitarios) {
	     delete lote;
	}

	for (lotePrivado* lote : lotesPrivados) {
		 delete lote;
	}
}
void Administracion::agregarLotePrivado(double area, bool vendido) {
    lotePrivado* nuevo = new lotePrivado(area, vendido);
    lotesPrivados.push_back(nuevo);
}

void Administracion::agregarLoteComunitario(string nombreLote,double area, double precioBase){
	LoteComunitario* nuevo = new LoteComunitario(nombreLote, area, precioBase);
	lotesComunitarios.push_back(nuevo);
}

void Administracion::agregarContratacion(string empresa,Fecha &fecha,float costo,string tipoServicio){
	 Contratacion* contratacion = new Contratacion(empresa, fecha, costo, tipoServicio);
	 contrataciones.push_back(contratacion);
}

double Administracion::calcularAreaTotalPrivado(){
    double totalArea = 0.0;

    for (const lotePrivado* lote : lotesPrivados) {
        totalArea += lote->getArea();
    }

    return totalArea;
}

int Administracion::cantidadLotesPrivadosOcupados() {
    int cont = 0;
    for (const lotePrivado* lote : lotesPrivados) {
        if (lote->getVendido()) {
            cont++;
        }
    }
    return cont;
}

float Administracion::calcularCostoContratacionesPorMes(Fecha& fecha) {
    float total = 0.0;

    for (Contratacion* contratacion : contrataciones) {
        if (contratacion->getFecha().getMes() == fecha.getMes() &&
        		contratacion->getFecha().getAnio() == fecha.getAnio()) {
            total += contratacion->getCosto();
        }
    }
    return total;
}

double Administracion::calcularConsumoComunitario(Fecha& fecha) {
    double total = 0.0;

    for (const LoteComunitario* lote : lotesComunitarios) {
        total += lote->getImporte(fecha);
    }

    return total;
}

void Administracion::agregarConsumo(int numLote, Fecha& fecha, double importe){
	for (LoteComunitario* lote : lotesComunitarios) {
		lote->agregarConsumo(importe,fecha);
		break;
	}

	for (lotePrivado* lote : lotesPrivados) {
		lote->agregarConsumo(importe,fecha);
		break;
	}
}
/*
double Administracion::calcularTotalReservas( Fecha& fecha) {
    double total = 0.0;

    for (const LoteComunitario* lote : lotesComunitarios) {
        const vector<Reserva*>& reservas = lote->getReservas();

        for (const Reserva* reserva : reservas) {
            if (reserva->getFecha().getMes() == fecha.getMes() &&
                reserva->getFecha().getAnio() == fecha.getAnio()) {
                total += reserva->getPrecio();
            }
        }
    }

    return total;
}

double Administracion::recaudacion( Fecha& fecha)  {
    double totalRecaudado = 0.0;

    for (const LoteComunitario* lote : lotesComunitarios) {
        const vector<Reserva*>& reservas = lote->getReservas();

        for (const Reserva* reserva : reservas) {
            if (reserva->getFecha().getMes() == fecha.getMes() &&
                reserva->getFecha().getAnio() == fecha.getAnio()) {
                totalRecaudado += reserva->getPrecio();
            }
        }
    }

    return totalRecaudado;
}
*/
double Administracion::calcularExpensaPrivada( Fecha& fecha) {
    double consumoComunitario = calcularConsumoComunitario(fecha);
    double totalReservas = calculaRecaudacion(fecha);

    if (consumoComunitario <= totalReservas) {
        return 0.0;
    }

    //double recaudacionReservas = recaudacion(fecha);
    int cantPrivadosOcupados = cantidadLotesPrivadosOcupados();

    return (consumoComunitario - totalReservas) / cantPrivadosOcupados;
}

bool Administracion::venderLote(int numLote, Persona *comprador)
	{
		 bool vendido = false;

		        for (auto& lote : lotesPrivados) {
		   		    if (lote->getNumero() == numLote && !lote->getVendido()) {
		                lote->VenderLote(comprador);
		                vendido = true;
		                break;
		   		    }
		        }
		        return vendido;
	}


double Administracion::calculaRecaudacion( Fecha& fecha) {
    double totalRecaudado = 0.0;

    for (LoteComunitario* lote : lotesComunitarios) {
        totalRecaudado += lote->calcularRecaudacion(fecha);
    }

    return totalRecaudado;
}

bool Administracion::agregarReservaLoteComunitario(int numLoteCom, Fecha& fecha, int horaInicio, int horaFin, Persona* persona)
{
    // Buscar el LoteComunitario por su número
    for (LoteComunitario* loteComunitario : lotesComunitarios)
    {
        if (loteComunitario->getNumero() == numLoteCom)
        {
            // Agregar la reserva al LoteComunitario encontrado
            //loteComunitario->agregarReserva(fecha, horaInicio, horaFin, persona);


            return loteComunitario->ComprobarReserva(fecha, horaInicio, horaFin, persona); // Terminar el bucle después de encontrar el lote
        }
    }

    cout << "Error: No se encontró el LoteComunitario con el número " << numLoteCom << endl;
}

void Administracion::PagarExpensaLotePrivado(int numLote, Fecha& fechaExpensa) {
    // Busca el lote privado por su número
    for (lotePrivado* lote : lotesPrivados) {
        if (lote->getNumero() == numLote) {
            // Paga la expensa del lote privado
            lote->PagarExpensa(fechaExpensa);
            return;  // Termina el bucle después de pagar la expensa
        }
    }

    // Si llegamos aquí, no se encontró un lote privado con el número especificado
    cout << "Error: No se encontró un lote privado con el número especificado." << endl;
}

void Administracion::CalcularExpensa(Fecha& fecha){
	double areaTotal = calcularAreaTotalPrivado();
	double servicios = calcularCostoContratacionesPorMes(fecha);
	double consumoComunitario = calcularExpensaPrivada(fecha);

	for (lotePrivado* lote : lotesPrivados) {
	        if (lote->getVendido()) {
	            lote->CrearExpensa(fecha, areaTotal, servicios, consumoComunitario);
	        }
	    }
}

void Administracion::emitirFactura(int numLote, Fecha& fechaExpensa)
	{
		for (auto& lote : lotesPrivados) {
		            if (lote->getNumero() == numLote) {
		                lote->EmitirFacturaExpensa(fechaExpensa);
		                break;
		            }
		        }
	}


