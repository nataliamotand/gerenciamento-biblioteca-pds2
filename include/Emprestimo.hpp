#ifndef EMPRESTIMO_HPP
#define EMPRESTIMO_HPP

#include "Livro.hpp"

#include <string>
#include <vector>
#include <map>

class Emprestimo {
    private:
        // <Livro, Data de empréstimo, Data de devolução>
        std::vector<std::map<Livro, std::map<Data, Data>>> livros;
        // dia(s) atrasado(s) e livro(s) atrasado(s)
        std::vector<std::map<Livro*, int>> diasAtrasados;
        // multa(s) e livro(s) atrasado(s)
        std::vector<std::map<Livro*, float>> multa;
        const int diasPadraoEmprestimo = 14;
        const int maximoLivrosEmprestados = 2;

    public:
        Emprestimo();
        std::vector<std::map<Livro, std::map<Data, Data>>> getLivros();
        int getDiasPadraoEmprestimo();
        Data calcularDataDevolucao(Data dataEmprestimo);
        void adicionarLivro(Livro livro, Data dataEmprestimo);
        bool renovarLivro(std::string titulo, Data dataAtual);
        bool podePegarLivroEmprestado();
};


#endif
