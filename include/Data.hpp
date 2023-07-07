#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <iostream>

class Data{
    private:
        int dia;
        int mes;
        int ano;
        int diasNoMes(int mes, int ano);

    public:
        Data();
        Data(int dia, int mes, int ano);
        Data getData() const;
        friend std::ostream& operator<<(std::ostream& os, const Data& data);
        int getDia() const;
        int getMes() const;
        int getAno() const;
        void setDia(int dia);
        void setMes(int mes);
        void setAno(int ano);
        void imprimeData();
        Data adicionarDias(Data dataInicial, int dias);
        bool operator<(const Data& other) const {
            if (this->ano != other.ano) {
                return this->ano < other.ano;
            }
            if (this->mes != other.mes) {
                return this->mes < other.mes;
            }
            return this->dia < other.dia;
        }
        int calcularDiferenca(Data data);
};
#endif