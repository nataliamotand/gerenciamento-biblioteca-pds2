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

int Data::getDia() const{
    return this->dia;
}

int Data::getMes() const{
    return this->mes;
}

int Data::getAno() const{
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

int Data::diasNoMes(int mes, int ano) {
    if (mes == 2) {
        if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0) {
            return 29;
        } else {
            return 28;
        }
    } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        return 30;
    } else {
        return 31;
    }
}

Data Data::adicionarDias(Data dataInicial, int dias) {
    int dia = dataInicial.getDia() + dias;
    int mes = dataInicial.getMes();
    int ano = dataInicial.getAno();

    while (dia > Data::diasNoMes(mes, ano)) {
        dia -= Data::diasNoMes(mes, ano);
        mes++;
        if (mes > 12) {
            mes = 1;
            ano++;
        }
    }

    return Data(dia, mes, ano);
}

int Data::calcularDiferenca(Data data){
    int dias = 0;
    while (data < *this){
        data = data.adicionarDias(data, 1);
        dias++;
    }
    return dias;
}