#ifndef CATALOGOLIVROS_HPP
#define CATALOGOLIVROS_HPP

#include "Livro.hpp"

#include <iostream>

class CatalogoLivros {
    private:
        /**
         * Vetor de livros do catalogo
         */
        std::vector<Livro> livros;

        /**
         * Vetor de generos do catalogo
         */
        std::vector<std::string> generos;

    public:
        /**
         * Construtor da classe CatalogoLivros
         */
        CatalogoLivros();

        /**
         * Retorna o vetor de livros do catalogo
         * @return vetor de livros
         */
        std::vector<Livro> getLivros();

        /**
         * Retorna o vetor de generos do catalogo
         * @return vetor de generos
         */
        std::vector<std::string> getGeneros();

        /**
         * Adiciona um genero ao vetor de generos do catalogo
         * @param genero genero a ser adicionado
         */
        void adicionarGenero(std::string genero);

        /**
         * Remove um genero do vetor de generos do catalogo
         * @param genero genero a ser removido
         */
        void removerGenero(std::string genero);

        /**
         * Edita um genero do vetor de generos do catalogo
         * @param genero genero a ser editado
         * @param novoGenero novo genero
         */
        void editarGenero(std::string genero, std::string novoGenero);

        /**
         * Define o vetor de livros do catalogo
         * @param livros vetor de livros
         */
        void setLivros(std::vector<Livro> livros);

        /**
         * Define o vetor de generos do catalogo
         * @param generos vetor de generos
         */
        void setGeneros(std::vector<std::string> generos);

        /**
         * Adiciona um livro ao vetor de livros do catalogo
         * @param titulo titulo do livro
         * @param genero genero do livro
         * @param autor autor do livro
         * @param numCopias numero de copias do livro
         * @return true se o livro foi adicionado com sucesso, false caso contrario
         */
        bool adicionarLivro(std::string titulo, std::string genero, std::string autor, int numCopias);

        /**
         * Remove um livro do vetor de livros do catalogo
         * @param titulo titulo do livro
         * @param autor autor do livro
         * @return true se o livro foi removido com sucesso, false caso contrario
         */
        bool removerLivro(std::string titulo, std::string autor);

        /**
         * Edita os dados de um livro do vetor de livros do catalogo
         * @param titulo titulo do livro
         * @param genero genero do livro
         * @param autor autor do livro
         * @param numCopias numero de copias do livro
         * @param defeito defeito do livro
         * @param endereco endereco do livro
         * @return true se o livro foi editado com sucesso, false caso contrario
         */
        bool editarLivro(std::string titulo, std::string genero, std::string autor, int numCopias, std::string defeito, std::string endereco);

        /**
         * Pesquisa por um livro no vetor de livros do catalogo
         * @param titulo titulo do livro
         * @return livro encontrado ou livro com titulo vazio caso o livro nao seja encontrado
         */
        Livro pesquisarLivro(std::string titulo);

        /**
         * Imprime todos os livros do vetor de livros do catalogo
         */
        void imprimeTodosLivros();

        /**
         * Verifica se um livro esta disponivel para emprestimo
         * @param titulo titulo do livro
         * @param autor autor do livro
         * @return true se o livro esta disponivel, false caso contrario
         */
        bool livroEstaDisponivel(std::string titulo, std::string autor);

        /**
         * Empresta um livro do vetor de livros do catalogo
         * @param titulo titulo do livro
         * @param autor autor do livro
         * @param dataDevolucao data de devolucao do livro
         */
        void emprestarLivro(std::string titulo, std::string autor, Data dataDevolucao);
};

#endif