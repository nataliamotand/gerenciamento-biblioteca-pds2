#include "test_config.h"

#include "Livro.hpp"

TEST_CASE("Testando get de título") {
    Livro livro = Livro("titulo", "genero", "autor", 10, true, "", "0011", "B1");
    REQUIRE(livro.getTitulo() == "titulo");
}

TEST_CASE("Testando get de gênero") {
    Livro livro = Livro("titulo", "genero", "autor", 10, true, "", "0011", "B1");
    REQUIRE(livro.getGenero() == "genero");
}

TEST_CASE("Testando get de autor") {
    Livro livro = Livro("titulo", "genero", "autor", 10, true, "", "0011", "B1");
    REQUIRE(livro.getAutor() == "autor");
}

TEST_CASE("Testando get de número de cópias") {
    Livro livro = Livro("titulo", "genero", "autor", 10, true, "", "0011", "B1");
    REQUIRE(livro.getNumCopias() == 10);
}

TEST_CASE("Testando get de disponibilidade") {
    Livro livro = Livro("titulo", "genero", "autor", 10, true, "", "0011", "B1");
    REQUIRE(livro.getDisponibilidade() == true);
}

TEST_CASE("Testando get de código") {
    Livro livro = Livro("titulo", "genero", "autor", 10, true, "", "0011", "B1");
    REQUIRE(livro.getCodigo() == "0011");
}

TEST_CASE("Testando get de endereço") {
    Livro livro = Livro("titulo", "genero", "autor", 10, true, "", "0011", "B1");
    REQUIRE(livro.getEndereco() == "B1");
}

TEST_CASE("Testando get de data de devolução") {
    Livro livro = Livro("titulo", "genero", "autor", 10, true, "", "0011", "B1");
    Data data = Data(1, 6, 2023);
    livro.setDataDevolucao(data);
    REQUIRE(livro.getDataDevolucao().getDia() == 1);
    REQUIRE(livro.getDataDevolucao().getMes() == 6);
    REQUIRE(livro.getDataDevolucao().getAno() == 2023);
}

TEST_CASE("Testando get de data de empréstimo") {
    Livro livro = Livro("titulo", "genero", "autor", 10, true, "", "0011", "B1");
    Data data = Data(1, 6, 2023);
    livro.setDataEmprestimo(data);
    REQUIRE(livro.getDataEmprestimo().getDia() == 1);
    REQUIRE(livro.getDataEmprestimo().getMes() == 6);
    REQUIRE(livro.getDataEmprestimo().getAno() == 2023);
}

TEST_CASE("Testando set de título") {
    Livro livro = Livro();
    livro.setTitulo("titulo");
    REQUIRE(livro.getTitulo() == "titulo");
}

TEST_CASE("Testando set de gênero") {
    Livro livro = Livro();
    livro.setGenero("genero");
    REQUIRE(livro.getGenero() == "genero");
}

TEST_CASE("Testando set de autor") {
    Livro livro = Livro();
    livro.setAutor("autor");
    REQUIRE(livro.getAutor() == "autor");
}

TEST_CASE("Testando set de número de cópias") {
    Livro livro = Livro();
    livro.setNumCopias(10);
    REQUIRE(livro.getNumCopias() == 10);
}

TEST_CASE("Testando set de disponibilidade") {
    Livro livro = Livro();
    livro.setDisponibilidade(true);
    REQUIRE(livro.getDisponibilidade() == true);
}

TEST_CASE("Testando set de código") {
    Livro livro = Livro();
    livro.setCodigo("0011");
    REQUIRE(livro.getCodigo() == "0011");
}

TEST_CASE("Testando set de endereço") {
    Livro livro = Livro();
    livro.setEndereco("B1");
    REQUIRE(livro.getEndereco() == "B1");
}

TEST_CASE("Testando set de data de devolução") {
    Livro livro = Livro();
    Data data = Data(1, 6, 2023);
    livro.setDataDevolucao(data);
    REQUIRE(livro.getDataDevolucao().getDia() == 1);
    REQUIRE(livro.getDataDevolucao().getMes() == 6);
    REQUIRE(livro.getDataDevolucao().getAno() == 2023);
}

TEST_CASE("Testando set de data de empréstimo") {
    Livro livro = Livro();
    Data data = Data(1, 6, 2023);
    livro.setDataEmprestimo(data);
    REQUIRE(livro.getDataEmprestimo().getDia() == 1);
    REQUIRE(livro.getDataEmprestimo().getMes() == 6);
    REQUIRE(livro.getDataEmprestimo().getAno() == 2023);
}

TEST_CASE("Testando empréstimo de livro") {
    Livro livro = Livro("titulo", "genero", "autor", 1, true, "", "0011", "B1");
    livro.emprestarLivro();
    REQUIRE(livro.getDisponibilidade() == false);
}

TEST_CASE("Testando devolução de livro") {
    Livro livro = Livro("titulo", "genero", "autor", 1, false, "", "0011", "B1");
    livro.devolverLivro();
    REQUIRE(livro.getDisponibilidade() == true);
}
