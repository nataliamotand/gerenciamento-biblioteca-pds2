#include "Data.hpp"

Data::Data() {}

Data::Data(int dia, int mes, int ano) {
    this->dia = dia;
    this->mes = mes;
    this->ano = ano;
}

Data Data::getData() const{
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Data& data) {
    os << data.getData();
    return os;
}

int Data::getDia() {
    return this->dia;
}

int Data::getMes() {
    return this->mes;
}

int Data::getAno() {
    return this->ano;
}

void Data::setDia(int dia) {
    this->dia = dia;
}

void Data::setMes(int mes) {
    this->mes = mes;
}

void Data::setAno(int ano) {
    this->ano = ano;
}

void Data::imprimeData() {
    std::cout << this->dia << "/" << this->mes << "/" << this->ano << std::endl;
}

Data Data::adicionarDias(Data dataInicial, int dias){
    Data data = dataInicial;
    data.setDia(data.getDia() + dias);
    return data;
}