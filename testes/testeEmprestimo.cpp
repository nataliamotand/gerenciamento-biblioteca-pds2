#include "test_config.h"

#include "Emprestimo.hpp"

TEST_CASE("Testando adição e get de livros"){
    Emprestimo emprestimo = Emprestimo();
    Livro livro = Livro("titulo", "genero", "autor", 10, true, "", "0011", "B1");
    Data data = Data(1, 6, 2023);
    emprestimo.adicionarLivro(livro, data);
    std::vector<std::map<Livro, std::map<Data, Data>>> livros = emprestimo.getLivros();
    REQUIRE(livros[0].begin()->first.getTitulo() == "titulo");
    // CHECK_EQ(livros[0].begin()->first.getGenero(), "genero");
}

TEST_CASE("Testando get de dias padrão de empréstimo"){
    Emprestimo emprestimo = Emprestimo();
    CHECK_EQ(emprestimo.getDiasPadraoEmprestimo(), 14);
}

TEST_CASE("Testando get de livros máximos para emprestar"){
    Emprestimo emprestimo = Emprestimo();
    CHECK_EQ(emprestimo.getMaximoLivrosEmprestados(), 2);
}

TEST_CASE("Testando cálculo de data de devolução"){
    Emprestimo emprestimo = Emprestimo();
    Data data = Data(1, 6, 2023);
    Data dataDevolucao = emprestimo.calcularDataDevolucao(data);
    CHECK_EQ(dataDevolucao.getDia(), 15);
    CHECK_EQ(dataDevolucao.getMes(), 6);
    CHECK_EQ(dataDevolucao.getAno(), 2023);
}

TEST_CASE("Testando se usuário pode pegar livro emprestado"){
    Emprestimo emprestimo = Emprestimo();
    CHECK_EQ(emprestimo.podePegarLivroEmprestado(), true);
}
