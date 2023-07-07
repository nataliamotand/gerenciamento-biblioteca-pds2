#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <iostream>

class Data{
    private:
        /**
         * Dia da data
         */
        int dia;
        /**
         * Mes da data
         */
        int mes;
        /**
         * Ano da data
         */
        int ano;
        /**
         * Verifica o numero de dias em um mes ou ano
         * @param mes mes a ser verificado
         * @param ano ano a ser verificado
         * @return numero de dias
         */
        int diasNoMes(int mes, int ano);

    public:
        /**
         * Construtor padrão da classe Data
         */
        Data();

        /**
         * Construtor da classe Data
         * @param dia dia da data
         * @param mes mes da data
         * @param ano ano da data
         */
        Data(int dia, int mes, int ano);

        /**
         * Obtem a data
         * @return data
         */
        Data getData() const;

        /**
         * Permite fazer um overload do operador de output
         */
        friend std::ostream& operator<<(std::ostream& os, const Data& data);

        /**
         * Permite fazer um overload do operador de input
         */
        int getDia() const;

        /**
         * Obtém o mes da data
         * @return mes da data
         */
        int getMes() const;

        /**
         * Obtém o ano da data
         * @return ano da data
         */
        int getAno() const;

        /**
         * Define o dia da data
         * @param dia dia da data
         */
        void setDia(int dia);

        /**
         * Define o mes da data
         * @param mes mes da data
         */
        void setMes(int mes);

        /**
         * Define o ano da data
         * @param ano ano da data
         */
        void setAno(int ano);

        /**
         * Imprime a data no formato DD/MM/AAAA
         */
        void imprimeData();

        /**
         * Adiciona dias a uma data
         * @param dataInicial data inicial
         * @param dias dias a serem adicionados
         * @return data final com os dias adicionados
         */
        Data adicionarDias(Data dataInicial, int dias);

        /**
         * Compara duas datas. Primeiro compara o ano, depois o mes e por ultimo o dia
         * @param other data a ser comparada
         * @return true se a data for menor que a outra, false caso contrario
         */
        bool operator<(const Data& other) const {
            if (this->ano != other.ano) {
                return this->ano < other.ano;
            }
            if (this->mes != other.mes) {
                return this->mes < other.mes;
            }
            return this->dia < other.dia;
        }

        /**
         * Calcula a diferanca entre duas datas
         * @param data data a ser comparada
         * @return numero de dias de diferenca entre as datas
         */
        int calcularDiferenca(Data data);
};
#endif