#ifndef CATALOGOLIVROS_HPP
#define CATALOGOLIVROS_HPP

#include "Livro.hpp"

#include <iostream>

class CatalogoLivros {
    private:
        std::vector<Livro> livros;
        std::vector<std::string> generos;

    public:
        CatalogoLivros();

        std::vector<Livro> getLivros();
        std::vector<std::string> getGeneros();
        void adicionarGenero(std::string genero);
        void removerGenero(std::string genero);
        void editarGenero(std::string genero, std::string novoGenero);

        void setLivros(std::vector<Livro> livros);
        void setGeneros(std::vector<std::string> generos);

        bool adicionarLivro(std::string titulo, std::string genero, std::string autor, int numCopias);
        bool removerLivro(std::string titulo, std::string autor);
        bool editarLivro(std::string titulo, std::string genero, std::string autor, int numCopias, std::string defeito, std::string endereco);
        Livro pesquisarLivro(std::string titulo);
        void imprimeTodosLivros();
};

#endif
