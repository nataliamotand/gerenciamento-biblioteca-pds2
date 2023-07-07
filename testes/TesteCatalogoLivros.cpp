// #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "test_config.h"

#include "CatalogoLivros.hpp"

TEST_CASE("Testa se o livro está no catálogo"){
    CatalogoLivros catalogoLivros = CatalogoLivros();
    CHECK_EQ(catalogoLivros.pesquisarLivro("O Pequeno Príncipe").getTitulo(), "O Pequeno Príncipe");
}

TEST_CASE("Testa se o livro não está no catálogo"){
    CatalogoLivros catalogoLivros = CatalogoLivros();
    CHECK_EQ(catalogoLivros.pesquisarLivro("O Pequeno Príncipe").getTitulo(), "O Pequeno Príncipe");
}

TEST_CASE("Testa o get de todos livros"){
    CatalogoLivros catalogoLivros = CatalogoLivros();
    catalogoLivros.getLivros();
    CHECK_EQ(catalogoLivros.getLivros().size(), 11);
}

TEST_CASE("Testa o set de todos livros está funcionando"){
    CatalogoLivros catalogoLivros = CatalogoLivros();
    Livro livro[3] = {
        Livro("O Pequeno Príncipe", "Fantasia", "Antoine de Saint-Exupéry", 10, true, "", "0011", "B1"),
        Livro("O Senhor dos Anéis", "Fantasia", "J. R. R. Tolkien", 10, true, "", "0012", "B2"),
        Livro("O Hobbit", "Fantasia", "J. R. R. Tolkien", 10, true, "", "0013", "B3")
    };
    std::vector<Livro> livros = {livro[0], livro[1], livro[2]};
    catalogoLivros.setLivros(livros);
    CHECK_EQ(catalogoLivros.getLivros().size(), 3);
}

TEST_CASE("Testa se adição de gênero está funcionando"){
    CatalogoLivros catalogoLivros = CatalogoLivros();
    catalogoLivros.adicionarGenero("Romance");
    CHECK_EQ(catalogoLivros.getGeneros().back(), "Romance");
}

TEST_CASE("Testa o set de todos gêneros está funcionando"){
    CatalogoLivros catalogoLivros = CatalogoLivros();
    std::vector<std::string> novosGeneros = {"Romance", "Ficção", "Terror"};
    catalogoLivros.setGeneros(novosGeneros);
    std::vector<std::string> generos = catalogoLivros.getGeneros();
    CHECK_EQ(generos[0], "Romance");
    CHECK_EQ(generos[1], "Ficção");
    CHECK_EQ(generos[2], "Terror");
}

TEST_CASE("Testa se adição e remoção de gênero está funcionando"){
    CatalogoLivros catalogoLivros = CatalogoLivros();
    catalogoLivros.adicionarGenero("Romance");
    catalogoLivros.removerGenero("Romance");
    CHECK_EQ(catalogoLivros.getGeneros().back(), "Fantasia");
}

TEST_CASE("Testa se adição e edição de gênero está funcionando"){
    CatalogoLivros catalogoLivros = CatalogoLivros();
    catalogoLivros.adicionarGenero("Romance");
    catalogoLivros.editarGenero("Romance", "Ficção");
    CHECK_EQ(catalogoLivros.getGeneros().back(), "Ficção");
}

TEST_CASE("Testa o get de todos generos"){
    CatalogoLivros catalogoLivros = CatalogoLivros();
    catalogoLivros.getGeneros();
    CHECK_EQ(catalogoLivros.getGeneros().size(), 3);
}

TEST_CASE("Testa se adição de livro está funcionando"){
    CatalogoLivros catalogoLivros = CatalogoLivros();
    catalogoLivros.adicionarLivro("O Poder da Espada", "Fantasia", "Joe Abercrombie", 1);
    CHECK_EQ(catalogoLivros.pesquisarLivro("O Poder da Espada").getTitulo(), "O Poder da Espada");
}

TEST_CASE("Testa se remoção de livro está funcionando"){
    CatalogoLivros catalogoLivros = CatalogoLivros();
    catalogoLivros.adicionarLivro("O Poder da Espada", "Fantasia", "Joe Abercrombie", 1);
    catalogoLivros.removerLivro("O Poder da Espada", "Joe Abercrombie");
    CHECK_EQ(catalogoLivros.pesquisarLivro("O Poder da Espada").getTitulo(), "");
}

TEST_CASE("Testa se edição de livro está funcionando"){
    CatalogoLivros catalogoLivros = CatalogoLivros();
    catalogoLivros.adicionarLivro("O Poder da Espada", "Fantasia", "Joe Abercrombie", 1);
    catalogoLivros.editarLivro("O Poder da Espada", "Fantasia", "Joe Abercrombie", 1, "Rasgado", "A1");
    CHECK_EQ(catalogoLivros.pesquisarLivro("O Poder da Espada").getTitulo(), "O Poder da Espada");
    CHECK_EQ(catalogoLivros.pesquisarLivro("O Poder da Espada").getAutor(), "Joe Abercrombie");
    CHECK_EQ(catalogoLivros.pesquisarLivro("O Poder da Espada").getGenero(), "Fantasia");
    CHECK_EQ(catalogoLivros.pesquisarLivro("O Poder da Espada").getDefeito(), "Rasgado");
    CHECK_EQ(catalogoLivros.pesquisarLivro("O Poder da Espada").getNumCopias(), 1);
    CHECK_EQ(catalogoLivros.pesquisarLivro("O Poder da Espada").getEndereco(), "A1");
}

TEST_CASE("Testa se o livro está disponível"){
    CatalogoLivros catalogoLivros = CatalogoLivros();
    CHECK_EQ(catalogoLivros.livroEstaDisponivel("O Pequeno Príncipe", "Antoine de Saint-Exupéry"), true);
}

TEST_CASE("Testa se o livro não está disponível"){
    CatalogoLivros catalogoLivros = CatalogoLivros();
    catalogoLivros.adicionarLivro("O Poder da Espada", "Fantasia", "Joe Abercrombie", 1);
    catalogoLivros.emprestarLivro("O Poder da Espada", "Joe Abercrombie", Data(1, 5, 2023));
    CHECK_EQ(catalogoLivros.livroEstaDisponivel("O Poder da Espada", "Joe Abercrombie"), false);
}

TEST_CASE("Testa se o livro foi emprestado"){
    CatalogoLivros catalogoLivros = CatalogoLivros();
    catalogoLivros.emprestarLivro("O Pequeno Príncipe", "Antoine de Saint-Exupéry", Data(1, 5, 2023));
    CHECK_EQ(catalogoLivros.livroEstaDisponivel("O Pequeno Príncipe", "Antoine de Saint-Exupéry"), false);
}

