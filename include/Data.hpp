#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <iostream>

class Data{
    private:
        int dia;
        int mes;
        int ano;
    public:
        Data();
        Data(int dia, int mes, int ano);
        Data getData() const;
        int getDia();
        int getMes();
        int getAno();
        void setDia(int dia);
        void setMes(int mes);
        void setAno(int ano);
};
#endif