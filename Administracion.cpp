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
void Administracion::agregarLotePrivado(double area, bool vendido, Persona* propietario) {
    lotePrivado* nuevo = new lotePrivado(area, vendido, propietario);
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
        if (lote->estaVendido()) {
            cont++;
        }
    }
    return cont;
}

float Administracion::calcularCostoContratacionesPorMes(int mes) {
    float total = 0.0;

    for (Contratacion* contratacion : contrataciones) {
        if (contratacion->getFecha().getMes() == mes) {
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

double Administracion::calcularExpensaPrivada( Fecha& fecha) {
    double consumoComunitario = calcularConsumoComunitario(fecha);
    double totalReservas = calcularTotalReservas(fecha);

    if (consumoComunitario <= totalReservas) {
        return 0.0;
    }

    double recaudacionReservas = recaudacion(fecha);
    int cantPrivadosOcupados = cantidadLotesPrivadosOcupados();

    return (consumoComunitario - recaudacionReservas) / cantPrivadosOcupados;
}

void Administracion::venderLotePrivado(Persona& comprador, lotePrivado* lote) {
    if (lote && !lote->estaVendido()) {
        // Establecer el nuevo propietario
        lote->setPropietario(&comprador);

        // Marcar el lote como vendido
        lote->setVendido(true);

        // Agregar el lote al array de lotes del nuevo propietario
        comprador.agregarLotePropietario(lote);
    } else {
        cout << "Error: El lote no está disponible para la venta." << endl;
    }
}

double Administracion::calculaRecaudacion( Fecha& fecha) {
    double totalRecaudado = 0.0;

    for (LoteComunitario* lote : lotesComunitarios) {
        totalRecaudado += lote->calcularRecaudacion(fecha);
    }

    return totalRecaudado;
}

void Administracion::agregarReservaLoteComunitario(int numLoteCom, Fecha& fecha, int horaInicio, int horaFin, double precioReserva, Persona* persona)
{
    // Buscar el LoteComunitario por su número
    for (LoteComunitario* loteComunitario : lotesComunitarios)
    {
        if (loteComunitario->getNumero() == numLoteCom)
        {
            // Agregar la reserva al LoteComunitario encontrado
            loteComunitario->agregarReserva(fecha, horaInicio, horaFin, precioReserva, persona);
            return;  // Terminar el bucle después de encontrar el lote
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


