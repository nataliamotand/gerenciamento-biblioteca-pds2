

#ifndef LIVRO_HPP
#define LIVRO_HPP

#include "Data.hpp"

#include <string>
#include <vector>

class Livro {
    private:
        /**
         * Titulo do livro
         */
        std::string titulo;
        /**
         * Genero do livro
         */
        std::string genero;
        /**
         * Autor do livro
         */
        std::string autor;
        /**
         * Numero de copias do livro
         */
        int numCopias;
        /**
         * Disponibilidade do livro
         */
        bool disponibilidade;
        /**
         * Defeito do livro
         */
        std::string defeito;
        /**
         * Codigo do livro
         */
        std::string codigo;
        /**
         * Endereco do livro
         */
        std::string endereco;
        /**
         * Data de data de emprestimo e devolucao do livro
         */
        Data dataEmprestimo, dataDevolucao;

    public:
        /**
         * Construtor padrao
         */
        Livro();

        /**
         * Construtor da classe Livro
         * @param titulo titulo do livro
         * @param genero genero do livro
         * @param autor autor do livro
         * @param numCopias numero de copias do livro
         * @param disponibilidade disponibilidade do livro
         * @param defeito defeito do livro
         * @param codigo codigo do livro
         * @param endereco endereco do livro
         */
        Livro(std::string titulo, std::string genero, std::string autor,
            int numCopias, bool disponibilidade, std::string defeito,
            std::string codigo, std::string endereco);

        /**
         * Retorna o titulo do livro
         * @return titulo do livro
         */
        std::string getTitulo() const;

        /**
         * Sobrecarga do operador de comparacao
         * @param other livro a ser comparado
         * @return true se o livro for menor que o outro, false caso contrario
         */
        bool operator<(const Livro& other) const;

        /**
         * Obtém o genero do livro
         * @return genero do livro
         */
        std::string getGenero();

        /**
         * Obtém o autor do livro
         * @return autor do livro
         */
        std::string getAutor();

        /**
         * Obtém o numero de copias do livro
         * @return numero de copias do livro
         */
        int getNumCopias();

        /**
         * Obtém a disponibilidade do livro
         * @return disponibilidade do livro
         */
        bool getDisponibilidade();

        /**
         * Obtém o defeito do livro
         * @return defeito do livro
         */
        std::string getDefeito();

        /**
         * Obtém o codigo do livro
         * @return codigo do livro
         */
        std::string getCodigo();

        /**
         * Obtém o endereco do livro
         * @return endereco do livro
         */
        std::string getEndereco();

        /**
         * Obtém a data de devolucao do livro
         * @return data de devolucao do livro
         */
        Data getDataDevolucao();

        /**
         * Obtém a data de emprestimo do livro
         * @return data de emprestimo do livro
         */
        Data getDataEmprestimo();

        /**
         * Altera o titulo do livro
         * @param titulo novo titulo do livro
         */
        void setTitulo(std::string titulo);

        /**
         * Altera o genero do livro
         * @param genero novo genero do livro
         */
        void setGenero(std::string genero);

        /**
         * Altera o autor do livro
         * @param autor novo autor do livro
         */
        void setAutor(std::string autor);

        /**
         * Altera o numero de copias do livro
         * @param numCopias novo numero de copias do livro
         */
        void setNumCopias(int numCopias);

        /**
         * Altera a disponibilidade do livro
         * @param disponibilidade nova disponibilidade do livro
         */
        void setDisponibilidade(bool disponibilidade);

        /**
         * Altera o defeito do livro
         * @param defeito novo defeito do livro
         */
        void setDefeito(std::string defeito);

        /**
         * Altera o codigo do livro
         * @param codigo novo codigo do livro
         */
        void setCodigo(std::string codigo);

        /**
         * Altera o endereco do livro
         * @param endereco novo endereco do livro
         */
        void setEndereco(std::string endereco);

        /**
         * Altera a data de devolucao do livro
         * @param dataDevolucao nova data de devolucao do livro
         */
        void setDataDevolucao(Data dataDevolucao);

        /**
         * Altera a data de emprestimo do livro
         * @param dataEmprestimo nova data de emprestimo do livro
         */
        void setDataEmprestimo(Data dataEmprestimo);

        /**
         * Realiza o emprestimo do livro
         */
        void emprestarLivro();

        /**
         * Realiza a devolucao do livro
         */
        void devolverLivro();
};

#endif