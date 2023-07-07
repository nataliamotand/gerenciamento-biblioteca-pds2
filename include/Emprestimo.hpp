#ifndef EMPRESTIMO_HPP
#define EMPRESTIMO_HPP

#include "Livro.hpp"

#include <string>
#include <vector>
#include <map>

class Emprestimo {
    private:
        /**
         * Vetor de livros emprestados, com data de emprestimo e data de devolucao
         * <Livro, Data de empréstimo, Data de devolução>
         */
        std::vector<std::map<Livro, std::map<Data, Data>>> livros;
        /**
         * Vetor de livros atrasados e dias atrasados para cada livro
         * dia(s) atrasado(s) e livro(s) atrasado(s)
         */
        std::vector<std::map<Livro, int>> diasAtrasados;
        /**
         * Vetor de livros atrasados e multa para cada livro
         * multa(s) e livro(s) atrasado(s)
         */
        std::vector<std::map<Livro, float>> multa;
        /**
         * Dias padrão para empréstimo de livros. Valor padrão: 14 dias
         */
        const int diasPadraoEmprestimo = 14;
        /**
         * Máximo de livros que podem ser emprestados por vez. Valor padrão: 2 livros
         */
        const int maximoLivrosEmprestados = 2;
        /**
         * Multa por dia de atraso. Valor padrão: 1
         */
        const int multaPorDia = 1;

    public:
        /**
         * Construtor da classe Emprestimo
         */
        Emprestimo();

        /**
         * Retorna o vetor de livros emprestados
         * @return vetor de livros emprestados
         */
        std::vector<std::map<Livro, std::map<Data, Data>>> getLivros();

        /**
         * Retorna a quantidade de dias padrão para empréstimo de livros
         * @return dias padrão para empréstimo de livros
         */
        int getDiasPadraoEmprestimo();

        /**
         * Retorna a quantidade máxima de livros que podem ser emprestados por vez
         * @return quantidade máxima de livros que podem ser emprestados por vez
         */
        int getMaximoLivrosEmprestados();

        /**
         * Retorna o valor total da multa
         * @return valor total da multa
         */
        float getMulta();

        /**
         * Calcula a multa de acordo com os livros atrasados e dias atrasados de cada livro
         * @param dataAtual data atual
         */
        void calcularMulta(Data dataAtual);

        /**
         * Calcula a data de devolução de um livro
         * @param dataEmprestimo data de empréstimo
         * @return data de devolução
         */
        Data calcularDataDevolucao(Data dataEmprestimo);

        /**
         * Adiciona um livro ao vetor de livros emprestados
         * @param livro livro a ser adicionado
         * @param dataEmprestimo data de empréstimo
         */
        void adicionarLivro(Livro livro, Data dataEmprestimo);

        /**
         * Renova um livro do vetor de livros emprestados
         * @param titulo titulo do livro a ser renovado
         * @param dataAtual data atual
         * @return true se o livro foi renovado, false caso contrario
         */
        bool renovarLivro(std::string titulo, Data dataAtual);

        /**
         * Verifica se usuario pode pegar um livro emprestado
         * @return true se o usuario pode pegar um livro emprestado, false caso contrario
         */
        bool podePegarLivroEmprestado();
};


#endif