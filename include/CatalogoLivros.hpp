#ifndef CATALOGOLIVROS_HPP
#define CATALOGOLIVROS_HPP

#include "Livro.hpp"

#include <string>
#include <vector>
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
        void editarGenero(std::string genero);

        void setLivros(std::vector<Livro> livros);
        void setGeneros(std::vector<std::string> generos);

        void adicionarLivro(Livro livro);
        void removerLivro(Livro livro);
        void editarLivro(Livro livro);
        Livro pesquisarLivro(std::string titulo);
};

#endif
